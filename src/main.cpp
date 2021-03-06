#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#undef STB_IMAGE_IMPLEMENTATION

#include "apps\HelloTriangleApplication.h"
#include "apps\HelloQuadIndexed.h"
#include "apps/HelloTexture.h"
#include "apps/HelloModel.h"


int main() 
{
	//HelloTriangleApplication app;
	//HelloQuadIndexed app;
	//HelloTexture app;
	HelloModel app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}