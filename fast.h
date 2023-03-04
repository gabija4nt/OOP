#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream> 
#include <vector> 
#include <chrono>
#include <boost/algorithm/string.hpp>
#include <numeric>

struct studentas {
	std::string vardas = " ", pavarde = " ";
	std::vector<int> paz;
	int egz = 0;
	double gal_paz_v = 0;
	double gal_paz_m = 0;
};

void bufer_nusk(std::string read_vardas, std::string write_vardas);
void pild(std::string& eil);
void galutinis_v(studentas& temp);
void galutinis_m(studentas& temp);