#include "ImageBuffer.h"

int main() {

  int32_t size[2] = { 100, 100 };
  ImageBuffer buffer(size[0], size[1]);
  for (int i = 0; i < size[0]; i++)
    for (int j = 0; j < size[1]; j++) {
      glm::vec3& color = buffer(i, j);
      color.r = (static_cast<float>(size[0]) - i) / static_cast<float>(size[0]);
      color.g = (static_cast<float>(size[1]) - j) / static_cast<float>(size[1]);
      color.b = (static_cast<float>(i * size[1] + j)) / static_cast<float>(size[0]*size[1]);
    }

  buffer.saveBMP("test.png");
  buffer.savePPM("test.ppm");

  return 0;
}