#ifndef __RAY_TRACER_ENGINE_H__
#define __RAY_TRACER_ENGINE_H__

// STD
#include <string>
#include <vector>
#include <memory>

// Ray Tracing in One Weekend
#include "Hitable.h"
#include "Camera.h"
#include "ImageBuffer.h"
#include "Ray.h"

enum OutputFormat {
  OUT_FORMAT_PNG = 0,
  OUT_FORMAT_BMP = 1,
  OUT_FORMAT_PPM = 2,
};

class RayTracerEngine {
public:
  RayTracerEngine();
  ~RayTracerEngine();

  void render();

  void saveOutput(OutputFormat format, const std::string& filePath);

  void addHitable(std::shared_ptr<Hitable> newHitablePtr);

private:
  glm::vec3 getBackColor(const Ray& ray) const;

private:
  ImageBuffer m_buffer;
  Camera      m_camera;
  std::vector<std::shared_ptr<Hitable>> m_hitables;

  // Number of samples per pixel
  uint32_t    m_nSpP;
};

#endif