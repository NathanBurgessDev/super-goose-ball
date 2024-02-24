#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

#include "obj.hpp"

ObjModel::ObjModel(std::string& obj)
{
    auto ss = std::stringstream{obj};

    for (std::string line; std::getline(ss, obj, '\n');)
    {
        auto firstSpace = line.find(' ');

        // If we don't find the first space, stop
        if (firstSpace == std::string::npos)
        {
            throw "Didn't find first space :(";
        }

        auto type = line.substr(0, firstSpace);

        if (type == "#" || type == "o" || type == "s")
        {
            continue;
        }
        else if (type == "v")
        {
            float x, y, z;

            if (sscanf(line.c_str(), "v %f %f %f", &x, &y, &z) != 3)
            {
                throw "Failed to parse v type";
            }

            this->verticies.push_back((guVector){x, y, z});
        }
        else if (type == "vn")
        {
            float x, y, z;

            if (sscanf(line.c_str(), "vn %f %f %f", &x, &y, &z) != 3)
            {
                throw "Failed to parse vn type";
            }

            this->normals.push_back((guVector){x, y, z});
        }
        else if (type == "vt")
        {
            float u, v;

            if (sscanf(line.c_str(), "vt %f %f", &u, &v) != 2)
            {
                throw "Failed to parse vt type";
            }

            this->uvs.push_back(UV{u, v});
        }
        else if (type == "f")
        {
            {
                std::string vertex1, vertex2, vertex3;
                unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                int matches = sscanf(line.c_str(), "%d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
                if (matches != 9)
                {
                    throw "Failed to parse f type";
                }
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                uvIndices.push_back(uvIndex[0]);
                uvIndices.push_back(uvIndex[1]);
                uvIndices.push_back(uvIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);
            }
        }
    }
}

int ObjModel::drawModel(){
    GX_Begin(GX_TRIANGLES, GX_VTXFMT0, 3 * vertexIndices.size());

    GRRLIB_3dMode(0.1,1000,45,0,0);
    GRRLIB_ObjectView(0,0,0, 0,0,0,1,1,1);
    for (int i = 0; i < vertexIndices.size(); i++)
    {
        guVector vertex = verticies[vertexIndices[i]];
        guVector normal = normals[normalIndices[i]];
        UV uv = uvs[uvIndices[i]];

        GX_Position3f32(vertex.x, vertex.y, vertex.z);
        // GX_Normal3f32(normal.x, normal.y, normal.z);
        GX_Color1u32(0xFFFFFFFF);
        // GX_TexCoord2f32(uv.u, uv.v);
    }


    GX_End();

    return 0;
}