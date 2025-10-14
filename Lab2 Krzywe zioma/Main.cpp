#include "OpenGL_Renderer.h"
#include "Renderer/Shaders/shaders.h"

// [TODO] Write compute shader for parametric function, fill all pixels that needed
// [TODO] Write vertex, fragment shader that draw parametric points that was created by compute shader
// [TODO] Optimize vertex drawing only what is in viewport
// [TODO] On allow movement in window and zooming
// [TODO] On zoom and move update every idk 0.2s or sth
// [TODO] GUI with adding nodes etc
// [TODO] If nothing change dont waste gpu to generate new frame just use last one


int main(){
  OpenGLRenderer::Renderer renderer = OpenGLRenderer::Renderer();

  // init window and opengl
  renderer.createWindow();
  renderer.createRenderer();

  // compile compute shader
  renderer.bindComputeShader(Shader::compute);
  std::vector<glm::vec2> data;
  data.emplace_back(glm::vec2({0.0f, 0.0f})); // z_0
  data.emplace_back(glm::vec2({500, 20.1f})); // maxIter, red
  data.emplace_back(glm::vec2({104.0f, 5.2f})); // green, blue
  renderer.runComputeShader(data);
  
  // compile vertex and fragment shader
  renderer.bindVertexShader(Shader::vertex);
  renderer.bindFragmentShader(Shader::fragment);
  renderer.compileShaders();

  // main loop
  while(renderer.isRunning()){
    renderer.renderFrame();
    renderer.windowEvents();
  }

  return 0;
}