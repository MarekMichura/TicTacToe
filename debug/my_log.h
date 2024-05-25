#pragma once

#ifndef NDEBUG
#include <string>
#define Log(str) log(str)
void log(const std::string& log);
#else
#define Log(str) (void)(str)
#endif