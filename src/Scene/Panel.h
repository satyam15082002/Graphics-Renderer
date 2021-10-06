#pragma  once
#include"Scene.h"
#include"Entity.h"
#include"Components.h"
#include "../imgui/imgui.h"
#include "../imgui/imgui_impl_glfw.h"
#include "../imgui/imgui_impl_opengl3.h"
class Panel
{
    public:
        Panel(Scene* sc):m_Scene(sc){}
        void Draw();
        void DrawPropertiesPanel();
        void DrawAddComponents();
    private:
        Scene* m_Scene;
        Entity m_Entity;
};
void Panel::Draw()
{
    ImGui::Begin("Panel");
    static char a[100]="";
    ImGui::InputText("###Name",a,sizeof(a));
    ImGui::SameLine();
    if(ImGui::Button("Add###add",{100,25}))
    {
        std::string name=a; 
        cout<<endl<<name<<endl;
        m_Scene->CreateEntity(name);
        strcpy(a,"");
    }           
    ImGui::Separator();

    auto view=m_Scene->GetRegistry().view<TagComponent>();
    ImGui::NewLine();
    for(auto entity:view)
    {
    
        auto tag=view.get<TagComponent>(entity).Tag.c_str();
       ImGui::Text(tag);
       if(ImGui::IsItemClicked())
        {
            m_Entity={entity,m_Scene};
        }
        ImGui::Separator();
    }
    if(m_Scene->GetRegistry().valid(m_Entity))
    {
        ImGui::Text("Selected Entity %s",m_Scene->GetRegistry().get<TagComponent>(m_Entity).Tag.c_str());
        this->DrawPropertiesPanel();
    }
    ImGui::End();
}
void Panel::DrawPropertiesPanel()
{
    ImGui::BeginChild("Properties###0001");
    if(m_Scene->GetRegistry().valid(m_Entity))
    {
         DrawAddComponents();
        if(m_Entity.HasComponent<TransformComponent>())
        {
            auto& a=m_Entity.GetComponent<TransformComponent>();
            if(ImGui::TreeNode("Tranform###0002"))
            {
                ImGui::SliderFloat3("Translate###131",&a.Translation.x,-10.0f,10.0f);
                ImGui::SliderFloat3("Scale###123",&a.Scale.x,0.0f,20.0f);
                ImGui::SliderFloat3("Rotate###124",&a.Rotation.x,-180.0f,180.0f);
                ImGui::TreePop();
            }
            
        }
        if(m_Entity.HasComponent<SpriteRendererComponent>())
        {
            auto& a=m_Entity.GetComponent<SpriteRendererComponent>();
            if(ImGui::TreeNode("SpriteComponent###0003"))
            {
                ImGui::ColorEdit4("Color###5000",&a.Color.r);
                ImGui::TreePop();
            }

        }
    }
    ImGui::EndChild();
}
void Panel::DrawAddComponents()
{
    
    if(ImGui::Button("AddComponents###3000",{ImGui::GetWindowWidth(),30}))
    {
        ImGui::OpenPopup("PopUp_AddComponents");
    }
    if(ImGui::BeginPopup("PopUp_AddComponents"))
    {
        if(ImGui::MenuItem("TransformComponent"))
        {
            if(!m_Entity.HasComponent<TransformComponent>())
                m_Entity.AddComponent<TransformComponent>();
        }
        if(ImGui::MenuItem("SpriteRendererComponent"))
        {
             if(!m_Entity.HasComponent<SpriteRendererComponent>())
                m_Entity.AddComponent<SpriteRendererComponent>();
        }
        ImGui::EndPopup();
    }

}