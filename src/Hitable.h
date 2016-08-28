#ifndef __HITABLE_H__
#define __HITABLE_H__

// GLM
#include <glm/glm.hpp>

// RayTracingInOneWeekend
#include "Ray.h"

struct HitRecord {
  // time, used for motion blur computation
  float     t;

  // ray.t 
  float     ray_t;

  // intersection point
  glm::vec3 point;

  // normal vector at the intersection point
  glm::vec3 normal;
};

class Hitable {
public:

  virtual bool hit(const Ray& ray, float t_min, float t_max, HitRecord& hitRecord) const = 0;
  virtual glm::vec3 shade(const HitRecord& hitRecord) const = 0;

};

#endif // __HITABLE_H__