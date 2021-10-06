#include"std_pch.h"
#include"pch.h"
using namespace std;
Ref<Camera> cam2;
float lframe=0.0f,ts;
void processInput() 
{ 
    float cframe=glfwGetTime();
    ts=cframe-lframe;
    lframe=cframe;
    if (Input::IsKeyPressed(Key::Left))
        cam2->TranslateX(7.0*ts);
    if (Input::IsKeyPressed(Key::Right))
        cam2->TranslateX(-7.0*ts);
    if (Input::IsKeyPressed(Key::Up))
        cam2->TranslateY(-7.0*ts);
    if (Input::IsKeyPressed(Key::Down))
        cam2->TranslateY(7.0*ts);
    if (Input::IsKeyPressed(Key::W))
        cam2->TranslateZ(-4.0*ts);
    if (Input::IsKeyPressed(Key::S))
        cam2->TranslateZ(4.0*ts);
    if(Input::IsKeyPressed(Key::A))
        cam2->SetRotation(20.0f*ts);
    if(Input::IsKeyPressed(Key::D))
        cam2->SetRotation(-20.0f*ts);
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{ 
    glViewport(0, 0, width, height);
}
void scroll_callback(GLFWwindow* window,double x,double y)
{
    cam2->SetFOV(y,ts);
}
void AddIcon()
{
	if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New", "Ctrl+N"))
                {}
				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

    ImVec2 size={100.0f,25.0f};
}
int main()
{
    unique_ptr<Application> app=make_unique<Application>();
    Input::AddWindow(app->GetWindow());
    Ref<Camera> cam=make_shared<Camera>((glm::vec3){0.0f,0.0f,2.0f});
    cam2=cam;
    glfwSetFramebufferSizeCallback(app->GetWindow(), framebuffer_size_callback);
    glfwSetScrollCallback(app->GetWindow(),scroll_callback);
    // glfwSetInputMode(app->GetWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    
    Scene sc;
    auto c=sc.CreateEntity("Camera");
    Panel p(&sc);
    Renderer2D::Init(cam);
    while (!glfwWindowShouldClose(app->GetWindow()))
    {

        // glBufferSubData(GL_ARRAY_BUFFER,0,v.size()*sizeof(Vertex),v.data());
        processInput();
        Renderer::Clear();
        app->ImGuiRender();
        sc.OnEditorUpdate();
        Renderer2D::Flush();
        Renderer2D::ShutDown();
        p.Draw();
        app->Update();

    }
    return 0;
}



