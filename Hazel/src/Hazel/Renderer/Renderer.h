#pragma once

namespace Hazel {

	enum class RendererAPI
	{
		None=0,OpenGl=1
	};

	class Renderer
	{
	public:
		static inline RendererAPI GetAPI() { return s_RendererAPI; }
	private:
		static RendererAPI s_RendererAPI;
	};

}
