#ifndef INDEX_BUFFER_H_
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

	//unsigned int getCount() const;

	inline unsigned int getCount() const {
		return count;
	}

};

#endif // !INDEX_BUFFER_H_

