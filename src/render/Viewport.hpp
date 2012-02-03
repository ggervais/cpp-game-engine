/* 
 * File:   Viewport.hpp
 * Author: Guillaume
 *
 * Created on January 18, 2012, 7:34 PM
 */

#ifndef VIEWPORT_HPP
#define	VIEWPORT_HPP

class Viewport {
public:
    Viewport(int x, int y, int width, int height, bool fullscreen);
    Viewport(int width, int height, bool fullscreen);
    Viewport(const Viewport& orig);
    virtual ~Viewport();
    void updateDimensions(int width, int height);
    
    bool isFullscreen() const;
    int getX() const;
    int getY() const;
    int getHeight() const;
    int getWidth() const;

    bool isDirty() const;
    void setDirty(bool dirty);
    
    
private:

    int x;
    int y;
    int width;
    int height;
    bool fullscreen;
    bool dirty;
};

#endif	/* VIEWPORT_HPP */

