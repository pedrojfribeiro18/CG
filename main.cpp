#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <math.h>


static GLfloat ang = 0.0, ang2=0.0;
int flag = 0, X=0 , Y=0 , Z=0;
float tunel_pos[12] ={0,5,10,15,20,25,30,35,40,45,50,55} ,tunel1=0 ,rot = 0;


void Piramide(int z)
{
	
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




void Tunel(int z , int init)
{
 
   glRotatef(init , 0 , 0 , 1);

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
	

	   
	glPushMatrix();
	//glRotatef(40 , 0 , 1 , 0);	
	Piramide(z);
	glPopMatrix();		
	
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
 	Tunel(tunel1    , 0.0f);
	Tunel(tunel1+5  ,60.0f);
	Tunel(tunel1+10 , 0.0f);
 	Tunel(tunel1+15 ,60.0f);
	Tunel(tunel1+20 , 0.0f);
	Tunel(tunel1+25 ,60.0f);
 	Tunel(tunel1+30 , 0.0f);
	Tunel(tunel1+35 ,60.0f);
	Tunel(tunel1+40 , 0.0f);
 	Tunel(tunel1+45 ,60.0f);
	Tunel(tunel1+50 , 0.0f);
	Tunel(tunel1+55 ,60.0f);
 	
		

   	glPopMatrix();
	
   glutSwapBuffers();

}

void Timer(int notUsed){

	tunel1 = tunel1 -1;
	
	if(tunel1 == -36) tunel1 = 0;
	glutPostRedisplay();	
	glutTimerFunc(80, Timer, 0);
}


void reshape(int w, int h)
{
   glViewport (20, 10, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-5.0, 5.0, -5.0, 5.0,1,70.0);

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   gluLookAt(0,0,0, 0,0,1, 0,1,0);
}

void rodar(int dir){ // 0-direita 1-esquerda

	if(dir == 0){
		rot += 20;
	}

	else{

	}
}


void Keyboard(unsigned char key,int x,int y)
{
	int i=0;
	switch(key){
		case 'w':	X += 5;break;//x
		case 's':	X -= 5;break;
		case 'a':	rot -=20.0;break;//y
		case 'd':	rot += 20.0;break;
		case 'r':	Z += 5;break;//x
		case 'f':	Z -= 5;break;
		case 27:        exit(0);
	}

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
   glutKeyboardFunc(Keyboard);
   Timer(0);
   glutMainLoop();
   return 0;
}
