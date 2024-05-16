#pragma once

#include <cstdint>
#include <string>

#define COLOR_BYTE_TO_FLOAT_RATION 1.f / 255.f;

namespace gl {
class Color {
public:
  const float red;
  const float green;
  const float blue;
  const float alpha;

  constexpr Color(  //
      const float& red,
      const float& green,
      const float& blue,
      const float& alpha = 1)
      : red(red), green(green), blue(blue), alpha(alpha)
  {
  }

  float tmp() { return red + green + blue + alpha; }

  constexpr static Color RGBA(  //
      const uint8_t& red_8,
      const uint8_t& green_8,
      const uint8_t& blue_8,
      const uint8_t& alpha_8 = 255)
  {
    const float red = red_8 * COLOR_BYTE_TO_FLOAT_RATION;
    const float green = green_8 * COLOR_BYTE_TO_FLOAT_RATION;
    const float blue = blue_8 * COLOR_BYTE_TO_FLOAT_RATION;
    const float alpha = alpha_8 * COLOR_BYTE_TO_FLOAT_RATION;

    return Color(red, green, blue, alpha);
  }

  constexpr static Color hexadecimalColorCode(const std::string color)
  {
    const uint8_t red = char2ToUint8_t(color.substr(1, 2).c_str());
    const uint8_t green = char2ToUint8_t(color.substr(3, 2).c_str());
    const uint8_t blue = char2ToUint8_t(color.substr(5, 2).c_str());
    const uint8_t alpha =
        color.length() == 9 ? char2ToUint8_t(color.substr(7, 2).c_str()) : 255;
    return RGBA(red, green, blue, alpha);
  }

private:
  constexpr static uint8_t charToUint8_t(const char data)
  {
    switch (data) {
      case '0':
        return 0x0;
      case '1':
        return 0x1;
      case '2':
        return 0x2;
      case '3':
        return 0x3;
      case '4':
        return 0x4;
      case '5':
        return 0x5;
      case '6':
        return 0x6;
      case '7':
        return 0x7;
      case '8':
        return 0x8;
      case '9':
        return 0x9;
      case 'A':
      case 'a':
        return 0xA;
      case 'B':
      case 'b':
        return 0xB;
      case 'C':
      case 'c':
        return 0xC;
      case 'D':
      case 'd':
        return 0xD;
      case 'E':
      case 'e':
        return 0xE;
      case 'F':
      case 'f':
        return 0xF;
      default:
        throw "you can not change: ";
    }
  }

  constexpr static uint8_t char2ToUint8_t(const char data[2])
  {
    return charToUint8_t(data[0]) * 16 + charToUint8_t(data[1]);
  }
};
}  // namespace gl