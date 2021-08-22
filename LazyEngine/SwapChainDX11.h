#ifndef SWAP_CHAIN_DX11_H
#define SWAP_CHAIN_DX11_H

#include <d3d11.h>

namespace lazy
{
	class SwapChainDX11
	{
	public: 
		SwapChainDX11(); 
		~SwapChainDX11(); 

		inline IDXGISwapChain* getSwapChain() { return *m_SwapChain; }

	private: 
		std::unique_ptr<IDXGISwapChain*> m_SwapChain;
		std::unique_ptr<DXGI_SWAP_CHAIN_DESC*> m_SwapChainDesc; 
	};
}
#endif