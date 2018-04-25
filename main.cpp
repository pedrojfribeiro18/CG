#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <math.h>


static GLfloat ang = 0.0, ang2=0.0;
int flag = 0, nRots = 0;
float tunel_pos[12] ={0,5,10,15,20,25,30,35,40,45,50,55} ,tunel1=0 ,rot = 0;


void Piramide(int z)
{
	
	glBegin(GL_TRIANGLES);                         

		//frente
		glNormal3f(0.6,0.4,-1.0);    
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,z + 0.0);
	    glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-12.0, -sqrt(507),z + 0.0);
	    glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(12.0, -sqrt(507),z + 0.0);
		//direita
		glNormal3f(0.4,0.6,0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(12.0, -sqrt(507),z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(12.0, -sqrt(507), z +5.0);
		//atras
		glNormal3f(-0.6,-0.4,1.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(0.0,0.0,z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(-12.0, -sqrt(507),z + 5.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex3f(12.0, -sqrt(507),z + 5.0);
		//esquerda
		glNormal3f(-0.4,-0.6,0.0);
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
		//nordeste
	glNormal3f(-0.5,-0.5,0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 26.0, 0.0, z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, sqrt(507), z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, sqrt(507), z+5);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 26.0, 0.0, z+5);
		//norte
	glNormal3f(-1.0,0.0,0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, sqrt(507), z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, sqrt(507), z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f ( 13.0, sqrt(507), z+5.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, sqrt(507), z+5.0);
		//noroeste
	glNormal3f(0.5,-0.5,0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-26.0, 0.0, z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-13.0, sqrt(507), z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-13.0, sqrt(507), z+5.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-26.0, 0.0, z+5.0);
		//sudoeste
	glNormal3f(0.5,0.5,0.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-26.0, 0.0, z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, -sqrt(507), z);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-13.0, -sqrt(507), z+5.0);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f (-26.0, 0.0, z+5.0);
		//sul
	glNormal3f(1.0,0.0,0.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-13.0, -sqrt(507), z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, -sqrt(507), z);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f ( 13.0, -sqrt(507), z+5.0);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f (-13.0, -sqrt(507), z+5.0);
		//sudeste
	glNormal3f(-0.5,0.5,0.0);
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
				
	Piramide(z);
	glPopMatrix();		
	
}



void init(void)
{
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 50.0 };
   GLfloat light0_diffuse[] = {1.0, 1.0, 1.0, 0.0};	
   GLfloat light0_position[] = {0.0, 0.0, -10.0, 100.0};

   glClearColor (0.8, 0.6, 0.1, 1.0);
   glShadeModel (GL_SMOOTH);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glColorMaterial(GL_FRONT, GL_DIFFUSE);
   glEnable(GL_COLOR_MATERIAL);
   glEnable(GL_NORMALIZE);
   glEnable( GL_DEPTH_TEST );
  
}


void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   	
	glPushMatrix();
	
	glRotatef(rot , 0 , 0 , 1);
 	Tunel(tunel_pos[0]  , 0.0f);
	Tunel(tunel_pos[1]  ,60.0f);
	Tunel(tunel_pos[2]  , 0.0f);
 	Tunel(tunel_pos[3]  ,60.0f);
	Tunel(tunel_pos[4]  , 0.0f);
	Tunel(tunel_pos[5]  ,60.0f);
 	Tunel(tunel_pos[6]  , 0.0f);
	Tunel(tunel_pos[7]  ,60.0f);
	Tunel(tunel_pos[8]  , 0.0f);
 	Tunel(tunel_pos[9]  ,60.0f);
	Tunel(tunel_pos[10] , 0.0f);
	Tunel(tunel_pos[11] ,60.0f);

  	glPopMatrix();
	
   glutSwapBuffers();

}

void Timer(int flag){

	if(flag == 0){ //movimento do tunel
		for(int i = 0; i<12 ; i++){	
			if(tunel_pos[i] <= -10) tunel_pos[i] += 55;
			tunel_pos[i] -= 1;	
		}
		glutPostRedisplay();	
		glutTimerFunc(80, Timer, 0);
		}
	
	if(flag == 1){ // rodar para esquerda
		rot -= 20.0;
		glutPostRedisplay();
		nRots--;
		if(nRots > 0)
			glutTimerFunc(40, Timer, 1);
	}		

	if(flag == 2){ // rodar para direita
		rot += 20.0;
		glutPostRedisplay();
		nRots--;
		if(nRots > 0)
			glutTimerFunc(40, Timer, 2);
	}
}


void reshape(int w, int h)
{
   glViewport (20, 10, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-5.0, 5.0, -5.0, 5.0,1,70.0);

   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   gluLookAt(0,0,-2, 0,0,0, 0,1,0);
}




void Keyboard(unsigned char key,int x,int y)
{
	int i=0;
	switch(key){
		case 'a':	nRots=3; Timer(1); break;//y
		case 'd':	nRots=3; Timer(2); break;
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
