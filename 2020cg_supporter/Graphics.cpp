#include "pch.h"
#include "Graphics.h"

void Graphics::Render(Scene* scene)
{
	for (auto& shaderAndSets : scene->renderSets)
	{
		auto shader = shaderAndSets.first->shader;
		auto& renderSets = shaderAndSets.second;

		glUseProgram(shader);

		for (auto& meshAndSets : renderSets)
		{
			auto mesh = meshAndSets.first;
			auto& gameObjects = meshAndSets.second;

			int attribPosition = glGetAttribLocation(shader, "a_Position");
			glEnableVertexAttribArray(attribPosition);
			//glBindBuffer(GL_ARRAY_BUFFER, m_VBORect);
			glVertexAttribPointer(attribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, 0);

			for (auto& gameObject : gameObjects)
			{
				//glUniform3f(uTrans, pos.x, pos.y, pos.z);
				//glUniform3f(uScale, size.x * 250, size.y * 250, size.z * 250);
				//glUniform4f(uColor, color.r, color.g, color.b, 1);
				//glUniform1f(uDepth, (pos.y + m_WindowSizeY / 2.f) / m_WindowSizeY);
				//glUniformMatrix4fv(uProjView, 1, GL_FALSE, &m_m4ProjView[0][0]);
				//glUniformMatrix4fv(uRotToCam, 1, GL_FALSE, &m_m4Model[0][0]);
			}
		}
	}
}
