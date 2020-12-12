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
	glutCreateWindow("�����̸� �����ұ�");

	if (glewInit() != GLEW_OK) {
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else std::cout << "GLEW Initialized\n";

	scene = new GameScene();
	scene->BuildObject();

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

	glutSwapBuffers();
}
