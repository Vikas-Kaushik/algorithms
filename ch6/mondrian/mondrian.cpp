/**
 * File: mondrian.cpp
 * --------------------
 * This program draws a graphical mondrian picture,
 * by dividing a rectangel in random smaller ones.
 */
#include <iostream>
#include <random.h>
#include <graphics.h>

using namespace std;
/**
 * Constants
 * ----------
 * MIN_EDGE -- Minimum size of a rectangle side.
 */
const float MIN_EDGE = 0.25;

/* Private Function Prototype */
void DrawMondrian(float x1,
		  float y1,
		  float x2,
		  float y2);

/* Main Function */
int main(){
  InitGraphics();
  float x1,y1,x2,y2;
  x1 = y1 = 0;
  x2 = GetWindowWidth();
  y2 = GetWindowHeight();
  cout << endl << "Width  = " << x2;
  cout << endl << "Height = " << y2;
  cout << endl << "Drawing Mondrian now...printng random nos too";

  DrawMondrian(x1,y1,x2,y2);

  cout << endl;
  return 0;
}

/**
 * Function: DrawMondrian
 * Usage: 
 * ---------------------------------------------
 * This recursive function draws mondrian image.
 */

void DrawMondrian(float x1,
		  float y1,
		  float x2,
		  float y2){
  float area = (x2-x1) * (y2-y1);
  Randomize();
  if( ((x2-x1) < MIN_EDGE) && (area < 1) ){
    return;
  }
  if( (area < 1) && ((y2-y1) < MIN_EDGE) ){ 
    return;
  }
  else {
    if( (x2-x1) < (y2-y1) ){
      float r = RandomReal( y1, y2);
      cout << endl << "r = " << r;
      MovePen( x1, r);
      DrawLine( x2, 0);
      DrawMondrian(x1, y1, x2, r);
      DrawMondrian(x1, r, x2, y2);
    }
    else if( (x2-x1) > (y2-y1) ){
      float r = RandomReal( x1, x2);
      cout << endl << "r = " << r;
      MovePen( r, y1);
      DrawLine( 0, y2);
      DrawMondrian(x1, y1, r, y2);
      DrawMondrian(r, y1, x2, y2);
    }
    /** Following case have same code as in dividing rectangle
     *  horizontally. You can change it to vertical division too.
     *  That's why it's been kept seperately.
     */
    else { // if( (x2-x1) = (y2-y1) ){
      float r = RandomReal( x1, x2);
      cout << endl << "r = " << r;
      MovePen( r, y1);
      DrawLine( 0, y2);
      DrawMondrian(x1, y1, r, y2);
      DrawMondrian(r, y1, x2, y2);
    }
  }
}
