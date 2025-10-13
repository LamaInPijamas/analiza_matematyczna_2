#include "OpenGL_Renderer.h"
#include "Renderer/Shaders/shaders.h"

int main(){
  OpenGLRenderer::Renderer renderer = OpenGLRenderer::Renderer();

  renderer.createWindow();
  renderer.createRenderer();

  renderer.bindVertexShader(Shader::vertex);
  renderer.bindFragmentShader(Shader::fragment);
  renderer.bindComputeShader(Shader::compute);
  std::vector<std::pair<float, float>> data;
  data.emplace_back(std::pair<float, float>({1, 1}));
  renderer.runComputeShader(data);
  renderer.compileShaders();

  while(renderer.isRunning()){

    renderer.renderFrame();
    renderer.windowEvents();
  }

  return 0;
}