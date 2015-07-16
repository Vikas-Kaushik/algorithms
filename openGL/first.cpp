#include<GL/glut.h>

int main(int argc, char**argv){
  char *Hello_World;
  glutInit(&argc, argv);
  glutInitWindowPosition(100,100);
  glutInitWindowSize(500,500);
  glutCreateWindow(Hello_World);
  glutMainLoop();
  return 0;
}
