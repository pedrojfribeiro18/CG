#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


static GLfloat ang = 0.0, ang2=0.0;
int flag=0;


void init(void)
{
   glClearColor (0.8, 0.6, 0.1, 1.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();

   glRotatef(ang2, 1.0,1.0, 0.0);



   glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 26.0, 0.0, 0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, sqrt(507), 0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, sqrt(507), 5.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 26.0, 0.0, 5.0);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, sqrt(507), 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, sqrt(507), 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, sqrt(507), 5.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, sqrt(507), 5.0);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-26.0, 0.0, 0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-13.0, sqrt(507), 0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-13.0, sqrt(507), 5.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-26.0, 0.0, 5.0);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-26.0, 0.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, -sqrt(507), 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, -sqrt(507), 5.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-26.0, 0.0, 5.0);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-13.0, -sqrt(507), 0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, -sqrt(507), 0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, -sqrt(507), 5.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-13.0, -sqrt(507), 5.0);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 26.0, 0.0, 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, -sqrt(507), 0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, -sqrt(507), 5.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 26.0, 0.0, 5.0);


    glEnd();

    glPopMatrix();

    glPushMatrix();
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-13.0, -sqrt(507), 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(13.0, -sqrt(507), 0.0);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(13.0, -sqrt(507), 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(13.0, -sqrt(507), 5.0);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-13.0, -sqrt(507), 5.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(13.0, -sqrt(507), 5.0);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-13.0, -sqrt(507), 5.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-13.0, -sqrt(507), 0.0);




        glEnd();
    glPopMatrix();





   glutSwapBuffers();
}


void reshape(int w, int h)
{
   glViewport (20, 10, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-30.0, 30.0, -30.0, 30.0,5,50.0);

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   gluLookAt(0,0,-3, 0,0,0, 0,1,0);
}

void rato(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON)
        if(state == GLUT_DOWN)
            flag =1;
    if(button == GLUT_RIGHT_BUTTON)
        if(state == GLUT_UP)
            flag = 2;

    glutPostRedisplay();
}
void coordenadas(int x, int y){
    if(flag == 1)
       ang = x;

   if(flag == 2)
        ang2 = y;
    glutPostRedisplay();
}
/*
 *  Request double buffer display mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (800, 600);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Vai com calma!!");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMouseFunc(rato);
   glutMotionFunc(coordenadas);
   glutMainLoop();
   return 0;
}
