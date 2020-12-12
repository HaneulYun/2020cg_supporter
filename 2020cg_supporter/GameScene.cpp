#include "pch.h"
#include "GameScene.h"

void GameScene::BuildObject()
{
	Shader* shader = nullptr;// new Shader();
	Mesh* mesh0 = new Mesh();
	Mesh* mesh1 = new Mesh();

	{
		mesh0->vertices = {
			-1.0f, -1.0f, 0.0f,
			0.0f, -1.0f, 0.0f,
			-1.0f, 0.0f, 0.0f,
		};

		auto cube = CreateEmpty();
		cube->AddComponent<MeshFilter>()->mesh = mesh0;
		cube->AddComponent<Renderer>()->shader = shader;
	}

	{
		mesh1->vertices = {
			1.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
		};

		auto cube = CreateEmpty();
		cube->AddComponent<MeshFilter>()->mesh = mesh1;
		cube->AddComponent<Renderer>()->shader = shader;
	}
}
