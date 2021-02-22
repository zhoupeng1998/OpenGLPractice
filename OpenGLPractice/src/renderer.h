#ifndef RENDERER_H_
#define RENDERER_H_

#include "vertex_array.h"
#include "index_buffer.h"
#include "shader.h"

class Renderer {
public:
    void draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};

#endif // !RENDERER_H_