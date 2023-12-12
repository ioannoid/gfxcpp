#version 430 core

out vec4 FragColor;

//uniform vec2 resolution;
uniform float test;

int fail = 0;

float map(float value, float min1, float max1, float min2, float max2) {
    return (value - min1) * (max2 - min2) / (max1 - min1) + min2;
}

bool inSet(int iter, float real, float imag) {
    float zR = 0;
    float zI = 0;
    for(int i = 0; i < iter; i++){
        float zRTemp = (zR*zR) - (zI*zI) + real;
        float zITemp = 2*zR*zI + imag;
        zR = zRTemp;
        zI = zITemp;
        if(sqrt((zR*zR) + (zI*zI)) > 2) {
            fail = i;
            return false;
        }
    }
    return true;
}  

void main()
{   
    // vec4 ndcPos;
    // ndcPos.xy = ((2.0 * gl_FragCoord.xy) - (2.0 * vec2(0.0, 0.0))) / (resolution.xy) - 1;
    // ndcPos.z = (2.0 * gl_FragCoord.z - gl_DepthRange.near - gl_DepthRange.far) /
    //     (gl_DepthRange.far - gl_DepthRange.near);
    // ndcPos.w = 1.0;

    // vec4 eyePos = invProj * (ndcPos / gl_FragCoord.w);

    //float x = map(gl_FragCoord.x, -test+0, test+resolution.x, test+-2.0, -test+0.5);
    //float y = map(gl_FragCoord.y, -test+0, test+resolution.y, test+-0.9, -test+1.1);
    //float x = map(gl_FragCoord.x, 0, 800, -2.0, 0.5);
    //float y = map(gl_FragCoord.y, 0, 600, -0.9, 1.1);
    float x = map(gl_FragCoord.x, 0, 800, -0.7459-test, -0.7449+test);
    float y = map(gl_FragCoord.y, 0, 600, 0.0995-test, 0.1005+test);


    int iter = 1000;

    if(inSet(iter, x, y)) {
        FragColor = vec4(0.0, 0.0, 0.0, 1.0);
    }
    else {
        float H = map(iter - fail - 1, 0, iter, 0, 360);
        float S = 1.0;
        float L = 0.5;

        float C = (1 - abs(2*L - 1)) * S;
        float X = C * (1 - abs(mod(H / 60, 2) - 1));
        float m = L - C/2;
        float r = 0;
        float g = 0;
        float b = 0;
        if (H >= 0 && H <= 60) {
            r = C+m;
            g = X+m;
            b = m;
        }
        else if (H >= 60 && H <= 120) {
            r = X+m;
            g = C+m;
            b = m;
        }
        else if (H >= 120 && H <= 180) {
            r = m;
            g = C+m;
            b = X+m;
        }
        else if (H >= 180 && H <= 240) {
            r = m;
            g = X+m;
            b = C+m;
        }
        else if (H >= 240 && H <= 300) {
            r = X+m;
            g = m;
            b = C+m;
        }
        else if (H >= 300 && H < 360) {
            r = C+m;
            g = m;
            b = X+m;
        }
        
        FragColor = vec4(r, g, b, 1.0);
    }
}

    
