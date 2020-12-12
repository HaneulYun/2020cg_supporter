﻿#ifndef PCH_H
#define PCH_H

// 여기에 미리 컴파일하려는 헤더 추가
#include "Dependencies/glew.h"
#include "Dependencies/freeglut.h"
#include "Dependencies/glm/glm.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <map>
using namespace std;


#include "Component.h"
#include "Camera.h"

#include "Mesh.h"
#include "MeshFilter.h"

#include "GameObject.h"
#include "Scene.h"

#include "Shader.h"

#include "Graphics.h"

#include "CyanFW.h"

#endif
