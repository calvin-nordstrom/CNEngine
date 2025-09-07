#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace CNEngine {
	class CNENGINE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}