//
// Created by Петр Кузнецов on 15.12.2025.
//

#ifndef AIP_1_12_2025_TRIANGL_H
#define AIP_1_12_2025_TRIANGL_H
#include "IDraw.h"
namespace top {
  struct Triangl: IDraw {
    Triangl(int x, int y, int l);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int len;
  };

} // top

#endif //AIP_1_12_2025_TRIANGL_H