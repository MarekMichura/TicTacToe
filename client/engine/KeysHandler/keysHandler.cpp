#include <format>
#include <functional>
#include <map>
#include <memory>

#include "keysHandler.hpp"
#include "GLFW/glfw3.h"
#include "keys.hpp"
#include "my_assert.h"
#include "my_log.h"

namespace gl {

static std::map<GLFWwindow*, KeysHandler*> mapCallToObject;

KeysHandler::KeysHandler(std::shared_ptr<Window> window, std::vector<std::pair<KeyStruct, weakFunction>> events)
    : window(window), eventMap(events.begin(), events.end())
{
  Assert(!mapCallToObject.contains(window->getWindow()), "You can't create multiple key handlers to single window");
  mapCallToObject.insert_or_assign(window->getWindow(), this);

  window->setKeyCallBack(keyCallback);
}

KeysHandler::~KeysHandler()
{
  window->setKeyCallBack(nullptr);
  mapCallToObject.erase(window->getWindow());
}

void KeysHandler::addEvent(const KeyStruct& key, const std::shared_ptr<function> fun)
{
  eventMap.insert(std::pair{key, fun});
}

void KeysHandler::keyCallBack(const KeyStruct& key)
{
  Log(std::format("Event key: {}\t{}\t{}",               //
                  convertKeyToString(key.key),           //
                  convertKeyStatusToString(key.status),  //
                  convertKeyModeToString(key.mode)       //
                  ));

  auto range = eventMap.equal_range(key);
  for (auto it = range.first; it != range.second; it++) {
    if (auto element = it->second.lock()) {
      (*element)();
    }
    else {
      // if element is expired remove it from the list
      eventMap.erase(it);
    }
  }
}

void KeysHandler::keyCallback(GLFWwindow* window, int key, int /*unused*/, int status, int mode)
{
  KeyStruct keyStruct{
      convertIntToKEY(key),            //
      convertIntToKEY_STATUS(status),  //
      convertIntToKEY_MODE(mode)       //
  };
  mapCallToObject[window]->keyCallBack(keyStruct);
}
}  // namespace gl
