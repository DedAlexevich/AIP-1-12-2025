#include <iostream>
#include "Geom.h"
#include "Shapes/IDraw.h"
#include "Shapes/Dot.h"
#include "Shapes/VLine.h"
#include "canvas.h"
#include "Shapes/HLine.h"
#include "Shapes/DLine.h"
#include "Shapes/Rectangle.h"
#include "Shapes/Square.h"
#include "Shapes/Triangl.h"

//EAlfiT

int main()
{
  using namespace top;
  IDraw* f[9] = {};
  p_t* p = new p_t[1];
  size_t s = 0;
  char* cnv = nullptr;
  int statusCode = 0;
  try {
    f[0] = new Dot(0, 0);
    f[1] = new Dot(1, -5);
    f[2] = new Square(7, 7, 3);
    f[3] = new VLine(4, 5, 3);
    f[4] = new HLine(2, 7, 4);
    f[5] = new DLine(-3, 1, 4);
    f[6] = new Rectangle(-10, -4, 4, 7);
    f[7] = new Triangl(0, -10, 4);
    for (size_t i = 0; i < 8; ++i) {
      getPoints(f[i], &p, s);
    }
    Frame_t fr = buildFrame(p, s);
    cnv = buildCanvas(fr, '.');
    paintCanvas(cnv, fr, p, s, 'o');
    printCanvas(cnv, fr);
  } catch(...) {
    statusCode = 1;
  }

  delete f[0];
  delete f[1];
  delete f[2];
  delete f[3];
  delete f[4];
  delete f[5];
  delete f[6];
  delete f[7];
  delete[] p;
  delete[] cnv;

  return statusCode;
}





