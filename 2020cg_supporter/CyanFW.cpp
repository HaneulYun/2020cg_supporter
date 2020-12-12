#include "pch.h"
#include "CyanFW.h"

void renderFunc()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glutSwapBuffers();
}

int CyanFW::run(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	glutDisplayFunc(renderFunc);
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
