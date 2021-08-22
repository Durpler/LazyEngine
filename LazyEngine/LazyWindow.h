#ifndef LAZY_WINDOW_H
#define LAZY_WINDOW_H

namespace lazy
{
	class LazyWindow
	{
	public: 
		LazyWindow(); 
		~LazyWindow(); 


		inline void setWidth(int width) { m_Width = width; }
		inline void setHeight(int height) { m_Height = height; }

		inline int getWidth() { return m_Width; }
		inline int getHeight() { return m_Height; }

	private: 
		int m_Width; 
		int m_Height; 
	};
}

#endif 
