#ifndef HARF_DESKTOP_SRC_APP_APPLICATION_H_
#define HARF_DESKTOP_SRC_APP_APPLICATION_H_

#include "gui/widget.h"

struct GLFWwindow;

namespace harf {

class Application
{
 public:
  ~Application();
  Application();
  Application(int argc, char* argv[]);
  Application(Application&&) = delete;
  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;
  Application& operator=(Application&&) = delete;
  int Run(gui::Widget* w);

 private:
  GLFWwindow* window_ = nullptr;

  void Init();
  void Shutdown();
  static void GlfwError(int error, const char* description);
};

}  // namespace harf

#endif  // HARF_DESKTOP_SRC_APP_APPLICATION_H_
