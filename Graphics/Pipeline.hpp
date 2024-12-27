#pragma once

#include <vulkan/vulkan.hpp>

#include "../IO/File.hpp"
#include "Geometry.hpp"
#include "SwapChain.hpp"
#include "Vertex.hpp"

namespace Graphics {
    class Pipeline {
    public:
        Pipeline(const vk::PhysicalDevice &physicalDevice,
                 const vk::Device &logicalDevice, const vk::Format &format,
                 const vk::SampleCountFlagBits &msaaSamples);

        ~Pipeline();

        [[nodiscard]] vk::RenderPass renderPass() const;

    private:
        void createRenderPass();
        [[nodiscard]] vk::Format findDepthFormat() const;
        [[nodiscard]] vk::Format
        findSupportedFormat(const std::vector<vk::Format> &candidates,
                            vk::ImageTiling tiling,
                            vk::FormatFeatureFlags features) const;
        void createGraphicsPipeline(const std::string &vertexShaderFilePath,
                                    const std::string &fragmentShaderFilePath);
        vk::ShaderModule createShaderModule(const std::vector<char> &code);

        vk::PhysicalDevice m_PhysicalDevice;
        vk::Device m_LogicalDevice;
        vk::Format m_SwapChainImageFormat;
        vk::SampleCountFlagBits m_MSAASamples;
        vk::RenderPass m_RenderPass;
        vk::PipelineLayout m_PipelineLayout;
        vk::Pipeline m_GraphicsPipeline;
    };
} // namespace Graphics
