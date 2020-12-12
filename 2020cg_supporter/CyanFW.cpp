#include "pch.h"
#include "CyanFW.h"
#include "GameScene.h"

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

	scene = new GameScene();
	scene->BuildObject();

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
	graphics->Render(scene);

	static vector<float> vertices {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * 4, vertices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);

	glutSwapBuffers();
}
