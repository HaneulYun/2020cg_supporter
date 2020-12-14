#include "pch.h"
#include "GameScene.h"
#include "scripts.h"

GameScene::GameScene()
{
    shader = new Shader();
    shader->LoadShaders("Shaders/vs.vs", "Shaders/fs.fs");
}

void GameScene::BuildObject()
{
    Material* robotMa = new Material();
    {
        robotMa->LoadDiffuseMap("Models/DefaultMaterial_Base_Color.dds");
        robotMa->LoadNormalMap("Models/DefaultMaterial_Normal.dds");
    }

    Material* rifleMa = new Material();
    {
        rifleMa->LoadDiffuseMap("Models/rifle_Base_Color.dds");
        rifleMa->LoadNormalMap("Models/rifle_005005005_Normal.dds");
    }


    Mesh* mesh = new Mesh();
    mesh->ReadObj("Models/blue_robot.obj");
    mesh->Init();

    Mesh* rifleMesh = new Mesh();
    rifleMesh->ReadObj("Models/rifle.obj");
    rifleMesh->Init();

    {
        auto rifle = CreateEmpty();
        auto rifleTrans = rifle->AddComponent<Transform>();
        rifleTrans->position = { 0, 0, 0 };
        rifleTrans->backword = rifleTrans->Forward();
        rifle->AddComponent<MeshFilter>()->mesh = rifleMesh;
        rifle->AddComponent<Renderer>()->shader = shader;
        rifle->GetComponent<Renderer>()->material = rifleMa;

        auto player = CreateEmpty();
        player->AddComponent<Transform>()->position = { 0, 2, 3 };
        player->AddComponent<FirstPersonCamera>();
        camera = player->AddComponent<Camera>();
        player->AddComponent<Renderer>()->shader = shader;
        player->AddComponent<Renderer>()->material = nullptr;
        player->AddComponent<Controller>();
        player->AddComponent<BulletGenerator>();
        player->AddComponent<Gravity>();
        player->AddChild(rifle);
    }

    BuildWall();

    for (int i = -1; i <= 1; ++i)
        for (int j = 0; j <= 2; ++j)
            for (int k = -1; k <= 1; ++k)
            {
                if (i && j && k) continue;
                auto cube = CreateEmpty();
                cube->tag = Tag::Robot;
                cube->AddComponent<Transform>()->position = { i * 10, j * 10, k * 10 };
                cube->AddComponent<MeshFilter>()->mesh = (!i && !j && !k) ? mesh : mesh;
                cube->AddComponent<Renderer>()->shader = shader;
                cube->GetComponent<Renderer>()->material = robotMa;
                cube->AddComponent<RotatingBehavior>();
            }
}

void GameScene::BuildWall()
{
    Mesh* floorMesh = new Mesh();
    floorMesh->ReadObj("Models/floor.obj");
    floorMesh->Init();

    Mesh* fence1Mesh = new Mesh();
    fence1Mesh->ReadObj("Models/fence.obj");
    fence1Mesh->Init();
    Mesh* fence2Mesh = new Mesh();
    fence2Mesh->ReadObj("Models/fence2.obj");
    fence2Mesh->Init();

    Mesh* wall1Mesh = new Mesh();
    wall1Mesh->ReadObj("Models/wall1.obj");
    wall1Mesh->Init();
    Mesh* wall2Mesh = new Mesh();
    wall2Mesh->ReadObj("Models/wall2.obj");
    wall2Mesh->Init();
    Mesh* wall3Mesh = new Mesh();
    wall3Mesh->ReadObj("Models/wall3.obj");
    wall3Mesh->Init();
    Mesh* wall4Mesh = new Mesh();
    wall4Mesh->ReadObj("Models/wall4.obj");
    wall4Mesh->Init();
    Mesh* wall5Mesh = new Mesh();
    wall5Mesh->ReadObj("Models/wall5.obj");
    wall5Mesh->Init();

    Material* floorMa = new Material();
    {
        floorMa->LoadDiffuseMap("Models/floor_Base_Color.dds");
        floorMa->LoadNormalMap("Models/floor_Normal.dds");
    }

    Material* wall13Ma = new Material();
    {
        wall13Ma->LoadDiffuseMap("Models/wall1_3_Base_Color.dds");
        wall13Ma->LoadNormalMap("Models/wall_Normal.dds");
    }
    Material* wall25Ma = new Material();
    {
        wall25Ma->LoadDiffuseMap("Models/wall2_5_Base_Color.dds");
        wall25Ma->LoadNormalMap("Models/wall_Normal.dds");
    }
    Material* wall4Ma = new Material();
    {
        wall4Ma->LoadDiffuseMap("Models/wall4_Base_Color.dds");
        wall4Ma->LoadNormalMap("Models/wall_Normal.dds");
    }

    Material* fenceMa = new Material();
    {
        fenceMa->LoadDiffuseMap("Models/fence_Base_Color.dds");
        fenceMa->LoadNormalMap("Models/fence_Normal.dds");
    }

    auto floor = CreateEmpty();
    floor->AddComponent<Transform>();
    floor->AddComponent<MeshFilter>()->mesh = floorMesh;
    floor->AddComponent<Renderer>()->shader = shader;
    floor->GetComponent<Renderer>()->material = floorMa;

    auto wall1 = CreateEmpty();
    wall1->AddComponent<Transform>();
    wall1->AddComponent<MeshFilter>()->mesh = wall1Mesh;
    wall1->AddComponent<Renderer>()->shader = shader;
    wall1->GetComponent<Renderer>()->material = wall13Ma;

    auto wall2 = CreateEmpty();
    wall2->AddComponent<Transform>();
    wall2->AddComponent<MeshFilter>()->mesh = wall2Mesh;
    wall2->AddComponent<Renderer>()->shader = shader;
    wall2->GetComponent<Renderer>()->material = wall25Ma;

    auto wall3 = CreateEmpty();
    wall3->AddComponent<Transform>();
    wall3->AddComponent<MeshFilter>()->mesh = wall3Mesh;
    wall3->AddComponent<Renderer>()->shader = shader;
    wall3->GetComponent<Renderer>()->material = wall13Ma;

    auto wall4 = CreateEmpty();
    wall4->AddComponent<Transform>();
    wall4->AddComponent<MeshFilter>()->mesh = wall4Mesh;
    wall4->AddComponent<Renderer>()->shader = shader;
    wall4->GetComponent<Renderer>()->material = wall4Ma;

    auto wall5 = CreateEmpty();
    wall5->AddComponent<Transform>();
    wall5->AddComponent<MeshFilter>()->mesh = wall5Mesh;
    wall5->AddComponent<Renderer>()->shader = shader;
    wall5->GetComponent<Renderer>()->material = wall25Ma;

    auto fence1 = CreateEmpty();
    fence1->AddComponent<Transform>();
    fence1->AddComponent<MeshFilter>()->mesh = fence1Mesh;
    fence1->AddComponent<Renderer>()->shader = shader;
    fence1->GetComponent<Renderer>()->material = fenceMa;

    auto fence2 = CreateEmpty();
    fence2->AddComponent<Transform>();
    fence2->AddComponent<MeshFilter>()->mesh = fence2Mesh;
    fence2->AddComponent<Renderer>()->shader = shader;
    fence2->GetComponent<Renderer>()->material = fenceMa;
}