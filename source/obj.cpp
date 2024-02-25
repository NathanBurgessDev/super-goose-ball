#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>

#include "obj.hpp"

ObjModel::ObjModel(std::string &obj)
{
    auto f = std::istringstream{obj};
    std::string line;

    while (std::getline(f, line))
    {
        auto firstSpace = line.find(' ');

        // If we don't find the first space, stop
        if (firstSpace == std::string::npos)
        {
            throw "Didn't find first space :(";
        }

        auto type = line.substr(0, firstSpace);

        if (strcmp(type.c_str(), "#") == 0 || strcmp(type.c_str(), "o") == 0 || strcmp(type.c_str(), "s") == 0)
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
                int matches = sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
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

int ObjModel::triple32(int x)
{
    x ^= x >> 17;
    x *= 0xed5ad4bbU;
    x ^= x >> 11;
    x *= 0xac4c1b51U;
    x ^= x >> 15;
    x *= 0x31848babU;
    x ^= x >> 14;
    return x;
}

int ObjModel::lowbias32(int  x)
{
    x ^= x >> 16;
    x *= 0x7feb352dU;
    x ^= x >> 15;
    x *= 0x846ca68bU;
    x ^= x >> 16;
    return x;
}


int ObjModel::drawModel(float a)
{
    GRRLIB_3dMode(0.1,1000,45,0,0);
    u32 col = lowbias32(0x000000FF);
    GRRLIB_ObjectViewBegin();
    GRRLIB_ObjectViewTrans(5.0f,-2.5f,0);
    GRRLIB_ObjectViewScale(1,1,1);
    // GRRLIB_ObjectViewRotate(a,a+1,a+2);
    GRRLIB_ObjectViewEnd();

    // GRRLIB_3dMode(0.1, 1000, 90, 0, 1);
    // GRRLIB_ObjectView(0, 0, 0, 0, 0, 0, 1, 1, 1);
    for (int i = 0; i < vertexIndices.size() - 3 ; i+=3)
    {
        GX_Begin(GX_TRIANGLES, GX_VTXFMT0, 3);
        unsigned int vertexIndex0 = vertexIndices[i];
        unsigned int vertexIndex1 = vertexIndices[i+1];
        unsigned int vertexIndex2 = vertexIndices[i+2];


        // unsigned int normalIndex0 = normalIndices[i];
        // unsigned int normalIndex1 = normalIndices[i+1];
        // unsigned int normalIndex2 = normalIndices[i+2];

        guVector vertex0 = verticies[vertexIndex0 - 1];
        guVector vertex1 = verticies[vertexIndex1 - 1 ];
        guVector vertex2 = verticies[vertexIndex2 - 1];
        

        // guVector normal0 = normals[normalIndex0 - 1];
        // guVector normal1 = normals[normalIndex1 - 1];
        // guVector normal2 = normals[normalIndex2 - 1];


        // UV uv = uvs[uvIndices[vertexIndex - 1];

        GX_Position3f32(vertex0.x, vertex0.y, vertex0.z);
        // GX_Normal3f32(normal0.x, normal0.y, normal0.z);
        col  = lowbias32(col) | 0xFF0000A0;
        GX_Color1u32(col );

        GX_Position3f32(vertex1.x, vertex1.y, vertex1.z);
        // GX_Normal3f32(normal1.x, normal1.y, normal1.z);
        col  = lowbias32(col) | 0xFF0000A0;
        GX_Color1u32(col );

        GX_Position3f32(vertex2.x, vertex2.y, vertex2.z);
        // GX_Normal3f32(normal2.x, normal2.y, normal2.z);
        col  = lowbias32(col) | 0xFF0000A0;
        GX_Color1u32(col );

        // GX_TexCoord2f32(uv.u, uv.v);
    }

    GX_End();

    return 0;
}


