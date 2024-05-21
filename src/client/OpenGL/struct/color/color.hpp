#pragma once

#include <cassert>
#include <cstdint>
#include <string>

constexpr float COLOR_BYTE_TO_FLOAT_RATION = 1.f / 255.f;
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
  constexpr static uint8_t VALUE_OF_0_ASCII = 48;
  constexpr static uint8_t VALUE_OF_A_ASCII = 65;
  constexpr static uint8_t VALUE_OF_a_ASCII = 97;
  constexpr static uint8_t HEX_VALUE_OF_A = 10;

  constexpr static uint8_t charToUint8_t(const unsigned char data)
  {
    assert((data >= '0' && data <= '9') || (data >= 'A' && data <= 'F') || (data >= 'a' && data <= 'f'));
    if (data >= '0' && data <= '9') {
      return data - VALUE_OF_0_ASCII;
    }
    if (data >= 'A' && data <= 'F') {
      return data - VALUE_OF_A_ASCII + HEX_VALUE_OF_A;
    }
    if (data >= 'a' && data <= 'f') {
      return data - VALUE_OF_a_ASCII + HEX_VALUE_OF_A;
    }
  }

  constexpr static uint8_t TWO_BYTE_SIZE = 16;
  constexpr static uint8_t char2ToUint8_t(const std::string data)
  {
    assert(data.length() <= 2);

    unsigned char firstNumber = static_cast<unsigned char>(data[0]);
    unsigned char secondNumber = static_cast<unsigned char>(data[1]);

    return static_cast<uint8_t>(charToUint8_t(firstNumber) * TWO_BYTE_SIZE) + charToUint8_t(secondNumber);
  }
};

namespace COLOR {
constexpr Color COLOR_BG = Color::hexadecimalColorCode("#DBB4AD");
constexpr Color COLOR_RED = Color::hexadecimalColorCode("#ff0000");
constexpr Color COLOR_GREEN = Color::hexadecimalColorCode("#00ff00");
constexpr Color COLOR_BLUE = Color::hexadecimalColorCode("#0000ff");
}  // namespace COLOR
}  // namespace gl
