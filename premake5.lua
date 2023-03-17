workspace "JulesEngine"
    architecture "x64"
    startproject "Sandbox"
    
    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "JulesEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "JulesEngine/vendor/Glad/include"

include "JulesEngine/vendor/GLFW"
include "JulesEngine/vendor/Glad"

project "JulesEngine"
    location "JulesEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "jepch.h"
    pchsource "JulesEngine/src/jepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
	    "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include", 
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
    }

    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

    defines
    {
        "JE_PLATFORM_WINDOWS",
        "JE_BUILD_DLL"
    }
    
    postbuildcommands
    {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "configurations:Debug"
        defines "JE_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "JE_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "JE_DIST"
        buildoptions "/MD"
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
        "JulesEngine/vendor/spdlog/include",
        "JulesEngine/src"
    }

    links
    {
        "JulesEngine"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "JE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "JE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "JE_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "JE_DIST"
        optimize "On"













