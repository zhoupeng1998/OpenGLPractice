#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "utils.h"

class Texture {
private:
	unsigned int rendererId;
	std::string filePath;
	unsigned char* localBuffer;
	int width, height, bpp;
public:
	Texture(const std::string& path);
	~Texture();
	void bind(unsigned int slot = 0) const;
	void unbind() const;

	inline int getWidth() const {
		return width;
	}

	inline int getHeight() const {
		return height;
	}
};

#endif // !TEXTURE_H_
