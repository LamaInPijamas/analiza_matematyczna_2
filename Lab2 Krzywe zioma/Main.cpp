#include "OpenGL_Renderer.h"
#include "Renderer/Shaders/shaders.h"

int main(){
  OpenGLRenderer::Renderer renderer = OpenGLRenderer::Renderer();

  renderer.createWindow();
  renderer.createRenderer();

  renderer.bindVertexShader(Shader::vertex);
  renderer.bindFragmentShader(Shader::fragment);
  renderer.bindComputeShader(Shader::compute);
  std::vector<glm::vec2> data;
  data.emplace_back(glm::vec2({0.0f, 0.0f}));
  data.emplace_back(glm::vec2({255.0f, 255.0f}));
  renderer.runComputeShader(data);
  renderer.compileShaders();

  while(renderer.isRunning()){

    renderer.renderFrame();
    renderer.windowEvents();
  }

  return 0;
}