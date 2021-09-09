#include "pch.h"
#include "SwapChainDX11.h"
#include "GlobalDefinitions.h"

lazy::SwapChainDX11::SwapChainDX11()
{
	m_BackBuffer = nullptr; 
	m_SwapChain = nullptr; 
	memset(&m_SwapChainDesc, 0, sizeof(DXGI_SWAP_CHAIN_DESC));
}

lazy::SwapChainDX11::~SwapChainDX11()
{
	m_SwapChain->Release(); 
	m_BackBuffer->Release(); 
	SafeRelease(m_SwapChain);
	SafeRelease(m_BackBuffer); 
}
