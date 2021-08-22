#ifndef APP_DX11_H
#define APP_DX11_H
// lazy engine
#include "AppBase.h"
#include "DeviceDX11.h"
#include "SwapChainDX11.h"


namespace lazy
{
	class AppDX11 : AppBase
	{
	public: 
		AppDX11() { OnCreate(); }


		/// <summary>
		/// Overrides for custom DX11-dependant commands
		/// </summary>
		/// <returns></returns>
		bool initialize() override; 
		void run() override; 
		void OnCreate() override; 
		void OnDestroy() override; 

	private: 
		DeviceDX11* m_Device;
		SwapChainDX11* m_SwapChain;



		
	};
}

#endif
