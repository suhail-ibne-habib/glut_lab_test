/*
 * OGL01Shape3D.cpp: 3D Shapes
 */
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Global variables */
char title[] = "3D Shapes";

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(0.0f, 2.0f, -12.0f);  // Move right and into the screen
   glRotatef(45.0f, 0.5f, 1.0f, 0.1f);

   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

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

        // 4rth cube in tail left side

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


   glEnd();  // End of drawing color-cube


   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   gluPerspective(70.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(840, 680);
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
