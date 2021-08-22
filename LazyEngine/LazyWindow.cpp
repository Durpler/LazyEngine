#include "pch.h"
#include "LazyWindow.h"


namespace lazy
{
	LazyWindow::LazyWindow() : 
		m_Width(0),
		m_Height(0)
	{
		m_Window = nullptr; 
	}

	LazyWindow::LazyWindow(int width, int height, const char* title)
	{
		setWidth(width); 
		setHeight(height); 

		m_Title = title; 

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr); 
		if (!m_Window)
		{
			std::cout << "Could not create window!" << std::endl; 
		}

	}

}
