#include "RayTracerEngine.h"

int main() {

  RayTracerEngine engine;

  engine.render();

  engine.saveOutput(OUT_FORMAT_PNG, "test.png");

  return 0;
}