#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "I3ean/Events/ApplicationEvent.h"

#include "Window.h"

namespace I3ean {

	class I3EAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}