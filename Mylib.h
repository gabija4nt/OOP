#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <ctime>
#include <exception>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::fixed;
using std::string;
using std::copy;
using std::sort;
using std::numeric_limits;
using std::streamsize;
using std::vector;

#ifndef MYLIB_H
#define MYLIB_H

struct studentas {
  string vardas = " ", pavarde = " ";
  vector<int> paz;
  int egz = 0;
  double gal_paz_v = 0;
  double gal_paz_m = 0;
};

void pild(studentas &temp, vector<string> splited, string &outputas);
void spausd(const studentas &temp);
void galutinis_v(studentas &temp);
void galutinis_m(studentas &temp);

#endif // MYLIB_H