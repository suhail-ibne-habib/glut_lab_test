#include <windows.h>
#include <GL/glut.h>

char title[] = "3D Shapes";

float rotateX = 0.0f, rotateY = 0.0f;
float translateX = 0.0f, translateY = 0.0f;


void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   // glTranslatef(0.0f, 2.0f, -12.0f);
   // glRotatef(45.0f, 0.5f, 1.0f, 0.1f);

   glTranslatef(translateX, translateY + 2.0f, -12.0f);  // Add translation
   glRotatef(rotateX, 1.0f, 0.0f, 0.0f);                 // Rotate on X
   glRotatef(rotateY, 0.0f, 1.0f, 0.0f);                 // Rotate on Y

   glBegin(GL_QUADS);

        // Front face  (z = 1.0f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Red
        glVertex3f( 1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);

        // Back face (z = -1.0f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f( 1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);

        // Top face (y = 1.0f)
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f( 1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);

        // Bottom face (y = -1.0f)
        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);

        // Right face (x = 1.0f)
        glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
        glVertex3f( 1.0f,  1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f, -1.0f);
        glVertex3f( 1.0f, -1.0f,  1.0f);
        glVertex3f( 1.0f,  1.0f,  1.0f);

        // Left face (x = -1.0f)
        glColor3f(1.0f, 0.0f, 0.0f);     // Cyan
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);

        // Front face  (z = 1.0f) // Second Cube
        glColor3f(0.0f, 1.0f, 0.0f);     // Red
        glVertex3f( 1.0f,  -1.0f,  1.0f);
        glVertex3f(-1.0f,  -1.0f,  1.0f);
        glVertex3f(-1.0f,  -3.0f,  1.0f);
        glVertex3f( 1.0f,  -3.0f,  1.0f);

        // Back face (z = -1.0f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f( 1.0f,  -1.0f, -1.0f);
        glVertex3f(-1.0f,  -1.0f, -1.0f);
        glVertex3f(-1.0f,  -3.0f, -1.0f);
        glVertex3f( 1.0f,  -3.0f, -1.0f);

        // Top face (y = -1.0f)
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f( 1.0f,  -1.0f, -1.0f);
        glVertex3f(-1.0f,  -1.0f, -1.0f);
        glVertex3f(-1.0f,  -1.0f,  1.0f);
        glVertex3f( 1.0f,  -1.0f,  1.0f);

        // Bottom face (y = -3.0f)
        glColor3f(1.0f, 0.0f, 0.0f);     // Yellow
        glVertex3f( 1.0f,  -3.0f, -1.0f);
        glVertex3f(-1.0f,  -3.0f, -1.0f);
        glVertex3f(-1.0f,  -3.0f,  1.0f);
        glVertex3f( 1.0f,  -3.0f,  1.0f);

        // Right face (x = 1.0f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Magenta
        glVertex3f( 1.0f,  -1.0f, -1.0f);
        glVertex3f( 1.0f,  -3.0f, -1.0f);
        glVertex3f( 1.0f,  -3.0f,  1.0f);
        glVertex3f( 1.0f,  -1.0f,  1.0f);

        // Left face (x = -1.0f)
        glColor3f(1.0f, 0.0f, 0.0f);     // Cyan
        glVertex3f(-1.0f,  -1.0f, -1.0f);
        glVertex3f(-1.0f,  -3.0f, -1.0f);
        glVertex3f(-1.0f,  -3.0f,  1.0f);
        glVertex3f(-1.0f,  -1.0f,  1.0f);

        // 3rd cube in tail left side

        // Top face (y = 3.0f)
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f( -1.0f,  -3.0f, -1.0f);
        glVertex3f(-3.0f,  -3.0f, -1.0f);
        glVertex3f(-3.0f,  -3.0f,  1.0f);
        glVertex3f( -1.0f,  -3.0f,  1.0f);

        // Bottom face (y = 6.0f)
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(-1.0f,  -5.0f, -1.0f);
        glVertex3f(-3.0f,  -5.0f, -1.0f);
        glVertex3f(-3.0f,  -5.0f,  1.0f);
        glVertex3f(-1.0f,  -5.0f,  1.0f);

        // Front face  (z = 1.0f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Red
        glVertex3f(-1.0f,  -3.0f,  1.0f);
        glVertex3f(-3.0f,  -3.0f,  1.0f);
        glVertex3f(-3.0f,  -5.0f,  1.0f);
        glVertex3f(-1.0f,  -5.0f,  1.0f);

        // Back face  (z = 1.0f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Red
        glVertex3f(-1.0f,  -3.0f,  -1.0f);
        glVertex3f(-3.0f,  -3.0f,  -1.0f);
        glVertex3f(-3.0f,  -5.0f,  -1.0f);
        glVertex3f(-1.0f,  -5.0f,  -1.0f);

        // 4th cube in tail left side

        // Top face (y = 3.0f)
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(-3.0f,  -3.0f, -1.0f);
        glVertex3f(-5.0f,  -3.0f, -1.0f);
        glVertex3f(-5.0f,  -3.0f,  1.0f);
        glVertex3f(-3.0f,  -3.0f,  1.0f);

        // Bottom face (y = 6.0f)
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(-3.0f,  -5.0f, -1.0f);
        glVertex3f(-5.0f,  -5.0f, -1.0f);
        glVertex3f(-5.0f,  -5.0f,  1.0f);
        glVertex3f(-3.0f,  -5.0f,  1.0f);

        // Front face  (z = 1.0f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Red
        glVertex3f(-3.0f,  -3.0f,  1.0f);
        glVertex3f(-5.0f,  -3.0f,  1.0f);
        glVertex3f(-5.0f,  -5.0f,  1.0f);
        glVertex3f(-3.0f,  -5.0f,  1.0f);

        // Back face  (z = 1.0f)
        glColor3f(1.0f, 1.0f, 0.0f);     // Red
        glVertex3f(-3.0f,  -3.0f,  -1.0f);
        glVertex3f(-5.0f,  -3.0f,  -1.0f);
        glVertex3f(-5.0f,  -5.0f,  -1.0f);
        glVertex3f(-3.0f,  -5.0f,  -1.0f);

        // Left face (x = -1.0f)
        glColor3f(1.0f, 0.0f, 0.0f);     // Cyan
        glVertex3f(-5.0f,  -3.0f, -1.0f);
        glVertex3f(-5.0f,  -5.0f, -1.0f);
        glVertex3f(-5.0f,  -5.0f,  1.0f);
        glVertex3f(-5.0f,  -3.0f,  1.0f);

        // Tail Right Cubes

        // Top face [ y = -3, x = 1, -1, z = 1,3 ]
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f, -3.0f, 1.0f );
        glVertex3f(-1.0f, -3.0f, 1.0f );
        glVertex3f(-1.0f, -3.0f, 5.0f );
        glVertex3f( 1.0f, -3.0f, 5.0f );

        // Bottom face [ y = -5, x = 1, -1, z = 1,3 ]
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f( 1.0f, -5.0f, 1.0f );
        glVertex3f(-1.0f, -5.0f, 1.0f );
        glVertex3f(-1.0f, -5.0f, 5.0f );
        glVertex3f( 1.0f, -5.0f, 5.0f );

        // Front face [ y=-3,-5, x=1,-1, z=3 ]
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 1.0f, -3.0f, 5.0f);
        glVertex3f(-1.0f, -3.0f, 5.0f);
        glVertex3f(-1.0f, -5.0f, 5.0f);
        glVertex3f( 1.0f, -5.0f, 5.0f);

        // Left face [ y=-3,-5, x=-3,-5, z=1,3 ]
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-1.0f, -3.0f, 1.0f);
        glVertex3f(-1.0f, -3.0f, 5.0f);
        glVertex3f(-1.0f, -5.0f, 5.0f);
        glVertex3f(-1.0f, -5.0f, 1.0f);

        // Right face for Tail Right Cube
        glColor3f(1.0f, 0.0f, 1.0f);  // Magenta
        glVertex3f( 1.0f, -3.0f, 1.0f );
        glVertex3f( 1.0f, -3.0f, 5.0f );
        glVertex3f( 1.0f, -5.0f, 5.0f );
        glVertex3f( 1.0f, -5.0f, 1.0f );

        // Back face for Tail Right Cube
        glColor3f(1.0f, 1.0f, 0.0f);  // Yellow
        glVertex3f( 1.0f, -3.0f, 1.0f );
        glVertex3f(-1.0f, -3.0f, 1.0f );
        glVertex3f(-1.0f, -5.0f, 1.0f );
        glVertex3f( 1.0f, -5.0f, 1.0f );



   glEnd();


   glutSwapBuffers();
}

void handleKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 27: // ESC key
            exit(0);
        case 'w':
        case 'W':
            translateY += 0.2f;
            break;
        case 's':
        case 'S':
            translateY -= 0.2f;
            break;
        case 'a':
        case 'A':
            translateX -= 0.2f;
            break;
        case 'd':
        case 'D':
            translateX += 0.2f;
            break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_RIGHT:
            rotateY += 5.0f;
            break;
        case GLUT_KEY_LEFT:
            rotateY -= 5.0f;
            break;
        case GLUT_KEY_UP:
            rotateX += 5.0f;
            break;
        case GLUT_KEY_DOWN:
            rotateX -= 5.0f;
            break;
    }
    glutPostRedisplay();
}


void reshape(GLsizei width, GLsizei height) {

   if (height == 0) height = 1;
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(70.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(840, 680);
   glutCreateWindow(title);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(handleKeys);
   glutSpecialFunc(specialKeys);
   initGL();
   glutMainLoop();
   return 0;
}
