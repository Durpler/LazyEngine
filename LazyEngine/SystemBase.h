#ifndef SYSTEM_BASE_H
#define SYSTEM_BASE_H


namespace lazy
{
	class SystemBase
	{
	public: 
		SystemBase() { OnCreate(); }
		~SystemBase() { OnDestroy(); }

		virtual void initialize() {};

	protected: 
		virtual void OnCreate() {}; 
		virtual void OnDestroy() {}; 
	};
}
#endif
