cmake_minimum_required(VERSION 3.16)
project(Kava VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)

add_subdirectory(Vendor/glfw)
add_subdirectory(Vendor/glm)

add_executable(${PROJECT_NAME}
        # Platform
        ${CMAKE_SOURCE_DIR}/Platform/main.cpp
        ${CMAKE_SOURCE_DIR}/Platform/Application.cpp
        ${CMAKE_SOURCE_DIR}/Platform/Window.cpp

        # Graphics
        ${CMAKE_SOURCE_DIR}/Graphics/stb_image/stb_image_impl.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/Renderer.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/Instance.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/Surface.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/Device.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/Queue.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/SwapChain.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/ImageView.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/Pipeline.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/Framebuffer.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/CommandPool.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/CommandBuffer.cpp
        # ${CMAKE_SOURCE_DIR}/Graphics/Vulkan/Buffer.cpp

        # Input

        # IO
        ${CMAKE_SOURCE_DIR}/IO/File.cpp

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