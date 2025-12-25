//
// Created by Петр Кузнецов on 15.12.2025.
//

#ifndef AIP_1_12_2025_IDRAW_H
#define AIP_1_12_2025_IDRAW_H
#include <cstddef>
#include "../Geom.h"

namespace top {
  struct IDraw {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t p) const = 0;
    virtual ~IDraw() = default;
  };
  size_t getPoints(IDraw* f, p_t** ps, size_t& s);
}
#endif