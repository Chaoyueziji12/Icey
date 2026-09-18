workspace "Icey"
	architecture "x64"
	configurations
	{
		"Debug", 
		"Release", 
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Icey"
	location "Icey"
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
		"Icey/vendor/spdlog/include", 
		"Icey/src"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0"
	
		defines
		{
			"IC_PLATFORM_WINDOWS", 
			"IC_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "IC_DEBUG"
			symbols "On"
			buildoptions { "/utf-8" }
		filter {}
		
		filter "configurations:Release"
			defines "IC_RELEASE"
			optimize "On"
			buildoptions { "/utf-8" }
		filter {}
		
		filter "configurations:Dist"
			defines "IC_DIST"
			optimize "On"
			buildoptions { "/utf-8" }
		filter {}

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	configurations { "Debug", "Release", "Dist"}
	files
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"$(SolutionDir)Icey/vendor/spdlog/include", 
		"$(SolutionDir)Icey/src"
	}

	links
	{
		"Icey"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0"
	
		defines
		{
			"IC_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "IC_DEBUG"
			symbols "On"
			buildoptions { "/utf-8" }
		filter {}
		
		filter "configurations:Release"
			defines "IC_RELEASE"
			optimize "On"
			buildoptions { "/utf-8" }
		filter {}
		
		filter "configurations:Dist"
			defines "IC_DIST"
			optimize "On"
			buildoptions { "/utf-8" }
		filter {}