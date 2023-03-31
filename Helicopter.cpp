#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;


GLfloat baseAmbientLight[]={0.2,0.2,0.2,1.0};//grey

GLfloat baseDiffuseLight[3][4]={{0.5,0.1,0.8,1.0}, //violet   
                               {1.0,0.0,0.0,1.0}, //red
                              {1.0,0.8,0.6,1.0}};//wood

GLfloat helicopterAmbientLight[]={0.2,0.2,0.2,1.0};//grey

GLfloat helicopterDiffuseLight[3][4]={{0.4,0.8,0.0,1.0},//green
                               {0.7,0.7,0.4,1.0},//khakhi
                               {0.3,0.7,1.0,1.0}};//blue
																									   


                
//flags
int bc=0,hc=0;

//at coordinates
GLfloat at[]={0.0,0.0,0.0};


void init() {
    glClearColor(0.3,0.7,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1.0, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
}


void draw_tail(int i)
{
 //tail of heli
 glPushMatrix();
 	glDisable(GL_LIGHTING);
	glColor4f(0.75294117647058823529411764705882,0.75294117647058823529411764705882,0.75294117647058823529411764705882,1.0);//grey

 glBegin(GL_LINE_LOOP);
 glVertex3f(1.2,-2.0+i,-9.0);
 glVertex3f(-1.2,-2.0+i,-9.0);
 glVertex3f(-0.2,-0.2+i,-29.0);
 glVertex3f(0.2,-0.2+i,-29.0);
 glEnd();

 	glEnable(GL_LIGHTING);

 glPopMatrix();

}

void draw_leg(int i)
{
 glPushMatrix();

 	glDisable(GL_LIGHTING);
	glColor4f(0.7,0.7,0.7,1.0);//grey

 glBegin(GL_LINES);
 //first leg
 glVertex3f(5,-7+i,7);
 glVertex3f(5,-7+i,-7);

 glVertex3f(5,-7+i,7);
 glVertex3f(5,-6+i,8);

 glVertex3f(5,-7+i,-7);
 glVertex3f(5,-6+i,-8);
 
 glVertex3f(0,0.0+i,5);
 glVertex3f(5,-7.0+i,5);

 glVertex3f(0,0.0+i,-5);
 glVertex3f(5,-7.0+i,-5);

  glVertex3f(-5,-7+i,7);
 glVertex3f(-5,-7+i,-7);
 
 //second leg
 glVertex3f(-5,-7+i,7);
 glVertex3f(-5,-6+i,8);

 glVertex3f(-5,-7+i,-7);
 glVertex3f(-5,-6+i,-8);
 
 glVertex3f(0,0.0+i,5);
 glVertex3f(-5,-7.0+i,5);

 glVertex3f(0,0.0+i,-5);
 glVertex3f(-5,-7.0+i,-5);

 glEnd();

 	glEnable(GL_LIGHTING);

 glPopMatrix();
}

void draw_house()
{
	glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,baseAmbientLight);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,baseDiffuseLight[1]);
	glTranslatef(25.0,0.0,-10.0);
	glutSolidCube(10.0);
	glTranslatef(25.0,-150.0,-10.0);
	glPopMatrix();
}

void draw_rotor(int i)
{
	glPushMatrix();   
	glDisable(GL_LIGHTING);
	glColor4f(0.7,0.7,0.7,1.0);//silver
	glLineWidth(5.0);
	glBegin(GL_LINES);//fan stick
	glVertex3f(0.0, 0.0+i, 0.0);
	glVertex3f(0.0, 10.0+i, 0.0);
	glEnd();
    glScalef(2.0, 1.0, 2.0);


	//rotor blade 1
	glPushMatrix();
	glRotatef(0.0, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);

	glVertex3f(0.0, 10.0+i, -0.5);
	glVertex3f(10.0, 10.0+i, -1.0);
	glVertex3f(10.0, 10.0+i, 1.0);
	glVertex3f(0.0, 10.0+i, 0.5);
	
	glEnd();
	glPopMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);

    //rotor blade 2
	glPushMatrix();
	glRotatef(0.0, 0.0, 1.0, 0.0);

	glBegin(GL_QUADS);
	glVertex3f(0.0, 10.0+i, -0.5);
	glVertex3f(10.0, 10.0+i, -1.0);
	glVertex3f(10.0, 10.0+i, 1.0);
	glVertex3f(0.0, 10.0+i, 0.5);
	glEnd();
	glPopMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glPushMatrix();
	glRotatef(0.0, 0.0, 1.0, 0.0);

	// roter blade 3
	glPushMatrix();
	glRotatef(0.0, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 10.0+i, -0.5);
	glVertex3f(10.0, 10.0+i, -1.0);
	glVertex3f(10.0, 10.0+i, 1.0);
	glVertex3f(0.0, 10.0+i, 0.5);
	glEnd();
	glPopMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);

	//rotor blade 4
	glPushMatrix();
	glRotatef(0.0, 0.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.0, 10.0+i, -0.5);
	glVertex3f(10.0, 10.0+i, -1.0);
	glVertex3f(10.0, 10.0+i, 1.0);
	glVertex3f(0.0, 10.0+i, 0.5);
	glEnd();
	glPopMatrix();
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glEnable(GL_LIGHTING);
	glPopMatrix();

}



