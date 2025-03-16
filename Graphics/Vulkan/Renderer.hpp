#pragma once

#define MAX_FRAMES_IN_FLIGHT 2

#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

#include "Device.hpp"
#include "Instance.hpp"
#include "Pipeline.hpp"
#include "Surface.hpp"
#include "SwapChain.hpp"

#include "Debug.hpp"

namespace Graphics {
namespace Vulkan {
class Renderer {
public:
    explicit Renderer(GLFWwindow *window);

    void DrawFrame();

private:
    GLFWwindow *m_Window;

    Instance m_Instance;
    Surface m_Surface;
    Device m_Device;
    SwapChain m_SwapChain;
    Vulkan::Pipeline m_Pipeline;
};
} // namespace Vulkan
} // namespace Graphics
