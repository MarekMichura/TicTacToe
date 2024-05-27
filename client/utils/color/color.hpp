#pragma once

#include <algorithm>
#include <string>

#include "my_assert.h"
#include "my_float_to_string.h"

using uchar = unsigned char;

namespace gl {
class Color {
public:
  float red;
  float green;
  float blue;
  float alpha;

  constexpr Color(const float red, const float green, const float blue, const float alpha = 1)
      : red(red), green(green), blue(blue), alpha(alpha)
  {
    /*Assert(red >= 0 && red <= 1, "Value of red: " + floatToString(red) + ", should be between 0 and 1");
    Assert(green >= 0 && green <= 1, "Value of green: " + floatToString(green) + ", should be between 0 and 1");
    Assert(blue >= 0 && blue <= 1, "Value of blue: " + floatToString(blue) + ", should be between 0 and 1");
    Assert(alpha >= 0 && alpha <= 1, "Value of alpha: " + floatToString(alpha) + ", should be between 0 and 1");*/
  }

  constexpr Color(const uchar red, const uchar green, const uchar blue, const uchar alpha = 255)
      : Color(uintToFloat(red), uintToFloat(green), uintToFloat(blue), uintToFloat(alpha))
  {
  }

  static constexpr Color RGBA(std::string color)
  {
    Assert(((color[0] == '#') &&                             //
            (color.length() == 7 || color.length() == 9) &&  //
            (std::all_of(color.begin() + 1, color.end(), checkIfIsHex))),
           "The given string: " + color + ", is not a valid HEX color");
    constexpr uchar DEFAULT_ALPHA_VALUE = 255;

    const uchar red = hexCharToUchar(color[1], color[2]);
    const uchar green = hexCharToUchar(color[3], color[4]);
    const uchar blue = hexCharToUchar(color[5], color[6]);
    const uchar alpha = color.length() == 9 ? hexCharToUchar(color[7], color[8]) : DEFAULT_ALPHA_VALUE;
    return Color(red, green, blue, alpha);
  }

private:
  static constexpr float uintToFloat(const uchar value)
  {
    constexpr float CONVERT_RATION = 1.f / 255.f;
    return float(value) * CONVERT_RATION;
  }

  static constexpr bool checkIfIsHex(const char hex)
  {
    return ((hex >= '0' && hex <= '9') || (hex >= 'a' && hex <= 'f') || (hex >= 'A' && hex <= 'F'));
  }

  static constexpr uchar hexCharToUchar(const char hex)
  {
    Assert(checkIfIsHex(hex), "this char: " + std::string(1, hex) + ", is not a valid hex");
    constexpr uchar DIFFERENCE_BETWEEN_ASCI_CODE_AND_NUMBER_FOR_NUMBER = '0';
    constexpr uchar DIFFERENCE_BETWEEN_ASCI_CODE_AND_NUMBER_FOR_SMALL_LETTER = 'a' - 10;
    constexpr uchar DIFFERENCE_BETWEEN_ASCI_CODE_AND_NUMBER_FOR_BIG_LETTER = 'A' - 10;

    if (hex >= '0' && hex <= '9') {
      return (uchar)(hex - DIFFERENCE_BETWEEN_ASCI_CODE_AND_NUMBER_FOR_NUMBER);
    }
    if (hex >= 'a' && hex <= 'f') {
      return (uchar)(hex - DIFFERENCE_BETWEEN_ASCI_CODE_AND_NUMBER_FOR_SMALL_LETTER);
    }
    return (uchar)(hex - DIFFERENCE_BETWEEN_ASCI_CODE_AND_NUMBER_FOR_BIG_LETTER);
  }

  static constexpr uchar hexCharToUchar(const char hex1, const char hex2)
  {
    constexpr uchar POSITION_MULTIPLIER = 16;

    uchar firstDigit = hexCharToUchar(hex1) * POSITION_MULTIPLIER;
    return firstDigit + hexCharToUchar(hex2);
  }
};
namespace COLORS {
static const Color COLOR_CLEAR = Color::RGBA("#00000000");
static const Color COLOR_RED = Color::RGBA("#ff0000");
static const Color COLOR_GREEN = Color::RGBA("#00ff00");
static const Color COLOR_BLUE = Color::RGBA("#0000ff");
static const Color COLOR_WHITE = Color::RGBA("#ffffff");
}  // namespace COLORS
}  // namespace gl