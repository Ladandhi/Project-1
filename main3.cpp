#include <windows.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>
#include <math.h>

float xrot =0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mouseDown = false;




//Deklarasi pengaturan lembaran kerja agar Gambar 3d yang kita buat saat diputar atau di geser tidak kemana mana
void ukur(int lebar, int tinggi){
if(tinggi==0) tinggi=1;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45,lebar/tinggi, 5, 450);
glTranslatef(0,0,-300);// jarak object dari lembaran kerja
glMatrixMode(GL_MODELVIEW);
}
void myinit(void){
glClearColor (1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glEnable(GL_DEPTH_TEST);

glMatrixMode(GL_MODELVIEW);
glPointSize(10.0);
glLineWidth(7.0f);
}

//Dan selanjutnya yaitu fungsi mouse
void idle()
{
if (!mouseDown)
{
xrot += 0.3;
yrot += 0.4;
}
glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
mouseDown = true;
xdiff = x - yrot;
ydiff = -y + xrot;
}
else
mouseDown = false;
}

void mouseMotion(int x, int y)
{
if(mouseDown)
{
yrot = x - xdiff;
xrot = y + ydiff;
glutPostRedisplay();
}
}

//Dibawah ini dimulai koding untuk membuat object
void tampilan(void){
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(0,0,3,0,0,0,0,1,0);
glRotatef(xrot, 1, 0,0);
glRotatef(yrot, 0,1,0);
glPushMatrix();


//Remot
glBegin(GL_POLYGON);//ATAS
glColor3f(-9,-9,-9);
glVertex3f(-50,15,22);
glVertex3f(50,15,22);
glVertex3f(50,15,-10);
glVertex3f(-50,15,-10);
glEnd();
glBegin(GL_POLYGON);//BAWAH
glColor3f(-9,-9,-9);
glVertex3f(-50,5,18);
glVertex3f(50,5,18);
glVertex3f(50,5,-6);
glVertex3f(-50,5,-6);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(-9,-9,-9);
glVertex3f(50,5,18);
glVertex3f(50,15,22);
glVertex3f(50,15,-10);
glVertex3f(50,5,-6);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(-9,-9,-9);
glVertex3f(-50,5,18);
glVertex3f(-50,15,22);
glVertex3f(-50,15,-10);
glVertex3f(-50,5,-6);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(-9,-9,-9);
glVertex3f(-50,5,18);
glVertex3f(-50,15,22);
glVertex3f(50,15,22);
glVertex3f(50,5,18);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(-9,-9,-9);
glVertex3f(-50,5,-6);
glVertex3f(-50,15,-10);
glVertex3f(50,15,-10);
glVertex3f(50,5,-6);
glEnd();

//Tombol Remot ON/OFF
glBegin(GL_POLYGON);//ATAS
glColor3f(-1,1,-1);
glVertex3f(40,18,20);
glVertex3f(45,18,20);
glVertex3f(45,18,12);
glVertex3f(40,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(-1,1,-1);
glVertex3f(45,18,20);
glVertex3f(45,15,20);
glVertex3f(45,15,12);
glVertex3f(45,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(-1,1,-1);
glVertex3f(40,18,20);
glVertex3f(40,15,20);
glVertex3f(40,15,12);
glVertex3f(40,18,12);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(-1,1,-1);
glVertex3f(40,18,20);
glVertex3f(40,15,20);
glVertex3f(45,15,20);
glVertex3f(45,18,20);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(-1,1,-1);
glVertex3f(40,18,12);
glVertex3f(40,15,12);
glVertex3f(45,15,12);
glVertex3f(45,18,12);
glEnd();


//Tombol Remot ECO
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(40,18,-8);
glVertex3f(45,18,-8);
glVertex3f(45,18,0);
glVertex3f(40,18,0);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(45,18,-8);
glVertex3f(45,15,-8);
glVertex3f(45,15,0);
glVertex3f(45,18,0);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(40,18,-8);
glVertex3f(40,15,-8);
glVertex3f(40,15,0);
glVertex3f(40,18,0);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(40,18,-8);
glVertex3f(40,15,-8);
glVertex3f(45,15,-8);
glVertex3f(45,18,-8);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(40,18,0);
glVertex3f(40,15,0);
glVertex3f(45,15,0);
glVertex3f(45,18,0);
glEnd();

//Tombol Remot 1
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,20);
glVertex3f(30,18,20);
glVertex3f(30,18,12);
glVertex3f(35,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(30,18,20);
glVertex3f(30,15,20);
glVertex3f(30,15,12);
glVertex3f(30,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,20);
glVertex3f(35,15,20);
glVertex3f(35,15,12);
glVertex3f(35,18,12);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,20);
glVertex3f(35,15,20);
glVertex3f(30,15,20);
glVertex3f(30,18,20);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,12);
glVertex3f(35,15,12);
glVertex3f(30,15,12);
glVertex3f(30,18,12);
glEnd();

//Tombol Remot 2 
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,10);
glVertex3f(30,18,10);
glVertex3f(30,18,2);
glVertex3f(35,18,2);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(30,18,10);
glVertex3f(30,15,10);
glVertex3f(30,15,2);
glVertex3f(30,18,2);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,10);
glVertex3f(35,15,10);
glVertex3f(35,15,2);
glVertex3f(35,18,2);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,10);
glVertex3f(35,15,10);
glVertex3f(30,15,10);
glVertex3f(30,18,10);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,2);
glVertex3f(35,15,2);
glVertex3f(30,15,2);
glVertex3f(30,18,2);
glEnd();


