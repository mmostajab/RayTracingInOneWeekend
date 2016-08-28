#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(const glm::vec3 & _origin, const glm::vec3 & _dir): m_origin(_origin), m_dir(_dir)
{
}

Ray::~Ray()
{
}

glm::vec3 Ray::origin() const
{
  return m_origin;
}

glm::vec3 Ray::direction() const
{
  return m_origin;
}

glm::vec3 Ray::point_at_param(const float & t) const
{
  return m_origin + t * m_dir;
}