void draw_helipad()
{
	glPushMatrix();

	glDisable(GL_LIGHTING);
	glColor3f(0.125,0.125,0.125);

	
	glTranslatef(0.0,-9.0,-1.0);
	glRotatef(-90.0,1.0,0.0,0.0);
	glScalef(1.0,1.0,0.1);
	glutSolidTorus(13.0,13.0,100,100);
   glScalef(1.0,1.0,1.0);

	glLineWidth(25.0);
	glColor3f(1.0,1.0,1.0);

	glBegin(GL_QUADS);
	//write H
	glVertex3f(-9.5,-1.5,16);
	glVertex3f(-9.5,1.5,16);
	glVertex3f(9.5,1.5,16);
	glVertex3f(9.5,-1.5,16);

	glVertex3f(9.5,11.5,16);
	glVertex3f(9.5,-11.5,16);
	glVertex3f(11.5,-11.5,16);
	glVertex3f(11.5,11.5,16);

	glVertex3f(-9.5,11.5,16);
	glVertex3f(-9.5,-11.5,16);
	glVertex3f(-11.5,-11.5,16);
	glVertex3f(-11.5,11.5,16);
	glEnd();
	glEnable(GL_LIGHTING);
	glPopMatrix();

}

void draw_body(int i)
{
	
	glPushMatrix();
	glTranslatef(0.0, 0.0+i, -1.0);
	glutSolidSphere(5.0, 32, 32);
	glPopMatrix();  
}

void draw_heli() 
{
    glPushMatrix();
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,helicopterAmbientLight);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,helicopterDiffuseLight[hc]);	
	glPopMatrix();
	
}

void draw_grass()
{
	glPushMatrix();
   	glDisable(GL_LIGHTING);
	glColor3f(0.13333,0.545098,0.13333);//forest green
	double i;
	glBegin(GL_LINES); //draw mesh
	for(i=-2500.0;i<=2500;i+=0.5)
	{	
		glVertex3d(-2500,-11,i);
		glVertex3d(2500,-11,i);
		glVertex3d(i,-11,-2500);
		glVertex3d(i,-11,2500);
	
	}
	glEnd();
	glEnable(GL_LIGHTING);
	draw_helipad();
	glPopMatrix();

}

int i=0;
void keyboard(unsigned char key, int x, int y) {
	
    switch (key) {
    case 't':
    	if(i<25){
		
    	i=i+5;
    }
        break;
    case 'd':
    	if(i>0){
		
        i=i-5; 
    }
        break;

    }
}

void drawNumberOne(float x, float y)
{
    glRasterPos2f(x, y); // Set the position for drawing
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1'); // Draw the character
}

void drawNumberni(float x, float y)
{
    glRasterPos2f(x, y); // Set the position for drawing
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '9'); // Draw the character
}
void drawNumberze(float x, float y)
{
    glRasterPos2f(x, y); // Set the position for drawing
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0'); // Draw the character
}
void drawNumberte(float x, float y)
{
    glRasterPos2f(x, y); // Set the position for drawing
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '3'); // Draw the character
}
void drawNumbersi(float x, float y)
{
    glRasterPos2f(x, y); // Set the position for drawing
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '6'); // Draw the character
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 50.0, 200.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glRotatef(0, 0.0, 1.0, 0.0);
	draw_grass();
	drawNumberOne(20+15,-90);
	drawNumberOne(25+15,-90);
	drawNumberni(30+15, -90);
	drawNumberze(35+15, -90);
	drawNumberte(40+15,-90);
	drawNumberze(45+15, -90);
	drawNumberni(50+15, -90);
	drawNumbersi(55+15, -90);
	draw_leg(i);
	draw_rotor(i);
	draw_body(i);
	draw_tail(i);
	glFlush();
	draw_house();
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("Helicopter Takeoff and Landing");
    init();    
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

