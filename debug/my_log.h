#pragma once

#ifndef NDEBUG
#include <iostream>
#define Log(str) log(str)
constexpr void log(const std::string& log)
{
  std::cout << log << "\n";
}
#else
#define Log(str) (void)(str)
#define LogFormat(str, args)
#endif