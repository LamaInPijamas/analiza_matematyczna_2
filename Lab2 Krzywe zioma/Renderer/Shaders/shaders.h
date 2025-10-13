#pragma once
#include "string"
namespace Shader{
std::string vertex = R"(
#version 430 core

layout(location = 0) in vec2 aPos;
void main() {
  gl_Position = vec4(aPos, 0.0, 1.0); 
}
)";

std::string fragment = R"(
#version 430 core

out vec4 FragColor;

void main() {
  vec2 position = gl_FragCoord.xy / vec2(800.0, 600.0);

  FragColor = vec4(position.x, position.y, 0.0, 1.0);
}
)";

std::string compute = R"(
#version 430 core

layout(local_size_x = 1) in; // Workgroup size (1 for simplicity)

// Input and Output SSBOs
layout(std430, binding = 0) buffer InputBuffer {
    vec3 inputData[];  // Input data
};

layout(std430, binding = 1) buffer OutputBuffer {
    vec3 outputData[]; // Processed output data
};

void main() {
    uint idx = gl_GlobalInvocationID.x; // Get index for current workgroup

    // Simple computation (e.g., scaling the points)
    outputData[idx] = inputData[idx] * 2.0;  // Example: scaling by 2
}
)";

};