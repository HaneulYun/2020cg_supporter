#include "pch.h"
#include "Graphics.h"

void Graphics::Render(Scene* scene)
{
	for (auto& shaderAndSets : scene->renderSets)
	{
		auto shader = shaderAndSets.first ? shaderAndSets.first->shader : 0;
		auto& renderSets = shaderAndSets.second;

		glUseProgram(shader);

		for (auto& meshAndSets : renderSets)
		{
			auto mesh = meshAndSets.first;
			if (!mesh) continue;
			
			auto& gameObjects = meshAndSets.second;

			int attribPosition = glGetAttribLocation(shader, "a_Position");
			glEnableVertexAttribArray(attribPosition);
			//glBindBuffer(GL_ARRAY_BUFFER, m_VBORect);
			glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);



			glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)500 / (float)500, 0.1f, 100.0f);

			//Ȥ�� ortho(����) ī�޶󿡼� :
			//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // ���� ��ǥ�� ǥ��

			// ī�޶� ��Ʈ����
			glm::mat4 View = glm::lookAt(
				glm::vec3(4, 3, 3), // ī�޶�� (4,3,3) �� �ִ�. ���� ��ǥ����
				glm::vec3(0, 0, 0), // �׸��� ī�޶� ������ ����
				glm::vec3(0, 1, 0)  // �Ӹ��� �����̴� (0,-1,0 ���� �غ���, ������ �����̴�)
			);

			// �� ��Ʈ���� : ���� ��Ʈ���� (���� ������ ��ġ�ȴ�)
			glm::mat4 Model = glm::mat4(1.0f);
			// �츮�� �𵨺��������� : 3�� ��Ʈ�������� ���Ѵ�
			glm::mat4 mvp = Projection * View * Model;

			int mvpID = glGetUniformLocation(shader, "MVP");
			glUniformMatrix4fv(mvpID, 1, GL_FALSE, &mvp[0][0]);



			GLuint vertexbuffer;
			glGenBuffers(1, &vertexbuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * 4, mesh->vertices.data(), GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
			for (auto& gameObject : gameObjects)
			{
				//glUniform3f(uTrans, pos.x, pos.y, pos.z);
				//glUniform3f(uScale, size.x * 250, size.y * 250, size.z * 250);
				//glUniform4f(uColor, color.r, color.g, color.b, 1);
				//glUniform1f(uDepth, (pos.y + m_WindowSizeY / 2.f) / m_WindowSizeY);
				//glUniformMatrix4fv(uProjView, 1, GL_FALSE, &m_m4ProjView[0][0]);
				//glUniformMatrix4fv(uRotToCam, 1, GL_FALSE, &m_m4Model[0][0]);

				glDrawArrays(GL_TRIANGLES, 0, 3);
			}
			glDisableVertexAttribArray(0);
		}
	}
}
