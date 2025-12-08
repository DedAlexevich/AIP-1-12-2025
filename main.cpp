#include <iostream>


namespace top {
  struct p_t {
    int x,y;
  };

  bool operator==(p_t a, p_t b)
  {
    return a.x == b.x && a.y == b.y;
  }

  bool operator!=(p_t a, p_t b)
  {
    return !(a == b);
  }

  struct Frame_t {
    p_t leftBott, rightTop;
  };

  struct IDraw {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t p) const = 0;
    virtual ~IDraw() = default;
  };


  struct Dot : IDraw {
    Dot(int x, int y) : IDraw(), o{x,y} {}
    ~Dot() override = default;
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t o;
  };

  void make_f(IDraw** f, size_t k);
  void getPoints(IDraw* f, p_t** ps, size_t& s);
  Frame_t buildFrame(const p_t* ps, size_t s); // Ищем мин и макс для х и у
  char* buildCanvas(Frame_t fr); // на основе фрейма считаем макс - мин + 1
  void paintCanvas(char* cnv, Frame_t fr, const p_t* ps , size_t k, char f); // координаты перевести в коорд канваса ужас
  void printCanvas(char* cnv, Frame_t fr);  // ТОЛЬКО ПОПРОБУЙ ВЫВЕСТИ ЛИШНИЙ ПРОБЕЛ!!!!

  struct VLine : IDraw {
    VLine(int x, int y, int len);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int length;
  };

  struct HLine : IDraw {
    HLine(int x, int y, int len);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int length;
  };

  struct Square : IDraw {
    Square(int x, int y, int len);
    p_t begin() const override;
    p_t next(p_t p) const override;
    p_t start;
    int length;
  };

}



int main()
{
  top::IDraw* f[3] = {};
  top::p_t* p = nullptr;
  size_t s = 0;
  char* cnv = nullptr;
  int statusCode = 0;
  try {
    top::make_f(f, 3);
    for (size_t i = 0; i < 3; ++i) {
      top::getPoints(f[i], &p, s);
    }
    top::Frame_t fr = top::buildFrame(p, s);
    cnv = top::buildCanvas(fr);
    top::paintCanvas(cnv, fr, p, s, 'o');
    top::printCanvas(cnv, fr);
  } catch(...) {
    statusCode = 1;
  }

  delete f[0];
  delete f[1];
  delete f[2];
  delete[] p;
  delete[] cnv;

  return statusCode;
}

top::p_t top::Dot::next(p_t p) const
{
  return begin();
}

void top::make_f(IDraw** f, size_t k)
{
  f[0] = new Dot(0, 0);
  f[1] = new Dot(-1, -5);
  f[2] = new Dot(7, 7);
}

void top::getPoints(IDraw* f, p_t** ps, size_t& s)
{
  p_t a = f->begin();
  // На паре
}

top::Frame_t top::buildFrame(const p_t* ps, size_t s)
{
}

char* top::buildCanvas(Frame_t fr)
{
}

void top::paintCanvas(char* cnv, Frame_t fr, const p_t* ps, size_t k, char f)
{
}

void top::printCanvas(char* cnv, Frame_t fr)
{
}

top::p_t top::Dot::begin() const
{
  return o;
}

top::VLine::VLine(int x, int y, int len) : IDraw(), start{x,y}, length(len)
{
  if (len == 0) {
    throw std::logic_error("USER invalid");
  }
}

top::p_t top::VLine::begin() const
{
  return start;
}

top::p_t top::VLine::next(p_t p) const
{
  if (p.y == start.y + length) {
    return start;
  }
  return p_t{start.x, p.y + 1};
}

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
  if (p.x == start.x + length) {
    return start;
  }
  return p_t{p.x + 1, start.y };
}

top::Square::Square(int x, int y, int len) : IDraw(), start{x, y}, length(len)
{}

top::p_t top::Square::begin() const
{
  return start;
}

top::p_t top::Square::next(p_t p) const
{
  if (p.y == start.y && p.x < start.x + length) {
    return p_t{p.x + 1, p.y};
  } else if (p.x == start.x + length && p.y < start.y + length) {
    return p_t{p.x, p.y + 1};
  } else if (p.y == start.y + length && p.x > start.x) {
    return p_t{p.x - 1, p.y};
  } else if (p.x == start.x && p.y > start.y) {
    return p_t{p.x, p.y - 1};
  }
  return start;
}





















