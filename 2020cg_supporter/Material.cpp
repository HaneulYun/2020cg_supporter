#include "pch.h"
#include "Material.h"

GLuint Material::LoadDDS(const char* imagepath)
{
    unsigned char header[124];

    FILE* fp;

    /* ���� ���� �õ� */
    fp = fopen(imagepath, "rb");
    if (fp == NULL)
        return 0;

    /* ���� Ÿ�� üũ */
    char filecode[4];
    fread(filecode, 1, 4, fp);
    if (strncmp(filecode, "DDS ", 4) != 0) {
        fclose(fp);
        return 0;
    }

    /* �̹����� ������ �ܾ�ɴϴ�.  */
    fread(&header, 124, 1, fp);

    unsigned int height = *(unsigned int*)&(header[8]);
    unsigned int width = *(unsigned int*)&(header[12]);
    unsigned int linearSize = *(unsigned int*)&(header[16]);
    unsigned int mipMapCount = *(unsigned int*)&(header[24]);
    unsigned int fourCC = *(unsigned int*)&(header[80]);

    unsigned char* buffer;
    unsigned int bufsize;
    /* ��� �Ӹ��� �����ϸ� �󸶳� ũ����? */
    bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize;
    buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char));
    fread(buffer, 1, bufsize, fp);
    /* ���� ������ �ݱ�  */
    fclose(fp);

    unsigned int components = (fourCC == FOURCC_DXT1) ? 3 : 4;
    unsigned int format;
    switch (fourCC)
    {
    case FOURCC_DXT1:
        format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
        break;
    case FOURCC_DXT3:
        format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
        break;
    case FOURCC_DXT5:
        format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
        break;
    default:
        free(buffer);
        return 0;
    }

    // Create one OpenGL texture
    GLuint textureID;
    glGenTextures(1, &textureID);

    // ���Ӱ� ������ �ؽ�ó�� "Bind"�մϴ�. : ���� ������ ��� Texutre ���� �Լ��� �� ģ���� �ǵ�ϴ�. 
    glBindTexture(GL_TEXTURE_2D, textureID);

    unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;
    unsigned int offset = 0;

    /* load the mipmaps */
    for (unsigned int level = 0; level < mipMapCount && (width || height); ++level)
    {
        unsigned int size = ((width + 3) / 4) * ((height + 3) / 4) * blockSize;
        glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height,
            0, size, buffer + offset);

        offset += size;
        width /= 2;
        height /= 2;
    }
    free(buffer);

    return textureID;
}

void Material::LoadDiffuseMap(const char* imagepath)
{
    diffuseID = LoadDDS(imagepath);
}

void Material::LoadNormalMap(const char* imagepath)
{
    normalID = LoadDDS(imagepath);
}
