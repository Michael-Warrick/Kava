#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

#include "Graphics/Vulkan/Renderer.hpp"

namespace Platform {
class Window {
public:
    Window();
    ~Window();

    void PollEvents();

    GLFWwindow *platformWindow();
    bool IsOpen();

private:
    static void framebufferResizeCallback(GLFWwindow *window, int width, int height);

    GLFWwindow *m_Window = nullptr;

    uint16_t m_Width = 1280;
    uint16_t m_Height = 800;
    std::string m_Title = "Kava 1.0.0";

    bool m_FramebufferResized = false;
};
} // namespace Platform
