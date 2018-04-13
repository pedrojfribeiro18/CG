#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


static GLfloat spin = 0.0;


void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glColor3f(0.0, 0.0, 1.0);
   glRotatef(spin, 0.0, 0.0, 1.0);
   glBegin(GL_POLYGON);
        glVertex3f ( 26.0, 0.0, 0.0);
        glVertex3f ( 13.0, sqrt(507), 0.0);
        glVertex3f (-13.0, sqrt(507), 0.0);
        glVertex3f (-26.0, 0.0, 0.0);
        glVertex3f (-13.0, -sqrt(507), 0.0);
        glVertex3f ( 13.0, -sqrt(507), 0.0);

    glEnd();
   glPopMatrix();

   glPushMatrix();
   glColor3f(0.0, 1.0, 0.0);
   glRotatef(spin, 0.0, 0.0, 1.0);
   glBegin(GL_POLYGON);
        glVertex3f ( 26.0, 0.0, 25.0);
        glVertex3f ( 13.0, sqrt(507), 25.0);
        glVertex3f (-13.0, sqrt(507), 25.0);
        glVertex3f (-26.0, 0.0, 25.0);
        glVertex3f (-13.0, -sqrt(507), 50.0);
        glVertex3f ( 13.0, -sqrt(507), 50.0);

    glEnd();
   glPopMatrix();

   glutSwapBuffers();
}

void spinDisplay(void)
{
   spin = spin + 2.0;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}

void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 51.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
   switch (button) {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay);
         break;
      case GLUT_MIDDLE_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
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
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}
