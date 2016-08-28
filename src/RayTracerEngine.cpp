#include "RayTracerEngine.h"

#include <glm/glm.hpp>

inline RayTracerEngine::RayTracerEngine()
{
}

inline RayTracerEngine::~RayTracerEngine()
{
}

glm::vec3 RayTracerEngine::getBackColor(const Ray& ray) const
{
  glm::vec3 unit_direction = glm::normalize(ray.direction());
  float t = (1.0f + unit_direction.b) / 2.0f;

  return (1 - t) * glm::vec3(1.0f, 1.0f, 1.0f) + t * glm::vec3(0.5f, 0.7f, 1.0f);
}
