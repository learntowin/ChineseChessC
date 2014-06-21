#ifndef _PRINTER_H_
#define _PRINTER_H_

#include <string>

class Printer {
 public:
  void Print();
  void Print(const std::string& board);

  static const int kWidth;
  static const int kHeight;

 private:
  void PrintPoint(int x, int y, char m);
  void PrintPointDefault(int x, int y);
  void PrintSplitter(int y);
};


#endif  // _PRINTER_H_
