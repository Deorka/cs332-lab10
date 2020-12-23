#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

//Статистически хранит текущий размер экрана
static int w = 0, h = 0;
double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;

// функция вызываемая перед вхождением в главный цикл
void init(void)
{
    glClearColor(0.0f, 0.8f, 1.0f, 1.0f);
}

// функция вызываемая каждый кадр - для его отрисовки, вычислений и тд.
void Update(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

// функция вызываемая при изменении размеров окна
void Reshape(int width, int height)
{
    w = width;
    h = height;
}

//Голубой экран
int main1(int argc, char* argv[])
{
    // инициализировать glut
    glutInit(&argc, argv);

    // установить начальное положение окна
    glutInitWindowPosition(100, 100);

    // установить начальные размеры окна
    glutInitWindowSize(800, 600);

    // установить параметры окна - двойная буфферизация
    // и поддержка цвета rgba
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    // создать окно с заголовком OpenGL
    glutCreateWindow("OpenGL");

    // укажем glut функцию, которая будет вызываться каждый кадр
    glutIdleFunc(Update);

    // укажем glut функцию, которая будет вызываться при
    // изменении размера окна приложения
    glutReshapeFunc(Reshape);
    init();

    // войти в главный цикл приложения
    glutMainLoop();

    return 0;
}

//обработчик поворотов
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

// вращение в 2D  квадрата вокруг центра экрана. квадрат с градиентной закраской
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
    glutCreateWindow("2d квадрат");

    glutDisplayFunc(renderRectangle);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}

//вращение в 3D куба (каркасный) в ортографической проекции
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


//вращение в 3D куба (твердотельный) в ортографической проекци
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

// функция вызываемая каждый кадр - для его отрисовки, вычислений и тд.
void renderSphere()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // загрузим едматрицу. вида
    glLoadIdentity();
    // зададим позицию камеры, точку наблюд. и вектор вверх
    gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // применим матрицу поворота на текущую матрицу
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    glColor3f(1, 1, 1);
    // отрисуем сферу радиусом 50 ед., размером 10x10 полигонов
    glutWireSphere(50.0f, 10, 10);


    // сбросить все данные на обработку в конвейер преобразования
    // OpegGL без ожидания завершения предыдущих инструкций
    glFlush();
    glutSwapBuffers();
}

// функция вызываемая при изменении размеров окна
void Reshape5(int width, int height) {
    w = width; h = height;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // применим матрицу перспективного преобразования исходя из
    // заданного угла обзора, отношения ширины к высоте
    // и расстояния ближней и дальней отсекающей плоскостей
    gluPerspective(65.0f, w / h, 1.0f, 1000.0f);
}

//вращение в 3D сферы - перспективная проекция
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

    // зададим позицию камеры, точку наблюд. и вектор вверх
    gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    // применим матрицу поворота на текущую матрицу
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    glColor3f(1, 1, 1);
    glutWireTeapot(50);

    // сбросить все данные на обработку в конвейер преобразования
    // OpegGL без ожидания завершения предыдущих инструкций
    glFlush();
    glutSwapBuffers();
}

//вращение в 3D чайника - перспективная проекция
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

    // применим матрицу поворота на текущую матрицу
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

    // сбросить все данные на обработку в конвейер преобразования
    // OpegGL без ожидания завершения предыдущих инструкций
    glFlush();
    glutSwapBuffers();
}

//вывести размерные точки
int main7(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600);
    glutCreateWindow(" OpenGL_HelloWolrd ");

    // изменяем размер точки на значение 10 пикселей
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

    // зададим позицию камеры, точку наблюд. и вектор вверх
    gluLookAt(100.0f, 100.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);


    // применим матрицу поворота на текущую матрицу
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    glRotatef(rotate_z, 0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLES);
    // текущим - делаем красный цвет по( RGB)
    glColor3f(1.0f, 0.0f, 0.0f);

    // первый красный треугольник
    glVertex3f(-75, 0.0f, -50);
    glVertex3f(-75, 0.0f, 50);
    glVertex3f(75, 0.0f, 50);

    // текущим - делаем синий цвет по( RGB)
    glColor3f(0.0f, 0.0f, 1.0f);

    // рисуем второй синий треугольник
    glVertex3f(-75.0f, 0.0f, -50.0f);
    glVertex3f(75.0f, 0.0f, -50.0f);
    glVertex3f(75.0f, 0.0f, 50.0f);
    glEnd();

    // сбросить все данные на обработку в конвейер преобразования
    // OpegGL без ожидания завершения предыдущих инструкций
    glFlush();
    glutSwapBuffers();
}

//два  треугольника разного цвета
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

    // зададим позицию камеры, точку наблюд. и вектор вверх
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

    // сбросить все данные на обработку в конвейер преобразования
    // OpegGL без ожидания завершения предыдущих инструкций
    glFlush();
    glutSwapBuffers();
}


//вращение в 3D треугольника (с градиентной закраской) вокруг осей координат
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
    //Голубой экран
    //main1(argc, argv);
    //вращение в 2D  квадрата вокруг центра экрана. квадрат с градиентной закраской
    //main2(argc, argv);
    //вращение в 3D куба (каркасный) в ортографической проекци
    //main3(argc, argv);
    //вращение в 3D куба (твердотельный) в ортографической проекци
    //main4(argc, argv);
    //вращение в 3D сферы и чайника - перспективная проекция
    //main5(argc, argv);
    //вращение в 3D чайника - перспективная проекция
    //main6(argc, argv);
    //вывести размерные точки
    //main7(argc, argv);
    //два  треугольника разного цвета
    //main8(argc, argv);
    //вращение в 3D треугольника (с градиентной закраской) вокруг осей координат
    main9(argc, argv);
	return 0;
}
