cmake_minimum_required(VERSION 3.16)
project(Kava VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)

# add_subdirectory(Vendor/glfw)
# add_subdirectory(Vendor/glm)

add_executable(${PROJECT_NAME}
        # Platform
        ${CMAKE_SOURCE_DIR}/Platform/main.cpp
        ${CMAKE_SOURCE_DIR}/Platform/Application.cpp
        ${CMAKE_SOURCE_DIR}/Platform/Window.cpp

        # Graphics
        ${CMAKE_SOURCE_DIR}/Graphics/stb_image/stb_image_impl.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Renderer.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Instance.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Surface.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Device.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Queue.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/SwapChain.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/ImageView.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Pipeline.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Framebuffer.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/CommandPool.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/CommandBuffer.cpp
        ${CMAKE_SOURCE_DIR}/Graphics/Buffer.cpp

        # Input

        # IO
        ${CMAKE_SOURCE_DIR}/IO/File.cpp

        # Physics
)

# add_subdirectory(Resources/Shaders)
# add_dependencies(${PROJECT_NAME} Shaders)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<INSTALL_INTERFACE:Engine>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Engine>
        glfw
        glm
        Vulkan::Vulkan
)

target_link_libraries(${PROJECT_NAME}
        glfw
        glm
        Vulkan::Vulkan
)