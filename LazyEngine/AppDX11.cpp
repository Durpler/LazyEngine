#include "pch.h"
#include "AppDX11.h"
#include "SystemDX11.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace lazy
{
	bool AppDX11::initialize()
	{
		if (glfwInit() == GLFW_FALSE)
		{
			LOG(ERROR) << "Could not initialize glfw";
			return false; 
		}
		LOG(INFO) << "GLFW initialized successfully";

		// set window hint to NO_API for usage with Vulkan and DirectX
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		LazyWindow window(m_Width, m_Height, m_ApplicationName.c_str()); 
		m_MainWindow = std::make_unique<LazyWindow>(window); 

		m_Device = new DeviceDX11(); 
		m_SwapChain = new SwapChainDX11(); 


		SystemDX11::InitializeDirectX11(*m_MainWindow, *m_Device, *m_SwapChain);

		return true;
	}
	void AppDX11::run()
	{
		while (!glfwWindowShouldClose(m_MainWindow->getWindow()))
		{
			// Render a frame
			m_Device->m_DevCon->ClearRenderTargetView(m_SwapChain->m_BackBuffer, glm::value_ptr(glm::vec4(0.0f, 0.2f, 0.4f, 1.0f)));
			m_SwapChain->m_SwapChain->Present(0,0);
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

