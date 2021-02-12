#version 330 core

#define PI 3.1415926538

out vec4 FragColor;

in vec2 textureCoords;

uniform sampler2D tex;
uniform float color;

void main()
{   
    vec4 texColor = texture(tex, textureCoords);
    if(texColor == vec4(1.0f, 1.0f, 1.0f, 1.0f)) {
        texColor = vec4(abs(sin(color)), abs(sin(color + ((2*PI)/3))), abs(sin(color + ((4*PI)/3))), 1.0f);
    }
    if(texColor.a < 0.1)
        discard;
    FragColor = texColor;
}