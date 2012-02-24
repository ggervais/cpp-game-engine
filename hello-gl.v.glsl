#version 130

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 worldMatrix;
attribute vec4 position;
attribute vec4 color;
attribute vec3 normal;
attribute vec2 texCoords;

varying vec2 fragTexCoords;
varying vec3 fragNormal;
varying vec3 fragPosition;
varying vec4 fragSpecular;
varying float fragShininess;
varying vec3 fragModelViewLightDirection;

const vec4 spotPosition = vec4(0.0, 0.0, 0.0, 10000.0);

void main(void) {

	vec4 center = worldMatrix * vec4(0, 0, 0, 1);
	vec4 transformedCenter = viewMatrix * center;

	mat4 viewModelMatrix = viewMatrix * worldMatrix;
    vec4 eyePosition = viewModelMatrix * position;
    vec4 specular = vec4(1.0, 1.0, 0.75, 0.0);
    float shininess = 4.0;

    vec3 lightDir = normalize(eyePosition.xyz - spotPosition.xyz);

    fragModelViewLightDirection = lightDir;

    fragNormal = (viewModelMatrix * vec4(normal, 0)).xyz;
    fragTexCoords = texCoords;
    fragPosition = eyePosition.xyz;
    fragSpecular = specular;
    fragShininess = shininess;

    gl_FrontColor = color;

	/*if (gl_VertexID == 0) {
		gl_Position = projectionMatrix * transformedCenter + vec4(0, 1, 0, 1);	
	} else if (gl_VertexID == 1) {
		gl_Position = projectionMatrix * transformedCenter + vec4(-1, -1, 0, 1);
	} else if (gl_VertexID == 2) {
		gl_Position = projectionMatrix * transformedCenter + vec4(1, -1, 0, 1);
	} else {
		gl_Position = projectionMatrix * eyePosition;
	}*/

	gl_Position = projectionMatrix * eyePosition;
}