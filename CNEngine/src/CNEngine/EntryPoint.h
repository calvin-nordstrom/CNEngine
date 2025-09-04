#pragma once

#ifdef CNE_PLATFORM_WINDOWS

extern CNEngine::Application* CNEngine::CreateApplication();

int main(int argc, char** argv) {
	
	CNEngine::Log::Init();
	CNE_CORE_WARN("Initialized Log!");
	int a = 5;
	CNE_INFO("Hello from CNEngine!");

	auto app = CNEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif