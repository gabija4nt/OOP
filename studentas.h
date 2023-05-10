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

class zmogus {
protected:
    std::string vardas_;
    std::string pavarde_;
public:
    zmogus() : vardas_(""), pavarde_("") {}
    zmogus(const std::string& vardas, const std::string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}

    // copy constructor
    zmogus(const zmogus& zmogus1) :
        vardas_{ zmogus1.vardas_ },
        pavarde_{ zmogus1.pavarde_ } { }

    // move constructor
    zmogus(zmogus&& zmogus1) noexcept :
        vardas_{ zmogus1.vardas_ },
        pavarde_{ zmogus1.pavarde_ }
    { 
        zmogus1.vardas_ = "";
        zmogus1.pavarde_ = "";
    }

    zmogus& operator=(const zmogus& zmogus1);
    zmogus& operator=(zmogus&& zmogus1) noexcept;
    virtual ~zmogus() {}
};


class studentas : public zmogus {
private:
    int egz_;
    std::vector<int> paz_;
    double gal_paz_v_;
public:
    // konstruktoriai
    studentas() : zmogus("", ""), egz_(0), gal_paz_v_(0.0) { }
    studentas(std::istream& is);
    studentas(const std::string& vardas, const std::string& pavarde, double gal_paz_v) : zmogus(vardas, pavarde), gal_paz_v_(gal_paz_v) { }

    // copy konstruktorius
    studentas(const studentas& studentas1) :
        zmogus(studentas1),
        egz_{ studentas1.egz_ },
        gal_paz_v_{ studentas1.gal_paz_v_ },
        paz_{ studentas1.paz_.begin(), studentas1.paz_.end() } { }
    
    // move konstruktorius
    studentas(studentas&& studentas1) noexcept :
        zmogus(std::move(studentas1)),
        egz_{ studentas1.egz_ },
        gal_paz_v_{ studentas1.gal_paz_v_ },
        paz_{ std::move(studentas1.paz_) }
    {
        studentas1.egz_ = 0;
        studentas1.gal_paz_v_ = 0;
        studentas1.paz_.clear();
    }

    // copy assignment
    studentas& operator=(const studentas& studentas1);

    // move assignment
    studentas& operator=(studentas&& studentas1) noexcept;

    // destruktorius
    ~studentas() { paz_.clear(); }

    // setteris
    std::istream& skaityti(std::istream& is);

    // getteriai
    inline std::vector<int> paz() const { return paz_; }
    inline int egz() const { return egz_; }
    inline double gal_paz_v() const { return gal_paz_v_; }

    double galutinis(double (*vid) (std::vector<int>)) const;

    std::string vardas() const { return vardas_; }
    std::string pavarde() const { return pavarde_; }

    friend std::ostream& operator<<(std::ostream& os, const studentas& s);
};


void generate(const std::string& write_vardas, int& n);
void mix(std::string read_vardas, std::string write_vardas, int n);
void eilute(std::string& eil, studentas& stud);
bool compareByGalutinis(const studentas& a, const studentas& b);
void sort_f(int& n, std::vector<studentas>& silpniuku, std::vector<studentas>& gudruciu, std::vector<studentas>& grupe);
void print(std::vector<studentas> kategorijos_vec, std::string failas);

#endif