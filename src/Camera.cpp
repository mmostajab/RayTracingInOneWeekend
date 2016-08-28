#include "Camera.h"

Camera::Camera(
  const glm::vec3 _origin, 
  const float     _nearPlane, 
  const glm::vec3 _planeHorizontal, 
  const glm::vec3 _planeVertical)
{
  glm::vec3 z = glm::normalize(glm::cross(_planeHorizontal, _planeVertical));

  m_origin                = _origin;
  m_planeLowerLeftCorner  = _origin - _planeHorizontal / 2.0f - _planeVertical / 2.0f - z * _nearPlane;
  m_planeHorizontal       = _planeHorizontal;
  m_planeVertical         = _planeVertical;
}

Camera::~Camera()
{
}

glm::vec3 Camera::origin() const
{
  return m_origin;
}

Ray Camera::getRay(const float & u, const float & v)
{
  glm::vec3 A = m_origin;
  glm::vec3 B = m_planeLowerLeftCorner + u * m_planeHorizontal + v * m_planeVertical;
  return Ray(A, glm::normalize(B - A));
}
