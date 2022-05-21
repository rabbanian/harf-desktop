#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <glad/gles2.h>
#include <imgui.h>

#include <cstdlib>
#include <iostream>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* description)
{
  std::cerr << "glfw error " << error << ": " << description << std::endl;
}

int main(int, char**)
{
  glfwSetErrorCallback(glfw_error_callback);
  if (!glfwInit()) {
    std::cerr << "can not initialize glfw" << std::endl;
    return EXIT_FAILURE;
  }

  // GLES 3.0 + GLSL ES 300
  const char* glsl_version = "#version 300 es";
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);

  GLFWwindow* window =
      glfwCreateWindow(960, 540, "Harf Desktop", nullptr, nullptr);
  if (window == nullptr) {
    std::cerr << "can not create window" << std::endl;
    return EXIT_FAILURE;
  }
  glfwMakeContextCurrent(window);
  gladLoadGLES2(glfwGetProcAddress);
  glfwSwapInterval(1);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

  ImGui::StyleColorsDark();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init(glsl_version);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
