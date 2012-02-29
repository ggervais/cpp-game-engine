#version 150

layout(points) in;
layout(triangle_strip, max_vertices = 4) out;
 
uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 worldMatrix;

out vec2 mapping;

void main() {

  vec4 center = worldMatrix * vec4(0, 0, 0, 1);
  vec4 transformedCenter = viewMatrix * center;

  // Bottom left
  gl_Position = projectionMatrix * (transformedCenter + vec4(-0.5, -0.5, 0.0, 1.0));	
  gl_FrontColor = vec4(1, 0, 1, 1);
  mapping = vec2(-1, -1);
  EmitVertex();

  // Top left
  gl_Position = projectionMatrix * (transformedCenter + vec4(-0.5, 0.5, 0.0, 1.0));	
  gl_FrontColor = vec4(1, 1, 0, 1);
  mapping = vec2(-1, 1);
  EmitVertex();

  // Bottom right
  gl_Position = projectionMatrix * (transformedCenter + vec4(0.5, -0.5, 0.0, 1.0));	
  gl_FrontColor = vec4(0, 1, 1, 1);
  mapping = vec2(1, -1);
  EmitVertex();

  // Top right
  gl_Position = projectionMatrix * (transformedCenter + vec4(0.5, 0.5, 0.0, 1.0));	
  gl_FrontColor = vec4(1, 1, 1, 1);
  mapping = vec2(1, 1);
  EmitVertex();

  EndPrimitive();
}