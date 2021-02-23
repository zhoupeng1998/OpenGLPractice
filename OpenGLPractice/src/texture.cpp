#include "texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture(const std::string& path)
    : rendererId(0), filePath(path), localBuffer(nullptr), width(0), height(0), bpp(0) {
	stbi_set_flip_vertically_on_load(1);
	localBuffer = stbi_load(path.c_str(), &width, &height, &bpp, 4);

	glCall(glGenTextures(1, &rendererId));
	glCall(glBindTexture(GL_TEXTURE_2D, rendererId));

	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	glCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	glCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer));
	glCall(glBindTexture(GL_TEXTURE_2D, 0));

	if (localBuffer) {
		stbi_image_free(localBuffer);
	}
}

Texture::~Texture() {
	glCall(glDeleteTextures(1, &rendererId));
}

void Texture::bind(unsigned int slot) const {
	glCall(glActiveTexture(GL_TEXTURE0 + slot));
	glCall(glBindTexture(GL_TEXTURE_2D, rendererId));
}

void Texture::unbind() const {
	glCall(glBindTexture(GL_TEXTURE_2D, 0));
}
