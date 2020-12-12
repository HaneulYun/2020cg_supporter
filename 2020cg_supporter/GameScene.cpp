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
    mesh->ReadObj("Models/blue_robot.obj");
    mesh->Init();

    {
        auto player = CreateEmpty();
        player->AddComponent<Transform>()->position = { 0, 0, 3 };
        camera = player->AddComponent<Camera>();
        player->AddComponent<Controller>();
    }

    Mesh* mesh0 = new Mesh();
    mesh0->vertices = {
        { -1.0f,-1.0f,-1.0f } ,
        { -1.0f,-1.0f, 1.0f } ,
        { -1.0f, 1.0f, 1.0f } ,
        { 1.0f, 1.0f,-1.0f  } ,
        { -1.0f,-1.0f,-1.0f } ,
        { -1.0f, 1.0f,-1.0f } ,
        { 1.0f,-1.0f, 1.0f  } ,
        { -1.0f,-1.0f,-1.0f } ,
        { 1.0f,-1.0f,-1.0f  } ,
        { 1.0f, 1.0f,-1.0f  } ,
        { 1.0f,-1.0f,-1.0f  } ,
        { -1.0f,-1.0f,-1.0f } ,
        { -1.0f,-1.0f,-1.0f } ,
        { -1.0f, 1.0f, 1.0f } ,
        { -1.0f, 1.0f,-1.0f } ,
        { 1.0f,-1.0f, 1.0f  } ,
        { -1.0f,-1.0f, 1.0f } ,
        { -1.0f,-1.0f,-1.0f } ,
        { -1.0f, 1.0f, 1.0f } ,
        { -1.0f,-1.0f, 1.0f } ,
        { 1.0f,-1.0f, 1.0f  } ,
        { 1.0f, 1.0f, 1.0f  } ,
        { 1.0f,-1.0f,-1.0f  } ,
        { 1.0f, 1.0f,-1.0f  } ,
        { 1.0f,-1.0f,-1.0f  } ,
        { 1.0f, 1.0f, 1.0f  } ,
        { 1.0f,-1.0f, 1.0f  } ,
        { 1.0f, 1.0f, 1.0f  } ,
        { 1.0f, 1.0f,-1.0f  } ,
        { -1.0f, 1.0f,-1.0f } ,
        { 1.0f, 1.0f, 1.0f  } ,
        { -1.0f, 1.0f,-1.0f } ,
        { -1.0f, 1.0f, 1.0f } ,
        { 1.0f, 1.0f, 1.0f  } ,
        { -1.0f, 1.0f, 1.0f } ,
        { 1.0f,-1.0f, 1.0f  }
    };
    mesh0->Init();

    for (int i = -3; i <= 3; ++i)
        for (int j = -3; j <= 3; ++j)
            for (int k = -3; k <= 3; ++k)
            {
                auto cube = CreateEmpty();
                cube->AddComponent<Transform>()->position = { i * 10, j * 10, k * 10 };

                cube->AddComponent<MeshFilter>()->mesh = (!i && !j && !k) ? mesh : mesh0;
                cube->AddComponent<Renderer>()->shader = shader;
                cube->AddComponent<RotatingBehavior>();
            }
}

