#include "pch.h"
#include "CyanFW.h"

Scene* CyanFW::scene = nullptr;
Graphics* CyanFW::graphics = nullptr;

int CyanFW::Run(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("게임이름 뭘로할까");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	scene = new Scene();

	glutDisplayFunc(Update);
	//glutIdleFunc(Idle);
	//
	//glutKeyboardFunc(KeyInput);
	//glutKeyboardUpFunc(KeyUpInput);
	//glutSpecialFunc(SpecialKeyInput);
	//glutSpecialUpFunc(SpecialKeyUpInput);
	//glutKeyboardUpFunc(KeyUpInput);
	//
	//glutMouseFunc(MouseInput);

	glutMainLoop();

	return 0;
}

void CyanFW::Update()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	scene->Update();
	graphics->Render();

	glutSwapBuffers();
}
