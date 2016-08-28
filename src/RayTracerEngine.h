#ifndef __RAY_TRACER_ENGINE_H__
#define __RAY_TRACER_ENGINE_H__

// Ray Tracing in One Weekend
#include "ImageBuffer.h"
#include "Ray.h"

class RayTracerEngine {
public:
  RayTracerEngine();
  ~RayTracerEngine();

  void render();

private:
  glm::vec3 getBackColor(const Ray& ray) const;

private:
  ImageBuffer m_buffer;
};

#endif