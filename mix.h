#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream> 
#include <vector> 
#include <chrono>
//#include <boost/algorithm/string.hpp>
#include <numeric>
#include <algorithm>
#include <execution>
#include <deque>

struct studentas {
	std::string vardas = " ", pavarde = " ";
	std::vector<int> paz;
	int egz = 0;
	double gal_paz_v = 0;
	double gal_paz_m = 0;
};

void mix(std::string read_vardas, std::string write_vardas, int n, std::deque<studentas>& grupe);
void pild(std::string& eil, studentas& temp);
void galutinis_v(studentas& temp);
bool compareByGalutinis(const studentas& a, const studentas& b);
void sort_f(int& n, std::deque<studentas>& silpniuku, std::deque<studentas>& gudruciu, std::deque<studentas>& grupe);
//void divide(std::vector<studentas> grupe, std::vector<studentas>& silpniuku, std::vector<studentas>& gudruciu);
void print(std::deque<studentas> kategorijos_vec, std::string failas);

