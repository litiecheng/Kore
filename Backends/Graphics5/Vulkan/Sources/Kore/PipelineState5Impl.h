#pragma once

#include <map>
#include <string>

#include <vulkan/vulkan.h>

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#ifdef RegisterClass
#undef RegisterClass
#endif

namespace Kore {
	namespace Graphics5 {
		class PipelineState;
		class Shader;
	}

	class PipelineState5Impl {
	public:
		PipelineState5Impl();

		Graphics5::Shader* vertexShader;
		Graphics5::Shader* fragmentShader;
		Graphics5::Shader* geometryShader;
		Graphics5::Shader* tessEvalShader;
		Graphics5::Shader* tessControlShader;

		const char** textures;
		int* textureValues;
		int textureCount;

		VkPipeline pipeline;
		VkPipelineCache pipelineCache;
		VkShaderModule vert_shader_module;
		VkShaderModule frag_shader_module;

		std::map<std::string, u32> vertexLocations;
		std::map<std::string, u32> fragmentLocations;
		std::map<std::string, u32> textureBindings;
		std::map<std::string, u32> vertexOffsets;
		std::map<std::string, u32> fragmentOffsets;

		VkPipelineLayout pipeline_layout;

		VkDescriptorSetLayout desc_layout;

		static Graphics5::PipelineState* current;
	};

	class ConstantLocation5Impl {
	public:
		u32 vertexOffset;
		u32 fragmentOffset;
	};

	class AttributeLocation5Impl {};
}
