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

    Mesh* floorMesh = new Mesh();
    floorMesh->ReadObj("Models/floor.obj");
    floorMesh->Init();

    Mesh* mesh = new Mesh();
    mesh->ReadObj("Models/blue_robot.obj");
    mesh->Init();

    Mesh* rifleMesh = new Mesh();
    rifleMesh->ReadObj("Models/rifle.obj");
    rifleMesh->Init();


    {
        auto floor = CreateEmpty();
        auto floorTrans = floor->AddComponent<Transform>();
        floorTrans->Scale(glm::vec3(2, 0, 2));
        floor->AddComponent<MeshFilter>()->mesh = floorMesh;
        floor->AddComponent<Renderer>()->shader = shader;
        floor->GetComponent<Renderer>()->material = nullptr;
        floor->AddComponent<Log>();

        auto player = CreateEmpty();
        player->AddComponent<Transform>()->position = { 0, 0, 3 };
        player->AddComponent<FirstPersonCamera>();
        camera = player->AddComponent<Camera>();
        player->AddComponent<Renderer>()->shader = shader;
        player->AddComponent<Renderer>()->material = nullptr;
        player->AddComponent<Controller>();
        player->AddComponent<BulletGenerator>();
        player->AddComponent<Gravity>();

        auto rifle = CreateEmpty();
        auto rifleTrans = rifle->AddComponent<Transform>();
        rifleTrans->position = { 0, 0, 0 };
        rifleTrans->backword = rifleTrans->Forward();
        rifle->AddComponent<MeshFilter>()->mesh = rifleMesh;
        rifle->AddComponent<Renderer>()->shader = shader;
        rifle->GetComponent<Renderer>()->material = material1;
    }

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

