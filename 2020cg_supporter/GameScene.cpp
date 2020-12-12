#include "pch.h"
#include "GameScene.h"

void GameScene::BuildObject()
{
	Shader* shader = nullptr;// new Shader();
	Mesh* tri = new Mesh();

	auto cube = CreateEmpty();
	cube->AddComponent<MeshFilter>()->mesh = tri;
	cube->AddComponent<Renderer>()->shader = shader;
}
