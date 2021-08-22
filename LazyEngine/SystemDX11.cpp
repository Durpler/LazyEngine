#include "pch.h"
#include "SystemDX11.h"

namespace lazy
{
    bool SystemDX11::InitializeDirectX11(LazyWindow& outputWindow, DeviceDX11& device, SwapChainDX11& swapChain)
    {
        HWND wnd = outputWindow.getHwnd();
        
        // zero out the description struct
        memset(&swapChain.m_SwapChainDesc, 0, sizeof(DXGI_SWAP_CHAIN_DESC));

        // one back buffer TODO: boolean bTripleBuffering?
        swapChain.m_SwapChainDesc.BufferCount = 1;
        swapChain.m_SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        swapChain.m_SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChain.m_SwapChainDesc.OutputWindow = wnd;
        swapChain.m_SwapChainDesc.SampleDesc.Count = 4; // multisampling times 4 
        swapChain.m_SwapChainDesc.Windowed = TRUE;


        // create device and swapchain
        if (D3D11CreateDeviceAndSwapChain(
            NULL,
            D3D_DRIVER_TYPE_HARDWARE,
            NULL,
            NULL,
            NULL,
            NULL,
            D3D11_SDK_VERSION,
            &swapChain.m_SwapChainDesc,
            &swapChain.m_SwapChain,
            &device.m_Device,
            NULL,
            &device.m_DevCon) != S_OK)
        {
            std::cout << "Failed to create D3D11 device and swapchain" << std::endl; 
            return false; 
        }                  

        return true;
    }

}
