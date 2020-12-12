#pragma once

class Shader
{
public:
	GLuint shader;

	void LoadShaders(const char* vertex_file_path, const char* fragment_file_path);
};
