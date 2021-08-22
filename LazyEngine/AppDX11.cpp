#include "pch.h"
#include "AppDX11.h"
namespace lazy
{
	bool AppDX11::initialize()
	{
		if (glfwInit() == GLFW_FALSE)
		{
			std::cout << "Could not initialize glfw!" << std::endl; 
			return false; 
		}
		std::cout << "GLFW initialized successfully" << std::endl; 

		// set window hint to NO_API for usage with Vulkan and DirectX
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		LazyWindow window(m_Width, m_Height, m_ApplicationName.c_str()); 
		m_MainWindow = std::make_unique<LazyWindow>(window); 

		return true;
	}
	void AppDX11::run()
	{
		while (!glfwWindowShouldClose(m_MainWindow->getWindow()))
		{
			glfwPollEvents(); 
		}
	}
	void AppDX11::OnCreate()
	{
		m_ApplicationName += " DX11";
		m_Width = 1280; 
		m_Height = 720; 
		initialize(); 
	}
	void AppDX11::OnDestroy()
	{
		// clean up for DirectX 11
		glfwTerminate(); 
	}
}

