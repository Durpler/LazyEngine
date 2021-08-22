#include "pch.h"
#include "SystemDX11.h"

namespace lazy
{
    bool SystemDX11::InitializeDirectX11(LazyWindow& outputWindow, DeviceDX11& device, SwapChainDX11& swapChain)
    {
        HWND wnd = outputWindow.getHwnd();

        DXGI_SWAP_CHAIN_DESC scd;
        // zero out the description struct
        memset(&scd, 0, sizeof(DXGI_SWAP_CHAIN_DESC));

        // one back buffer TODO: boolean bTripleBuffering?
        scd.BufferCount = 1;
        scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        scd.OutputWindow = wnd;
        scd.SampleDesc.Count = 4; // multisampling times 4 
        scd.Windowed = TRUE;

        IDXGISwapChain* tmpSwapChain; 
        ID3D11Device* dev; 
        ID3D11DeviceContext* devCon; 


        // create device and swapchain
        if (D3D11CreateDeviceAndSwapChain(
            NULL,
            D3D_DRIVER_TYPE_HARDWARE,
            NULL,
            NULL,
            NULL,
            NULL,
            D3D11_SDK_VERSION,
            &scd,
            &tmpSwapChain,
            &dev,
            NULL,
            &devCon) != S_OK)
        {
            std::cout << "Failed to create D3D11 device and swapchain" << std::endl; 
            return false; 
        }           


        

        return true;
    }

}
