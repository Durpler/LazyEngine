#ifndef APP_BASE_H
#define APP_BASE_H

//lazy engine 
#include "LazyWindow.h"
#include "DeviceBase.h"

// std
#include <string>
#include <memory>

namespace lazy
{
	/// <summary>
	/// Base Application class. Inherit from this BaseClass to implement further APIs.
	/// Base Class is already supposed to initialize GLFW (might be altered for OpenGL, since the macro definition for glfw
	/// with OpenGL is different. 
	/// </summary>
	class AppBase
	{
	public:

		AppBase() { OnCreate(); }
		~AppBase() { OnDestroy(); }

		AppBase(const AppBase& other) = delete;
		AppBase operator=(const AppBase& other) = delete;

		/// <summary>
		/// ATTRIBUTES
		/// </summary>
		virtual void OnCreate() { initialize(); }
		virtual void OnDestroy() {}

		virtual bool initialize() {}


		std::string m_ApplicationName{ "LazyApp" };

		int m_Width{ 1280 };
		int m_Height{ 720 };

		
	private: 
		std::unique_ptr<DeviceBase> m_Device; 
		std::unique_ptr<LazyWindow> m_MainWindow; 
		
	};
}


#endif