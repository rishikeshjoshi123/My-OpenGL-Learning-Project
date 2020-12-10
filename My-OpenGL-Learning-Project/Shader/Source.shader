#vertex shader
#version 330 core

layout(location = 0) in vec3 in_positions;
layout(location = 1) in vec3 in_colors;
layout(location = 2) in vec2 in_texcord;

out vec4 out_colors;
out vec2 out_texcord;

uniform mat4 u_MVP;
void main()
{
    gl_Position = u_MVP*vec4(in_positions, 1.0f);
    out_colors = vec4(in_colors,1);
    out_texcord = in_texcord;
}


#fragment shader
#version 330 core
out vec4 FragColor;
in vec4 out_colors;
in vec2 out_texcord;
uniform sampler2D TS1;
uniform sampler2D TS2;
void main()
{
    FragColor = texture(TS2, out_texcord)*out_colors;
}