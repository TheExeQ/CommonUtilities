include "Premake/extensions.lua"

workspace "CommonUtilities"
	location "."
	startproject "CommonUtilities"
	architecture "x64"

	configurations {
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "CommonUtilities"
	location "."
		
	language "C++"
	cppdialect "C++20"

	targetdir ("./bin/%{prj.name}/" .. outputdir)
	targetname("%{prj.name}-%{cfg.buildcfg}")
	objdir ("./bin-int/%{prj.name}/" .. outputdir)

	files {
		"**.h",
		"**.hpp",
		"**.cpp"
	}

	includedirs {
		".",
		"./include/"
	}

	filter "configurations:Debug"
		defines "_DEBUG"
		runtime "Debug"
		symbols "on"
		
	filter "configurations:Release"
		defines "_RELEASE"
		runtime "Release"
		optimize "on"

	filter "system:windows"
		kind "ConsoleApp"	
		systemversion "latest"
		