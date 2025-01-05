#include "Application.hpp"

Platform::Application::Application() : m_Renderer(m_Window.platformWindow()) {}

Platform::Application::~Application() {}

void Platform::Application::Run() {
    while (m_Window.IsOpen()) {
        // Process Window Events
        m_Window.PollEvents();

        // Process Input State

        // Update Game State (Physics, Game Logic, AI...)

        // Update Renderer
        m_Renderer.DrawFrame();

        // Present Rendered Scene
        m_Window.Present();
    }
}
