#ifndef DEVICE_BASE_H
#define DEVICE_BASE_H
namespace lazy
{
	class DeviceBase
	{
	public:
		DeviceBase()
		{
			OnCreate();
		}
		~DeviceBase()
		{
			OnDestroy();
		}

		DeviceBase(const DeviceBase& other) = delete;
		DeviceBase operator=(const DeviceBase& other) = delete;

		virtual void OnCreate() {}
		virtual void OnDestroy() {}

	};
}

#endif