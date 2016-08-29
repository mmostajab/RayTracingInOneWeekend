#include "RayTracerEngine.h"

// STD
#include <random>

// GLM
#include <glm/glm.hpp>


RayTracerEngine::RayTracerEngine(): 
  m_camera(glm::vec3(0.0f), 1.3f, glm::vec3(2.6f, 0.0f, 0.0f), glm::vec3(0.0f, 2.0f, 0.0f)), 
  m_buffer(800, 600),
  m_nSpP(100)
{
}

RayTracerEngine::~RayTracerEngine()
{
}

void RayTracerEngine::render()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<float> dis(0.0f, 1.0f);

  for (uint32_t y = 0; y < m_buffer.getHeight(); y++)
    for (uint32_t x = 0; x < m_buffer.getWidth(); x++) {
      
      // pixel color
      glm::vec3& color = m_buffer(x, y);
      
      // Sending more rays per pixel
      for (uint32_t s = 0; s < m_nSpP; s++) {
        //std::cout << dis(gen) << " " << std::endl;
        float u = glm::clamp(static_cast<float>(x + static_cast<float>(dis(gen))) / static_cast<float>(m_buffer.getWidth()) , 0.0f, 1.0f);
        float v = glm::clamp(static_cast<float>(y + static_cast<float>(dis(gen))) / static_cast<float>(m_buffer.getHeight()), 0.0f, 1.0f);
        float t_min = 0.0f, t_max = std::numeric_limits<float>::max();

        Ray ray = m_camera.getRay(u, v);

        // intersecting ray with hitable primitives
        for (auto& hitable : m_hitables) {
          HitRecord hitRecord;
          if (hitable->hit(ray, t_min, t_max, hitRecord)) {
            t_max = hitRecord.ray_t;
            color += hitable->shade(hitRecord);
          }
        }

        // if it does not intersect with any primitive
        if (t_max == std::numeric_limits<float>::max()) color += getBackColor(ray);
      }

      // averaging all collected samples
      color /= m_nSpP;
    }
}

void RayTracerEngine::saveOutput(OutputFormat format, const std::string & filePath)
{
  if      (format == OUT_FORMAT_PNG) m_buffer.savePNG(filePath);
  else if (format == OUT_FORMAT_BMP) m_buffer.saveBMP(filePath);
  else if (format == OUT_FORMAT_PPM) m_buffer.savePPM(filePath);
}

void RayTracerEngine::addHitable(std::shared_ptr<Hitable> _newHitablePtr)
{
  m_hitables.push_back(_newHitablePtr);
}

glm::vec3 RayTracerEngine::getBackColor(const Ray& ray) const
{
  glm::vec3 unit_direction = glm::normalize(ray.direction());
  float t = 0.5f * (1.0f + unit_direction.g);

  return (1 - t) * glm::vec3(1.0f, 1.0f, 1.0f) + t * glm::vec3(0.5f, 0.7f, 1.0f);
}
