#ifndef SWAP_CHAIN_DX11_H
#define SWAP_CHAIN_DX11_H

#include <d3d11.h>
#include <memory>

namespace lazy
{
	class SwapChainDX11
	{
	public: 
		SwapChainDX11(); 
		~SwapChainDX11(); 

		
	public: 
		IDXGISwapChain* m_SwapChain;
		DXGI_SWAP_CHAIN_DESC m_SwapChainDesc; 
	};
}
#endif