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

#define BIT(x) (1 << x)
