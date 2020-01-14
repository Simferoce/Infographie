#version 400 core
out vec4 fragColor;
in vec4 color;
in vec2 uvs;
void main()
{
    fragColor=color;
}