workspace "CNEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CNEngine"
	location "CNEngine"
	kind "SharedLib"
	language "C++"
	buildoptions{"/utf-8"}
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "cnepch.h"
	pchsource "CNEngine/src/cnepch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CNE_PLATFORM_WINDOWS",
			"CNE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CNE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CNE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CNE_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	buildoptions{"/utf-8"}
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"CNEngine/vendor/spdlog/include",
		"CNEngine/src"
	}

	links
	{
		"CNEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CNE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CNE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "CNE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CNE_DIST"
		optimize "On"