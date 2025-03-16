cmake_minimum_required(VERSION 3.16)
project(Kava VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)

add_subdirectory(Vendor/glfw)
add_subdirectory(Vendor/glm)

set(HEADERS
        # Platform
        Platform/Application.hpp
        Platform/Window.hpp

        # Physics

        # Graphics
        Graphics/stb_image/stb_image.h
        Graphics/Vulkan/Renderer.hpp
        Graphics/Vulkan/Instance.hpp
        Graphics/Vulkan/Surface.hpp
        Graphics/Vulkan/Device.hpp
        Graphics/Vulkan/Queue.hpp
        Graphics/Vulkan/SwapChain.hpp
        Graphics/Vulkan/ImageView.hpp
        Graphics/Vulkan/Pipeline.hpp
        Graphics/Vulkan/Framebuffer.hpp
        Graphics/Vulkan/CommandPool.hpp
        Graphics/Vulkan/CommandBuffer.hpp
        Graphics/Vulkan/Debug.hpp

        # Input

        # IO
        IO/File.hpp
)

set(SOURCES
        # Platform
        Platform/main.cpp
        Platform/Application.cpp
        Platform/Window.cpp

        # Physics

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
)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

source_group("Headers" FILES ${HEADERS})

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

if(CMAKE_GENERATOR STREQUAL "Xcode")
        message(STATUS "Generating project for Xcode")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMTL_DEBUG")
        set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)