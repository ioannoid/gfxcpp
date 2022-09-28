#version 430 core

out vec4 FragColor;

// in vec2 textureCoords;

// uniform sampler2D tex;

// uniform int currentFrame;
// uniform int frames;

void main()
{   
    //vec4 texColor = texture(tex, textureCoords);
    //if(texColor.a < 0.1)
    //    discard;
    //FragColor = texColor;
    // vec4 texColor = texture(tex, vec2(textureCoords.x + (1.0f/float(frames) * float(currentFrame%10)), textureCoords.y - (1.0f/float(frames) * int(currentFrame/10))));
    // if(texColor.a < 0.1)
    //     discard;
    // FragColor = texColor;

    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
