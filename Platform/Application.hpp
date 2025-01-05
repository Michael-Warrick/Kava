#include <optional>

#include "Window.hpp"
#include "Graphics/Vulkan/Renderer.hpp"

namespace Platform {
    class Application {
    public:
        Application();
        ~Application();

        void Run();

    private:
        Window m_Window;
        Graphics::Vulkan::Renderer m_Renderer;
    };
} // namespace Platform