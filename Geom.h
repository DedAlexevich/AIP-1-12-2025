#ifndef GEOM_H
#define GEOM_H
#include <cstddef>
#include <algorithm>

namespace top {
  struct p_t {
    int x,y;
  };

  bool operator==(top::p_t a, top::p_t b);
  bool operator!=(top::p_t a, top::p_t b);

  struct Frame_t {
    p_t leftBott, rightTop;
  };

  Frame_t buildFrame(const p_t* ps, size_t s);
  size_t rows(Frame_t fr);
  size_t cols(Frame_t fr);
}


#endif