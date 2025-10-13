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

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);

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
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    running = false;
    return;
  };

  int width, height;
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);

  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
}

bool OpenGLRenderer::Renderer::isRunning()
{
  return running;
}

void OpenGLRenderer::Renderer::renderFrame() {
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);


  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
  glfwSwapBuffers(window);
}

void OpenGLRenderer::Renderer::compileShaders() {
  GLuint vertexShaderPart = glCreateShader(GL_VERTEX_SHADER);
  const char* vertexShaderData = vertexShader.c_str();
  glShaderSource(vertexShaderPart, 1, &vertexShaderData, nullptr);
  glCompileShader(vertexShaderPart);
  GLuint fragmentShaderPart = glCreateShader(GL_FRAGMENT_SHADER);
  const char* fragmentShaderData = fragmentShader.c_str();
  glShaderSource(fragmentShaderPart, 1, &fragmentShaderData, nullptr);
  glCompileShader(fragmentShaderPart);
  compiledShader = glCreateProgram();
  glAttachShader(compiledShader, vertexShaderPart);
  glAttachShader(compiledShader, fragmentShaderPart);
  glLinkProgram(compiledShader);
  glDeleteShader(vertexShaderPart);
  glDeleteShader(fragmentShaderPart);
}

void OpenGLRenderer::Renderer::bindComputeShader(std::string shader) {
  computeShader = shader;
}

void OpenGLRenderer::Renderer::bindVertexShader(std::string shader) {
  vertexShader = shader;
}

void OpenGLRenderer::Renderer::bindFragmentShader(std::string shader) {
  fragmentShader = shader;
};