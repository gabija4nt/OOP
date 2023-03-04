#include "mix.h"

void mix(std::string read_vardas, std::string write_vardas) {
    std::vector<std::string> splited;
    std::string eil;
    //----------------------------------------------------------------------
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    std::ifstream open_f(read_vardas);
    std::getline(open_f, eil); //ignore first line
    try {
        if (!open_f) {
            throw std::runtime_error("Tuscias ivesties failas");
        }
        while (open_f) {
            if (!open_f.eof()) {
                std::getline(open_f, eil);
                splited.push_back(eil);
            }
            else break;
        }
        open_f.close();
    }
    catch (std::exception& e) {
        std::cout << "Klaida: " << e.what() << "\n";
        return;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo nuskaitymas tiesiai i eiluciu vektoriu uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::string outputas = "";
    for (std::string& a : splited) {
        pild(a);
        (a.compare(*splited.rbegin()) != 0) ? outputas += a + "\n" : outputas += a;
    }
    splited.clear();
    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Eiluciu vektoriaus duomenu apdorojimas ir konvertavimas i viena eilute uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::ofstream out_f(write_vardas);

    out_f << std::left << std::setw(10) << "Vardas" << std::setw(15) << "Pavarde";
    out_f << std::left << std::setw(20) << "Galutinis (Vid.)" << "Galutinis (Med.)" << std::endl;
    out_f << "--------------------------------------------------------" << std::endl;

    out_f << outputas;
    out_f.close();
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Failo irasymas per viena eilute uztruko: " << diff.count() << " s\n";
    //std::cout<<outputas;
    diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    std::cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";
}
