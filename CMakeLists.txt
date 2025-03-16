cmake_minimum_required(VERSION 3.16)
project(Kava VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)

add_subdirectory(Vendor/glfw)
add_subdirectory(Vendor/glm)

add_executable(${PROJECT_NAME}
        # Platform
        Platform/main.cpp
        Platform/Application.cpp
        Platform/Window.cpp

        # Graphics
        Graphics/stb_image/stb_image_impl.cpp
        Graphics/Vulkan/Renderer.cpp
        Graphics/Vulkan/Instance.cpp
        Graphics/Vulkan/Surface.cpp
        Graphics/Vulkan/Device.cpp
        Graphics/Vulkan/Queue.cpp
        Graphics/Vulkan/SwapChain.cpp
        Graphics/Vulkan/ImageView.cpp
        Graphics/Vulkan/Pipeline.cpp
        Graphics/Vulkan/Framebuffer.cpp
        Graphics/Vulkan/CommandPool.cpp
        Graphics/Vulkan/CommandBuffer.cpp
        # Graphics/Vulkan/Buffer.cpp
        Graphics/Vulkan/Debug.cpp

        # Input

        # IO
        IO/File.cpp

        # Physics
)

add_subdirectory(Resources/Shaders)
add_dependencies(${PROJECT_NAME} Shaders)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        glfw
        glm
        Vulkan::Vulkan
)

target_link_libraries(${PROJECT_NAME}
        glfw
        glm
        Vulkan::Vulkan
)