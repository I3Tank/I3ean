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

#ifdef I3_ENABLE_ASSERTS
	#define I3_ASSERT(x, ...) { if(!(x)) { I3_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define I3_CORE_ASSERT(x, ...) { if(!(x)) { I3_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define I3_ASSERT(x, ...)
	#define I3_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)