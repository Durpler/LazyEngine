#ifndef SYSTEM_DX11_H
#define SYSTEM_DX11_H

#include <GLFW/glfw3.h>

#include "SystemBase.h"
#include "DeviceDX11.h"
#include "SwapChainDX11.h"
#include "LazyWindow.h"



namespace lazy
{
	class SystemDX11 : SystemBase
	{
		static bool InitializeDirectX11(LazyWindow& outputWindow, DeviceDX11& device, SwapChainDX11& swapChain); 
		
	};

}

#endif 