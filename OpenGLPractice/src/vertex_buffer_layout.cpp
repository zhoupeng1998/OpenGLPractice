#include "vertex_buffer_layout.h"

VertexBufferLayout::VertexBufferLayout(): stride(0) {
}

unsigned int VertexBufferElement::getSizeOfType(unsigned int type)
{
	switch (type){
	case GL_FLOAT:
		return sizeof(GLfloat);
	case GL_UNSIGNED_INT:
		return sizeof(GLuint);
	case GL_UNSIGNED_BYTE:
		return sizeof(GLubyte);
	}
	// never reach!
	//return 0;
}
