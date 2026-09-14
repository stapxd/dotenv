workspace "DotEnv"
    configurations { "Debug", "Release" }

    architecture "x64"
    startproject "dotenvTest"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "dotenv"
    location "dotenv"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp" 
    }

    filter "system:windows"
        systemversion "latest"

    filter "system:linux"
        systemversion "latest"

project "dotenvTest"
    location "dotenvTest"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files { 
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp" 
    }

    links { "dotenv" }
    includedirs { "dotenv/src" }

    filter "system:windows"
        systemversion "latest"

    filter "system:linux"
        systemversion "latest"
