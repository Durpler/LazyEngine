#ifndef DEVICE_DX11_H
#define DEVICE_DX11_H
#include <d3d11.h>
#include <memory>


namespace lazy
{
	class DeviceDX11
	{
	public: 
		DeviceDX11() {
			m_Device = nullptr; 
			m_DevCon = nullptr; 

		};
		~DeviceDX11() {};

		inline ID3D11Device* getDevice() { return m_Device; }
		inline ID3D11DeviceContext* getContext() { return m_DevCon; }

	
		ID3D11Device* m_Device; 
		ID3D11DeviceContext* m_DevCon; 

	};
}

#endif