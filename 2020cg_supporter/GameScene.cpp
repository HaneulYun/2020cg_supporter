#include "pch.h"
#include "GameScene.h"

void GameScene::BuildObject()
{
	Mesh* tri = new Mesh();

	auto cube = CreateEmpty();
	cube->AddComponent<MeshFilter>()->mesh = tri;
}
