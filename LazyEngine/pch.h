// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#ifdef WITH_DIRECTX_11
#define GLFW_EXPOSE_NATIVE_WIN32
// directX11 includes
#include <d3d11.h>
#include <d3dcompiler.h>

//directX11 linking
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "winmm.lib")
#endif



// add headers that you want to pre-compile here
#include<GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
// link glfw
#pragma comment(lib, "glfw3.lib")

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>


//std
#include <iostream>


// Safely release a COM object.
template<typename T>
inline void SafeRelease(T & ptr)
{
    if (ptr != NULL)
    {
        ptr->Release();
        ptr = NULL;
    }
}


#endif //PCH_H
