//
// Created by Петр Кузнецов on 15.12.2025.
//

#include "./Dot.h"

top::Dot::Dot(int x, int y):
  IDraw(),
  o{x,y}
{}

top::p_t top::Dot::next(p_t p) const
{
  return begin();
}

top::p_t top::Dot::begin() const
{
  return o;
}
