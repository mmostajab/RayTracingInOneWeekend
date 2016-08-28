#include "ImageBuffer.h"

#define  STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

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
    m_colorBuffer[y].resize(_width, glm::vec3(0.0f, 0.0f, 0.0f));
  }
}

glm::vec3& ImageBuffer::operator()(const uint32_t & x, const uint32_t & y)
{
  return m_colorBuffer[y][x];
}

const glm::vec3 &ImageBuffer::operator()(const uint32_t & x, const uint32_t & y) const
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
    for (int32_t x = 0; x < m_width; x++) {
      const glm::vec3& color = (*this)(x, y);

      const int32_t r = static_cast<int32_t>(color.r * 255.9f);
      const int32_t g = static_cast<int32_t>(color.g * 255.9f);
      const int32_t b = static_cast<int32_t>(color.b * 255.9f);

      outPPM << r << " " << g << " " << b << std::endl;

    }

  return true;
}

bool ImageBuffer::saveBMP(const std::string & filePath) const
{
  std::vector<unsigned char> data(3 * m_width * m_height);

  for (int32_t y = m_height - 1; y >= 0; y--)
    for (int32_t x = 0; x < m_width; x++) {
      data[3 * (m_width * y + x) + 0] = static_cast<uint8_t>(m_colorBuffer[y][x].r * 255.9);
      data[3 * (m_width * y + x) + 1] = static_cast<uint8_t>(m_colorBuffer[y][x].g * 255.9);
      data[3 * (m_width * y + x) + 2] = static_cast<uint8_t>(m_colorBuffer[y][x].b * 255.9);
    }

  if(stbi_write_bmp(filePath.c_str(), m_width, m_height, 3, data.data()) == 1)
    return true;

  return false;
}

bool ImageBuffer::savePNG(const std::string & filePath) const
{
  std::vector<unsigned char> data(3 * m_width * m_height);

  for (int32_t y = m_height - 1; y >= 0; y--)
    for (int32_t x = 0; x < m_width; x++) {
      data[3 * (m_width * y + x) + 0] = static_cast<uint8_t>(m_colorBuffer[y][x].r * 255.9);
      data[3 * (m_width * y + x) + 1] = static_cast<uint8_t>(m_colorBuffer[y][x].g * 255.9);
      data[3 * (m_width * y + x) + 2] = static_cast<uint8_t>(m_colorBuffer[y][x].b * 255.9);
    }

  if (stbi_write_png(filePath.c_str(), m_width, m_height, 3, data.data(), 0) == 1)
    return true;

  return false;
}