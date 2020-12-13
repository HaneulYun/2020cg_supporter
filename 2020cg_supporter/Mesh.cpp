#include "pch.h"
#include "Mesh.h"

void Mesh::ReadObj(const char* _fileName)
{
    std::ifstream in(_fileName);

    if (!in.is_open())
    {
        std::cout << "ReadObj " << _fileName << " Failed." << std::endl;
        return;
    }

    vector<glm::vec3> vertices;
    vector<glm::vec3> normals;
    vector<glm::vec2> uvs;

    string tempString;
    float tempFloat, x, y, z;

    while (!in.eof())
    {
        in >> tempString;

        if (tempString.size() == 1 && tempString[0] == 'v')
        {
            in >> x >> y >> z;
            width[0] = min(width[0], x);
            width[1] = max(width[1], x);
            height[0] = min(height[0], y);
            height[1] = max(height[1], y);
            depth[0] = min(depth[0], z);
            depth[1] = max(depth[1], z);

            vertices.emplace_back(x, y, z);
        }
        else if (tempString.size() == 2 && tempString[0] == 'v' && tempString[1] == 'n')
        {
            in >> x >> y >> z;
            normals.emplace_back(x, y, z);
        }
        else if (tempString.size() == 2 && tempString[0] == 'v' && tempString[1] == 't')
        {
            in >> x >> y >> z;
            uvs.emplace_back(x, y);
        }
        else if (tempString.size() == 1 && tempString[0] == 'f')
        {
            for (int i = 0; i < 3; ++i)
            {
                in >> tempString;

                istringstream iss(tempString);

                std::getline(iss, tempString, '/');
                verticesIndices.push_back(atoi(tempString.c_str()) - 1);

                std::getline(iss, tempString, '/');
                uvsIndices.push_back(atoi(tempString.c_str()) - 1);
                
                std::getline(iss, tempString, '/');
                normalsIndices.push_back(atoi(tempString.c_str()) - 1);
            }
        }
    }

    for (unsigned int i = 0; i < verticesIndices.size(); ++i)
    {
        this->vertices.emplace_back(vertices[verticesIndices[i]]);
        auto uv = uvs[uvsIndices[i]];
        uv.y = 1 - uv.y;
        this->uvs.emplace_back(uv);
    }
}