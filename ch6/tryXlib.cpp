//#include<X11/Xlib.h> // Every Xlib program must include this
#include<iostream>
#include<sdl.h>
//#include<graphics>
//#include"graphics.h"
int main(){
  //char *display_name;
  //  Display XOpenDisplay(display_name);
  int gd, gm = VGAMAX, gd = DETECT;
  initgraph(&gd, &gm, NULL);
  line(50, 50, 80, 80);
  delay(5000);

  return 0;
}
