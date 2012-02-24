#version 110

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 worldMatrix;
uniform int useTexture;
uniform int useLighting;

varying vec2 ofragTexCoords;
varying vec3 ofragNormal;
varying vec3 ofragPosition;
varying vec4 ofragSpecular;
varying vec3 ofragModelViewLightDirection;
varying float ofragShininess;

//const vec3 lightDirection = vec3(0.408248, -0.816497, -0.408248);
const vec4 lightDiffuse = vec4(0.8, 0.8, 0.8, 0.0);
const vec4 lightAmbient = vec4(0.5, 0.5, 0.5, 1.0);
const vec4 lightSpecular = vec4(1.0, 1.0, 1.0, 1.0);

float cel(float d)
{
    return smoothstep(0.35, 0.37, d) * 0.4 + smoothstep(0.70, 0.72, d) * 0.6;
}

float warpDiffuse(float d)
{
    return cel(d * 0.5 + 0.5);
}

void main()
{
	vec3 lightDir = normalize(ofragModelViewLightDirection);
    vec3 normal = normalize(ofragNormal);
    vec3 eye = normalize(ofragPosition);
    vec3 reflection = reflect(lightDir, normal);

    vec4 color = gl_Color;

    
    vec4 ofragDiffuse = color;

    if (useTexture == 1) {
	    //vec4 textureColor = texture2D(texture, ofragTexCoords);
		//ofragDiffuse *= textureColor;
		ofragDiffuse *= vec4(1, 1, 1, 1);
    }

    vec4 finalColor = ofragDiffuse;
    if (useLighting == 1) {
        vec4 diffuseFactor = max(warpDiffuse(-dot(normal, lightDir)), 0.0) * lightDiffuse;
        vec4 ambientDiffuseFactor = diffuseFactor + lightAmbient;
        vec4 specularFactor = max(pow(-dot(reflection, eye), ofragShininess), 0.0) * lightSpecular;
        finalColor = specularFactor * ofragSpecular + ambientDiffuseFactor * ofragDiffuse;
    }
    gl_FragColor = finalColor;
}