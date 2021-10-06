#pragma once
#include<GL/glew.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
using namespace std;

enum class ShaderType
{
    None=-1,
    VERTEX,
    FRAGMENT
};
class Shader
{
    public:
        Shader(string vertexPath, string fragmentPath);
        ~Shader();
        void Bind() const;
        void Unbind() const;
        void SetMat4(const string& key,glm::mat4 value);
        void SetInt1(const string& key,int value);

    private:
        void CompileShader(unsigned int shaderID,ShaderType type) const;
        void LinkShader() const;

        unsigned int m_RendererID;
        mutable bool is_Bind;
};

