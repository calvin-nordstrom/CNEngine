#pragma once

#ifdef CNE_PLATFORM_WINDOWS

extern CNEngine::Application* CNEngine::CreateApplication();

int main(int argc, char** argv) {
	printf("CNEngine Starting...\n");
	auto app = CNEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif