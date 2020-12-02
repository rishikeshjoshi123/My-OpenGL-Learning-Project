#vertex shader
#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 clr;
out vec4 sclr;
uniform vec4 move;
void main()
{
    gl_Position = vec4(aPos.x + move.x, aPos.y, 0, 1);
    sclr = vec4(clr,1);
}
#fragment shader
#version 330 core
out vec4 FragColor;
in vec4 sclr;
void main()
{
    FragColor = sclr;
}