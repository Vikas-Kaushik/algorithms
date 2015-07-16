//  turtle_tree.c

//  This example introduces RECURSION.  This means that a function calls itself.
//  Imagine you could instantly create a copy of yourself.  You could tell copy 1 to do your math homework
//  and copy 2 to do your english homework.
//  Then copy 1 copies itself.  It tells copy 1-1 to do all the even math problems and copy 1-2 to do all the
//  odd math problems and on and on.
//  Soon you have hundreds of copies of yourself and the homework gets done really really fast!   Wow!

//  In this example, "branch" draws a couple sticks.  But it wants more sticks at the end of each stick.
//  So it copies itself and each copy draws more sticks!  You'll see...

//  Compile command:  It must use C++ because the x-window graphics library is in C++
//  g++ -Wall -W -Werror turtle_tree.c -o turtle_tree -lX11

//  After you compile it, this is the command to run it:   ("./" means "here". Linux runs whatever it finds.)
//  ./turtle_tree


#include <X11/Xlib.h> // Every Xlib program must include this
#include <assert.h>   // I include this to test return values the lazy way
#include <unistd.h>   // So we got the profile for 10 seconds
#include <stdio.h>    // This has the keyboard and file IO functions
#include <math.h>     // sine, cosine and various math functions
#include <stdbool.h>  // Defines true, false
#include <time.h>     // I need this because I will use the time to "seed" the random function
#include <stdlib.h>   // I need this because it has the random functions

#define NIL (0)       // A name for the void pointer

#define window_width 800
#define window_height 600
#define origin_x 400
#define origin_y 300

double rand_range(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

GC gc;   //This will be the "graphics context"  It remembers the colors and window and various details.
Display *dpy;
Window w;
double turtle_x; double turtle_y; double turtle_heading;  //heading is in degrees.  zero is to the right.
bool turtle_pen_active = true;

int home() {
  turtle_x=0.0; turtle_y=0.0; turtle_heading=0.0;
  return(0);
}

int gotoxy (double new_x, double new_y) {
  int x1=turtle_x+origin_x;
  int y1=window_height-(turtle_y+origin_y);
  int x2=new_x+origin_x;
  int y2=window_height-(new_y+origin_y);
  if (turtle_pen_active) XDrawLine(dpy, w, gc, x1, y1, x2, y2);      // Draw theline
  turtle_x=new_x;turtle_y=new_y;
  return(0);
}

int forward(double distance) {
  double new_x=turtle_x+distance*cos(turtle_heading*M_PI/180.0);
  double new_y=turtle_y+distance*sin(turtle_heading*M_PI/180.0);
  int x1=turtle_x+origin_x;
  int y1=window_height-(turtle_y+origin_y);
  int x2=new_x+origin_x;
  int y2=window_height-(new_y+origin_y);
  if (turtle_pen_active) XDrawLine(dpy, w, gc, x1, y1, x2, y2);      // Draw theline
  turtle_x=new_x;turtle_y=new_y;
  return(0);
}

int right(double angle) { turtle_heading = turtle_heading-angle; return (0); }
int left(double angle) { turtle_heading = turtle_heading+angle; return (0); }

int get_pen(XColor desired_col) {
  XSetForeground(dpy, gc, desired_col.pixel);  // Tell the GC we draw using the desired color
  return(0);
}

int pen_up() {turtle_pen_active = false; return(0); }
int pen_down() {turtle_pen_active = true; return(0); }

//======================================================================================================
int branch(int depth)   //  This is a RECURSIVE dunction that will make a FRACTAL
{
  printf("depth=%d\n",depth);
  if (depth > 4) return(0);   //  The is the recursion ESCAPE route.  Without it the program crashes.
  depth++;
  left(10); forward(100/depth); branch(depth);  // branch is going to branch!  How weird!
  //usleep(100000); XFlush(dpy); // Optional: use this to see the lines being drawn, one-by-one
  forward(-100/depth);
  right(20); forward(100/depth); branch(depth); // branch will branch again!  Weirder!
  //usleep(100000); XFlush(dpy); // Optional: use this to see the lines being drawn, one-by-one
  forward(-100/depth);
  left(10);
  return(0);
}
//======================================================================================================

int main()
{
  char keyboard_input[100];
  XColor black_col,white_col,red_col,green_col,blue_col,yellow_col,magenta_col,cyan_col;
  Colormap colormap;
  char black_bits[] = "#000000";
  char white_bits[] = "#FFFFFF";    // Mix red, green and blue to get white
  char red_bits[] = "#FF0000";
  char green_bits[] = "#00FF00";
  char blue_bits[] = "#0000FF";
  char yellow_bits[] = "#FFFF00";   // Mix red and green to get yellow
  char magenta_bits[] = "#FF00FF";  // A sort of purple color
  char cyan_bits[] = "#00FFFF";     // A blue-green color

  //Display *dpy = XOpenDisplay(NIL); 
  dpy = XOpenDisplay(NIL); assert(dpy);   // Open the display
  // Define the colors we want to use
  colormap = DefaultColormap(dpy, 0);
  XParseColor(dpy, colormap, black_bits, &black_col); XAllocColor(dpy, colormap, &black_col);
  XParseColor(dpy, colormap, white_bits, &white_col); XAllocColor(dpy, colormap, &white_col);
  XParseColor(dpy, colormap, red_bits, &red_col); XAllocColor(dpy, colormap, &red_col);
  XParseColor(dpy, colormap, green_bits, &green_col);XAllocColor(dpy, colormap, &green_col);
  XParseColor(dpy, colormap, blue_bits, &blue_col);XAllocColor(dpy, colormap, &blue_col);
  XParseColor(dpy, colormap, yellow_bits, &yellow_col);XAllocColor(dpy, colormap, &yellow_col);
  XParseColor(dpy, colormap, magenta_bits, &magenta_col);XAllocColor(dpy, colormap, &magenta_col);
  XParseColor(dpy, colormap, cyan_bits, &cyan_col);XAllocColor(dpy, colormap, &cyan_col);
  // Create the window  The numbers are the x and y locations on the screen, the width and height, 
  // border width (which is usually zero)
  w = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, window_width, window_height,
  0, black_col.pixel, black_col.pixel);
  XSelectInput(dpy, w, StructureNotifyMask);        // We want to get MapNotify events
  XMapWindow(dpy, w);         // "Map" the window (that is, make it appear on the screen)
  for(;;){XEvent e; XNextEvent(dpy,&e); if(e.type == MapNotify) break;} //Wait for the MapNotify event
  // which means that the window has appeared on the screen.
  gc = XCreateGC(dpy, w, 0, NIL);        // Create a "Graphics Context"
  get_pen(white_col);
  //  We are finally ready to do some drawing!  Whew!  

  // ................  Students: you put your beautiful code HERE: .......................
  home();      // Send the turtle to the middle of the window.  That's its "home"
  get_pen(green_col);  pen_down();
  left(90);
  branch(1);    //Draw the FRACTAL
  XFlush(dpy); // Tell the graphics server to show us the results now.
  sleep(1);  // Wait for 1 second
  printf("Press enter when done.\n");
  fgets (keyboard_input,100,stdin); 
  return(0);
}

