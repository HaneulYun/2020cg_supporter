#pragma once

const float INF = 987654321;

struct PackedVertex {
    glm::vec3 position;
    glm::vec2 uv;
    glm::vec3 normal;
    bool operator<(const PackedVertex that) const {
        return memcmp((void*)this, (void*)&that, sizeof(PackedVertex)) > 0;
    };
};

bool getSimilarVertexIndex_fast(
    PackedVertex& packed,
    std::map<PackedVertex, unsigned short>& VertexToOutIndex,
    unsigned short& result
) {
    std::map<PackedVertex, unsigned short>::iterator it = VertexToOutIndex.find(packed);
    if (it == VertexToOutIndex.end()) {
        return false;
    }
    else {
        result = it->second;
        return true;
    }
}

class Mesh
{
public:
    GLuint verticesBuffer;
    GLuint uvsBuffer;

    float width[2]{ INF, -INF };
    float height[2]{ INF, -INF };
    float depth[2]{ INF, -INF };

    vector<glm::vec3> vertices;
    vector<glm::vec3> normals;
    vector<glm::vec2> uvs;
    vector<GLushort> verticesIndices;
    vector<GLushort> normalsIndices;
    vector<GLushort> uvsIndices;

    void ReadObj(const char* _fileName);
    void Init()
    {
        glGenBuffers(1, &verticesBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);
        
        glGenBuffers(1, &uvsBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, uvsBuffer);
        glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), uvs.data(), GL_STATIC_DRAW);
    }

    void indexVBO(
        std::vector<glm::vec3>& in_vertices,
        std::vector<glm::vec2>& in_uvs,
        std::vector<glm::vec3>& in_normals,

        std::vector<unsigned short>& out_indices,
        std::vector<glm::vec3>& out_vertices,
        std::vector<glm::vec2>& out_uvs,
        std::vector<glm::vec3>& out_normals
    ) {
        std::map<PackedVertex, unsigned short> VertexToOutIndex;

        // For each input vertex
        for (unsigned int i = 0; i < in_vertices.size(); i++) {

            PackedVertex packed = { in_vertices[i], in_uvs[i], in_normals[i] };


            // Try to find a similar vertex in out_XXXX
            unsigned short index;
            bool found = getSimilarVertexIndex_fast(packed, VertexToOutIndex, index);

            if (found) { // A similar vertex is already in the VBO, use it instead !
                out_indices.push_back(index);
            }
            else { // If not, it needs to be added in the output data.
                out_vertices.push_back(in_vertices[i]);
                out_uvs.push_back(in_uvs[i]);
                out_normals.push_back(in_normals[i]);
                unsigned short newindex = (unsigned short)out_vertices.size() - 1;
                out_indices.push_back(newindex);
                VertexToOutIndex[packed] = newindex;
            }
        }
    }
};
