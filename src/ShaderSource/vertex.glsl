#version 400 core

layout(location=0)in vec3 vertexPosition;

layout(location=3)in vec4 colors;

out vec4 color;
void main()
{

    color=colors;
    gl_Position=vec4(vertexPosition.xyz,1.);
}