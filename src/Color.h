#ifndef __COLOR_H__
#define __COLOR_H__

struct Color3fa {
  float r, g, b, a;

  Color3fa(const float& _r = 0.0f, const float& _g = 0.0f, const float& _b = 0.0f, const float& _a = 0.0f) :
    r(_r), g(_g), b(_b), a(_a) {}
};

#endif // __COLOR_H__
