//
// Created by Петр Кузнецов on 15.12.2025.
//

#ifndef AIP_1_12_2025_CANVAS_H
#define AIP_1_12_2025_CANVAS_H
#include "Geom.h"
#include <iosfwd>
namespace top {
  char* buildCanvas(Frame_t fr, char);
  void paintCanvas(char* cnv, Frame_t fr, p_t * p, size_t k, char f);
  void printCanvas(char* cnv, Frame_t fr);
}

#endif //AIP_1_12_2025_CANVAS_H