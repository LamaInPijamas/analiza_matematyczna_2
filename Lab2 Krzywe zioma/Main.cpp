#include "OpenGL_Renderer.h"



int main(){
  OpenGLRenderer::Renderer renderer = OpenGLRenderer::Renderer();

  renderer.createWindow();
  renderer.createRenderer();

  while(renderer.isRunning()){


    renderer.renderFrame();
    renderer.windowEvents();
  }

  return 0;
}