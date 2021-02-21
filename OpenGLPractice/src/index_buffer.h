#ifndef IDNEX_BUFFER_H_
#define	INDEX_BUFFER_H_

class IndexBuffer {
private:
	unsigned int rendererId;
	unsigned int count;

public:
	IndexBuffer(const unsigned int* data, unsigned int cnt);
	~IndexBuffer();

	void bind() const;
	void unbind() const;

	inline unsigned int getCount() const;
};

#endif // !INDEX_BUFFER_H_

