#include "cnepch.h"
#include "Application.h"

#include "CNEngine/Events/ApplicationEvent.h"
#include "CNEngine/Log.h"

namespace CNEngine {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {
	}

	void Application::Run() {
		while (m_Running) {
			m_Window->OnUpdate();
		}
	}
}