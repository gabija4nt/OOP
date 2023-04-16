#include "mix.h"

void mix(std::string read_vardas, std::string write_vardas, int n, std::vector<studentas>& grupe) {
    std::string eil;
    //----------------------------------------------------------------------
    auto st = std::chrono::high_resolution_clock::now();
    std::ifstream open_f(read_vardas);
    std::ofstream out_f(write_vardas);
    studentas temp;
    std::vector<std::string> out;

    out_f << std::left << std::setw(15) << "Vardas" << std::setw(20) << "Pavarde";
    out_f << "Galutinis (Vid.)" << std::endl;
    out_f << "---------------------------------------------------" << std::endl;
    std::getline(open_f, eil); //ignore first line
    try {
        if (!open_f) {
            throw std::runtime_error("Tuscias ivesties failas");
        }
        while (open_f) {
            if (!open_f.eof()) {
                std::getline(open_f, eil);
                pild(eil, temp);
                grupe.push_back(std::move(temp));
                out.push_back(eil);
                //out_f << eil << "\n";
            }
            else break;
        }
        open_f.close();
    }
    catch (std::exception& e) {
        std::cout << "Klaida: " << e.what() << "\n";
        return;
    }
    // std::cout << grupe.size() << "\n";

    std::string outputas = "";
    for (std::string& a : out)
        (a.compare(*out.rbegin()) != 0) ? outputas += a + "\n" : outputas += a;

    out.clear();

    out_f << outputas;
    out_f.close();

    //std::cout<<outputas;
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - st;  // Skirtumas (s)
    std::cout << "Laikas sugaistas nuskaityti ir suskaiciuoti " << n << " studentu galutinius balus: " << diff.count() << " s\n";
}

void pild(std::string& eil, studentas& temp) {
    std::istringstream iss(eil);
    iss >> temp.vardas >> temp.pavarde;
    std::transform(std::istream_iterator<int>(iss), std::istream_iterator<int>(),
        std::back_inserter(temp.paz), [](int i) { return i; });
    if (!temp.paz.empty()) {
        temp.egz = temp.paz.back();
        temp.paz.pop_back();
    }
    galutinis_v(temp);
    temp.paz.clear();
    std::ostringstream oss;
    oss << std::left << std::setw(15) << temp.vardas << std::setw(20) << temp.pavarde;
    oss << std::fixed << std::setprecision(2) << temp.gal_paz_v << "\n";
    eil = oss.str();
    oss.str("");
}

void galutinis_v(studentas& temp) {
    double sum = 0.0;
    for (const int& pazym : temp.paz) {
        sum += pazym;
    }
    double vid = sum / temp.paz.size();
    temp.gal_paz_v = 0.4 * vid + 0.6 * temp.egz;
}