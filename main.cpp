/* 
 * File:   main.cpp
 * Author: Guillaume
 *
 * Created on January 16, 2012, 9:37 PM
 */

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <GL/glew.h>
#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif


using namespace std;

static void update_fade_factor(void) {
    
}

static void render(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

static int make_resources(void)
{
    return 1;
}

/*
 * 
 */
int main(int argc, char* argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Hello World");
    glutIdleFunc(&update_fade_factor);
    glutDisplayFunc(&render);

    glewInit();
    
    string version = (char *) glGetString(GL_VERSION);
    
    cout << "OpenGL version is " << version << endl;
    
    if (!GLEW_VERSION_3_3) {
        cerr << "OpenGL 3.3 not available" << endl;
        return EXIT_FAILURE;
    }

    if (!make_resources()) {
        cerr << "Failed to load resources" << endl;
        return EXIT_FAILURE;
    }
    
    glutMainLoop();
    
    return EXIT_SUCCESS;
}

