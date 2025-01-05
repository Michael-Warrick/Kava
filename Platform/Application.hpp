#include <optional>

#include "Graphics/Vulkan/Renderer.hpp"
#include "Window.hpp"

namespace Platform {
    /**
     * @class Application
     * @brief An umbrella class managing all major engine systems.
     *
     * @details The Application class handles everything from platform windows
     * to renderers.
     */
    class Application {
    public:
        /**
         * @brief Default Application constructor.
         *
         * @details #Application provides a way to instantiate the principal
         * Application object, initialising a window and suitible renderer.
         */
        Application();

        /**
         * @brief Default Application destructor.
         *
         * @details #~Application destroys the Application instance and starts
         * the chain of de-allocation of all its scoped member variables.
         */
        ~Application() = default;

        /**
         * @brief A method that drives the main application loop.
         *
         * @details #Run is a method that abstracts the top-most loop, where it
         * checks for every iteration if the window should remain open and if
         * not shuts down Application.
         */
        void Run();

    private:
        Window m_Window; /**< A member variable to manage platform window events. */
        Graphics::Vulkan::Renderer m_Renderer; /**< A member variable to manage Vulkan rendering operations. */
    };
} // namespace Platform