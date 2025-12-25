//
// Created by Петр Кузнецов on 15.12.2025.
//

#ifndef AIP_1_12_2025_VLINE_H
#define AIP_1_12_2025_VLINE_H
#include "IDraw.h"
#include <stdexcept>
namespace top {
  struct VLine : IDraw {
    VLine(int x, int y, int len);
    p_t begin() const override;
    p_t next(p_t p) const override;
  private:
    p_t start;
    int length;
  };
}

#endif //AIP_1_12_2025_VLINE_H