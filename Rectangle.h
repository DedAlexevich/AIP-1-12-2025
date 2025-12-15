//
// Created by Петр Кузнецов on 15.12.2025.
//

#ifndef AIP_1_12_2025_RECTANGLE_H
#define AIP_1_12_2025_RECTANGLE_H
#include "IDraw.h"
namespace top {
  struct Rectangle: IDraw {
    Rectangle(int x, int y, int a, int b);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int a_, b_;
  };
} // top

#endif //AIP_1_12_2025_RECTANGLE_H