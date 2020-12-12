#include "pch.h"
#include "Graphics.h"

void Graphics::Render(Scene* scene)
{
	for (auto& shaderAndSets : scene->renderSets)
	{
		auto shader = shaderAndSets.first ? shaderAndSets.first->shader : 0;
		auto& renderSets = shaderAndSets.second;

		glUseProgram(shader);

		glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)500 / (float)500, 0.1f, 100.0f);
		int projID = glGetUniformLocation(shader, "Proj");
		glUniformMatrix4fv(projID, 1, GL_FALSE, &Projection[0][0]);
		//혹은 ortho(직교) 카메라에선 :
		//glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // 월드 좌표로 표현

		glm::mat4 View = glm::lookAt(
			glm::vec3(4, 3, 3), // 카메라는 (4,3,3) 에 있다. 월드 좌표에서
			glm::vec3(0, 0, 0), // 그리고 카메라가 원점을 본다
			glm::vec3(0, 1, 0)  // 머리가 위쪽이다 (0,-1,0 으로 해보면, 뒤집어 볼것이다)
		);
		int viewID = glGetUniformLocation(shader, "View");
		glUniformMatrix4fv(viewID, 1, GL_FALSE, &View[0][0]);

		for (auto& meshAndSets : renderSets)
		{
			auto mesh = meshAndSets.first;
			if (!mesh) continue;
			
			auto& gameObjects = meshAndSets.second;

			int attribPosition = glGetAttribLocation(shader, "a_Position");
			glEnableVertexAttribArray(attribPosition);
			//glBindBuffer(GL_ARRAY_BUFFER, m_VBORect);
			glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

			GLuint vertexbuffer;
			glGenBuffers(1, &vertexbuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * 4, mesh->vertices.data(), GL_STATIC_DRAW);

			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
			for (auto& gameObject : gameObjects)
			{
				glm::mat4 Model = glm::mat4(1.0f);
				int modelID = glGetUniformLocation(shader, "Model");
				glUniformMatrix4fv(modelID, 1, GL_FALSE, &Model[0][0]);

				glDrawArrays(GL_TRIANGLES, 0, 3);
			}
			glDisableVertexAttribArray(0);
		}
	}
}
