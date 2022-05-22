#include "application.h"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <glad/gles2.h>
#include <imgui.h>

#include <cstdlib>
#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

harf::Application::Application() { Init(); }

int harf::Application::Run(gui::Widget* w)
{
  while (!glfwWindowShouldClose(window_)) {
    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    w->OnRender();

    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window_, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window_);
  }

  return 0;
}

harf::Application::Application(int argc, char** argv) { Init(); }

void harf::Application::Init()
{
  glfwSetErrorCallback(GlfwError);
  if (!glfwInit()) {
    std::cerr << "can not initialize glfw" << std::endl;
    std::exit(EXIT_FAILURE);
  }

  // GLES 3.0 + GLSL ES 300
  const char* glsl_version = "#version 300 es";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

  window_ = glfwCreateWindow(960, 540, "Harf Desktop", nullptr, nullptr);
  if (window_ == nullptr) {
    std::cerr << "can not create window" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(window_);
  gladLoadGLES2(glfwGetProcAddress);
  glfwSwapInterval(1);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  ImGui::StyleColorsDark();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window_, true);
  ImGui_ImplOpenGL3_Init(glsl_version);
}

void harf::Application::Shutdown()
{
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window_);
  glfwTerminate();
}

void harf::Application::GlfwError(int error, const char* description)
{
  std::cerr << "glfw error " << error << ": " << description << std::endl;
}

harf::Application::~Application() { Shutdown(); }
