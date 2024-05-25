#include <compare>
#include <string>

#include <GLFW/glfw3.h>

#define KEYS                                                \
  X(SPACE, "Space", GLFW_KEY_SPACE)                         \
  X(APOSTROPHE, "Apostrophe", GLFW_KEY_APOSTROPHE)          \
  X(COMMA, "Comma", GLFW_KEY_COMMA)                         \
  X(MINUS, "Minus", GLFW_KEY_MINUS)                         \
  X(PERIOD, "Period", GLFW_KEY_PERIOD)                      \
  X(SLASH, "Slash", GLFW_KEY_SLASH)                         \
  X(n0, "n0", GLFW_KEY_0)                                   \
  X(n1, "n1", GLFW_KEY_1)                                   \
  X(n2, "n2", GLFW_KEY_2)                                   \
  X(n3, "n3", GLFW_KEY_3)                                   \
  X(n4, "n4", GLFW_KEY_4)                                   \
  X(n5, "n5", GLFW_KEY_5)                                   \
  X(n6, "n6", GLFW_KEY_6)                                   \
  X(n7, "n7", GLFW_KEY_7)                                   \
  X(n8, "n8", GLFW_KEY_8)                                   \
  X(n9, "n9", GLFW_KEY_9)                                   \
  X(SEMICOLON, "Semicolon", GLFW_KEY_SEMICOLON)             \
  X(EQUAL, "Equal", GLFW_KEY_EQUAL)                         \
  X(A, "A", GLFW_KEY_A)                                     \
  X(B, "B", GLFW_KEY_B)                                     \
  X(C, "C", GLFW_KEY_C)                                     \
  X(D, "D", GLFW_KEY_D)                                     \
  X(E, "E", GLFW_KEY_E)                                     \
  X(F, "F", GLFW_KEY_F)                                     \
  X(G, "G", GLFW_KEY_G)                                     \
  X(H, "H", GLFW_KEY_H)                                     \
  X(I, "I", GLFW_KEY_I)                                     \
  X(J, "J", GLFW_KEY_J)                                     \
  X(K, "K", GLFW_KEY_K)                                     \
  X(L, "L", GLFW_KEY_L)                                     \
  X(M, "M", GLFW_KEY_M)                                     \
  X(N, "N", GLFW_KEY_N)                                     \
  X(O, "O", GLFW_KEY_O)                                     \
  X(P, "P", GLFW_KEY_P)                                     \
  X(Q, "Q", GLFW_KEY_Q)                                     \
  X(R, "R", GLFW_KEY_R)                                     \
  X(S, "S", GLFW_KEY_S)                                     \
  X(T, "T", GLFW_KEY_T)                                     \
  X(U, "U", GLFW_KEY_U)                                     \
  X(V, "V", GLFW_KEY_V)                                     \
  X(W, "W", GLFW_KEY_W)                                     \
  X(X, "X", GLFW_KEY_X)                                     \
  X(Y, "Y", GLFW_KEY_Y)                                     \
  X(Z, "Z", GLFW_KEY_Z)                                     \
  X(LEFT_BRACKET, "Left_bracket", GLFW_KEY_LEFT_BRACKET)    \
  X(BACKSLASH, "Backslash", GLFW_KEY_BACKSLASH)             \
  X(RIGHT_BRACKET, "Right_bracket", GLFW_KEY_RIGHT_BRACKET) \
  X(GRAVE_ACCENT, "Grave_accent", GLFW_KEY_GRAVE_ACCENT)    \
  X(WORLD_1, "World_1", GLFW_KEY_WORLD_1)                   \
  X(WORLD_2, "World_2", GLFW_KEY_WORLD_2)                   \
  X(ESCAPE, "Escape", GLFW_KEY_ESCAPE)                      \
  X(ENTER, "Enter", GLFW_KEY_ENTER)                         \
  X(TAB, "Tab", GLFW_KEY_TAB)                               \
  X(BACKSPACE, "Backspace", GLFW_KEY_BACKSPACE)             \
  X(INSERT, "Insert", GLFW_KEY_INSERT)                      \
  X(DELETE, "Delete", GLFW_KEY_DELETE)                      \
  X(RIGHT, "Right", GLFW_KEY_RIGHT)                         \
  X(LEFT, "Left", GLFW_KEY_LEFT)                            \
  X(DOWN, "Down", GLFW_KEY_DOWN)                            \
  X(UP, "Up", GLFW_KEY_UP)                                  \
  X(PAGE_UP, "Page_up", GLFW_KEY_PAGE_UP)                   \
  X(PAGE_DOWN, "Page_down", GLFW_KEY_PAGE_DOWN)             \
  X(HOME, "Home", GLFW_KEY_HOME)                            \
  X(END, "End", GLFW_KEY_END)                               \
  X(CAPS_LOCK, "Caps_lock", GLFW_KEY_CAPS_LOCK)             \
  X(SCROLL_LOCK, "Scroll_lock", GLFW_KEY_SCROLL_LOCK)       \
  X(NUM_LOCK, "Num_lock", GLFW_KEY_NUM_LOCK)                \
  X(PRINT_SCREEN, "Print_screen", GLFW_KEY_PRINT_SCREEN)    \
  X(PAUSE, "Pause", GLFW_KEY_PAUSE)                         \
  X(F1, "F1", GLFW_KEY_F1)                                  \
  X(F2, "F2", GLFW_KEY_F2)                                  \
  X(F3, "F3", GLFW_KEY_F3)                                  \
  X(F4, "F4", GLFW_KEY_F4)                                  \
  X(F5, "F5", GLFW_KEY_F5)                                  \
  X(F6, "F6", GLFW_KEY_F6)                                  \
  X(F7, "F7", GLFW_KEY_F7)                                  \
  X(F8, "F8", GLFW_KEY_F8)                                  \
  X(F9, "F9", GLFW_KEY_F9)                                  \
  X(F10, "F10", GLFW_KEY_F10)                               \
  X(F11, "F11", GLFW_KEY_F11)                               \
  X(F12, "F12", GLFW_KEY_F12)                               \
  X(F13, "F13", GLFW_KEY_F13)                               \
  X(F14, "F14", GLFW_KEY_F14)                               \
  X(F15, "F15", GLFW_KEY_F15)                               \
  X(F16, "F16", GLFW_KEY_F16)                               \
  X(F17, "F17", GLFW_KEY_F17)                               \
  X(F18, "F18", GLFW_KEY_F18)                               \
  X(F19, "F19", GLFW_KEY_F19)                               \
  X(F20, "F20", GLFW_KEY_F20)                               \
  X(F21, "F21", GLFW_KEY_F21)                               \
  X(F22, "F22", GLFW_KEY_F22)                               \
  X(F23, "F23", GLFW_KEY_F23)                               \
  X(F24, "F24", GLFW_KEY_F24)                               \
  X(F25, "F25", GLFW_KEY_F25)                               \
  X(KP_0, "Kp_0", GLFW_KEY_KP_0)                            \
  X(KP_1, "Kp_1", GLFW_KEY_KP_1)                            \
  X(KP_2, "Kp_2", GLFW_KEY_KP_2)                            \
  X(KP_3, "Kp_3", GLFW_KEY_KP_3)                            \
  X(KP_4, "Kp_4", GLFW_KEY_KP_4)                            \
  X(KP_5, "Kp_5", GLFW_KEY_KP_5)                            \
  X(KP_6, "Kp_6", GLFW_KEY_KP_6)                            \
  X(KP_7, "Kp_7", GLFW_KEY_KP_7)                            \
  X(KP_8, "Kp_8", GLFW_KEY_KP_8)                            \
  X(KP_9, "Kp_9", GLFW_KEY_KP_9)                            \
  X(KP_DECIMAL, "Kp_decimal", GLFW_KEY_KP_DECIMAL)          \
  X(KP_DIVIDE, "Kp_divide", GLFW_KEY_KP_DIVIDE)             \
  X(KP_MULTIPLY, "Kp_multiply", GLFW_KEY_KP_MULTIPLY)       \
  X(KP_SUBTRACT, "Kp_subtract", GLFW_KEY_KP_SUBTRACT)       \
  X(KP_ADD, "Kp_add", GLFW_KEY_KP_ADD)                      \
  X(KP_ENTER, "Kp_enter", GLFW_KEY_KP_ENTER)                \
  X(KP_EQUAL, "Kp_equal", GLFW_KEY_KP_EQUAL)                \
  X(LEFT_SHIFT, "Left_shift", GLFW_KEY_LEFT_SHIFT)          \
  X(LEFT_CONTROL, "Left_control", GLFW_KEY_LEFT_CONTROL)    \
  X(LEFT_ALT, "Left_alt", GLFW_KEY_LEFT_ALT)                \
  X(LEFT_SUPER, "Left_super", GLFW_KEY_LEFT_SUPER)          \
  X(RIGHT_SHIFT, "Right_shift", GLFW_KEY_RIGHT_SHIFT)       \
  X(RIGHT_CONTROL, "Right_control", GLFW_KEY_RIGHT_CONTROL) \
  X(RIGHT_ALT, "Right_alt", GLFW_KEY_RIGHT_ALT)             \
  X(RIGHT_SUPER, "Right_super", GLFW_KEY_RIGHT_SUPER)       \
  X(MENU, "Menu", GLFW_KEY_MENU)

