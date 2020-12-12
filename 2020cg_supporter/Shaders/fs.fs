#version 330 core

in vec2 UV;

out vec3 color;

uniform sampler2D DiffuseTextureSampler;
uniform sampler2D NormalTextureSampler;

void main()
{
	color = texture(DiffuseTextureSampler, UV).rgb;
}