#version 330

// Input vertex attributes (from vertex shader)
in vec3 fragPosition;
in vec2 fragTexCoord;
in vec4 fragColor;
in vec3 fragNormal;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

uniform vec3 light_dir;
uniform vec4 light_color;
uniform vec4 ambient_color;

// Output fragment color
out vec4 finalColor;

void main()
{
    // Texel color fetching from texture sampler
    vec4 texelColor = texture(texture0, fragTexCoord);
    vec3 lightDot = vec3(0.0);
    vec3 normal = normalize(fragNormal);

    vec4 tint = colDiffuse*fragColor;

    // NOTE: Implement here your fragment shader code

    vec3 light = vec3(0.0);

    light = -normalize(light_dir);

    float NdotL = max(dot(normal, light), 0.0);
    lightDot += light_color.rgb*NdotL;

    finalColor = texelColor*ambient_color + texelColor*vec4(lightDot, 1.0); 
}
