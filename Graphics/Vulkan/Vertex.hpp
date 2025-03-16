#pragma once

#include <glm/glm.hpp>
#include <vulkan/vulkan.hpp>

namespace Graphics {
struct Vertex {
    glm::vec2 position;
    glm::vec3 color;

    static vk::VertexInputBindingDescription getBindingDescription() {
        constexpr vk::VertexInputBindingDescription bindingDescription =
            vk::VertexInputBindingDescription()
                .setBinding(0)
                .setStride(sizeof(Vertex))
                .setInputRate(vk::VertexInputRate::eVertex);

        return bindingDescription;
    }

    static std::array<vk::VertexInputAttributeDescription, 2>
    getAttributeDescriptions() {
        std::array<vk::VertexInputAttributeDescription, 2>
            attributeDescriptions;
        attributeDescriptions[0]
            .setBinding(0)
            .setLocation(0)
            .setFormat(vk::Format::eR32G32Sfloat)
            .setOffset(offsetof(Vertex, position));

        attributeDescriptions[1]
            .setBinding(0)
            .setLocation(1)
            .setFormat(vk::Format::eR32G32B32Sfloat)
            .setOffset(offsetof(Vertex, position));

        return attributeDescriptions;
    }
};
} // namespace Graphics