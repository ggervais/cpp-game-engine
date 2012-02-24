#version 150

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;
 
in vec2 fragTexCoords[];
in vec3 fragNormal[];
in vec3 fragPosition[];
in vec4 fragSpecular[];
in vec3 fragModelViewLightDirection[];
in float fragShininess[];

out vec2 ofragTexCoords;
out vec3 ofragNormal;
out vec3 ofragPosition;
out vec4 ofragSpecular;
out vec3 ofragModelViewLightDirection;
out float ofragShininess;

void main() {
  for(int i = 0; i < gl_in.length(); i++) {
    gl_Position = gl_in[i].gl_Position;
	gl_FrontColor = gl_in[i].gl_FrontColor;

	ofragTexCoords = fragTexCoords[i];
	ofragNormal = fragNormal[i];
	ofragPosition = fragPosition[i];
	ofragSpecular = fragSpecular[i];
	ofragModelViewLightDirection = fragModelViewLightDirection[i];
	ofragShininess = fragShininess[i];

    EmitVertex();
  }
  EndPrimitive();
}