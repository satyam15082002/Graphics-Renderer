#pragma once
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"IMGUIWindow.h"
class Application
{
private:
    GLFWwindow* m_Window;
    IMGUIWindow m_IMGUI;
public:
    Application();
   virtual ~Application();
   GLFWwindow* GetWindow() const;
   void Update();
   void ImGuiRender();
   void Run();
};

