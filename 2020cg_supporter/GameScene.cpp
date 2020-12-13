#include "pch.h"
#include "GameScene.h"
#include "scripts.h"

void GameScene::BuildObject()
{
    Shader* shader = new Shader();
    {
        shader->LoadShaders("Shaders/vs.vs", "Shaders/fs.fs");
    }

    Material* material = new Material();
    {
        material->LoadDiffuseMap("Models/DefaultMaterial_Base_Color.dds");
        material->LoadNormalMap("Models/DefaultMaterial_Normal.dds");
    }
    Material* material1 = new Material();
    {
        material1->LoadDiffuseMap("Models/rifle_Base_Color.dds");
        material1->LoadNormalMap("Models/rifle_005005005_Normal.dds");
    }

    Mesh* mesh = new Mesh();
    mesh->ReadObj("Models/blue_robot.obj");
    mesh->Init();

    Mesh* mesh1 = new Mesh();
    mesh1->ReadObj("Models/rifle.obj");
    mesh1->Init();

    {
        auto player = CreateEmpty();
        player->AddComponent<Transform>()->position = { 0, 0, 3 };
        player->AddComponent<FirstPersonCamera>();
        camera = player->AddComponent<Camera>();
        player->AddComponent<Controller>();

        auto rifle = CreateEmpty();
        auto rifleTrans = rifle->AddComponent<Transform>();
        rifleTrans->position = { 0, 0, 0 };
        rifleTrans->backword = rifleTrans->Forward();
        rifle->AddComponent<MeshFilter>()->mesh = mesh1;
        rifle->AddComponent<Renderer>()->shader = shader;
        rifle->GetComponent<Renderer>()->material = material1;
        rifle->AddComponent<Attach>()->target = player;
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

                cube->AddComponent<MeshFilter>()->mesh = (!i && !j && !k) ? mesh : mesh;
                cube->AddComponent<Renderer>()->shader = shader;
                cube->GetComponent<Renderer>()->material = material;
                cube->AddComponent<RotatingBehavior>();
            }
}

