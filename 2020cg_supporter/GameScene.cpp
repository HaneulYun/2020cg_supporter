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
	Material* rifleMa = new Material();
	{
		rifleMa->LoadDiffuseMap("Models/rifle_Base_Color.dds");
		rifleMa->LoadNormalMap("Models/rifle_005005005_Normal.dds");
	}

	Mesh* robotMesh = new Mesh();
	robotMesh->ReadObj("Models/blue_robot.obj");
	robotMesh->Init();

	Mesh* box1 = new Mesh();
	box1->ReadObj("Models/box.obj");
	box1->Init();

	Mesh* box2 = new Mesh();
	box2->ReadObj("Models/box2.obj");
	box2->Init();

	Mesh* rifleMesh = new Mesh();
	rifleMesh->ReadObj("Models/rifle.obj");
	rifleMesh->Init();

	{
		auto box = CreateEmpty();
		box->AddComponent<Transform>();
		box->AddComponent<MeshFilter>()->mesh = rifleMesh;
		box->AddComponent<Renderer>()->shader = shader;
		box->GetComponent<Renderer>()->material = rifleMa;
		box->AddComponent<BulletGenerator>();
	}

	{
		auto rifle = CreateEmpty();
		auto rifleTrans = rifle->AddComponent<Transform>();
		rifleTrans->position = { 0.5, -0.7, -0.3 };
		rifle->AddComponent<MeshFilter>()->mesh = rifleMesh;
		rifle->AddComponent<Renderer>()->shader = shader;
		rifle->GetComponent<Renderer>()->material = rifleMa;
		rifle->AddComponent<BulletGenerator>();

		auto player = CreateEmpty();
		player->AddComponent<Transform>()->position = { 50, 2, -10 };
		player->AddComponent<FirstPersonCamera>();
		camera = player->AddComponent<Camera>();
		player->AddComponent<Renderer>()->shader = shader;
		player->AddComponent<Renderer>()->material = nullptr;
		player->AddComponent<BoundingBox>()->SetBoundingBox(glm::vec3(-0.5, 0.1, -0.5), glm::vec3(0.5, 1, 0.5));
		player->AddComponent<Controller>();
		player->AddComponent<Collider<Controller>>()->eventfunc = &Controller::OnCollision;
		player->AddComponent<Gravity>();
		player->AddChild(rifle);
	}

	auto mesh = new Mesh();
	mesh->ReadObj("Models/bullet.obj");
	mesh->Init();

	Material* material2 = new Material();
	material2->LoadDiffuseMap("Models/Bullet_Base_Coler.dds");

	BuildWall();

	for (int i = 0; i < 5; ++i)
	{
		auto robot = CreateEmpty();
		robot->tag = Tag::Robot;
		robot->AddComponent<Transform>()->position = { 60, 0, -i * 5.0f - 1.5f };
		robot->AddComponent<MeshFilter>()->mesh = robotMesh;
		robot->AddComponent<Renderer>()->shader = shader;
		robot->GetComponent<Renderer>()->material = nullptr;
		robot->AddComponent<RotatingBehavior>();
		robot->AddComponent<Robot>();
		robot->AddComponent<BoundingBox>();
		robot->AddComponent<Collider<Robot>>()->eventfunc = &Robot::OnCollision;
	}

	{
		auto robot = CreateEmpty();
		robot->tag = Tag::Robot;
		robot->AddComponent<Transform>()->position = { 1, 0, 1 };
		robot->AddComponent<MeshFilter>()->mesh = robotMesh;
		robot->AddComponent<Renderer>()->shader = shader;
		robot->GetComponent<Renderer>()->material = nullptr;
		robot->AddComponent<RotatingBehavior>();
		robot->AddComponent<Robot>();
		robot->AddComponent<BoundingBox>();
		robot->AddComponent<Collider<Robot>>()->eventfunc = &Robot::OnCollision;
	}
	{
		auto robot = CreateEmpty();
		robot->tag = Tag::Robot;
		robot->AddComponent<Transform>()->position = { -40, 0, 15 };
		robot->AddComponent<MeshFilter>()->mesh = robotMesh;
		robot->AddComponent<Renderer>()->shader = shader;
		robot->GetComponent<Renderer>()->material = nullptr;
		robot->AddComponent<RotatingBehavior>();
		robot->AddComponent<Robot>();
		robot->AddComponent<BoundingBox>();
		robot->AddComponent<Collider<Robot>>()->eventfunc = &Robot::OnCollision;
	}
}

