#include "CommandBuffer.hpp"

Graphics::CommandBuffer::CommandBuffer(const vk::Device &logicalDevice, const vk::RenderPass &renderPass,
                                       const std::vector<vk::Framebuffer> &swapChainFramebuffers,
                                       const vk::Extent2D &swapChainExtent, const vk::CommandPool &commandPool,
                                       vk::PipelineBindPoint pipelineBindPoint, const vk::Pipeline &pipeline,
                                       int maxFramesInFlight)
        : m_LogicalDevice(logicalDevice), m_RenderPass(renderPass), m_SwapChainFramebuffers(swapChainFramebuffers),
          m_SwapChainExtent(swapChainExtent), m_CommandPool(commandPool), m_MAX_FRAMES_IN_FLIGHT(maxFramesInFlight) {
    switch (pipelineBindPoint) {
        case vk::PipelineBindPoint::eGraphics:
            createGraphicsCommandBuffers();
            break;
        case vk::PipelineBindPoint::eCompute:
//            createComputeCommandBuffers();
            break;
        case vk::PipelineBindPoint::eRayTracingKHR:
            throw std::runtime_error("Tried using RayTracingKHR/NV but option isn't supported yet!");
            break;
        case vk::PipelineBindPoint::eSubpassShadingHUAWEI:
            throw std::runtime_error("Tried using SubpassShadingHUAWEI but option isn't supported yet!");
            break;
    }
}

void Graphics::CommandBuffer::Record(vk::CommandBuffer commandBuffer, uint32_t imageIndex) {

}

void Graphics::CommandBuffer::createGraphicsCommandBuffers() {
    m_GraphicsCommandBuffers.resize(m_MAX_FRAMES_IN_FLIGHT);
    vk::CommandBufferAllocateInfo allocateInfo = vk::CommandBufferAllocateInfo()
            .setCommandPool(m_CommandPool)
            .setLevel(vk::CommandBufferLevel::ePrimary)
            .setCommandBufferCount(static_cast<uint32_t>(m_GraphicsCommandBuffers.size()));

    vk::Result result = m_LogicalDevice.allocateCommandBuffers(&allocateInfo, m_GraphicsCommandBuffers.data());
    if (result != vk::Result::eSuccess) {
        throw std::runtime_error("Failed to allocate command buffers! Error: " + vk::to_string(result));
    }
}

void Graphics::CommandBuffer::recordGraphicsCommandBuffers(vk::CommandBuffer commandBuffer, uint32_t imageIndex) {
    vk::CommandBufferBeginInfo beginInfo = vk::CommandBufferBeginInfo();

    vk::Result result = commandBuffer.begin(&beginInfo);
    if (result != vk::Result::eSuccess) {
        throw std::runtime_error("Failed to begin recording command buffer! Error: " + vk::to_string(result));
    }

    vk::ClearValue clearColor(vk::ClearColorValue(0.0f, 0.0f, 0.0f, 1.0f));

    vk::RenderPassBeginInfo renderPassInfo = vk::RenderPassBeginInfo()
            .setRenderPass(m_RenderPass)
            .setFramebuffer(m_SwapChainFramebuffers[imageIndex])
            .setRenderArea(vk::Rect2D(vk::Offset2D(0, 0), vk::Extent2D(m_SwapChainExtent)))
            .setClearValueCount(1)
            .setPClearValues(&clearColor);

    commandBuffer.beginRenderPass(&renderPassInfo, vk::SubpassContents::eInline);
    commandBuffer.bindPipeline(vk::PipelineBindPoint::eGraphics, m_GraphicsPipeline);

    vk::Viewport viewport = vk::Viewport()
            .setX(0.0f)
            .setY(0.0f)
            .setWidth(static_cast<float>(m_SwapChainExtent.width))
            .setHeight(static_cast<float>(m_SwapChainExtent.height))
            .setMinDepth(0.0f)
            .setMaxDepth(1.0f);
    commandBuffer.setViewport(0, 1, &viewport);

    vk::Rect2D scissor = vk::Rect2D()
            .setOffset(vk::Offset2D(0, 0))
            .setExtent(m_SwapChainExtent);
    commandBuffer.setScissor(0, 1, &scissor);
}
