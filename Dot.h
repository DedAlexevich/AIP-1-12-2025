//
// Created by Петр Кузнецов on 15.12.2025.
//

#ifndef AIP_1_12_2025_DOT_H
#define AIP_1_12_2025_DOT_H
#include "IDraw.h"
namespace top {
  struct Dot : IDraw {
    Dot(int x, int y);
    ~Dot() override = default;
    p_t begin() const override;
    p_t next(p_t p) const override;
  private:
    p_t o;
  };
}
#endif //AIP_1_12_2025_DOT_H