#pragma once

#include <vector>
#include <vulkan/vulkan.hpp>

#include "Vertex.hpp"
#include "Device.hpp"

namespace Graphics {
    class Buffer {
    enum class Type {
        eVertex,
        eIndex,
        eUniform
    };
    public:
        explicit Buffer(const vk::Device &logicalDevice, Type bufferType);
        ~Buffer();

    private:
        void createVertexBuffer();
        void createIndexBuffer();
        void createUniformBuffer();

        vk::PhysicalDevice m_PhysicalDevice;
        vk::Device m_LogicalDevice;

        std::vector<Vertex> m_Vertices;
        vk::Buffer m_VertexBuffer;
        vk::DeviceMemory m_VertexBufferMemory;

        vk::Buffer m_IndexBuffer;
        vk::Buffer m_UniformBuffer;
    };
} // namespace Graphics