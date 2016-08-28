#ifndef __RAY_H__
#define __RAY_H__

#include <glm/glm.hpp>

class Ray {
public:
  Ray();
  Ray(const glm::vec3& origin, const glm::vec3& dir);
  ~Ray();

  glm::vec3 origin()    const;
  glm::vec3 direction() const;
  glm::vec3 point_at_param(const float& t) const;

  void setOrigin(const glm::vec3& origin);
  void setDirection(const glm::vec3& dir);

private:
  glm::vec3 m_origin, m_dir;

};

#endif // __COLOR_H__
