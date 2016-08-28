#ifndef  __IMAGE_BUFFER_H__
#define __IMAGE_BUFFER_H__

// STD
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

// RayTracingInOneWeekend
#include "Color.h"

class ImageBuffer {
public:
  ImageBuffer(const uint32_t& width = 100, const uint32_t& height = 100);
  ~ImageBuffer();

  void resize(const uint32_t& width, const uint32_t& height);

  Color3fa& operator()(const uint32_t& x, const uint32_t& y);
  const Color3fa& operator()(const uint32_t& x, const uint32_t& y) const;

  bool savePPM(const std::string& filePath) const;
  bool saveBMP(const std::string& filePath) const;
  bool savePNG(const std::string& filePath) const;


private:
  int32_t                            m_width, m_height;
  std::vector<std::vector<Color3fa>> m_colorBuffer;
};

#endif // __IMAGE_BUFFER_H__