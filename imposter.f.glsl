#version 110

varying vec2 mapping;

void main()
{
    float lengthSquared = dot(mapping, mapping);
	if (lengthSquared > 1.0) {
	    discard;
	}
    gl_FragColor = gl_Color;
}