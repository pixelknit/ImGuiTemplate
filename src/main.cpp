#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include "imgui.h"
#include <GLFW/glfw3.h>
#include <iostream>

void MySaveFunction(){
    std::cout << "saving..\n";
}

int main() {
  // Setup GLFW
  if (!glfwInit())
    return -1;

  GLFWwindow *window =
      glfwCreateWindow(1280, 720, "Store App", nullptr, nullptr);
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);

  // Setup ImGui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 130");

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    // Start ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Your UI code here
    // ImGui::Begin("Hello, Store App!");
    // ImGui::Text("This is your first ImGui window!");
    // if (ImGui::Button("Click me!")) {
    //     // Handle click
    // }
    // ImGui::End();
    float f {0.5f};
    char buf[256] = "";

    ImGui::Begin("Hello, Store App!");
    ImGui::Text("Hello, world %d", 123);
    if (ImGui::Button("Save"))
      MySaveFunction();
    ImGui::InputText("string", buf, IM_COUNTOF(buf));
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    ImGui::End();

    // Rendering
    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
  }

  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}