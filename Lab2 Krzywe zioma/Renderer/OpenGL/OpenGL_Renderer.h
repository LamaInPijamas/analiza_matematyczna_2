#pragma once
#include "GL/gl.h"
#include "GLFW/glfw3.h"
#include <string>
#include <vector>
#include <stdexcept>

namespace OpenGLRenderer{
class Renderer{
private:
  std::pair<float, float> global_position = {0.0f, 0.0f};
  float zoom  = 1.0f;
  GLFWwindow* window;
  bool running = true;

public:
  Renderer();
  ~Renderer();

  void windowMovement(std::pair<float, float> move);
  void windowZoom(float zoom);

  void windowEvents();
  
  void createWindow();
  void createRenderer();
  bool isRunning();
  void renderFrame();

  void pushPoints(std::initializer_list<std::pair<float, float>> data);
  void runComputeShader(std::string shader);
  void runVertexShader(std::string shader);
  void runFragmentShader(std::string shader);
  
};
};