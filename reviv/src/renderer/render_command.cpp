#include "render_command.h"

void logMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParams);

void RenderCommand::iDrawArrays(const Vao& object)
{
    glDrawArrays(GL_TRIANGLES, 0, object.nrOfTriangles * 3);
}

void RenderCommand::iSetClearColor(const Vec4f& color)
{
    glClearColor(color.x, color.y, color.z, color.w);
}

void RenderCommand::iClear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderCommand::iInit()
{

//#if RV_DEBUG //TODO:
#if 1
    glDebugMessageCallback(logMessageCallback, nullptr);
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); // enables you too look in the call stack
    cout << "Running in DEBUG mode" << endl;
#endif
   
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void logMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParams)
{
    cout << endl;
    switch(severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:
            cout << "[OpenGL Debug HIGH] " << message << endl;
            assert(false);
            break;

        case GL_DEBUG_SEVERITY_MEDIUM:
            cout << "[OpenGL Debug MEDIUM] " << message << endl;
            assert(false);
            break;

        case GL_DEBUG_SEVERITY_LOW:
            cout << "[OpenGL Debug LOW] " << message << endl;
            assert(false);
            break;

        case GL_DEBUG_SEVERITY_NOTIFICATION:
            cout << "[OpenGL Debug NOTIFICATION] " << message << endl;
            break;

        default:
            cout << "ERROR: opengl returned unknown debug error SEVERITY" << endl;
            assert(false);
    }
}