#include "Window.hpp"

Platform::Window::Window() {
    if (!glfwInit()) {
        std::cerr << "Failed to init GLFW!" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    m_Window =
        glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
    if (!m_Window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();

        return;
    }

    glfwSetWindowUserPointer(m_Window, this);
    glfwSetFramebufferSizeCallback(m_Window, framebufferResizeCallback);
}

Platform::Window::~Window() {
    if (m_Window) {
        glfwDestroyWindow(m_Window);
        m_Window = nullptr;
    }

    glfwTerminate();
}

void Platform::Window::Present() { 
    // m_Renderer->DrawFrame();
}

void Platform::Window::PollEvents() { return glfwPollEvents(); }

GLFWwindow *Platform::Window::platformWindow() { return m_Window; }

bool Platform::Window::IsOpen() { return !glfwWindowShouldClose(m_Window); }

void Platform::Window::framebufferResizeCallback(GLFWwindow *window, int width,
                                                 int height) {
    auto appWindow =
        reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
    appWindow->m_FramebufferResized = true;
}