//
// Created by Петр Кузнецов on 15.12.2025.
//

#ifndef AIP_1_12_2025_HLINE_H
#define AIP_1_12_2025_HLINE_H
#include "./IDraw.h"

namespace top {
  struct HLine : IDraw {
    HLine(int x, int y, int len);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int length;
  };
} // top

#endif //AIP_1_12_2025_HLINE_H