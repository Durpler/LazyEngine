#ifndef LAZY_WINDOW_H
#define LAZY_WINDOW_H
#include "pch.h"


namespace lazy
{
	class LazyWindow
	{
	public: 
		LazyWindow(); 
		LazyWindow(int width, int height, const char* title); 
		~LazyWindow() {};


		inline void setWidth(int width) { m_Width = width; }
		inline void setHeight(int height) { m_Height = height; }

		inline int getWidth() { return m_Width; }
		inline int getHeight() { return m_Height; }

		inline GLFWwindow* getWindow() { return m_Window; }
#ifdef WITH_DIRECTX_11
		inline HWND getHwnd() { return glfwGetWin32Window(m_Window); }
#endif 

	private: 
		int m_Width{ 0 };
		int m_Height{ 0 };
		std::string m_Title{};

		GLFWwindow* m_Window; 
	};
}

#endif 
