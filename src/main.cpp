#if defined(linux) || defined(_WIN32)
#include <GL/glut.h>    /* Для Linux и Windows */
#else
#include <GLUT/GLUT.h>  /* Для Mac OS */
#endif

// #include <stdio.h>
// #include <memory>
#include <OpenGL/gl.h>
#include "image.cpp"

// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Создадим одну текстуру OpenGL
    GLuint textureID;
    glGenTextures(1, &textureID);

    // Сделаем созданную текстуру текущий, таким образом все следующие функции будут работать именно с этой текстурой
    glBindTexture(GL_TEXTURE_2D, textureID);

    Image img("/Users/amdankovtsev/Downloads/hotfix.jpg");

    // Передадим изображение OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img.width, img.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.bitMap);

    // The next commands sets the texture parameters
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // If the u,v coordinates overflow the range 0,1 the image is repeated
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // The magnification function ("linear" produces better results)
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); //The minifying function

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECR );

    glBegin(GL_QUADS);
    // glColor3f(1.0, 1.0 * (rotate_x / 100), 1.0);
    glTexCoord2f(0,1);
    glVertex2i(50, 600);
    // glColor3f(0.0, 0.0, 1.0);
    glTexCoord2f(0,0);
    glVertex2i(50, 50);
    // glColor3f(0.0, 1.0 * (rotate_y / 100), 0.0);
    glTexCoord2f(1,0);
    glVertex2i(600, 50);
    // glColor3f(1.0, 0.0, 0.0);
    glTexCoord2f(1,1);
    glVertex2i(600, 600);
    glEnd();

    glutSwapBuffers();
}

// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {

    //  Right arrow - increase rotation by 5 degree
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;

        //  Left arrow - decrease rotation by 5 degree
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;

    else if (key == GLUT_KEY_UP)
        rotate_x += 5;

    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;

    //  Request display update
    glutPostRedisplay();

}

void keyboard (unsigned char key, int x, int y){

    switch (key) {

        case 27: // “esc” on keyboard

            exit(0);

            break;

        default: // “a” on keyboard

            break;

    }

}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);

    // Включаем двойную буферизацию и четырехкомпонентный цвет
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL lesson 1");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);

    glEnable(GL_TEXTURE_2D);

    glutMainLoop();

    return 0;
}
