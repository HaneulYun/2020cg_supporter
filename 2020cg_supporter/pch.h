#ifndef PCH_H
#define PCH_H

// 여기에 미리 컴파일하려는 헤더 추가
#include "Dependencies/glew.h"
#include "Dependencies/freeglut.h"
#include "Dependencies/glm/glm.hpp"
#include "Dependencies/glm/gtx/transform.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <unordered_map>
using namespace std;

#include "Singleton.h"
#include "Input.h"

#include "Component.h"

#include "Transform.h"
#include "Camera.h"

#include "Mesh.h"
#include "MeshFilter.h"

#include "Shader.h"
#include "Renderer.h"

#include "GameObject.h"
#include "Scene.h"

#include "Graphics.h"

#include "CyanFW.h"

#endif
