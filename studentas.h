#ifndef STUDENTAS_H
#define STUDENTAS_H
#pragma once

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream> 
#include <vector> 
#include <chrono>
#include <numeric>
#include <algorithm>
#include <execution>
#include <random>

double vidurkis(std::vector<int> pazymiai);

class studentas {
private:
	std::string vardas_;
	std::string pavarde_;
	int egz_;
	std::vector<int> paz_;
	double gal_paz_v_;

public:
	// konstruktoriai
	studentas() { vardas_ = ""; pavarde_ = ""; egz_ = 0; gal_paz_v_ = 0.0; }
	studentas(std::istream& is);
	studentas(std::string vardas, std::string pavarde, double gal_paz_v);

	// destruktorius
	~studentas() { }

	// setteris
	std::istream& skaityti(std::istream& is);

	// getteriai
	inline std::string vardas() const { return vardas_; }
	inline std::string pavarde() const { return pavarde_; }
	inline std::vector<int> paz() const { return paz_; }
	inline int egz() const { return egz_; }
	inline double gal_paz_v() const { return gal_paz_v_; }

	double galutinis(double (*) (std::vector<int>) = vidurkis) const;
};

void generate(const std::string& write_vardas, int& n);
void mix(std::string read_vardas, std::string write_vardas, int n);
void eilute(std::string& eil, studentas& stud);
bool compareByGalutinis(const studentas& a, const studentas& b);
void sort_f(int& n, std::vector<studentas>& silpniuku, std::vector<studentas>& gudruciu, std::vector<studentas>& grupe);
void print(std::vector<studentas> kategorijos_vec, std::string failas);

#endif