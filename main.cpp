#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <math.h>
#include <stdio.h>	// Header File For Standard Input / Output
#include <stdarg.h>	// Header File For Variable Argument Routines
#include <string.h>

//texturas

#define false 0
#define true 1


struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
};

typedef struct Image Image;

int flag=0;

static unsigned int getint(FILE *fp)
{
  int c, c1, c2, c3;

  /*  get 4 bytes */
  c = getc(fp);
  c1 = getc(fp);
  c2 = getc(fp);
  c3 = getc(fp);

  return ((unsigned int) c) +
    (((unsigned int) c1) << 8) +
    (((unsigned int) c2) << 16) +
    (((unsigned int) c3) << 24);
}

static unsigned int getshort(FILE* fp)
{
  int c, c1;

  /* get 2 bytes*/
  c = getc(fp);
  c1 = getc(fp);

  return ((unsigned int) c) + (((unsigned int) c1) << 8);
}




// Function Prototypes
void init(void);
void LoadTexture(void);
int LoadBMP(char *filename, Image *image);
void display(void);
void reshape(int w, int h);
void Keyboard(unsigned char key,int x,int y);
void Timer(int notUsed);
void Piramide(int z);
void Tunel(int z , int init);

// Global Variables ----------------------------------------------------------

GLuint texture_id[1];

float			xrot;			// X Rotation ( NEW )
float			yrot;			// Y Rotation ( NEW )
float			zrot;			// Z Rotation ( NEW )

static GLfloat ang = 0.0, ang2=0.0;
int  nRots = 0, start = 0;
float tunel_pos[12] ={0,5,10,15,20,25,30,35,40,45,50,55} ,tunel1=0 ,rot = 0;

// LoadGLTextures ----------------------------------------------------------

void LoadTexture(void)
{
	Image *TextureImage;

	TextureImage = (Image *) malloc(sizeof(Image));

	if (TextureImage == NULL)
	{
		printf("Error allocating space for image");
		exit(1);
	}


	LoadBMP("1.bmp", TextureImage);
	//LoadBMP("C:\\Users\\pedro\\Desktop\\5� Ano\\2sem\\CG\\game3D\\bin\\Debug\\tex1.bmp", TextureImage);

	glGenTextures(1, &texture_id[0]);

	glBindTexture(GL_TEXTURE_2D, texture_id[0]);

	glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage->sizeX, TextureImage->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage->data);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);		// Create The Texture

	free (TextureImage->data);
	free( TextureImage );

}

//--------- loading image BMP

int LoadBMP(char *filename, Image *image) {
    FILE *file;
    unsigned long size;                 /*  size of the image in bytes. */
    unsigned long i;                    /*  standard counter. */
    unsigned short int planes;          /*  number of planes in image (must be 1)  */
    unsigned short int bpp;             /*  number of bits per pixel (must be 24) */
    char temp;                          /*  used to convert bgr to rgb color. */

    /*  make sure the file is there. */
    if ((file = fopen(filename, "rb"))==NULL) {
      printf("File Not Found : %s\n",filename);
      return 0;
    }

    /*  seek through the bmp header, up to the width height: */
    fseek(file, 18, SEEK_CUR);

    /*  No 100% errorchecking anymore!!! */

    /*  read the width */    image->sizeX = getint (file);

    /*  read the height */
    image->sizeY = getint (file);

    /*  calculate the size (assuming 24 bits or 3 bytes per pixel). */
    size = image->sizeX * image->sizeY * 3;

    /*  read the planes */
    planes = getshort(file);
    if (planes != 1) {
	printf("Planes from %s is not 1: %u\n", filename, planes);
	return 0;
    }

    /*  read the bpp */
    bpp = getshort(file);
    if (bpp != 24) {
      printf("Bpp from %s is not 24: %u\n", filename, bpp);
      return 0;
    }

    /*  seek past the rest of the bitmap header. */
    fseek(file, 24, SEEK_CUR);

    /*  read the data.  */
    image->data = (char *) malloc(size);
    if (image->data == NULL) {
	printf("Error allocating memory for color-corrected image data");
	return 0;
    }

    if ((i = fread(image->data, size, 1, file)) != 1) {
	printf("Error reading image data from %s.\n", filename);
	return 0;
    }

    for (i=0;i<size;i+=3) { /*  reverse all of the colors. (bgr -> rgb) */
      temp = image->data[i];
      image->data[i] = image->data[i+2];
      image->data[i+2] = temp;
    }

    fclose(file); /* Close the file and release the filedes */

    /*  we're done. */
    return 1;
}

void Piramide(int z)
{	glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, texture_id[0]);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
		
	glBegin(GL_TRIANGLES);                         

		//frente
		glNormal3f(0.6,0.4,-1.0);    
          	glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0, 0); glVertex3f(-12.0, -sqrt(507),z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(1, 0); glVertex3f(12.0, -sqrt(507),z + 0.0);
            glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0.5, 1); glVertex3f(0.0,0.0,z + 0.0);


		//direita
		glNormal3f(0.4,0.6,0.0);
             //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0, 0); glVertex3f(12.0, -sqrt(507),z + 0.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(1, 0); glVertex3f(12.0, -sqrt(507), z +5.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0.5, 1); glVertex3f(0.0,0.0,z + 0.0);

		//atras
		glNormal3f(-0.6,-0.4,1.0);
           //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0, 0); glVertex3f(-12.0, -sqrt(507),z + 5.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(1, 0); glVertex3f(12.0, -sqrt(507),z + 5.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0.5, 1); glVertex3f(0.0,0.0,z + 0.0);


		//esquerda
		glNormal3f(-0.4,-0.6,0.0);
             //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0, 0); glVertex3f(-12.0, -sqrt(507),z + 5.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(1, 0); glVertex3f(-12.0, -sqrt(507),z + 0.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0.5, 1); glVertex3f(0.0,0.0,z + 0.0);

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
  
	//luz
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat mat_shininess[] = { 70.0 };
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

//	glRotatef(rot , 0 , 1 , 0);
// 	Piramide(0);
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
		case 27 :       exit(0); break;
		case 'w':	Timer(0); break;
		case 't':	LoadTexture(); break;
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
 //  Timer(0);
   glutMainLoop();
   return 0;
}
