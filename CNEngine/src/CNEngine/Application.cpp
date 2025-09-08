#include "cnepch.h"
#include "Application.h"

#include "CNEngine/Events/ApplicationEvent.h"
#include "CNEngine/Log.h"

namespace CNEngine {
	Application::Application() {}

	Application::~Application() {}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		CNE_CORE_TRACE(e.ToString());

		while (true);
	}
}