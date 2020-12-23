#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

//������������� ������ ������� ������ ������
static int w = 0, h = 0;
double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;

// ������� ���������� ����� ���������� � ������� ����
void init(void)
{
    glClearColor(0.0f, 0.8f, 1.0f, 1.0f);
}

// ������� ���������� ������ ���� - ��� ��� ���������, ���������� � ��.
void Update(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

// ������� ���������� ��� ��������� �������� ����
void Reshape(int width, int height)
{
    w = width;
    h = height;
}

//������� �����
int main1(int argc, char* argv[])
{
    // ���������������� glut
    glutInit(&argc, argv);

    // ���������� ��������� ��������� ����
    glutInitWindowPosition(100, 100);

    // ���������� ��������� ������� ����
    glutInitWindowSize(800, 600);

    // ���������� ��������� ���� - ������� ������������
    // � ��������� ����� rgba
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    // ������� ���� � ���������� OpenGL
    glutCreateWindow("OpenGL");

    // ������ glut �������, ������� ����� ���������� ������ ����
    glutIdleFunc(Update);

    // ������ glut �������, ������� ����� ���������� ���
    // ��������� ������� ���� ����������
    glutReshapeFunc(Reshape);
    init();

    // ����� � ������� ���� ����������
    glutMainLoop();

    return 0;
}

//���������� ���������
void specialKeys(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_UP: rotate_x += 5; break;
        case GLUT_KEY_DOWN: rotate_x -= 5; break;

        case GLUT_KEY_RIGHT: rotate_y += 5; break;
        case GLUT_KEY_LEFT: rotate_y -= 5; break;

        case GLUT_KEY_PAGE_UP: rotate_z += 5; break;
        case GLUT_KEY_PAGE_DOWN: rotate_z -= 5; break;
    }

    glutPostRedisplay();
}

// �������� � 2D  �������� ������ ������ ������. ������� � ����������� ���������
void renderRectangle()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(rotate_y, 0.0, 1.0, 0.0);

    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0, 1.0, 0.0); glVertex2f(-0.5f, 0.5f);
    glColor3f(1.0, 0.0, 1.0); glVertex2f(0.5f, 0.5f);
    glColor3f(1.0, 1.0, 1.0); glVertex2f(0.5f, -0.5f);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

int main2(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("2d �������");

    glutDisplayFunc(renderRectangle);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}

//�������� � 3D ���� (���������) � ��������������� ��������
void renderWireCube()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    glutWireCube(1);

    glFlush();
    glutSwapBuffers();
}

int main3(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL_HelloWorld");

    glutDisplayFunc(renderWireCube);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}


//�������� � 3D ���� (�������������) � ��������������� �������
void renderWireCube2()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    glutSolidCube(1);

    glFlush();
    glutSwapBuffers();
}

int main4(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL_HelloWorld");

    glutDisplayFunc(renderWireCube2);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}

double angle = 30;

// ������� ���������� ������ ���� - ��� ��� ���������, ���������� � ��.
void renderSphere()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // �������� ���������. ����
    glLoadIdentity();
    // ������� ������� ������, ����� ������. � ������ �����
    gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // �������� ������� �������� �� ������� �������
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    glColor3f(1, 1, 1);
    // �������� ����� �������� 50 ��., �������� 10x10 ���������
    glutWireSphere(50.0f, 10, 10);


    // �������� ��� ������ �� ��������� � �������� ��������������
    // OpegGL ��� �������� ���������� ���������� ����������
    glFlush();
    glutSwapBuffers();
}

// ������� ���������� ��� ��������� �������� ����
void Reshape5(int width, int height) {
    w = width; h = height;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // �������� ������� �������������� �������������� ������ ��
    // ��������� ���� ������, ��������� ������ � ������
    // � ���������� ������� � ������� ���������� ����������
    gluPerspective(65.0f, w / h, 1.0f, 1000.0f);
}

//�������� � 3D ����� - ������������� ��������
int main5(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow(" OpenGL_HelloWolrd ");
    glutReshapeFunc(Reshape5);
    glutDisplayFunc(renderSphere);
    glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}

