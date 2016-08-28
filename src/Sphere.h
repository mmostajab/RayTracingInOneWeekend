#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "Hitable.h"

class Sphere : public Hitable {
public:

  Sphere(const glm::vec3& center = glm::vec3(0.0f), const float& radius = 1.0f);
  ~Sphere();

  bool      hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord) const override;
  glm::vec3 shade(const HitRecord& hitRecord) const override;

private:
  glm::vec3 m_center;
  float     m_radius;
};

#endif // __SPHERE_H__