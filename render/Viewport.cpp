/* 
 * File:   Viewport.cpp
 * Author: Guillaume
 * 
 * Created on January 18, 2012, 7:34 PM
 */

#include "Viewport.hpp"

Viewport::Viewport(int width, int height, bool fullscreen) : width(width), height(height), fullscreen(fullscreen), dirty(true) {
}

Viewport::Viewport(const Viewport& orig) {
}

Viewport::~Viewport() {
}

void Viewport::updateDimensions(int width, int height) {
    this->width = width;
    this->height = height;
    this->dirty = true;
}

bool Viewport::isDirty() const {
    return this->dirty;
}

void Viewport::setDirty(bool dirty) {
    this->dirty = dirty;
}

bool Viewport::isFullscreen() const {
    return fullscreen;
}

int Viewport::getHeight() const {
    return height;
}

int Viewport::getWidth() const {
    return width;
}
