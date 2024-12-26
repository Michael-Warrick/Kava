#include "Application.hpp"

void Platform::Application::Run() {
    while (m_Window.IsOpen()) {
        // Process Window Events
        m_Window.PollEvents();

        // Process Input State

        // Update Game State (Physics, Game Logic, AI...)

        // Update Renderer

        // Present Rendered Scene
        m_Window.Present();
    }
}