//Tombol Remot 3
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,0);
glVertex3f(30,18,0);
glVertex3f(30,18,-8);
glVertex3f(35,18,-8);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(30,18,0);
glVertex3f(30,15,0);
glVertex3f(30,15,-8);
glVertex3f(30,18,-8);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,0);
glVertex3f(35,15,0);
glVertex3f(35,15,-8);
glVertex3f(35,18,-8);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,0);
glVertex3f(35,15,0);
glVertex3f(30,15,0);
glVertex3f(30,18,0);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(35,18,-8);
glVertex3f(35,15,-8);
glVertex3f(30,15,-8);
glVertex3f(30,18,-8);
glEnd();

//Tombol Remot 4
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,20);
glVertex3f(20,18,20);
glVertex3f(20,18,12);
glVertex3f(25,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(20,18,20);
glVertex3f(20,15,20);
glVertex3f(20,15,12);
glVertex3f(20,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,20);
glVertex3f(25,15,20);
glVertex3f(25,15,12);
glVertex3f(25,18,12);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,20);
glVertex3f(25,15,20);
glVertex3f(20,15,20);
glVertex3f(20,18,20);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,12);
glVertex3f(25,15,12);
glVertex3f(20,15,12);
glVertex3f(20,18,12);
glEnd();

//Tombol Remot 5 
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,10);
glVertex3f(20,18,10);
glVertex3f(20,18,2);
glVertex3f(25,18,2);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(20,18,10);
glVertex3f(20,15,10);
glVertex3f(20,15,2);
glVertex3f(20,18,2);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,10);
glVertex3f(25,15,10);
glVertex3f(25,15,2);
glVertex3f(25,18,2);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,10);
glVertex3f(25,15,10);
glVertex3f(20,15,10);
glVertex3f(20,18,10);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,2);
glVertex3f(25,15,2);
glVertex3f(20,15,2);
glVertex3f(20,18,2);
glEnd();


//Tombol Remot 6
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,0);
glVertex3f(20,18,0);
glVertex3f(20,18,-8);
glVertex3f(25,18,-8);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(20,18,0);
glVertex3f(20,15,0);
glVertex3f(20,15,-8);
glVertex3f(20,18,-8);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,0);
glVertex3f(25,15,0);
glVertex3f(25,15,-8);
glVertex3f(25,18,-8);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,0);
glVertex3f(25,15,0);
glVertex3f(20,15,0);
glVertex3f(20,18,0);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(25,18,-8);
glVertex3f(25,15,-8);
glVertex3f(20,15,-8);
glVertex3f(20,18,-8);
glEnd();

//Tombol Remot 7
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,20);
glVertex3f(10,18,20);
glVertex3f(10,18,12);
glVertex3f(15,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(10,18,20);
glVertex3f(10,15,20);
glVertex3f(10,15,12);
glVertex3f(10,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,20);
glVertex3f(15,15,20);
glVertex3f(15,15,12);
glVertex3f(15,18,12);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,20);
glVertex3f(15,15,20);
glVertex3f(10,15,20);
glVertex3f(10,18,20);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,12);
glVertex3f(15,15,12);
glVertex3f(10,15,12);
glVertex3f(10,18,12);
glEnd();

