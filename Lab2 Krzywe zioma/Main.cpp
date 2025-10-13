#include "OpenGL_Renderer.h"
#include "Renderer/Shaders/shaders.h"

int main(){
  OpenGLRenderer::Renderer renderer = OpenGLRenderer::Renderer();

  renderer.createWindow();
  renderer.createRenderer();

  renderer.bindVertexShader(Shader::vertex);
  renderer.bindFragmentShader(Shader::fragment);
  renderer.compileShaders();

  while(renderer.isRunning()){

    renderer.renderFrame();
    renderer.windowEvents();
  }

  return 0;
}