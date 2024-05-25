#include "closeWindow.hpp"
#include <triangle.hpp>

namespace gl {
CloseWindow::CloseWindow(std::shared_ptr<Engine> engine) : engine(engine)
{
  auto weakEngine = std::weak_ptr<Engine>(engine);
  auto keyHandler = engine->getKeyHandler();
  closeWindow = std::make_shared<function>([weakEngine]() {
    if (auto element = weakEngine.lock())
      element->getWindow()->close();
  });
  creteNewTriangle = std::make_shared<function>([weakEngine]() {
    if (auto element = weakEngine.lock())
      element->insertObj<Triangle>();
  });
  keyHandler->addEvent(KeyStruct{KEY::Q}, closeWindow);
  keyHandler->addEvent(KeyStruct{.key = KEY::W, .status = KEY_STATUS::DOWN}, creteNewTriangle);
  keyHandler->addEvent(KeyStruct{.key = KEY::W, .status = KEY_STATUS::DOWN}, creteNewTriangle);
  keyHandler->addEvent(KeyStruct{.key = KEY::W, .status = KEY_STATUS::DOWN}, creteNewTriangle);
  keyHandler->addEvent(KeyStruct{.key = KEY::W, .status = KEY_STATUS::DOWN}, creteNewTriangle);
  keyHandler->addEvent(KeyStruct{.key = KEY::W, .status = KEY_STATUS::DOWN}, creteNewTriangle);
}
}  // namespace gl