#define KEYS_STATUS             \
  X(DOWN, "Down", GLFW_REPEAT)  \
  X(PRESS, "Press", GLFW_PRESS) \
  X(UP, "Up", GLFW_RELEASE)

#define KEYS_MODE                  \
  X(NONE, "None", 0)               \
  X(SHIFT, "Shift", 1)             \
  X(CTRL, "Ctrl", 2)               \
  X(SHIFT_CTRL, "Shift + Ctrl", 3) \
  X(ALT, "Alt", 4)                 \
  X(SHIFT_ALT, "Shift + Alt", 5)   \
  X(CTL_ALT, "Ctrl + Alt", 6)      \
  X(SHIFT_CTRL_ALT, "Shift + Ctrl + Alt", 7)

#pragma once

namespace gl {
#define X(enum, name, value) enum = (value),
enum class KEY_STATUS { KEYS_STATUS };
#undef X

#define X(enum, name, value) enum = (value),
enum class KEY_MODE { KEYS_MODE };
#undef X

#define X(enum, name, value) enum = (value),
enum class KEY { KEYS };
#undef X

struct KeyStruct {
  KEY key;
  KEY_STATUS status = KEY_STATUS::PRESS;
  KEY_MODE mode = KEY_MODE::NONE;

  std::strong_ordering operator<=>(const KeyStruct& other) const;
  bool operator==(const KeyStruct& other) const;
};


KEY convertIntToKEY(int key);
KEY_STATUS convertIntToKEY_STATUS(int key);
KEY_MODE convertIntToKEY_MODE(int key);

std::string convertKeyToString(KEY key);
std::string convertKeyStatusToString(KEY_STATUS key);
std::string convertKeyModeToString(KEY_MODE key);

}  // namespace gl
