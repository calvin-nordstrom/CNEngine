#pragma once

#ifdef CNE_PLATFORM_WINDOWS
	#ifdef CNE_BUILD_DLL
		#define CNENGINE_API __declspec(dllexport)
	#else
		#define CNENGINE_API __declspec(dllimport)
	#endif
#else
	#error CNEngine only supports Windows!
#endif

#ifdef CNE_ENABLE_ASSERTS
	#define CNE_ASSERT(x, ...) { if(!(x)) { CNE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define CNE_CORE_ASSERT(x, ...) { if(!(x)) { CNE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define CNE_ASSERT(x, ...)
	#define CNE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
