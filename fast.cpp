#include "fast.h"


void bufer_nusk(std::string read_vardas, std::string write_vardas) {
    std::vector<std::string> splited;
    std::string eil;
    std::stringstream my_buffer;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::ifstream open_f(read_vardas);

    my_buffer << open_f.rdbuf();
    open_f.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Failo nuskaitymas i buferi uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::getline(my_buffer, eil); //to ignore the first line
    try {
        if (!my_buffer) {
            throw std::runtime_error("Tuscias ivesties failas");
        }
        while (my_buffer) {
        if (!my_buffer.eof()) {
            std::getline(my_buffer, eil);
            splited.push_back(eil);
        }
        else break;
        }
    }
    catch (std::exception& e) {
        std::cout << "Klaida: " << e.what() << "\n\n";
        return;
    }
    
    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Buferio padalijimas i eiluciu vektoriu uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::string outputas = "";
    for (std::string& a : splited) {
        pild(a);
        (a.compare(*splited.rbegin()) != 0) ? outputas += a + "\n" : outputas += a;
    }
    splited.clear();
    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Eiluciu vektoriuas duomenu apdorojimas ir konvertavimas i viena eilute uztruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::ofstream out_f(write_vardas);

    out_f << std::left << std::setw(10) << "Vardas" << std::setw(15) << "Pavarde";
    out_f << std::left << std::setw(20) << "Galutinis (Vid.)" << "Galutinis (Med.)" << std::endl;
    out_f << "--------------------------------------------------------" << std::endl;

    out_f << outputas;
    out_f.close();
    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Failo irassyas per viena eilute uztruko: " << diff.count() << " s\n";

    diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    std::cout << "Visas sugaistas laikas: " << diff.count() << " s\n\n";

}

void pild(std::string& eil) {
    studentas temp;
    std::istringstream iss(eil);
    iss >> temp.vardas >> temp.pavarde;
    int pazym;
    while (iss >> pazym) {
        temp.paz.push_back(pazym);
    }
    temp.egz = temp.paz.back();
    temp.paz.pop_back();
    galutinis_v(temp);
    galutinis_m(temp);

    std::ostringstream oss;
    oss << std::left << std::setw(10) << temp.vardas << std::setw(15) << temp.pavarde;
    oss << std::setw(20) << std::fixed << std::setprecision(2) << temp.gal_paz_v << temp.gal_paz_m << std::endl;
    eil = oss.str();
}

void galutinis_v(studentas& temp) {
    double vid = accumulate(temp.paz.begin(), temp.paz.end(), 0.0) / temp.paz.size();
    temp.gal_paz_v = 0.4 * vid + 0.6 * temp.egz;
}

void galutinis_m(studentas& temp) {
    int n = temp.paz.size();
    int mid = n / 2;

    std::nth_element(temp.paz.begin(), temp.paz.begin() + mid, temp.paz.end());

    double med = temp.paz[mid];
    if (n % 2 == 0) {
        std::nth_element(temp.paz.begin(), temp.paz.begin() + mid - 1, temp.paz.end());
        med = (med + temp.paz[mid - 1]) / 2.0;
    }

    temp.gal_paz_m = 0.4 * med + 0.6 * temp.egz;
}