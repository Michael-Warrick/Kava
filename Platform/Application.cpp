#include "Application.hpp"

Platform::Application::Application()
    : m_Window(), m_Renderer(m_Window.platformWindow()) {}

void Platform::Application::Run() {
    while (m_Window.IsOpen()) {
        // Process platform window events
        m_Window.PollEvents();

        // Process input state

        // Update game state (physics, game logic, AI...)

        // Update renderer
        m_Renderer.DrawFrame();
    }
}