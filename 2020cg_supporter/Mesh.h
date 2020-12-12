#pragma once

class Mesh
{
public:
    vector<float> vertices;
    vector<float> uvs;
    vector<float> textures;
    vector<int> verticesIndex;
    vector<int> uvsIndex;
    vector<int> texturesIndex;

    void ReadObj(const char* _fileName);

};
