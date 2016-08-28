#ifndef __CAMERA_H__
#define __CAMERA_H__

// GLM
#include <glm/glm.hpp>

// RayTracingInOneWeekend
#include "Ray.h"

class Camera {
public:
  Camera(
    const glm::vec3 origin                  = glm::vec3(0.0f),
    const float     nearPlane               = 0.2f,
    const glm::vec3 planeHorizontal         = glm::vec3(2.0f, 0.0f, 0.0f),
    const glm::vec3 planeVertical           = glm::vec3(0.0f, 2.0f, 0.0f)
    );
  ~Camera();

  glm::vec3 origin() const;
  
  Ray getRay(const float& u, const float& v);

private:
  glm::vec3 m_origin;
  glm::vec3 m_planeLowerLeftCorner;
  glm::vec3 m_planeHorizontal, m_planeVertical;
};

#endif //__CAMERA_H__