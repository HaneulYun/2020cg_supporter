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

    string tempString;
    float tempFloat;

    while (!in.eof())
    {
        in >> tempString;

        if (tempString.size() == 1 && tempString[0] == 'v')
        {
            in >> tempFloat;
            vertices.push_back(tempFloat);
            in >> tempFloat;
            vertices.push_back(tempFloat);
            in >> tempFloat;
            vertices.push_back(tempFloat);
        }
        else if (tempString.size() == 2 && tempString[0] == 'v' && tempString[1] == 'n')
        {
            in >> tempFloat;
            uvs.push_back(tempFloat);
            in >> tempFloat;
            uvs.push_back(tempFloat);
            in >> tempFloat;
            uvs.push_back(tempFloat);
        }
        else if (tempString.size() == 2 && tempString[0] == 'v' && tempString[1] == 't')
        {
            in >> tempFloat;
            textures.push_back(tempFloat);
            in >> tempFloat;
            textures.push_back(tempFloat);
            in >> tempFloat;
            textures.push_back(tempFloat);
        }
        else if (tempString.size() == 1 && tempString[0] == 'f')
        {
            for (int i = 0; i < 3; ++i)
            {
                in >> tempString;

                istringstream iss(tempString);

                std::getline(iss, tempString, '/');
                verticesIndex.push_back(atoi(tempString.c_str()) - 1);

                std::getline(iss, tempString, '/');
                texturesIndex.push_back(atoi(tempString.c_str()) - 1);

                std::getline(iss, tempString, '/');
                uvsIndex.push_back(atoi(tempString.c_str()) - 1);
            }
        }
    }
}