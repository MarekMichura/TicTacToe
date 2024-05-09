#ifndef COLOR_HPP
#define COLOR_HPP

struct Color {
  float red;
  float green;
  float blue;
  float alpha = 1;
};

namespace COLORS {
constexpr Color colorFromRGBA(const unsigned char red,
                              const unsigned char green,
                              const unsigned char blue,
                              const unsigned alpha = 255)
{
  return Color{red / 255.f, green / 255.f, blue / 255.f, alpha / 255.f};
}

constexpr Color RED{1.f, 0.f, 0.f, 1.f};
constexpr Color GREEN{0.f, 1.f, 0.f, 1.f};
constexpr Color BLUE{0.f, 0.f, 1.f, 1.f};
constexpr Color BG = colorFromRGBA(0x7C, 0x98, 0x85);
}  // namespace COLORS

#endif