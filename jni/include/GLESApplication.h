#ifndef GLES_APPLICATION
#define GLES_APPLICATION

#include <android_native_app_glue.h>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <android/asset_manager.h>
#include <android/native_activity.h>
#include <stdlib.h>
#include "Log.h"

class GLESApplication
{
    public:
        GLESApplication(android_app *context)
        {
            this->display = EGL_NO_DISPLAY;
            this->surface = EGL_NO_SURFACE;
            this->context = EGL_NO_CONTEXT;
            this->width = 0;
            this->height = 0;
            this->androidContext = context;
            
        }
        
        virtual ~GLESApplication() {}
        int initWindow(android_app *app);
        void terminateWindow(android_app *app) {}
        void tearDownEGLContext();
        virtual int32_t handleInput(struct android_app* app, AInputEvent* event);
        void handleCommand(struct android_app* app, int32_t cmd);
        void run();
    
protected:
        virtual void saveState(android_app *app) {}
        virtual void gainedFocus(android_app *app) {}
        virtual void lostFocus(android_app *app) {}
        virtual void _drawOneFrame();
        virtual void drawOneFrame()  = 0;
        virtual void onStart(android_app* app) {}
        virtual void initShaders() = 0;
        virtual void positInit() = 0;
        GLuint loadShader(const char *shaderSrc, GLenum shaderType);
        

    
protected:
        EGLDisplay display;
        EGLSurface surface;
        EGLContext context;
        android_app *androidContext;
        int width;
        int height;
        GLuint shaderProgramObject;
};
#endif // GLES_APPLICATION
