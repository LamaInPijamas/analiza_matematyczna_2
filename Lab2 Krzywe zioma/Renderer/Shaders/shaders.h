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

// Declare the SSBO for color data
layout(std140, binding = 0) buffer ColorBuffer {
    vec2 colors[]; // Array of colors stored in the SSBO
};

out vec4 FragColor;

void main() {
    // For simplicity, let's access the first color in the array
    // You can access based on any condition, like gl_FragCoord or other logic.
    FragColor = vec4(colors[0].x, colors[0].y, colors[1].x,  colors[1].y); // Access the first color from the SSBO
}

)";

std::string compute = R"(
#version 430 core

layout(local_size_x = 1) in; // Workgroup size (1 for simplicity)

// Input and Output SSBOs
layout(std430, binding = 0) buffer InputBuffer {
    vec2 inputData[];  // Input data
};

void main() {
    uint idx = gl_GlobalInvocationID.x; // Get index for current workgroup

    // Simple computation (e.g., scaling the points)
    inputData[idx] = inputData[idx] / 255.0f;  // Example: scaling divide by 255
}
)";

};