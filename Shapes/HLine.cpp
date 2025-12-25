//
// Created by Петр Кузнецов on 15.12.2025.
//

#include "./HLine.h"
top::HLine::HLine(int x, int y, int len) : IDraw(), start{x, y}, length(len)
{
  if (len == 0) {
    throw std::logic_error("USER invalid");
  }
}

top::p_t top::HLine::begin() const
{
  return start;
}

top::p_t top::HLine::next(p_t p) const
{
  if (p.x == start.x + length - 1) {
    return start;
  }
  if (length > 0) {
    return p_t{p.x + 1, start.y };
  }
  return p_t{p.x - 1, start.y };
}