#pragma once

#include "Scene.h"

#include <Entity/entt.hpp>
#include<iostream>
#define EZ_ASSERT(cond,msg) if(!(cond))\
{ \
std::cout<<msg<<std::endl;\
}

class Entity
{
public:
    Entity() = default;
    Entity(entt::entity handle, Scene* scene);
    Entity(const Entity& other) = default;
    void SetEntity(entt::entity handle,Scene* scene);
    template<typename T, typename... Args>
    T& AddComponent(Args&&... args)
    {
       EZ_ASSERT(!HasComponent<T>(),"Entity already has component!");
        T& component = m_Scene->m_Registry.emplace<T>(m_EntityHandle, std::forward<Args>(args)...);
        return component;
    }

    template<typename T>
    T& GetComponent()
    {
       EZ_ASSERT(HasComponent<T>(), "Entity does not have component!");
        return m_Scene->m_Registry.get<T>(m_EntityHandle);
    }

    template<typename T>
    bool HasComponent()
    {
        return m_Scene->m_Registry.has<T>(m_EntityHandle);
    }

    template<typename T>
    void RemoveComponent()
    {
       EZ_ASSERT(HasComponent<T>(),"Entity does not have component!");
        m_Scene->m_Registry.remove<T>(m_EntityHandle);
    }

    operator bool() const { return m_EntityHandle != entt::null; }
    operator entt::entity() const { return m_EntityHandle; }
    operator uint32_t() const { return (uint32_t)m_EntityHandle; }

    bool operator==(const Entity& other) const
    {
        return m_EntityHandle == other.m_EntityHandle && m_Scene == other.m_Scene;
    }
    bool operator!=(const Entity& other) const
    {
        return !(*this == other);
    }
private:
    entt::entity m_EntityHandle{ entt::null };
    Scene* m_Scene = nullptr;
};
