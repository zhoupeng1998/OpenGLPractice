#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <unordered_map>

struct ShaderProgramSource {
	std::string vertexSource;
	std::string fragmentSource;
};

class Shader {
private:
	std::string filePath;
	unsigned int rendererId;
	std::unordered_map<std::string, unsigned int> uniformLocationCache;

public:
	Shader(const std::string& filepath);
	~Shader();

	void bind() const;
	void unbind() const;

	// set uniforms
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

private:
	unsigned int getUniformLocation(const std::string& name);
	ShaderProgramSource parseShader(const std::string& filePath);
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int compileShader(unsigned int type, const std::string& source);
};

#endif // !SHADER_H_


