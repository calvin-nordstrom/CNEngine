#include "CNEngine.h"

class ExampleLayer : public CNEngine::Layer {
public:
	ExampleLayer() : Layer("Example") {
	}

	void OnUpdate() override {
		 CNE_INFO("ExampleLayer::Update");
	}

	void OnEvent(CNEngine::Event& event) override {
		 CNE_TRACE("{0}", event.ToString());
	}
};

class SandboxApp : public CNEngine::Application {
public:
	SandboxApp() {
		PushLayer(new ExampleLayer());
	}

	~SandboxApp() {}
};

CNEngine::Application* CNEngine::CreateApplication() {
	return new SandboxApp();
}