#pragma once

#include <vulkan/vulkan.hpp>
#include "Queue.hpp"

namespace Graphics {
    class CommandPool {
    public:
        CommandPool(const vk::SurfaceKHR &surface, const vk::PhysicalDevice &physicalDevice,
                    const vk::Device &logicalDevice);

        ~CommandPool();

    private:
        vk::SurfaceKHR m_Surface;
        vk::PhysicalDevice m_PhysicalDevice;
        vk::Device m_LogicalDevice;

        vk::CommandPool m_CommandPool;
    };
} // namespace Graphics