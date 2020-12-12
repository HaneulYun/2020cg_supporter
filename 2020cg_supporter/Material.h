#pragma once

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

class Material
{
public:
	GLuint diffuseID;
	GLuint normalID;

public:
	GLuint LoadDDS(const char*);
	
	void LoadDiffuseMap(const char*);
	void LoadNormalMap(const char*);
};
