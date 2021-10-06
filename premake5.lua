-- premake5.lua
include "dependencies.lua"
workspace "Opengl"
   configurations
   { 
      "Debug",
      "Release"
   } 
   platforms 
   { 
      "x64"
   }


project "Opengl"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   targetdir "bin-int/"
   objdir "bin/obj/"
   staticruntime "On"
   defines
   {
      "GLEW_STATIC",
      "IMGUI_IMPL_OPENGL_LOADER_GLEW",
   }
   files 
   {
      "src/**.h",
      "src/**.cpp",
      "*.cpp",
      "%{IncludeDirs.STB_IMAGE}/**.cpp",
      "%{IncludeDirs.STB_IMAGE}/**.h",
   }

   includedirs
   {    
      "%{IncludeDirs.GLFW}",
      "%{IncludeDirs.GLEW}",
      "%{IncludeDirs.GLM}",
      "%{IncludeDirs.STB_IMAGE}",
      "%{IncludeDirs.FontAwesome}",
      "%{IncludeDirs.Entt}"
   } 

   libdirs
   {
      "%{LibraryDirs.GLFW}",
      "%{LibraryDirs.GLEW}"

   }
   links 
   {
      "glew32s",
      ":libglfw3.a",
      "opengl32",
      "Gdi32",
      "shell32",
      "User32",
      "imm32"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"