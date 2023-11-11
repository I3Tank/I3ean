#pragma once

#include "Core.h"

namespace I3ean {

	class I3EAN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}