#include "Geom.h"

bool top::operator==(top::p_t a, top::p_t b)
{
  return a.x == b.x && a.y == b.y;
}

bool top::operator!=(top::p_t a, top::p_t b)
{
  return !(a == b);
}

size_t top::rows(Frame_t fr)
{
  return fr.rightTop.y - fr.leftBott.y + 1;
}

size_t top::cols(Frame_t fr)
{
  return fr.rightTop.x - fr.leftBott.x + 1;
}


