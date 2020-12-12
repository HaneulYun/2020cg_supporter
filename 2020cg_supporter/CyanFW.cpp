#include "pch.h"
#include "CyanFW.h"
#include "GameScene.h"
#include "ReadObj.h"

Scene* CyanFW::scene = nullptr;
Graphics* CyanFW::graphics = nullptr;

int CyanFW::Run(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("BootCamp");

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

	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LESS);

	glutMainLoop();

	return 0;
}

void CyanFW::Update()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Time::Instance()->Update();

	scene->Update();
	graphics->Render(scene);

	glutSwapBuffers();
}
