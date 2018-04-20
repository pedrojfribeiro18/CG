#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>


static GLfloat ang = 0.0, ang2=0.0;
int flag = 0; 
float tunel1 = 0,rot = 0;


void Piramide(int z)
{
	glRotatef(ang, 0, 1, 0);
	glBegin(GL_TRIANGLES);                         
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-12.0, -sqrt(507),z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(12.0, -sqrt(507),z + 0.0);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(12.0, -sqrt(507),z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(12.0, -sqrt(507), z +5.0);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-12.0, -sqrt(507),z + 5.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(12.0, -sqrt(507),z + 5.0);

            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-12.0, -sqrt(507),z + 5.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-12.0, -sqrt(507),z + 0.0);

        glEnd();
	

}




void Tunel(int z , int rot)
{
 



   glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 26.0, 0.0, z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, sqrt(507), z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, sqrt(507), z+5);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 26.0, 0.0, z+5);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, sqrt(507), z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, sqrt(507), z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, sqrt(507), z+5.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, sqrt(507), z+5.0);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-26.0, 0.0, z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-13.0, sqrt(507), z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-13.0, sqrt(507), z+5.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-26.0, 0.0, z+5.0);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-26.0, 0.0, z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, -sqrt(507), z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, -sqrt(507), z+5.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-26.0, 0.0, z+5.0);

        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-13.0, -sqrt(507), z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, -sqrt(507), z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, -sqrt(507), z+5.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-13.0, -sqrt(507), z+5.0);

        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 26.0, 0.0, z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, -sqrt(507), z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, -sqrt(507), z+5.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 26.0, 0.0, z+5.0);


    glEnd();
	
	
	Piramide(z);
		

}



void init(void)
{
   glClearColor (0.8, 0.6, 0.1, 1.0);
   glShadeModel (GL_SMOOTH);
   glEnable( GL_DEPTH_TEST );
  
}


void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	
	glPushMatrix();
	glRotatef(rot , 0 , 0 , 1);
 	Tunel(tunel1  , 0.0f);
	Tunel(tunel1+5 ,60.0f);
	Tunel(tunel1+10 , 0.0f);
 	Tunel(tunel1+15 ,60.0f);
	Tunel(tunel1+20 , 0.0f);
	Tunel(tunel1+25 ,60.0f);
 	Tunel(tunel1+30 , 0.0f);
	Tunel(tunel1+35 ,60.0f);
	

   	glPopMatrix();

   glutSwapBuffers();

}

void Timer(int notUsed){

	tunel1 = tunel1 -1;
	rot++;
	if(tunel1 == -30) tunel1 = 6;
	glutPostRedisplay();	
	glutTimerFunc(40, Timer, 0);
}


void reshape(int w, int h)
{
   glViewport (100, 80, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-30.0, 30.0, -30.0, 30.0,5,100.0);

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   gluLookAt(0,0,-6, 0,0,7, 0,1,0);
}


/*
 *  Request double buffer display mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (800, 600);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Vai com calma!!");
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   Timer(0);
   glutMainLoop();
   return 0;
}