void renderTeapot()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ������� ������� ������, ����� ������. � ������ �����
    gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // �������� ������� �������� �� ������� �������
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    glColor3f(1, 1, 1);
    glutWireTeapot(50);

    // �������� ��� ������ �� ��������� � �������� ��������������
    // OpegGL ��� �������� ���������� ���������� ����������
    glFlush();
    glutSwapBuffers();
}

//�������� � 3D ������� - ������������� ��������
int main6(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow(" OpenGL_HelloWolrd ");
    glutReshapeFunc(Reshape5);
    glutDisplayFunc(renderTeapot);
    glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}

void renderPoints() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // �������� ������� �������� �� ������� �������
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    glBegin(GL_POINTS);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);

    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    // �������� ��� ������ �� ��������� � �������� ��������������
    // OpegGL ��� �������� ���������� ���������� ����������
    glFlush();
    glutSwapBuffers();
}

//������� ��������� �����
int main7(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow(" OpenGL_HelloWolrd ");

    // �������� ������ ����� �� �������� 10 ��������
    glPointSize(10.0f);
    glutReshapeFunc(Reshape5);
    glutDisplayFunc(renderPoints);
    glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}

void render2Triangles()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ������� ������� ������, ����� ������. � ������ �����
    gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);


    // �������� ������� �������� �� ������� �������
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLES);
    // ������� - ������ ������� ���� ��( RGB)
    glColor3f(1.0f, 0.0f, 0.0f);

    // ������ ������� �����������
    glVertex3f(-75, 0.0f, -50);
    glVertex3f(-75, 0.0f, 50);
    glVertex3f(75, 0.0f, 50);

    // ������� - ������ ����� ���� ��( RGB)
    glColor3f(0.0f, 0.0f, 1.0f);

    // ������ ������ ����� �����������
    glVertex3f(-75.0f, 0.0f, -50.0f);
    glVertex3f(75.0f, 0.0f, -50.0f);
    glVertex3f(75.0f, 0.0f, 50.0f);
    glEnd();

    // �������� ��� ������ �� ��������� � �������� ��������������
    // OpegGL ��� �������� ���������� ���������� ����������
    glFlush();
    glutSwapBuffers();
}

//���  ������������ ������� �����
int main8(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow(" OpenGL_HelloWolrd ");
    glutReshapeFunc(Reshape5);
    glutDisplayFunc(render2Triangles);
    glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}

void renderTriangle()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ������� ������� ������, ����� ������. � ������ �����
    gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);
    GLfloat BlueCol[3] = { 0 , 0 , 1 };

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glColor3ub(0, 255, 0);
    glVertex3f(75.0, 0.0, 0.0);
    glColor3fv(BlueCol);
    glVertex3f(75.0, 75.0, 0.0);
    glEnd();

    // �������� ��� ������ �� ��������� � �������� ��������������
    // OpegGL ��� �������� ���������� ���������� ����������
    glFlush();
    glutSwapBuffers();
}


//�������� � 3D ������������ (� ����������� ���������) ������ ���� ���������
int main9(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow(" OpenGL_HelloWolrd ");
    glutReshapeFunc(Reshape5);
    glutDisplayFunc(renderTriangle);
    glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}

int main(int argc, char* argv[]) {
    //������� �����
    //main1(argc, argv);
    //�������� � 2D  �������� ������ ������ ������. ������� � ����������� ���������
    //main2(argc, argv);
    //�������� � 3D ���� (���������) � ��������������� �������
    //main3(argc, argv);
    //�������� � 3D ���� (�������������) � ��������������� �������
    //main4(argc, argv);
    //�������� � 3D ����� � ������� - ������������� ��������
    //main5(argc, argv);
    //�������� � 3D ������� - ������������� ��������
    //main6(argc, argv);
    //������� ��������� �����
    //main7(argc, argv);
    //���  ������������ ������� �����
    //main8(argc, argv);
    //�������� � 3D ������������ (� ����������� ���������) ������ ���� ���������
    main9(argc, argv);
	return 0;
}
