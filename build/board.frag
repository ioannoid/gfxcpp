#version 330 core

#define PI 3.14159265358

out vec4 FragColor;

in vec2 textureCoords;

uniform sampler2D tex;
uniform vec2 resolution;
uniform vec2 cursorPos;

void main()
{   
    //vec4 texColor = texture(tex, textureCoords);
    //if(texColor.a < 0.1)
    //    discard;
    if((cursorPos).x <= gl_FragCoord.x + 10 && (cursorPos).x  >= gl_FragCoord.x -10)
        if(resolution.y - (cursorPos).y <= gl_FragCoord.y + 10 && resolution.y - (cursorPos).y  >= gl_FragCoord.y -10)
            FragColor = vec4(1.0, 0.0, 0.0, 1.0);
        else
            FragColor = vec4(0.0, 0.5, 0.8, 1.0);//texColor;
    else
            FragColor = vec4(0.0, 0.5, 0.8, 1.0);
    
}