#include "CommandPool.hpp"

Graphics::CommandPool::CommandPool(const vk::SurfaceKHR &surface, const vk::PhysicalDevice &physicalDevice,
                                   const vk::Device &logicalDevice)
        : m_Surface(surface), m_PhysicalDevice(physicalDevice), m_LogicalDevice(logicalDevice) {
    Queue::QueueFamilyIndices queueFamilyIndices = Queue::FindQueueFamilies(m_PhysicalDevice, m_Surface);

    vk::CommandPoolCreateInfo poolInfo = vk::CommandPoolCreateInfo()
            .setFlags(vk::CommandPoolCreateFlagBits::eResetCommandBuffer)
            .setQueueFamilyIndex(queueFamilyIndices.graphicsFamily.value());

    vk::Result result = m_LogicalDevice.createCommandPool(&poolInfo, nullptr, &m_CommandPool);
    if (result != vk::Result::eSuccess) {
        throw std::runtime_error("Failed to create command pool! Error: " + vk::to_string(result));
    }
}

Graphics::CommandPool::~CommandPool() {
    m_LogicalDevice.destroyCommandPool(m_CommandPool);
}