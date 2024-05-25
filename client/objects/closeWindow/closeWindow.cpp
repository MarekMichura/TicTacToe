#include "closeWindow.hpp"

namespace gl {
CloseWindow::CloseWindow(std::weak_ptr<Engine> engine) : engine(engine)
{
  auto keyHandler = engine.lock()->getKeyHandler();
  fun = std::make_shared<function>([engine]() {
    if (auto element = engine.lock())
      element->getWindow()->close();
  });
  keyHandler->addEvent(KeyStruct{KEY::Q}, fun);
}
}  // namespace gl