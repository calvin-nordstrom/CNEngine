#pragma once

#include "CNEngine/Window.h"

#include <GLFW/glfw3.h>

namespace CNEngine {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		GLFWwindow* m_Window;
		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			EventCallbackFn EventCallback;
			bool VSync;
		};
		WindowData m_Data;

		void Init(const WindowProps& props);
		void Shutdown();
	};
}