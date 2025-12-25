//
// Created by Петр Кузнецов on 15.12.2025.
//

#include "../Rectangle.h"

top::Rectangle::Rectangle(int x, int y, int a, int b):
  start{x,y},
  a_(a),
  b_(b)
{}

top::p_t top::Rectangle::begin() const
{
  return start;
}

top::p_t top::Rectangle::next(p_t p) const
{
  if (p.x == start.x && p.y < start.y + a_ - 1) {
    return {p.x, p.y + 1};
  } else if (p.y == start.y + a_ - 1 && p.x < start.x + b_ - 1) {
    return {p.x + 1, p.y};
  } else if (p.x == start.x + b_ - 1 && p.y > start.y) {
    return {p.x, p.y - 1};
  } else if (p.y == start.y && p.x > start.x) {
    return {p.x - 1, p.y};
  }
  return start;
}