#include "ImageBuffer.h"

ImageBuffer::ImageBuffer(const uint32_t & _width, const uint32_t & _height): 
  m_width(_width), m_height(_height)
{
  resize(_width, _height);
}

ImageBuffer::~ImageBuffer()
{
}

void ImageBuffer::resize(const uint32_t& _width, const uint32_t& _height)
{
  m_colorBuffer.resize(_height);
  for (uint32_t y = 0; y < _height; y++) {
    m_colorBuffer[y].resize(_width, Color3fa(0.0f, 0.0f, 0.0f, 0.0f));
  }
}

Color3fa & ImageBuffer::operator()(const uint32_t & x, const uint32_t & y)
{
  return m_colorBuffer[y][x];
}

const Color3fa & ImageBuffer::operator()(const uint32_t & x, const uint32_t & y) const
{
  return m_colorBuffer[y][x];
}

bool ImageBuffer::savePPM(const std::string& filePath) const
{
  std::ofstream outPPM(filePath);

  if (!outPPM.good()) return false;

  outPPM << "P3"    << std::endl;
  outPPM << m_width << " " << m_height   << std::endl;
  outPPM << "255"   << std::endl;

  for (int32_t y = m_height - 1; y >= 0; y--)
    for (uint32_t x = 0; x < m_width; x++) {
      const Color3fa& color = (*this)(x, y);

      const int32_t r = static_cast<int32_t>(color.r * 255.9f);
      const int32_t g = static_cast<int32_t>(color.g * 255.9f);
      const int32_t b = static_cast<int32_t>(color.b * 255.9f);

      outPPM << r << " " << g << " " << b << std::endl;

    }

  return true;
}