//Tombol Remot 8 
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,10);
glVertex3f(10,18,10);
glVertex3f(10,18,2);
glVertex3f(15,18,2);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(10,18,10);
glVertex3f(10,15,10);
glVertex3f(10,15,2);
glVertex3f(10,18,2);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,10);
glVertex3f(15,15,10);
glVertex3f(15,15,2);
glVertex3f(15,18,2);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,10);
glVertex3f(15,15,10);
glVertex3f(10,15,10);
glVertex3f(10,18,10);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,2);
glVertex3f(15,15,2);
glVertex3f(10,15,2);
glVertex3f(10,18,2);
glEnd();

//Tombol Remot 9
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,0);
glVertex3f(10,18,0);
glVertex3f(10,18,-8);
glVertex3f(15,18,-8);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(10,18,0);
glVertex3f(10,15,0);
glVertex3f(10,15,-8);
glVertex3f(10,18,-8);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,0);
glVertex3f(15,15,0);
glVertex3f(15,15,-8);
glVertex3f(15,18,-8);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,0);
glVertex3f(15,15,0);
glVertex3f(10,15,0);
glVertex3f(10,18,0);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(15,18,-8);
glVertex3f(15,15,-8);
glVertex3f(10,15,-8);
glVertex3f(10,18,-8);
glEnd();

//Tombol Remot 0
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(5,18,10);
glVertex3f(0,18,10);
glVertex3f(0,18,2);
glVertex3f(5,18,2);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(0,18,10);
glVertex3f(0,15,10);
glVertex3f(0,15,2);
glVertex3f(0,18,2);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(5,18,10);
glVertex3f(5,15,10);
glVertex3f(5,15,2);
glVertex3f(5,18,2);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(5,18,10);
glVertex3f(5,15,10);
glVertex3f(0,15,10);
glVertex3f(0,18,10);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(5,18,2);
glVertex3f(5,15,2);
glVertex3f(0,15,2);
glVertex3f(0,18,2);
glEnd();

//Tombol Remot PANJANG KANAN
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-5,18,20);
glVertex3f(-20,18,20);
glVertex3f(-20,18,12);
glVertex3f(-5,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-20,18,20);
glVertex3f(-20,15,20);
glVertex3f(-20,15,12);
glVertex3f(-20,18,12);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-5,18,20);
glVertex3f(-5,15,20);
glVertex3f(-5,15,12);
glVertex3f(-5,18,12);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-5,18,20);
glVertex3f(-5,15,20);
glVertex3f(-20,15,20);
glVertex3f(-20,18,20);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-5,18,12);
glVertex3f(-5,15,12);
glVertex3f(-20,15,12);
glVertex3f(-20,18,12);
glEnd();

//Tombol Remot PANJANG KIRI
glBegin(GL_POLYGON);//ATAS
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-5,18,0);
glVertex3f(-20,18,0);
glVertex3f(-20,18,-8);
glVertex3f(-5,18,-8);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-20,18,0);
glVertex3f(-20,15,0);
glVertex3f(-20,15,-8);
glVertex3f(-20,18,-8);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-5,18,0);
glVertex3f(-5,15,0);
glVertex3f(-5,15,-8);
glVertex3f(-5,18,-8);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-5,18,0);
glVertex3f(-5,15,0);
glVertex3f(-20,15,0);
glVertex3f(-20,18,0);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(0.75, 0.75, 0.75);
glVertex3f(-5,18,-8);
glVertex3f(-5,15,-8);
glVertex3f(-20,15,-8);
glVertex3f(-20,18,-8);
glEnd();

