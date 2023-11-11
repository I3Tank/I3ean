#pragma once

#ifdef I3_PLATFORM_WINDOWS

extern I3ean::Application* I3ean::CreateApplication();

int main(int argc, char** argv) {
	I3ean::Log::Init();
	I3_CORE_WARN("Initialized Log!");
	int a = 5;
	I3_CORE_INFO("Hello! Var={0}", a);

	auto app = I3ean::CreateApplication();
	app->Run();
	delete app;
}

#endif