#pragma once

#include <string>
using uint = unsigned int;

constexpr char DECIMAL = 10;
constexpr char CHAR_0 = 48;
static constexpr std::string floatToString(const float number, const uint precision = 3)
{
  std::string result;
  // check if number is positive or negative
  const float absNumber = (number < 0) ? -number : number;
  if (number < 0) {
    result += '-';
  }

  // convert integer part
  std::string intResult;
  uint absInt = static_cast<uint>(absNumber);
  float decimalPart = absNumber - static_cast<float>(absInt);
  while (absInt > 0) {
    char rest = static_cast<char>(absInt % DECIMAL);
    absInt /= DECIMAL;

    char intChar = static_cast<char>(CHAR_0 + rest);
    intResult += intChar;
  }
  result.append(intResult.rbegin(), intResult.rend());

  // convert float part
  std::string floatResult;
  for (uint i = 0; i < precision; i++) {
    decimalPart *= DECIMAL;
    int intPart = static_cast<int>(decimalPart);
    char charNum = static_cast<char>(intPart + CHAR_0);
    decimalPart -= static_cast<float>(intPart);

    floatResult += charNum;
  }
  // remove 0 from end
  while (*floatResult.end() == CHAR_0) {
    floatResult.pop_back();
  }
  if (floatResult.length() > 0) {
    result += ',';
    result += floatResult;
  }

  return result;
}