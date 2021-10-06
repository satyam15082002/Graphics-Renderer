#pragma once
#include<glm/glm.hpp>
#include<memory>
struct Vertex
{
    glm::vec4 m_Position;
    glm::vec4 m_Color;
    glm::vec2 m_TextCoords;
    float m_TextId;
};
template<typename T>
using Ref=std::shared_ptr<T>;
