#include "OpenGL_Renderer.h"

OpenGLRenderer::Renderer::Renderer() { };

OpenGLRenderer::Renderer::~Renderer()
{
  running = false;
  if(window) glfwDestroyWindow(window);
  glfwTerminate();
};

void OpenGLRenderer::Renderer::windowEvents()
{
    glfwPollEvents();
  if(glfwWindowShouldClose(window)) running = false;
}

void OpenGLRenderer::Renderer::createWindow()
{

  if(!glfwInit()) {
    running = false;
    glfwTerminate();
    throw std::runtime_error("Can't initialize GLFW");
  }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); 

  window = glfwCreateWindow(800, 600, "Curve", nullptr, nullptr);
  if(!window) {
    running = false;
    glfwTerminate();
    throw std::runtime_error("Can't Create Window");
  };

  glfwMakeContextCurrent(window);
  
  running = true;
}

void OpenGLRenderer::Renderer::createRenderer()
{

}

bool OpenGLRenderer::Renderer::isRunning()
{
  return running;
}

void OpenGLRenderer::Renderer::renderFrame() {


  glfwSwapBuffers(window);
};