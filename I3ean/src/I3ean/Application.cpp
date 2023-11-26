#include "i3pch.h"
#include "Application.h"

#include "I3ean/Events/ApplicationEvent.h"
#include "I3ean/Log.h"

namespace I3ean {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		I3_TRACE(e);

		while (true);
	}

}