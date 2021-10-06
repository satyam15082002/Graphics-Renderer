#pragma once

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


class Camera
{
    public:
        Camera(const glm::vec3& pos);
        ~Camera();
        glm::mat4& GetProjectionViewMatrix();
        void TranslateX(float x);
        void TranslateY(float y);
        void TranslateZ(float z);
        void SetRotation(float x);
        void ZoomIn(float ts);
        void ZoomOut(float ts);
        void SetFOV(double y,float ts);

    private:
        void CalculateViewMatrix();
    private:
       
        glm::vec3 m_Pos;
        float m_Rotation;
        glm::mat4 m_View;
        glm::mat4 m_Proj;
        glm::mat4 m_PV;
        float m_CameraSpeed;
        float m_ZoomLevel;
        float m_FOV;
};

