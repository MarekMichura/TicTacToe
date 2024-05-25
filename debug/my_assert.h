#pragma once

#ifndef NDEBUG
#include <iostream>
#define Assert(Expr, Msg) m_assert(#Expr, Expr, __FILE__, __LINE__, Msg)
constexpr void m_assert(const char* expr_str, bool expr, const char* file, int line, const char* msg)
{
  if (!expr) {
    std::cerr  //
        << "Assert failed:\t" << msg << "\n"
        << "Expected:\t" << expr_str << "\n"
        << "Source:\t\t" << file << ", line " << line << "\n";
    abort();
  }
}
constexpr void m_assert(const char* expr_str, bool expr, const char* file, int line, const std::string msg)
{
  if (!expr) {
    std::cerr  //
        << "Assert failed:\t" << msg << "\n"
        << "Expected:\t" << expr_str << "\n"
        << "Source:\t\t" << file << ", line " << line << "\n";
    abort();
  }
}
#else
#define Assert(Expr, Msg) \
  (void)(Msg);            \
  (void)(Expr);
#endif
