#include <iostream>
#include"Shader.h"
using namespace std;

Shader::Shader(string vertexPath, string fragmentPath):is_Bind(false)
{
    ifstream vsFile(vertexPath);
    ifstream fsFile(fragmentPath);
    string vsSource,fsSource;
    stringstream Stream[2];
    if(!vsFile||!fsFile)
    {
        cout<<"Error in opening file";
    }
    else
    {
        Stream[0]<<vsFile.rdbuf();
        Stream[1]<<fsFile.rdbuf();
    }
    string vsCode,fsCode;
    vsCode=Stream[0].str();
    fsCode=Stream[1].str();
    const char* vShaderCode =vsCode.c_str();
    const char* fShaderCode =fsCode.c_str();
    unsigned int vertex, fragment;

    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    this->CompileShader(vertex,ShaderType::VERTEX);

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    this->CompileShader(fragment,ShaderType::FRAGMENT);

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, vertex);
    glAttachShader(m_RendererID, fragment);
    glLinkProgram(m_RendererID);
    this->LinkShader();    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    
}
Shader::~Shader()
{
    glDeleteProgram(m_RendererID);
}
void Shader::Bind() const
{ 
    if(!is_Bind)
    {
        is_Bind=true;   
        glUseProgram(m_RendererID);
    }
    
}  
void Shader::Unbind() const
{ 
    if(is_Bind)
    {
        is_Bind=false;
        glUseProgram(0);
    }
} 
void Shader::SetMat4(const string& key,glm::mat4 value)
{
   int location=glGetUniformLocation(m_RendererID,key.c_str());
   if(location!=-1)
   {
       glUniformMatrix4fv(location,1,GL_FALSE,glm::value_ptr(value));
   }
}
void Shader::SetInt1(const string& key,int value)
{
    int location=glGetUniformLocation(m_RendererID,key.c_str());
    if(location!=-1)
    {
        glUniform1i(location,value);
    }
}
void Shader::SetIntArray(const string& key,int count,int* value)
{
    int location=glGetUniformLocation(m_RendererID,key.c_str());
    if(location!=-1)
    {
        glUniform1iv(location,count,value);
    }
}



void Shader::CompileShader(unsigned int shaderID,ShaderType type) const
{
    int success;
    char infoLog[100];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(shaderID, 100, NULL, infoLog);
        if(type==ShaderType::VERTEX)
            cout << "ERROR VERTEXCOMPILATION_FAILED\n" << infoLog << endl;
        else if(type==ShaderType::FRAGMENT)
            cout << "ERROR FRAGMENTCOMPILATION_FAILED\n" << infoLog << endl;
    }
}
void Shader::LinkShader() const
{
    int success;
    char infoLog[512];
    glGetProgramiv(m_RendererID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(m_RendererID, 100, NULL, infoLog);
        cout<<"Shader Linking Error"<<infoLog<<endl;
    }
}