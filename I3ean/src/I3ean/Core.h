#pragma once

#ifdef I3_PLATFORM_WINDOWS
	#ifdef I3_BUILD_DLL
		#define I3EAN_API __declspec(dllexport)
	#else
		#define I3EAN_API __declspec(dllimport)
	#endif
#else
	#error I3ean only supports Windows!
#endif

#define BIT(x) (1 << x)