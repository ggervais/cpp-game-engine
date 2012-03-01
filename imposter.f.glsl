#version 110

varying vec2 mapping;
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 worldMatrix;

const vec4 lightDiffuse = vec4(0.8, 0.8, 0.8, 0.0);
const vec4 lightAmbient = vec4(0.5, 0.5, 0.5, 1.0);
const vec4 lightSpecular = vec4(1.0, 1.0, 1.0, 1.0);

void main()
{
    float lengthSquared = dot(mapping, mapping);
	if (lengthSquared > 1.0) {
	    discard;
	}

	vec3 normal = vec3(mapping, sqrt(1.0 - lengthSquared));
	vec4 center = worldMatrix * vec4(0, 0, 0, 1);
    vec4 sphereCenter = viewMatrix * center;

	float radius = 1.0;
	vec3 pointOnSphere = (normal * radius) + sphereCenter.xyz;

	vec4 finalColor = gl_Color;

	vec3 lightDir = pointOnSphere - vec3(0.0, 0.0, 0.0);
	vec4 specular = vec4(1.0, 1.0, 0.75, 0.0);
	vec3 reflection = reflect(lightDir, normal);


	vec4 diffuseFactor = max(-dot(normal, lightDir), 0.0) * lightDiffuse;
    vec4 ambientDiffuseFactor = diffuseFactor + lightAmbient;
    vec4 specularFactor = max(pow(-dot(reflection, pointOnSphere), 0.8), 0.0) * lightSpecular;
    finalColor = specularFactor * specular + ambientDiffuseFactor * gl_Color;

	vec4 clipPosition = projectionMatrix * vec4(pointOnSphere, 1);
	float ndcDepth = clipPosition.z / clipPosition.w;

    gl_FragColor = finalColor;
	gl_FragDepth = ((gl_DepthRange.diff * ndcDepth) + gl_DepthRange.near + gl_DepthRange.far) / 2.0;
}