#ifndef VERTEX_BUFFER_H_
#define	VERTEX_BUFFER_H_

class VertexBuffer {
private:
	unsigned int rendererId;

public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void bind() const;
	void unbind() const;
};

#endif // !VERTEX_BUFFER_H_
