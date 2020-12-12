#include "pch.h"
#include "Graphics.h"

void Graphics::Render(Scene* scene)
{
	for (auto& shaderAndSets : scene->renderSets)
	{
		auto shader = shaderAndSets.first ? shaderAndSets.first->shader : 0;
		auto& renderSets = shaderAndSets.second;

		glUseProgram(shader);


		int projID = glGetUniformLocation(shader, "Proj");
		glUniformMatrix4fv(projID, 1, GL_FALSE, &scene->camera->proj[0][0]);

		int viewID = glGetUniformLocation(shader, "View");
		glUniformMatrix4fv(viewID, 1, GL_FALSE, &scene->camera->view[0][0]);

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
			glGenBuffers(3, &vertexbuffer);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glBufferData(GL_ARRAY_BUFFER, mesh->vertices.size() * 4, mesh->vertices.data(), GL_STATIC_DRAW);

			GLuint elementbuffer;
			glGenBuffers(1, &elementbuffer);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh->verticesIndex.size() * sizeof(int), mesh->verticesIndex.data(), GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3, (void*)0);
			for (auto& gameObject : gameObjects)
			{
				auto transform = gameObject->GetComponent<Transform>();
				if (!transform) continue;

				int modelID = glGetUniformLocation(shader, "Model");
				glUniformMatrix4fv(modelID, 1, GL_FALSE, &transform->locatToWorldMatrix[0][0]);

				glDrawElements(GL_TRIANGLES, mesh->verticesIndex.size(), GL_INT, 0);
			}
			glDisableVertexAttribArray(0);
		}
	}
}
