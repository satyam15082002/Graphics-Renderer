#pragma once
#include<Entity/entt.hpp>
#include"../Batch/Renderer2D.h"


class Entity;

class Scene
{
public:
    Scene();
    ~Scene();

    Entity CreateEntity(const std::string& name = std::string());
    void DestroyEntity(Entity entity);
    void OnEditorUpdate();
    entt::registry& GetRegistry();
private:
    entt::registry m_Registry;
    friend class Entity;
};
