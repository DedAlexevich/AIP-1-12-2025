#include <iostream>


namespace top {
  struct p_t {
    int x,y;
  };

  struct Frame_t {
    p_t leftBott, rightTop;
  };

  struct IDraw {
    virtual p_t begin() const = 0;
    virtual p_t next() const = 0;
    virtual ~IDraw() = default;
  };


  struct Dot : IDraw {
    p_t o;
    Dot(int x, int y) : IDraw(), o{x,y} {}
    p_t begin() const override;
    p_t next() const override;

    ~Dot() override = default;
  };

  void make_f(IDraw** f, size_t k)
  {}
  void getPoints(IDraw* f, p_t** ps, size_t& s) {}
  Frame_t buildFrame(const p_t* ps, size_t s) {} // Ищем мин и макс для х и у
  char* buildCanvas(Frame_t fr) {} // на основе фрейма считаем макс - мин + 1
  void paintCanvas(char* cnv, Frame_t fr, const p_t* ps , size_t k, char f) {} // координаты перевести в коорд канваса ужас
  void printCanvas(char* cnv, Frame_t fr) {}  // ТОЛЬКО ПОПРОБУЙ ВЫВЕСТИ ЛИШНИЙ ПРОБЕЛ!!!!
  bool operator==(p_t a, p_t b)
  {
    return a.x == b.x && a.y == b.y;
  }

  bool operator!=(p_t a, p_t b)
  {
    return !(a == b);
  }
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

top::p_t top::Dot::next() const
{
  return begin();
}

top::p_t top::Dot::begin() const
{
  return o;
}
