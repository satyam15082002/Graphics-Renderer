#include"Panel.h"
#include"./../Batch/Renderer2D.h"
#include<cstring>
#include"./../Renderer/Texture.h"
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
    this->DrawTexturePanel();
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
        if(m_Entity.HasComponent<TextureComponent>())
        {
            auto& a=m_Entity.GetComponent<TextureComponent>();
            if(ImGui::TreeNode("TextureComponent###38130981098"))
            {
                ImGui::InputFloat("###input-textid",(float*)&a.TextID,0.0f,10.0f);
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
        if(ImGui::MenuItem("TextureComponent"))
        {
             if(!m_Entity.HasComponent<TextureComponent>())
                m_Entity.AddComponent<TextureComponent>();
        }
        ImGui::EndPopup();
    }

}
void Panel::DrawTexturePanel()
{
    ImGui::Begin("Texture Panel");
    static char a[200]="";
    ImGui::InputText("###Texture-Path",a,sizeof(a));
    ImGui::SameLine();
    if(ImGui::Button("Add Texture"))
    {
        if(strcmpi(a,"")!=0)
        {
            Renderer2D::m_Texture[Renderer2D::m_TextureCount]=Texture::Create(a);
            Renderer2D::m_TextureCount++;
        }        
    }
    float windowWidth=ImGui::GetContentRegionAvailWidth();
    float padding=10,cellWidth=100;
    float cellSize=padding+cellWidth;
    int columns=windowWidth/cellSize;
    if(columns==0)
        columns=1;
    ImGui::Columns(columns,0,false);
    for(int i=0;i<Renderer2D::m_TextureCount;i++)
    {
        ImGui::Image(reinterpret_cast<void*>(Renderer2D::m_Texture[i]->GetRedererID()),{cellWidth,100});
        ImGui::NextColumn();
    }
    ImGui::Columns(1);
    ImGui::End();
}

