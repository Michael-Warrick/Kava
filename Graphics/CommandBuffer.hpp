#pragma once

#include <vector>
#include <vulkan/vulkan.hpp>

namespace Graphics {
    class CommandBuffer {
    public:
        CommandBuffer(const vk::Device &logicalDevice, const vk::RenderPass &renderPass,
                      const std::vector<vk::Framebuffer> &swapChainFramebuffers, const vk::Extent2D &swapChainExtent,
                      const vk::CommandPool &commandPool, vk::PipelineBindPoint pipelineBindPoint,
                      const vk::Pipeline &pipeline, const int maxFramesInFlight);

        void Record(vk::CommandBuffer commandBuffer, uint32_t imageIndex);

    private:
        void createGraphicsCommandBuffers();

        void recordGraphicsCommandBuffers(vk::CommandBuffer commandBuffer, uint32_t imageIndex);

//        void createComputeCommandBuffer();
//        void recordComputeCommandBuffer();


        vk::Device m_LogicalDevice;
        vk::RenderPass m_RenderPass;
        std::vector<vk::Framebuffer> m_SwapChainFramebuffers;
        vk::Extent2D m_SwapChainExtent;
        vk::Pipeline m_GraphicsPipeline;
        vk::CommandPool m_CommandPool;
        std::vector<vk::CommandBuffer> m_GraphicsCommandBuffers;
        int m_MAX_FRAMES_IN_FLIGHT;
    };

} // namespace Graphics