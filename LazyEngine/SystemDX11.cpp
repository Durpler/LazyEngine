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
            std::cout << "FAILED to create D3D11 device and swapchain" << std::endl; 
            return false; 
        }
        std::cout << "SUCCESS in creating D3D11 device and swapchain" << std::endl; 
        
        // set the render target

        // get the address of the backbuffer
        ID3D11Texture2D* pBackBuffer; 
        swapChain.m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);

        // use the back buffer address to create the render target
        device.m_Device->CreateRenderTargetView(pBackBuffer, NULL, &device.m_BackBuffer);
        pBackBuffer->Release(); 

        //set the render target as the back buffer
        device.m_DevCon->OMSetRenderTargets(1, &device.m_BackBuffer, NULL); 


        // set the viewport
        D3D11_VIEWPORT viewport; 
        memset(&viewport, 0, sizeof(D3D11_VIEWPORT)); 

        viewport.TopLeftX = 0; 
        viewport.TopLeftY = 0; 
        // TODO: take parameters from glfw-window
        viewport.Width = 1280; // this needs to be taken from the glfw-window
        viewport.Height = 720;  // this needs to be taken from the GLFW window

        device.m_DevCon->RSSetViewports(1, &viewport); 
        return true;
    }

}
