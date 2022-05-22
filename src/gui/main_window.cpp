#include "main_window.h"

#include <imgui.h>

void gui::MainWindow::OnRender()
{
  ImGui::Begin("Hi");
  ImGui::Text("Hello, world");
  ImGui::End();
}
