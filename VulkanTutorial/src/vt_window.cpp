#include "vt_window.hpp"
#include <stdexcept>

namespace vt {

	VtWindow::VtWindow(int w, int h, std::string name) :width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	VtWindow::~VtWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void VtWindow::initWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		
		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}

	void VtWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface");
		}
	}

}
