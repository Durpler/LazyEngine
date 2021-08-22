#ifndef SWAPCHAIN_BASE_H
#define SWAPCHAIN_BASE_H

namespace lazy
{
	class SwapChainBase
	{
	public: 
		SwapChainBase() { OnCreate();  }
		~SwapChainBase() { OnDestroy(); }
	};
}

#endif