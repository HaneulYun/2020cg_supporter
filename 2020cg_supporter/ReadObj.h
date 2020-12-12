#pragma once

void ReadObj(const char* _fileName,
    vector<float>& _vertecies,
    vector<float>& _uvs,
    vector<float>& _textures,
    vector<float>& _verteciesIndex,
    vector<float>& _uvsIndex,
    vector<float>& _texturesIndex)
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
            _vertecies.push_back(tempFloat);
            in >> tempFloat;
            _vertecies.push_back(tempFloat);
            in >> tempFloat;
            _vertecies.push_back(tempFloat);
        }
        else if (tempString.size() == 2 && tempString[0] == 'v' && tempString[1] == 'n')
        {
            in >> tempFloat;
            _uvs.push_back(tempFloat);
            in >> tempFloat;
            _uvs.push_back(tempFloat);
            in >> tempFloat;
            _uvs.push_back(tempFloat);
        }
        else if (tempString.size() == 2 && tempString[0] == 'v' && tempString[1] == 't')
        {
            in >> tempFloat;
            _textures.push_back(tempFloat);
            in >> tempFloat;
            _textures.push_back(tempFloat);
            in >> tempFloat;
            _textures.push_back(tempFloat);
        }
        else if (tempString.size() == 1 && tempString[0] == 'f')
        {
            for (int i = 0; i < 3; ++i)
            {
                in >> tempString;

                istringstream iss(tempString);

                std::getline(iss, tempString, '/');
                _verteciesIndex.push_back(atoi(tempString.c_str()) - 1);

                std::getline(iss, tempString, '/');
                _texturesIndex.push_back(atoi(tempString.c_str()) - 1);

                std::getline(iss, tempString, '/');
                _uvsIndex.push_back(atoi(tempString.c_str()) - 1);
            }
        }
    }
}
