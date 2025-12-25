//
// Created by Петр Кузнецов on 15.12.2025.
//

#include "DLine.h"

top::DLine::DLine(int x, int y, int len):
  start{x, y},
  length(len)
{}

top::p_t top::DLine::begin() const
{
  return start;
}

top::p_t top::DLine::next(p_t p) const
{
  if (p.x < start.x + length - 1) {
    return {p.x + 1, p.y + 1};
  }
  return start;
}
