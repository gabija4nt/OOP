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

/// <summary>
/// Skaičiuoja studento namų darbų pažymių vidurkį.
/// </summary>
/// <param name="pazymiai"></param>
/// <returns></returns>
double vidurkis(std::vector<int> pazymiai);

class zmogus {
protected:
    /// zmogus klasės vardo parametras
    std::string vardas_;
    /// zmogus klasės pavardės parametras
    std::string pavarde_;
public:
    /// zmogus klasės default konstruktorius
    zmogus() : vardas_(""), pavarde_("") {}
    /// zmogus klasės konstruktorius
    zmogus(const std::string& vardas, const std::string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}

    /// copy konstruktorius zmogus klasei
    zmogus(const zmogus& zmogus1) :
        vardas_{ zmogus1.vardas_ },
        pavarde_{ zmogus1.pavarde_ } { }

    /// move konstruktorius zmogus klasei
    zmogus(zmogus&& zmogus1) noexcept :
        vardas_{ zmogus1.vardas_ },
        pavarde_{ zmogus1.pavarde_ }
    { 
        zmogus1.vardas_ = "";
        zmogus1.pavarde_ = "";
    }
    /// virtuali funkcija zmogus klasei
    virtual std::string vardas() const = 0;
    /// virtuali funkcija zmogus klasei
    virtual std::string pavarde() const = 0;

    /// move prieskyros operatorius zmogus klasei.
    zmogus& operator=(const zmogus& zmogus1);
    /// move prieskyros operatorius zmogus klasei.
    zmogus& operator=(zmogus&& zmogus1) noexcept;
    /// zmogus klasės destruktorius
    virtual ~zmogus() {}
};


class studentas : public zmogus {
private:
    /// studentas klasės egzamino pažymio parametras
    int egz_;
    /// studentas klasės namų darbų vektoriaus parametras
    std::vector<int> paz_;
    /// studentas klasės galutinio pažymio parametras
    double gal_paz_v_;
public:
    /// default konstruktorius studentas klasei
    studentas() : zmogus("", ""), egz_(0), gal_paz_v_(0.0) { }
    /// studentas objekto konstruktorius skaitantis iš įvesties failo
    studentas(std::istream& is);
    /// studentas konstruktorius su vardo, pavardės ir galutinio pažymio parametrais
    studentas(const std::string& vardas, const std::string& pavarde, double gal_paz_v) : zmogus(vardas, pavarde), gal_paz_v_(gal_paz_v) { }

    /// copy konstruktorius studentas klasei
    studentas(const studentas& studentas1) :
        zmogus(studentas1),
        egz_{ studentas1.egz_ },
        gal_paz_v_{ studentas1.gal_paz_v_ },
        paz_{ studentas1.paz_.begin(), studentas1.paz_.end() } { }
    
    /// move konstruktorius studentas klasei
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

    /// copy prieskyros operatorius studentas klasei.
    studentas& operator=(const studentas& studentas1);

    /// move prieskyros operatorius studentas klasei.
    studentas& operator=(studentas&& studentas1) noexcept;

    /// studentas klasės destruktorius
    ~studentas() { paz_.clear(); }

    /// Studento klasės setter funkcija, skaitanti iš įvesties srauto.
    std::istream& skaityti(std::istream& is);

    /// Studento klasės getter funkcija, grąžinanti studento namų darbų pažymių vektorių.
    inline std::vector<int> paz() const { return paz_; }

    /// Studento klasės getter funkcija, grąžinanti egzamino pažymį.
    inline int egz() const { return egz_; }

    /// Studento klasės getter funkcija, grąžinanti galutinį studento pažymį.
    inline double gal_paz_v() const { return gal_paz_v_; }

    /// Studento klasės funkcija, skaičiuoja galutinį studento pažymį.
    double galutinis(double (*vid) (std::vector<int>)) const;

    /// Studento klasės getter funkcija, grąžinanti žmogaus vardą.
    std::string vardas() const { return vardas_; }

    /// Studento klasės getter funkcija, grąžinanti žmogaus pavardę.
    std::string pavarde() const { return pavarde_; }
    
    /// Studento klasės friend funkcija, perdengia išvesties operatorių << studento klasei.
    friend std::ostream& operator<<(std::ostream& os, const studentas& s);
};

/// <summary>
/// Generuoja atsitiktinius studento duomenis: vardą, pavardę, namų darbų pažymius ir egzamino pažymį.
/// </summary>
/// <param name="write_vardas"></param>
/// <param name="n"></param>
void generate(const std::string& write_vardas, int& n);

/// <summary>
/// Skaičiuoja galutinius studento balus
/// </summary>
/// <param name="read_vardas"></param>
/// <param name="write_vardas"></param>
/// <param name="n"></param>
void mix(std::string read_vardas, std::string write_vardas, int n);

/// <summary>
/// Studento duomenis sudeda į išvesties eilutę
/// </summary>
/// <param name="eil"></param>
/// <param name="stud"></param>
void eilute(std::string& eil, studentas& stud);

/// <summary>
/// Lygina dviejų studentų galutinius balus
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
bool compareByGalutinis(const studentas& a, const studentas& b);

/// <summary>
/// Rūšiuoja studentus pagal galutinio pažymio dydį ir pagal tai padalina studento vektorių į du vektorius.
/// </summary>
/// <param name="n"></param>
/// <param name="silpniuku"></param>
/// <param name="gudruciu"></param>
/// <param name="grupe"></param>
void sort_f(int& n, std::vector<studentas>& silpniuku, std::vector<studentas>& gudruciu, std::vector<studentas>& grupe);

/// <summary>
/// Išveda studentų vardą, pavardę ir galutinį pažymį į rezultatų failą, atitinkamai pagal vektorių, kuriam priklauso pagal galutinį pažymį.
/// </summary>
/// <param name="kategorijos_vec"></param>
/// <param name="failas"></param>
void print(std::vector<studentas> kategorijos_vec, std::string failas);

#endif