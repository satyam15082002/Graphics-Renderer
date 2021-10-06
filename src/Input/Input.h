#pragma once

#include <glm/glm.hpp>
#include<GLFW/glfw3.h>
#include "KeyCode.h"
#include "MouseCode.h"
class Input
{
    public:
        static void AddWindow(GLFWwindow* window);
        static bool IsKeyPressed(KeyCode key);
        static bool IsMouseButtonPressed(MouseCode button);
        static glm::vec2 GetMousePosition();
        static float GetMouseX();
        static float GetMouseY();
    private:
        static  GLFWwindow* m_Window;
};