#include "renderer.h"
#include "vertex_buffer.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    glCall(glGenBuffers(1, &rendererId));
    glCall(glBindBuffer(GL_ARRAY_BUFFER, rendererId));
    glCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer() {
    glCall(glDeleteBuffers(1, &rendererId));
}

void VertexBuffer::bind() const {
    glCall(glBindBuffer(GL_ARRAY_BUFFER, rendererId));
}

void VertexBuffer::unbind() const {
    glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