//Tombol Remot WARNA MERAH
glBegin(GL_POLYGON);//ATAS
glColor3f(1,-1,-1);
glVertex3f(-25,18,19);
glVertex3f(-30,18,19);
glVertex3f(-30,18,14);
glVertex3f(-25,18,14);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(1,-1,-1);
glVertex3f(-30,18,19);
glVertex3f(-30,15,19);
glVertex3f(-30,15,14);
glVertex3f(-30,18,14);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(1,-1,-1);
glVertex3f(-25,18,19);
glVertex3f(-25,15,19);
glVertex3f(-25,15,14);
glVertex3f(-25,18,14);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(1,-1,-1);
glVertex3f(-25,18,19);
glVertex3f(-25,15,19);
glVertex3f(-30,15,19);
glVertex3f(-30,18,19);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(1,-1,-1);
glVertex3f(-25,18,14);
glVertex3f(-25,15,14);
glVertex3f(-30,15,14);
glVertex3f(-30,18,14);
glEnd();

//Tombol Remot WARNA UNGU
glBegin(GL_POLYGON);//ATAS
glColor3f(1,-1,1);
glVertex3f(-25,18,12);
glVertex3f(-30,18,12);
glVertex3f(-30,18,7);
glVertex3f(-25,18,7);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(1,-1,1);
glVertex3f(-30,18,12);
glVertex3f(-30,15,12);
glVertex3f(-30,15,7);
glVertex3f(-30,18,7);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(1,-1,1);
glVertex3f(-25,18,12);
glVertex3f(-25,15,12);
glVertex3f(-25,15,7);
glVertex3f(-25,18,7);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(1,-1,1);
glVertex3f(-25,18,12);
glVertex3f(-25,15,12);
glVertex3f(-30,15,12);
glVertex3f(-30,18,12);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(1,-1,1);
glVertex3f(-25,18,7);
glVertex3f(-25,15,7);
glVertex3f(-30,15,7);
glVertex3f(-30,18,7);
glEnd();

//Tombol Remot WARNA BIRU
glBegin(GL_POLYGON);//ATAS
glColor3f(-1,-1,1);
glVertex3f(-25,18,5);
glVertex3f(-30,18,5);
glVertex3f(-30,18,0);
glVertex3f(-25,18,0);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(-1,-1,1);
glVertex3f(-30,18,5);
glVertex3f(-30,15,5);
glVertex3f(-30,15,0);
glVertex3f(-30,18,0);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(-1,-1,1);
glVertex3f(-25,18,5);
glVertex3f(-25,15,5);
glVertex3f(-25,15,0);
glVertex3f(-25,18,0);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(-1,-1,1);
glVertex3f(-25,18,5);
glVertex3f(-25,15,5);
glVertex3f(-30,15,5);
glVertex3f(-30,18,5);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(-1,-1,1);
glVertex3f(-25,18,0);
glVertex3f(-25,15,0);
glVertex3f(-30,15,0);
glVertex3f(-30,18,0);
glEnd();

//Tombol Remot  WARNA KUNING 
glBegin(GL_POLYGON);//ATAS
glColor3f(1,1,-1);
glVertex3f(-25,18,-2);
glVertex3f(-30,18,-2);
glVertex3f(-30,18,-7);
glVertex3f(-25,18,-7);
glEnd();
glBegin(GL_POLYGON);//SAMPING KANAN
glColor3f(1,1,-1);
glVertex3f(-30,18,-2);
glVertex3f(-30,15,-2);
glVertex3f(-30,15,-7);
glVertex3f(-30,18,-7);
glEnd();
glBegin(GL_POLYGON);//SAMPING KIRI
glColor3f(1,1,-1);
glVertex3f(-25,18,-2);
glVertex3f(-25,15,-2);
glVertex3f(-25,15,-7);
glVertex3f(-25,18,-7);
glEnd();
glBegin(GL_POLYGON);//DEPAN
glColor3f(1,1,-1);
glVertex3f(-25,18,-2);
glVertex3f(-25,15,-2);
glVertex3f(-30,15,-2);
glVertex3f(-30,18,-2);
glEnd();
glBegin(GL_POLYGON);//BELAKANG
glColor3f(1,1,-1);
glVertex3f(-25,18,-7);
glVertex3f(-25,15,-7);
glVertex3f(-30,15,-7);
glVertex3f(-30,18,-7);
glEnd();

glPushMatrix();
glPopMatrix();
glutSwapBuffers();
}


int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(240, 80);
    glutInitWindowSize(640, 480);
    glutCreateWindow("REMOT TV 3D");
    myinit();
    glutDisplayFunc(tampilan);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukur);
    glutMainLoop();
}
