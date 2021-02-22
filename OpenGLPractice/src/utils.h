#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>

#include <glad/glad.h>

#define ASSERT(x) if(!(x)) __debugbreak();
#define glCall(x) glClearError();\
    x;\
    ASSERT(glLogCall(#x, __FILE__, __LINE__));

void glClearError();
bool glLogCall(const char* function, const char* file, int line);

#endif // !RENDERER_H_