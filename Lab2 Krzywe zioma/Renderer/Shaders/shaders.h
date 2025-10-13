#pragma once
#include "string"
namespace Shader{
std::string vertex = R"(
#version 330 core

layout(location = 0) in vec2 aPos;
void main() {
  gl_Position = vec4(aPos, 0.0, 1.0); 
}
)";

std::string fragment = R"(
#version 330 core

out vec4 FragColor;

void main() {
  vec2 position = gl_FragCoord.xy / vec2(800.0, 600.0);

  FragColor = vec4(position.x, position.y, 0.0, 1.0);
}
)";

};