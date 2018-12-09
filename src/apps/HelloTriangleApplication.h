#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <functional>
#include <cstdlib>
#include <vector>
#include <optional>

struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;

	bool isComplete() {
		return graphicsFamily.has_value();
	}
};

class HelloTriangleApplication
{
public:
	void run();

private:
	const int WIDTH = 800;
	const int HEIGHT = 600;
	const std::vector<const char*> VALIDATION_LAYERS = {
		"VK_LAYER_LUNARG_standard_validation"
	};
#ifdef NDEBUG
	const bool b_enableValidationLayers = false;
#else
	const bool b_enableValidationLayers = true;
#endif

	GLFWwindow* m_window;
	VkInstance m_vkInstance;
	VkDebugUtilsMessengerEXT m_callback;

	VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
	VkDevice m_device;

	VkQueue m_graphicsQueue;

	void checkAvailableExtensions();
	void cleanup();
	void createInstance();
	void createLogicalDevice();
	bool checkValidationLayerSupport();
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	std::vector<const char*> getRequiredExtensions();
	void initWindow();
	void initVulkan();
	bool isDeviceSuitable(VkPhysicalDevice device);
	void mainLoop();
	void pickPhysicalDevice();
	void setupDebugCallback();


	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData);
};

