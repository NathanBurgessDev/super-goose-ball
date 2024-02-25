#pragma once

#include <string>
#include <vector>

#include <grrlib.h>

#include "uv.hpp"

class ObjModel
{
public:

    std::vector<guVector> verticies;
    std::vector<UV> uvs;
    std::vector<guVector> normals;

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;

    ObjModel(std::string &name);
    int drawModel(float a);
    int triple32(int x);
    int lowbias32(int x);
};