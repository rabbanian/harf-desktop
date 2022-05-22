#include "application.h"
#include "gui/main_window.h"

int main(int argc, char *argv[])
{
  harf::Application app(argc, argv);
  gui::MainWindow window;

  return app.Run(&window);
}
