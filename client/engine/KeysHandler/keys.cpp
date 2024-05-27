#include <format>

#include "keys.hpp"
#include "my_log.h"

namespace gl {
KEY convertIntToKEY(int key)
{
  switch (key) {
#define X(enum, name, value) \
  case value:                \
    return KEY::enum;
    KEYS;
#undef X
    default:
      Log(std::format("Failed to convert int {} to KEY", key));
      abort();
  }
};

KEY_MODE convertIntToKEY_MODE(int key)
{
  switch (key) {
#define X(enum, name, value) \
  case value:                \
    return KEY_MODE::enum;
    KEYS_MODE;
#undef X
    default:
      Log(std::format("Failed to convert int {} to KEY", key));
      abort();
  }
}

KEY_STATUS convertIntToKEY_STATUS(int key)
{
  switch (key) {
#define X(enum, name, value) \
  case value:                \
    return KEY_STATUS::enum;
    KEYS_STATUS;
#undef X
    default:
      Log(std::format("Failed to convert int {} to KEY", key));
      abort();
  }
}

#ifndef NDEBUG
std::string convertKeyToString(KEY key)
{
  switch (key) {
#define X(enum, name, value) \
  case KEY::enum:            \
    return name;
    KEYS;
#undef X
    default:
      abort();
  }
  abort();
}
std::string convertKeyStatusToString(KEY_STATUS key)
{
  switch (key) {
#define X(enum, name, value) \
  case KEY_STATUS::enum:     \
    return name;
    KEYS_STATUS;
#undef X
    default:
      abort();
  }
  abort();
}
std::string convertKeyModeToString(KEY_MODE key)
{
  switch (key) {
#define X(enum, name, value) \
  case KEY_MODE::enum:       \
    return name;
    KEYS_MODE;
#undef X
    default:
      abort();
  }
  abort();
}

#else
std::string convertKeyToString(KEY /*unused*/)
{
  return "";
}
std::string convertKeyStatusToString(KEY_STATUS /*unused*/)
{
  return "";
}
std::string convertKeyModeToString(KEY_MODE /*unused*/)
{
  return "";
}
#endif  // DEBUG

std::strong_ordering KeyStruct::operator<=>(const KeyStruct& other) const
{
  if (auto cmp = key <=> other.key; cmp != 0) {
    return cmp;
  }
  if (auto cmp = mode <=> other.mode; cmp != 0) {
    return cmp;
  }
  return status <=> other.status;
}

bool KeyStruct::operator==(const KeyStruct& other) const
{
  return key == other.key && mode == other.mode && status == other.status;
}
// bool operator<(const KeyStruct& left, const KeyStruct& right)
//{
//  if (left.key != right.key) {
//    return left.key < right.key;
//  }
//  if (left.mode != right.mode) {
//    return left.mode < right.mode;
//  }
//  return left.status < right.status;
//}
// bool operator>(const KeyStruct& left, const KeyStruct& right)
//{
//  if (left.key != right.key) {
//    return left.key > right.key;
//  }
//  if (left.mode != right.mode) {
//    return left.mode > right.mode;
//  }
//  return left.status > right.status;
//}
// bool operator==(const KeyStruct& left, const KeyStruct& right)
//{
//  return left.key == right.key && left.mode == right.mode && left.status == right.status;
//}
}  // namespace gl