#pragma once
#include<GLFW/glfw3.h>
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
class IMGUIWindow
{
private:
    GLFWwindow* m_Window;
public:
    IMGUIWindow()=default;
    void Init(GLFWwindow* window);
    void RenderFrame();
    void  Clear();
    void End();
    ~IMGUIWindow();
};

