#include "Sphere.h"

Sphere::Sphere(const glm::vec3& _center, const float& _radius):
  m_center(_center), m_radius(_radius)
{

}

Sphere::~Sphere() {
}

bool Sphere::hit(const Ray & _ray, float _t_min, float _t_max, HitRecord & _hitRecord) const
{
  glm::vec3 oc = m_center - _ray.origin();
  float a = glm::dot(_ray.direction(), _ray.direction());
  float b = 2.0f * glm::dot(oc, _ray.direction());
  float c = glm::dot(oc, oc) - m_radius * m_radius;
  float discriminant = b * b - 4 * a * c;
  if (discriminant >= 0) {
    float root[2] = { -b - sqrt(discriminant) / (2 * a), -b + sqrt(discriminant) / (2 * a) };
    if (root[0] >= 0 && root[0] > _t_min && root[0] <= _t_max) {
      _hitRecord.ray_t  = root[0];
      _hitRecord.point  = _ray.point_at_param(_hitRecord.ray_t);
      _hitRecord.normal = glm::normalize(glm::vec3(_hitRecord.point - m_center));
      return true;
    }
    if (root[1] >= 0 && root[1] > _t_min && root[1] <= _t_max) {
      _hitRecord.ray_t  = root[1];
      _hitRecord.point  = _ray.point_at_param(_hitRecord.ray_t);
      _hitRecord.normal = glm::normalize(glm::vec3(_hitRecord.point - m_center));
      return true;
    }
  }
  
  return false;
}

glm::vec3 Sphere::shade(const HitRecord & _hitRecord) const
{
  return 0.5f * (glm::vec3(1.0f) + _hitRecord.normal) ;
}
