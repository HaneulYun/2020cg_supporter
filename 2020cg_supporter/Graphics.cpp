#include "pch.h"
#include "Graphics.h"

void Graphics::Render(Scene* scene)
{
	for (auto& shaderAndSets : scene->renderSets)
	{
		auto shader = shaderAndSets.first ? shaderAndSets.first->shader : 0;
		auto& renderSets = shaderAndSets.second;

		glUseProgram(shader);


		GLuint projID = glGetUniformLocation(shader, "Proj");
		glUniformMatrix4fv(projID, 1, GL_FALSE, &scene->camera->proj[0][0]);

		GLuint viewID = glGetUniformLocation(shader, "View");
		glUniformMatrix4fv(viewID, 1, GL_FALSE, &scene->camera->view[0][0]);

		GLuint DiffuseTextureID = glGetUniformLocation(shader, "DiffuseTextureSampler");
		GLuint NormalTextureID = glGetUniformLocation(shader, "NormalTextureSampler");

		for (auto& meshAndSets : renderSets)
		{
			auto mesh = meshAndSets.first;
			if (!mesh) continue;
			
			auto& gameObjects = meshAndSets.second;
					

			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, mesh->verticesBuffer);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

			glEnableVertexAttribArray(1);
			glBindBuffer(GL_ARRAY_BUFFER, mesh->uvsBuffer);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
			for (auto& gameObject : gameObjects)
			{
				auto transform = gameObject->GetComponent<Transform>();
				if (!transform) continue;

				auto material = gameObject->GetComponent<Renderer>()->material;
				if (material)
				{
					glActiveTexture(GL_TEXTURE0);
					glBindTexture(GL_TEXTURE_2D, material->diffuseID);
					glUniform1i(DiffuseTextureID, 0);

					glActiveTexture(GL_TEXTURE1);
					glBindTexture(GL_TEXTURE_2D, material->normalID);
					glUniform1i(NormalTextureID, 1);
				}

				int modelID = glGetUniformLocation(shader, "Model");
				glUniformMatrix4fv(modelID, 1, GL_FALSE, &transform->locatToWorldMatrix[0][0]);

				glDrawArrays(GL_TRIANGLES, 0, mesh->vertices.size() * 3);
			}
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(0);
		}
	}
}
