//
// Created by Петр Кузнецов on 15.12.2025.
//

#ifndef AIP_1_12_2025_SQUARE_H
#define AIP_1_12_2025_SQUARE_H
#include "IDraw.h"

namespace top {
  struct Square: IDraw {
    Square(int x, int y, int l);
    Square(p_t p, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };
} // top

#endif //AIP_1_12_2025_SQUARE_H