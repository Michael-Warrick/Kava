#include "Buffer.hpp"

Graphics::Buffer::Buffer(const vk::Device &logicalDevice, const Type bufferType)
    : m_LogicalDevice(logicalDevice) {
    switch (bufferType) {
    case Type::eVertex:
        createVertexBuffer();
        break;
    case Type::eIndex:
        createIndexBuffer();
        break;
    case Type::eUniform:
        createUniformBuffer();
        break;
    }
}

Graphics::Buffer::~Buffer() {
    m_LogicalDevice.destroyBuffer(m_VertexBuffer, nullptr);
    m_LogicalDevice.freeMemory(m_VertexBufferMemory, nullptr);
}

void Graphics::Buffer::createVertexBuffer() {
    constexpr vk::BufferCreateInfo bufferInfo =
        vk::BufferCreateInfo()
            .setSize(sizeof(Vertex))
            .setUsage(vk::BufferUsageFlagBits::eVertexBuffer)
            .setSharingMode(vk::SharingMode::eExclusive);

    if (m_LogicalDevice.createBuffer(&bufferInfo, nullptr, &m_VertexBuffer) !=
        vk::Result::eSuccess) {
        throw std::runtime_error("Failed to create vertex buffer!");
    }

    vk::MemoryRequirements memoryRequirements;
    m_LogicalDevice.getBufferMemoryRequirements(m_VertexBuffer, &memoryRequirements);


    vk::MemoryAllocateInfo memoryAllocateInfo = vk::MemoryAllocateInfo()
    .setAllocationSize(memoryRequirements.size)
    .setMemoryTypeIndex(Device::FindMemoryType(m_PhysicalDevice, memoryRequirements.memoryTypeBits,
                                 vk::MemoryPropertyFlags properties));
}