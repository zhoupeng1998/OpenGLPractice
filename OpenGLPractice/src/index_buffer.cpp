#include "renderer.h"
#include "index_buffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int cnt): count(cnt) {
    glCall(glGenBuffers(1, &rendererId));
    glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId));
    glCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, cnt * sizeof(GLuint), data, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer() {
    glCall(glDeleteBuffers(1, &rendererId));
}

void IndexBuffer::bind() const {
    glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId));
}

void IndexBuffer::unbind() const {
    glCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

inline unsigned int IndexBuffer::getCount() const {
    return count;
}
