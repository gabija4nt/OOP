#include "studentas.h"

void generate(const std::string& write_vardas, int& n) {
    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream out_f(write_vardas);
    //std::random_device rd;
    std::mt19937_64 mt(1729);//rd());
    std::uniform_int_distribution<int> dist(1, 10);
    //----------------------------------------------------------------------------
    out_f << std::left << std::setw(20) << "Vardas" << std::setw(20) << "Pavarde";
    for (int i = 1; i < 11; ++i)
        out_f << "ND" + std::to_string(i) + "\t";
    out_f << "Egz.\n";
    //----------------------------------------------------------------------------
    for (int i = 1; i < n + 1; i++) {
        out_f << std::left << std::setw(20) << "Vardas" + std::to_string(i)
            << std::setw(20) << "Pavarde" + std::to_string(i);
        for (int j = 0; j < 11; ++j) {
            out_f << std::setw(5) << dist(mt) << "\t";
        }
        if (i != n) out_f << "\n";
    }
    out_f.close();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    diff = end - start; // Skirtumas (s)
    std::cout << "Laikas sugaistas generuoti " << n << " studentu duomenis: " << diff.count() << " s\n";
}

void mix(std::string read_vardas, std::string write_vardas, int n) {
    std::string eil;
    //----------------------------------------------------------------------
    auto st = std::chrono::high_resolution_clock::now();
    std::ifstream open_f(read_vardas);
    std::ofstream out_f(write_vardas);
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
                std::istringstream iss(eil);
                studentas temp(iss);
                eilute(eil, temp);
                //grupe.push_back(std::move(temp));
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

void eilute(std::string& eil, studentas& stud) {
    std::ostringstream oss;
    oss << std::left << std::setw(15) << stud.vardas() << std::setw(20) << stud.pavarde();
    oss << std::fixed << std::setprecision(2) << stud.gal_paz_v();
    eil = oss.str();
    oss.str("");
}

void print(std::vector<studentas> kategorijos_vec, std::string failas) {
    auto st = std::chrono::high_resolution_clock::now();
    std::ofstream out_f(failas);

    out_f << std::left << std::setw(15) << "Vardas" << std::setw(20) << "Pavarde";
    out_f << "Galutinis (Vid.)" << std::endl;
    out_f << "---------------------------------------------------" << std::endl;

    for (const auto& temp : kategorijos_vec) {
        out_f << std::left << std::setw(15) << temp.vardas() << std::setw(20) << temp.pavarde();
        out_f << std::fixed << std::setprecision(2) << temp.gal_paz_v() << "\n";
    }

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - st;  // Skirtumas (s)
    std::cout << "Laikas sugaistas isvesti " << failas << " duomenis i faila: " << diff.count() << " s\n";
    if (kategorijos_vec[0].gal_paz_v() < 5) std::cout << "\n";
}

std::vector<std::string> input_files = {
    "studentai1k.txt",
    "studentai10k.txt",
    "studentai100k.txt",
    "studentai1M.txt",
    "studentai10M.txt"
};

std::vector<std::string> output_files = {
    "studentai1k_rez.txt",
    "studentai10k_rez.txt",
    "studentai100k_rez.txt",
    "studentai1M_rez.txt",
    "studentai10M_rez.txt"
};

std::vector<std::string> silpniukai_out = {
    "silpniukai1k_rez.txt",
    "silpniukai10k_rez.txt",
    "silpniukai100k_rez.txt",
    "silpniukai1M_rez.txt",
    "silpniukai10M_rez.txt"
};

std::vector<std::string> gudruciai_out = {
    "gudruciai1k_rez.txt",
    "gudruciai10k_rez.txt",
    "gudruciai100k_rez.txt",
    "gudruciai1M_rez.txt",
    "gudruciai10M_rez.txt"
};