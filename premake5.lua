workspace "I3ean"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "I3ean"
	location "I3ean"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"I3_PLATFORM_WINDOWS",
			"I3_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	
	filter "configurations:Debug"
		defines "I3_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "I3_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "I3_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"I3ean/vendor/spdlog/include",
		"I3ean/src"
	}

	links
	{
		"I3ean"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"I3_PLATFORM_WINDOWS"
		}
	
	filter "configurations:Debug"
		defines "I3_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "I3_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "I3_DIST"
		optimize "On"