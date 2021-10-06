#include"Application.h"
#include<iostream>
#include<cassert>



Application::Application():m_Window(nullptr)
{
    if (!glfwInit())
    {
        std::cout << "Failed to initialize GLFW" << std::endl;
        assert(false);
    }
    m_Window = glfwCreateWindow(640, 480, "LearnOpenGL", NULL, NULL);
    if (m_Window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        assert(false);
    }
    glfwMakeContextCurrent(m_Window);

    if (glewInit()!=GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        assert(false);
      
    }
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
    m_IMGUI.Init(m_Window);

}
Application::~Application()
{
    m_IMGUI.End();
    glfwDestroyWindow(m_Window);
    glfwTerminate();
}
GLFWwindow* Application::GetWindow() const
{
    return m_Window;
}
void Application::Update()
{
    m_IMGUI.Clear();
    glfwSwapBuffers(m_Window);
    glfwPollEvents();
}

void Application::Run()
{
}
void Application::ImGuiRender()
{
    m_IMGUI.RenderFrame();
}

