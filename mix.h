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

struct studentas {
	std::string vardas = " ", pavarde = " ";
	std::vector<int> paz;
	int egz = 0;
	double gal_paz_v = 0;
	double gal_paz_m = 0;
};

void mix(std::string read_vardas, std::string write_vardas, int& n);
void pild(std::string& eil);
void galutinis_v(studentas& temp);
bool compareByGalutinis(const studentas& a, const studentas& b);
void sort_f(std::string read_vardas, std::string sorted, int& n, std::vector<studentas>& silpniuku,
																 std::vector<studentas>& gudruciu);
//void divide(std::vector<studentas> grupe, std::vector<studentas>& silpniuku, std::vector<studentas>& gudruciu);
void print(std::vector<studentas> kategorijos_vec, std::string failas);

