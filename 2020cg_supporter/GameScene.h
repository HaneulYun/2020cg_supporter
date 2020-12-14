#pragma once

class GameScene : public Scene
{
public:
	GameScene();

	void BuildObject() override;

private:
	void BuildWall();

	Shader* shader = nullptr;
};
