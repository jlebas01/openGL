#version 330 core
precision mediump float;

in vec3 vPosition;
in vec3 vNormal;
in vec2 vTexture;

uniform sampler2D uTexture;
vec3 uLightPosition = vec3(1000.f, 1000.f, 1000.f);
vec3 uLightColor = vec3(1);
float uLightDirIntensity = 1.f;
float uLightAmbIntensity = 0.5f;

out vec4 fFragColor;

vec3 computeDiffuseLighting() {
    vec3 lightDirection = normalize(uLightPosition - vPosition);
    vec3 diffuse = vec3(max(dot(vNormal, lightDirection), 0.f));
    return diffuse * uLightDirIntensity;
}


void main() {
    //vec4 textureColor = texture(uTexture, vTexture);
    vec4 textureColor = vec4(1.f, 0.f, 1.f, 0.4f);
    if (textureColor.w == 0.f) {
        discard;
    }

    vec3 diffuse = computeDiffuseLighting();
    vec3 ambient = vec3(uLightAmbIntensity);
    vec3 light =  (diffuse + ambient) * uLightColor;

    fFragColor = vec4(
    min(1.f, light.x),
    min(1.f, light.y),
    min(1.f, light.z),
    1.f
    ) * textureColor;
}
