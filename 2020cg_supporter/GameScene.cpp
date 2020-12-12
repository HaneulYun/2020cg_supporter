#include "pch.h"
#include "GameScene.h"
#include "scripts.h"

void GameScene::BuildObject()
{
    Shader* shader = new Shader();
    {
        shader->LoadShaders("Shaders/vs.vs", "Shaders/fs.fs");
    }

    Mesh* mesh = new Mesh();
    mesh->ReadObj("Models/robot.obj");

    {
        auto player = CreateEmpty();
        player->AddComponent<Transform>()->position = { 0, 0, 3 };
        camera = player->AddComponent<Camera>();
        player->AddComponent<Controller>();
    }

    auto cube = CreateEmpty();
    cube->AddComponent<Transform>()->position = {0, 0, 0};
    cube->AddComponent<MeshFilter>()->mesh = mesh;
    cube->AddComponent<Renderer>()->shader = shader;
    cube->AddComponent<RotatingBehavior>();
}


