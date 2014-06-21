#include "printer.h"
#include "chess.h"

#include <map>
#include <stdio.h>
#include <string>

const int Printer::kWidth = 9;
const int Printer::kHeight = 10;

namespace {
const char* kRedColor = "\e[0;31m";
const char* kBlackColor = "\e[0;32m";
const char* kColorEnd = "\e[m";
}  // namespace

void Printer::Print(const std::string& board) {
  int sz = board.size();
  int x = 0;
  int y = 0;
  printf("  ");
  for (int i = 0; i < sz; i++) {
    char s = board[i];
    if (s == '/') {
      printf("\n");
      PrintSplitter(y);
      printf("  ");
      x = 0;
      y++;
    } else {
      if (s > '0' && s <= '9') {
        for (int j = '0'; j < s; j++) {
          PrintPointDefault(x++, y);
        }
      } else {
        PrintPoint(x++, y, s);
      }
    }
  }
  printf("\n");
}

void Printer::PrintPoint(int x, int y, char m) {
  static std::map<char, const char*> name = {
    {'r', "车"},
    {'n', "马"},
    {'b', "相"},
    {'a', "士"},
    {'k', "将"},
    {'c', "炮"},
    {'p', "兵"},
    {'R', "车"},
    {'N', "马"},
    {'B', "相"},
    {'A', "士"},
    {'K', "将"},
    {'C', "炮"},
    {'P', "兵"},
  };
  bool isRed = m >= 'A' && m <= 'Z';
  printf("%s%s%s", isRed ? kRedColor : kBlackColor, name[m], kColorEnd);
  if (x < kWidth - 1) {
    printf("-");
  }
}

void Printer::PrintPointDefault(int x, int y) {
  if (x == kWidth - 1) {
    printf("+");
  } else {
    printf("+--");
  }
}

void Printer::PrintSplitter(int y) {
  if (y == 4) {
    printf("  |      楚河    汉界     |\n");
  } else if (y < kHeight - 1) {
    printf("  ");
    for (int j = 0; j < kWidth; j++) {
      if (((y == 0 || y == 7) && j == 3)) {
        printf("| \\");
      } else if ((y == 0 || y == 7) && j == 4) {
        printf("|/ ");
      } else if ((y == 1 || y == 8) && j == 4) {
        printf("|\\ ");
      } else if ((y == 1 || y == 8) && j == 3) {
        printf("| /");
      } else {
        printf("|  ");
      }
    }
    printf("  ");
    printf("\n");
  }
}

void Printer::Print() {
  for (int i = 0; i < kHeight; i++) {
    printf("  ");
    for (int j = 0; j < kWidth; j++) {
      PrintPointDefault(j, i);
    }
    printf("\n");
    PrintSplitter(i);
  }
}
