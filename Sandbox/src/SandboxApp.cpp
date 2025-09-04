#include "CNEngine.h"

class SandboxApp : public CNEngine::Application {
public:
	SandboxApp() {

	}

	~SandboxApp() {

	}
};

CNEngine::Application* CNEngine::CreateApplication() {
	return new SandboxApp();
}