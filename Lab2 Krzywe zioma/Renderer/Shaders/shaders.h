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

int maxIter = 500;

void main() {
    vec2 c = (gl_FragCoord.xy / vec2(800.0, 600.0)) * 3.0 - vec2(2.0, 1.5);
    vec2 a1 = c;
    vec2 a2 = a1;
    
    int j = 0;
    for(int i = 0; i < maxIter; i++){
        a2.x = a1.x * a1.x - a1.y * a1.y + c.x;  // Real part of (a1 * a1 + c)
        a2.y = 2.0 * a1.x * a1.y + c.y;   
        
        if (length(a2) > 2.0f){
            break;
        };

        a1 = a2;
        j = j + 1;
    };

    float t = float(j) / float(maxIter); 
    vec3 color = vec3(
        0.5 + 0.5 * sin(t * 20.0 + 0.0),  // Red channel with adjusted frequency
        0.5 + 0.5 * cos(t * 1.5 + 1.0),  // Green channel with different frequency and phase
        0.5 + 0.5 * sin(t * 10.0 + 2.0)   // Blue channel with another frequency and phase shift
    );
    float smoothColor = smoothstep(0.0, 1.0, length(a2));
    FragColor = vec4(color * smoothColor, 1.0);  // Set the final color
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