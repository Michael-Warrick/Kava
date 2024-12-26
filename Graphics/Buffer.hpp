#pragma once

#include <vulkan/vulkan.hpp>

namespace Graphics {
    class Buffer {
    public:
        Buffer();
        ~Buffer();

    private:
        vk::Buffer vertexBuffer;
    };
}