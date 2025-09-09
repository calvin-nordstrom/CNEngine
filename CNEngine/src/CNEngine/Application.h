#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "CNEngine/Events/ApplicationEvent.h"
#include "Window.h"

namespace CNEngine {
	class CNENGINE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		bool OnWindowClose(WindowCloseEvent& e);
	};

	Application* CreateApplication();
}