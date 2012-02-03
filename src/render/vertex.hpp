/* 
 * File:   vertex.hpp
 * Author: Guillaume
 *
 * Created on February 1, 2012, 6:35 PM
 */

#ifndef VERTEX_HPP
#define	VERTEX_HPP

struct Vertex {
    float x, y, z;      // Position.
    float r, g, b, a;   // Color.
    float nx, ny, nz;   // Normal.
    float tu, tv;       // Texcoords.
};

#endif	/* VERTEX_HPP */

