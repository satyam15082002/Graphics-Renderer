#include"Input.h"

GLFWwindow* Input::m_Window=nullptr;
void Input::AddWindow(GLFWwindow* window)
{
    Input::m_Window=window;
}
bool Input::IsKeyPressed(KeyCode key)
{
    auto state = glfwGetKey(m_Window, static_cast<int32_t>(key));
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

bool Input::IsMouseButtonPressed(MouseCode button)
{
    auto state = glfwGetMouseButton(m_Window, static_cast<int32_t>(button));
    return state == GLFW_PRESS;
}

glm::vec2 Input::GetMousePosition()
{
    double xpos, ypos;
    glfwGetCursorPos(m_Window, &xpos, &ypos);

    return { (float)xpos, (float)ypos };
}

float Input::GetMouseX()
{
    return GetMousePosition().x;
}

float Input::GetMouseY()
{
    return GetMousePosition().y;
}

