#version 330 core

#define PI 3.1415926538

out vec4 FragColor;

in vec2 textureCoords;

uniform sampler2D tex;

void main()
{   
    vec4 texColor = texture(tex, textureCoords);
    if(texColor.a < 0.1)
        discard;
    FragColor = texColor;
}