void GameScene::BuildWall()
{
	Mesh* floorMesh = new Mesh();
	floorMesh->ReadObj("Models/floor.obj");
	floorMesh->Init();

	Mesh* cillingMesh = new Mesh();
	cillingMesh->ReadObj("Models/cilling.obj");
	cillingMesh->Init();

	Mesh* room1Mesh = new Mesh();
	room1Mesh->ReadObj("Models/room1.obj");
	room1Mesh->Init();

	Mesh* room21Mesh = new Mesh();
	room21Mesh->ReadObj("Models/room2_1.obj");
	room21Mesh->Init();
	Mesh* room22Mesh = new Mesh();
	room22Mesh->ReadObj("Models/room2_2.obj");
	room22Mesh->Init();
	Mesh* room23Mesh = new Mesh();
	room23Mesh->ReadObj("Models/room2_3.obj");
	room23Mesh->Init();
	Mesh* room24Mesh = new Mesh();
	room24Mesh->ReadObj("Models/room2-4.obj");
	room24Mesh->Init();

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
	Mesh* wall6Mesh = new Mesh();
	wall6Mesh->ReadObj("Models/wall6.obj");
	wall6Mesh->Init();
	Mesh* wall7Mesh = new Mesh();
	wall7Mesh->ReadObj("Models/wall7.obj");
	wall7Mesh->Init();
	Mesh* wall8Mesh = new Mesh();
	wall8Mesh->ReadObj("Models/wall8.obj");
	wall8Mesh->Init();
	Mesh* wallnMesh = new Mesh();
	wallnMesh->ReadObj("Models/no_wall.obj");
	wallnMesh->Init();

	Material* floorMa = new Material();
	{
		floorMa->LoadDiffuseMap("Models/floor_Base_Color.dds");
		floorMa->LoadNormalMap("Models/floor_Normal.dds");
	}

	Material* cillingMa = new Material();
	{
		cillingMa->LoadDiffuseMap("Models/cilling_Base_Color.dds");
		cillingMa->LoadNormalMap("Models/wall_Normal.dds");
	}

	Material* room1Ma = new Material();
	{
		room1Ma->LoadDiffuseMap("Models/room1.dds");
		room1Ma->LoadNormalMap("Models/wall_Normal.dds");
	}

	Material* room21Ma = new Material();
	{
		room21Ma->LoadDiffuseMap("Models/room2_1_Base_Color.dds");
		room21Ma->LoadNormalMap("Models/room2_1_2_Normal.dds");
	}
	Material* room22Ma = new Material();
	{
		room22Ma->LoadDiffuseMap("Models/room2_2_Base_Color.dds");
		room22Ma->LoadNormalMap("Models/room2_1_2_Normal.dds");
	}
	Material* room23Ma = new Material();
	{
		room23Ma->LoadDiffuseMap("Models/room2_3_Base_Color.dds");
		room23Ma->LoadNormalMap("Models/room2_3_Normal.dds");
	}
	Material* room24Ma = new Material();
	{
		room24Ma->LoadDiffuseMap("Models/room2_4_Base_Color.dds");
		room24Ma->LoadNormalMap("Models/room2_4_Default_Normal.dds");
	}

	Material* wall134Ma = new Material();
	{
		wall134Ma->LoadDiffuseMap("Models/wall1_3_4_Base_Color.dds");
		wall134Ma->LoadNormalMap("Models/wall_Normal.dds");
	}
	Material* wall25Ma = new Material();
	{
		wall25Ma->LoadDiffuseMap("Models/wall2_5_Base_Color.dds");
		wall25Ma->LoadNormalMap("Models/wall_Normal.dds");
	}
	Material* wall678n = new Material();
	{
		wall678n->LoadDiffuseMap("Models/wall678ndiff.dds");
		wall678n->LoadNormalMap("Models/wall_Normal.dds");
	}

	Material* fenceMa = new Material();
	{
		fenceMa->LoadDiffuseMap("Models/fence_Base_Color.dds");
		fenceMa->LoadNormalMap("Models/fence_Normal.dds");
	}

	//Wall object
	{
		auto floor = CreateEmpty();
		floor->tag = Tag::Wall;
		floor->AddComponent<Transform>();
		floor->AddComponent<MeshFilter>()->mesh = floorMesh;
		floor->AddComponent<BoundingBox>();
		floor->AddComponent<Renderer>()->shader = shader;
		floor->GetComponent<Renderer>()->material = floorMa;

		auto wall1 = CreateEmpty();
		wall1->tag = Tag::Wall;
		wall1->AddComponent<Transform>();
		wall1->AddComponent<MeshFilter>()->mesh = wall1Mesh;
		wall1->AddComponent<Renderer>()->shader = shader;
		wall1->GetComponent<Renderer>()->material = wall134Ma;
		wall1->AddComponent<BoundingBox>();

		auto wall2 = CreateEmpty();
		wall2->tag = Tag::Wall;
		wall2->AddComponent<Transform>();
		wall2->AddComponent<MeshFilter>()->mesh = wall2Mesh;
		wall2->AddComponent<Renderer>()->shader = shader;
		wall2->GetComponent<Renderer>()->material = wall25Ma;
		wall2->AddComponent<BoundingBox>();

		auto wall3 = CreateEmpty();
		wall3->tag = Tag::Wall;
		wall3->AddComponent<Transform>();
		wall3->AddComponent<MeshFilter>()->mesh = wall3Mesh;
		wall3->AddComponent<Renderer>()->shader = shader;
		wall3->GetComponent<Renderer>()->material = wall134Ma;
		wall3->AddComponent<BoundingBox>();

		auto wall4 = CreateEmpty();
		wall4->tag = Tag::Wall;
		wall4->AddComponent<Transform>();
		wall4->AddComponent<MeshFilter>()->mesh = wall4Mesh;
		wall4->AddComponent<Renderer>()->shader = shader;
		wall4->GetComponent<Renderer>()->material = wall134Ma;
		wall4->AddComponent<BoundingBox>();

		auto wall5 = CreateEmpty();
		wall5->tag = Tag::Wall;
		wall5->AddComponent<Transform>();
		wall5->AddComponent<MeshFilter>()->mesh = wall5Mesh;
		wall5->AddComponent<Renderer>()->shader = shader;
		wall5->GetComponent<Renderer>()->material = wall25Ma;
		wall5->AddComponent<BoundingBox>();

		auto wall6 = CreateEmpty();
		wall6->tag = Tag::Wall;
		wall6->AddComponent<Transform>();
		wall6->AddComponent<MeshFilter>()->mesh = wall6Mesh;
		wall6->AddComponent<Renderer>()->shader = shader;
		wall6->GetComponent<Renderer>()->material = wall678n;
		wall6->AddComponent<BoundingBox>();

		auto wall7 = CreateEmpty();
		wall7->tag = Tag::Wall;
		wall7->AddComponent<Transform>();
		wall7->AddComponent<MeshFilter>()->mesh = wall7Mesh;
		wall7->AddComponent<Renderer>()->shader = shader;
		wall7->GetComponent<Renderer>()->material = wall678n;
		wall7->AddComponent<BoundingBox>();

		auto wall8 = CreateEmpty();
		wall8->tag = Tag::Wall;
		wall8->AddComponent<Transform>();
		wall8->AddComponent<MeshFilter>()->mesh = wall8Mesh;
		wall8->AddComponent<Renderer>()->shader = shader;
		wall8->GetComponent<Renderer>()->material = wall678n;
		wall8->AddComponent<BoundingBox>();

		auto walln = CreateEmpty();
		walln->AddComponent<Transform>();
		walln->AddComponent<MeshFilter>()->mesh = wallnMesh;
		walln->AddComponent<Renderer>()->shader = shader;
		walln->GetComponent<Renderer>()->material = wall678n;
	}

	auto cilling = CreateEmpty();
	cilling->AddComponent<Transform>();
	cilling->AddComponent<MeshFilter>()->mesh = cillingMesh;
	cilling->AddComponent<Renderer>()->shader = shader;
	cilling->GetComponent<Renderer>()->material = cillingMa;

	auto room1 = CreateEmpty();
	room1->tag = Tag::Wall;
	room1->AddComponent<Transform>();
	room1->AddComponent<MeshFilter>()->mesh = room1Mesh;
	room1->AddComponent<Renderer>()->shader = shader;
	room1->GetComponent<Renderer>()->material = room1Ma;
	room1->AddComponent<BoundingBox>();

	auto room21 = CreateEmpty();
	room21->tag = Tag::Wall;
	room21->AddComponent<Transform>();
	room21->AddComponent<MeshFilter>()->mesh = room21Mesh;
	room21->AddComponent<Renderer>()->shader = shader;
	room21->GetComponent<Renderer>()->material = room21Ma;
	room21->AddComponent<BoundingBox>();

	auto room22 = CreateEmpty();
	room22->tag = Tag::Wall;
	room22->AddComponent<Transform>();
	room22->AddComponent<MeshFilter>()->mesh = room22Mesh;
	room22->AddComponent<Renderer>()->shader = shader;
	room22->GetComponent<Renderer>()->material = room22Ma;
	room22->AddComponent<BoundingBox>();

	auto room23 = CreateEmpty();
	room23->tag = Tag::Wall;
	room23->AddComponent<Transform>();
	room23->AddComponent<MeshFilter>()->mesh = room23Mesh;
	room23->AddComponent<Renderer>()->shader = shader;
	room23->GetComponent<Renderer>()->material = room23Ma;
	room23->AddComponent<BoundingBox>();

	auto room24 = CreateEmpty();
	room24->tag = Tag::Wall;
	room24->AddComponent<Transform>();
	room24->AddComponent<MeshFilter>()->mesh = room24Mesh;
	room24->AddComponent<Renderer>()->shader = shader;
	room24->GetComponent<Renderer>()->material = room24Ma;
	room24->AddComponent<BoundingBox>();

	
	auto fence1 = CreateEmpty();
	fence1->tag = Tag::Wall;
	fence1->AddComponent<Transform>();
	auto box1 = fence1->AddComponent<MeshFilter>()->mesh = fence1Mesh;
	fence1->AddComponent<Renderer>()->shader = shader;
	fence1->GetComponent<Renderer>()->material = fenceMa;
	fence1->AddComponent<BoundingBox>();
	box1->height[0] -= 10.0f;
	box1->height[1] += 10.0f;

	auto fence2 = CreateEmpty();
	fence2->tag = Tag::Wall;
	fence2->AddComponent<Transform>();
	auto box2 = fence2->AddComponent<MeshFilter>()->mesh = fence2Mesh;
	fence2->AddComponent<Renderer>()->shader = shader;
	fence2->GetComponent<Renderer>()->material = fenceMa;
	fence2->AddComponent<BoundingBox>();
	box2->height[0] -= 10.0f;
	box2->height[1] += 10.0f;
}