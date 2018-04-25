#include <stdio.h>			// Header File For Standard Input / Output
#include <stdarg.h>			// Header File For Variable Argument Routines
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<stdlib.h>
#include <math.h>


#define false 0
#define true 1


static GLfloat ang = 0.0, ang2=0.0;
int X=0 , Y=0 , Z=0;
float tunel_pos[12] ={0,5,10,15,20,25,30,35,40,45,50,55} ,tunel1=0 ,rot = 0;



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


	//LoadBMP("Logo.bmp", TextureImage);
	LoadBMP("C:\\Users\\pedro\\Desktop\\5º Ano\\2sem\\CG\\game3D\\bin\\Debug\\tex1.bmp", TextureImage);

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
{


    glBindTexture(GL_TEXTURE_2D, texture_id[0]);

	glBegin(GL_TRIANGLES);

            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0, 0); glVertex3f(-12.0, -sqrt(507),z + 0.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(1, 0); glVertex3f(12.0, -sqrt(507),z + 0.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0.5, 1); glVertex3f(0.0,0.0,z + 0.0);


            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0, 0); glVertex3f(12.0, -sqrt(507),z + 0.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(1, 0); glVertex3f(12.0, -sqrt(507), z +5.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0.5, 1); glVertex3f(0.0,0.0,z + 0.0);


            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0, 0); glVertex3f(-12.0, -sqrt(507),z + 5.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(1, 0); glVertex3f(12.0, -sqrt(507),z + 5.0);
            //glColor3f(1.0f, 0.0f, 0.0f);
            glTexCoord2f(0.5, 1); glVertex3f(0.0,0.0,z + 0.0);


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

void Timer(int notUsed){

	tunel1 = tunel1 -1;

	if(tunel1 == -36) tunel1 = 0;
	glutPostRedisplay();
	glutTimerFunc(80, Timer, 0);
}



void init(void)
{

    LoadTexture();
    glEnable(GL_TEXTURE_2D);


    glClearColor (0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);
	glDepthFunc(GL_LESS);
    glShadeModel (GL_SMOOTH);
    glEnable( GL_DEPTH_TEST );

    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	glMatrixMode(GL_MODELVIEW);

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

void reshape(int w, int h)
{
   glViewport (20, 10, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glFrustum(-5.0, 5.0, -5.0, 5.0,1,70.0);


   glMatrixMode(GL_MODELVIEW);

   glLoadIdentity();
   gluLookAt(0,0,-10, 0,0,1, 0,1,0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

   // giving window size in X- and Y- direction
   glutInitWindowSize (800, 600);
   glutInitWindowPosition (0, 0);

   // Giving name to window
   glutCreateWindow ("Vai com calma!!");

   init ();

   glutDisplayFunc(display);

   glutReshapeFunc(reshape);
   glutKeyboardFunc(Keyboard);
   Timer(0);
   glutMainLoop();


   return 0;
}
