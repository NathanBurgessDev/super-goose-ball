#pragma once

#include <string>
#include <vector>

#include <grrlib.h>

#include "uv.hpp"

class ObjModel
{
private:
    std::vector<guVector> verticies;
    std::vector<UV> uvs;
    std::vector<guVector> normals;

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;

public:
    ObjModel(std::string &name);
};