#include "pch.h"
#include "CyanFW.h"
#include "GameScene.h"
#include "ReadObj.h"

Scene* CyanFW::scene = nullptr;
Graphics* CyanFW::graphics = nullptr;

vector<float> vertecies;
vector<float> uvs;
vector<float> textures;
vector<float> verteciesIndex;
vector<float> uvsIndex;
vector<float> texturesIndex;

GLuint vao, vbo[3], ebo[3];

int CyanFW::Run(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("게임이름 뭘로할까");

	if (glewInit() != GLEW_OK) {
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else std::cout << "GLEW Initialized\n";

	scene = new GameScene();
	scene->BuildObject();

	ReadObj("robot2.obj", vertecies, uvs, textures, verteciesIndex, uvsIndex, texturesIndex);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(3, vbo);
	glGenBuffers(3, ebo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, vertecies.size() * sizeof(float) * 3, vertecies.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, verteciesIndex.size() * sizeof(int), verteciesIndex.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
	glEnableVertexAttribArray(0);

	//glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	//glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(float) * 3, uvs.data(), GL_STATIC_DRAW);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[1]);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, uvsIndex.size() * sizeof(int), uvsIndex.data(), GL_STATIC_DRAW);
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
	//glEnableVertexAttribArray(1);

	//glBindBuffer(GL_ARRAY_BUFFER, vbo[2]);
	//glBufferData(GL_ARRAY_BUFFER, textures.size() * sizeof(float) * 3, textures.data(), GL_STATIC_DRAW);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo[2]);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, texturesIndex.size() * sizeof(int), texturesIndex.data(), GL_STATIC_DRAW);
	//glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
	//glEnableVertexAttribArray(2);

	glutDisplayFunc(Update);
	glutIdleFunc(Update);
	
	glutMouseFunc(MouseInput);
	glutKeyboardFunc(KeyInput);
	glutKeyboardUpFunc(KeyUpInput);
	glutSpecialFunc(SpecialKeyInput);
	glutSpecialUpFunc(SpecialKeyUpInput);

	glutMainLoop();

	return 0;
}

void CyanFW::Update()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	Time::Instance()->Update();

	scene->Update();
	graphics->Render(scene);

	Input::Instance()->Update();

	static vector<float> vertices{
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
	};



	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, vertecies.size() * sizeof(float), GL_UNSIGNED_INT, 0);

	glutSwapBuffers();
}
