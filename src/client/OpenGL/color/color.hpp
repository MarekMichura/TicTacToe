#pragma once

#include <cstdint>
#include <string>

#define COLOR_BYTE_TO_FLOAT_RATION 1.f / 255.f;
constexpr uint8_t COLOR_BYTE_MAX_VALUE = 255;

namespace gl {
class Color {
public:
  float red;
  float green;
  float blue;
  float alpha;

  constexpr Color(  //
      const float& red,
      const float& green,
      const float& blue,
      const float& alpha = 1)
      : red(red), green(green), blue(blue), alpha(alpha)
  {
  }

  constexpr static Color RGBA(  //
      const uint8_t& red_8,
      const uint8_t& green_8,
      const uint8_t& blue_8,
      const uint8_t& alpha_8 = COLOR_BYTE_MAX_VALUE)
  {
    const float red = float(red_8) * COLOR_BYTE_TO_FLOAT_RATION;
    const float green = float(green_8) * COLOR_BYTE_TO_FLOAT_RATION;
    const float blue = float(blue_8) * COLOR_BYTE_TO_FLOAT_RATION;
    const float alpha = float(alpha_8) * COLOR_BYTE_TO_FLOAT_RATION;

    return Color(red, green, blue, alpha);
  }

  constexpr static Color hexadecimalColorCode(const std::string color)
  {
    const uint8_t red = char2ToUint8_t(color.substr(1, 2));
    const uint8_t green = char2ToUint8_t(color.substr(3, 2));
    const uint8_t blue = char2ToUint8_t(color.substr(5, 2));
    const uint8_t alpha = color.length() == 9 ? char2ToUint8_t(color.substr(7, 2)) : 255;
    return RGBA(red, green, blue, alpha);
  }

private:
#define HEX_VALUE_OF_A 10;
  constexpr static uint8_t charToUint8_t(const char data)
  {
    if (data >= '0' && data <= '9') {
      return data - '0';
    }
    if (data >= 'A' && data <= 'F') {
      return data - 'A' + HEX_VALUE_OF_A;
    }
    if (data >= 'a' && data <= 'f') {
      return data - 'a' + HEX_VALUE_OF_A;
    }
    throw "data outside the range";
  }

#define TWO_BYTE_SIZE 16;
  constexpr static uint8_t char2ToUint8_t(const std::string data)
  {
    if (data.length() > 2) {
      throw "Wrong string length";
    }
    return charToUint8_t(data[0]) * TWO_BYTE_SIZE + charToUint8_t(data[1]);
  }
};
}  // namespace gl
