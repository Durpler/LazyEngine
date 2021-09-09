#ifndef RENDERER_BASE_H
#define RENDERER_BASE_H

namespace lazy
{

	/// <summary>
	/// Rendering class which holds a ring buffer for command execution. 
	/// This is the main class, that's supposedly going to draw your scenes to the screen. The content it's supposed to draw is going to be controlled
	/// by the commmands inserted into its ring buffer.
	/// </summary>
	class RendererBase
	{
	public: 
		RendererBase() = default;
		~RendererBase() = default; 


	};
}

#endif