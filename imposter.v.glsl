#version 110

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

    gl_FrontColor = color;
    gl_Position = position;
}