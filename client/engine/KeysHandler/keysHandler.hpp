#pragma once

#include <GLFW/glfw3.h>

#include <functional>
#include <memory>
#include <map>
#include <utility>
#include <vector>

#include "window.hpp"
#include "keys.hpp"

using function = std::function<void()>;
using weakFunction = std::weak_ptr<function>;

namespace gl {
class KeysHandler {
private:
  std::shared_ptr<Window> window;
  std::multimap<KeyStruct, weakFunction> eventMap{};
  std::map<int, int> tmpMap{};

public:
  KeysHandler(KeysHandler&&) = delete;
  KeysHandler(const KeysHandler&) = delete;
  KeysHandler& operator=(KeysHandler&&) = delete;
  KeysHandler& operator=(const KeysHandler&) = delete;

  KeysHandler(std::shared_ptr<Window> window, std::vector<std::pair<KeyStruct, weakFunction>> events = {});
  ~KeysHandler();

  void addEvent(const KeyStruct& key, const std::shared_ptr<function>);
  void keyCallBack(const KeyStruct& key);

private:
  static void keyCallback(GLFWwindow*, int, int, int, int);
};
}  // namespace gl
