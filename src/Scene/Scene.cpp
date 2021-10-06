#include "Scene.h"
#include "Components.h"
#include <glm/glm.hpp>

#include "Entity.h"


Scene::Scene()
{
}

Scene::~Scene()
{
}
entt::registry& Scene::GetRegistry()
{
    return m_Registry;
}
Entity Scene::CreateEntity(const std::string& name)
{
    Entity entity = { m_Registry.create(), this };
    auto& tag = entity.AddComponent<TagComponent>();
    tag.Tag = name.empty() ? "Entity" : name;
    return entity;
}

void Scene::DestroyEntity(Entity entity)
{
    m_Registry.destroy(entity);
}
void Scene::OnEditorUpdate()
{
    auto view=m_Registry.view<TransformComponent,SpriteRendererComponent>();
    for(auto entity:view)
    {
        auto[trans,sprite]=view.get<TransformComponent,SpriteRendererComponent>(entity);
        Renderer2D::DrawQuad(trans.GetTransform(),sprite.Color);
    }
}
