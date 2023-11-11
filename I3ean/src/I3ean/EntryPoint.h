#pragma once

#ifdef I3_PLATFORM_WINDOWS

extern I3ean::Application* I3ean::CreateApplication();

int main(int argc, char** argv) {
	auto app = I3ean::CreateApplication();
	app->Run();
	delete app;
}

#endif