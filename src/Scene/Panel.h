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
        void DrawTexturePanel();
    private:
        Scene* m_Scene;
        Entity m_Entity;
};