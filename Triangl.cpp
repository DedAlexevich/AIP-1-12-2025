//
// Created by Петр Кузнецов on 15.12.2025.
//

#include "Triangl.h"

top::Triangl::Triangl(int x, int y, int l):
  start{x, y},
  len(l)
{}

top::p_t top::Triangl::begin() const
{
  return start;
}

top::p_t top::Triangl::next(p_t p) const
{
  if (p.x == start.x && p.y < start.y + len - 1) {
    return {p.x, p.y + 1};
  } else if (p.y == start.y && p.x > start.x) {
    return {p.x - 1, p.y};
  } else {
    return {p.x + 1, p.y - 1};
  }
  return start;
}