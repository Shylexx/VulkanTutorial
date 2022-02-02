#pragma once

#include <string>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace vt {

	class VtWindow {
	public:

		VtWindow(int w, int h, std::string name);
		~VtWindow();

		VtWindow(const VtWindow&) = delete;
		VtWindow& operator=(const VtWindow&) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }
	private:

		void initWindow();
		const int width;
		const int height;

		std::string windowName;
		GLFWwindow* window;

	};
}