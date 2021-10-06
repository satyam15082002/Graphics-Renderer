#include"Camera.h"

Camera::Camera(const glm::vec3& pos):m_CameraSpeed(1.0f)
{
    m_ZoomLevel=1.0f;
    m_Rotation=0.0f;
    m_FOV=45.0f;
    m_Pos=pos;
    m_PV=glm::mat4(1.0f);
    CalculateViewMatrix();
}
void Camera::CalculateViewMatrix()
{
    m_View=glm::translate(glm::mat4(1.0f),m_Pos)*
    glm::rotate(glm::mat4(1.0f),glm::radians(m_Rotation),{0.0f,1.0f,0.0f});
    // m_Proj=glm::ortho(-(m_AspectRatio*m_ZoomLevel),(m_AspectRatio*m_ZoomLevel),-(m_AspectRatio*m_ZoomLevel),m_AspectRatio*m_ZoomLevel,-1.0f,1.0f);
    m_Proj=glm::perspective(glm::radians(m_FOV),16.0f/9.0f,0.1f,1000.0f);
    m_View=glm::inverse(m_View);
    m_PV=m_Proj*m_View;
}
glm::mat4& Camera::GetProjectionViewMatrix()
{
    return m_PV;
}
Camera::~Camera()
{
}
void Camera::TranslateX(float x)
{
    m_Pos.x+=x;
    CalculateViewMatrix();
}
void Camera::TranslateY(float y)
{
    m_Pos.y+=y;
    CalculateViewMatrix();
}
void Camera::TranslateZ(float z)
{
    m_Pos.z+=z;
    CalculateViewMatrix();
}
void Camera::ZoomIn(float ts)
{
    m_FOV=m_FOV-20.0f*ts;
    if(m_FOV<5.0f)
        m_FOV=5.0f;
    CalculateViewMatrix();
}
void Camera::ZoomOut(float ts)
{
     m_FOV=m_FOV+20.0f*ts;
    if(m_FOV<5.0f)
        m_FOV=5.0f;

    CalculateViewMatrix();
}
void Camera::SetFOV(double y,float ts)
{
    m_FOV=m_FOV-2.5*y;
    if(m_FOV<1.0f)
        m_FOV=1.0f;
    if(m_FOV>180.0f)
        m_FOV=180.0f;
    CalculateViewMatrix();
}
void Camera::SetRotation(float x)
{
    m_Rotation+=x;
    CalculateViewMatrix();
}
