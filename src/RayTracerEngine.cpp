#include "RayTracerEngine.h"

#include <glm/glm.hpp>

RayTracerEngine::RayTracerEngine(): m_camera(), m_buffer(800, 600)
{
}

RayTracerEngine::~RayTracerEngine()
{
}

void RayTracerEngine::render()
{
  for (uint32_t y = 0; y < m_buffer.getHeight(); y++)
    for (uint32_t x = 0; x < m_buffer.getWidth(); x++) {
      float u = static_cast<float>(x) / static_cast<float>(m_buffer.getWidth());
      float v = static_cast<float>(y) / static_cast<float>(m_buffer.getHeight());

      Ray ray = m_camera.getRay(u, v);

      glm::vec3& color = m_buffer(x, y); 
      color = getBackColor(ray);
    }
}

void RayTracerEngine::saveOutput(OutputFormat format, const std::string & filePath)
{
  if      (format == OUT_FORMAT_PNG) m_buffer.savePNG(filePath);
  else if (format == OUT_FORMAT_BMP) m_buffer.saveBMP(filePath);
  else if (format == OUT_FORMAT_PPM) m_buffer.savePPM(filePath);
}

glm::vec3 RayTracerEngine::getBackColor(const Ray& ray) const
{
  glm::vec3 unit_direction = glm::normalize(ray.direction());
  float t = 0.5f * (1.0f + unit_direction.g);

  return (1 - t) * glm::vec3(1.0f, 1.0f, 1.0f) + t * glm::vec3(0.5f, 0.7f, 1.0f);
}
