#include "studentas.h"

studentas::studentas(std::istream& is) {
	skaityti(is);
}

studentas::studentas(std::string vardas, std::string pavarde, double gal_paz_v) {
    vardas_ = vardas;
    pavarde_ = pavarde;
    gal_paz_v_ = gal_paz_v;
}

std::istream& studentas::skaityti(std::istream& is) {
	is >> vardas_ >> pavarde_;
    std::transform(std::istream_iterator<int>(is), std::istream_iterator<int>(),
        std::back_inserter(paz_), [](int i) { return i; });
    if (!paz_.empty()) {
       egz_ = paz_.back();
       paz_.pop_back();
    }

    gal_paz_v_ = galutinis();
    return is;
}

double vidurkis(std::vector<int> pazymiai) {
    return (double)std::accumulate(pazymiai.begin(), pazymiai.end(), 0) / pazymiai.size();
}

double studentas::galutinis(double (*vid) (std::vector<int>)) const {
    return 0.4 * vidurkis(paz()) + 0.6 * egz();
}

bool compareByGalutinis(const studentas& a, const studentas& b) {
    return a.gal_paz_v() < b.gal_paz_v();
}

void sort_f(int& n, std::vector<studentas>& silpniuku, std::vector<studentas>& gudruciu, std::vector<studentas>& grupe) {
    auto start = std::chrono::high_resolution_clock::now();

    sort(grupe.begin(), grupe.end(), compareByGalutinis);
    
    std::chrono::duration<double> differ = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Laikas sugaistas rikiuoti " << n << " irasu didejimo tvarka: " << differ.count() << " s\n";

    auto st = std::chrono::high_resolution_clock::now();
    auto partition_point = std::partition(grupe.begin(), grupe.end(), [](const studentas& student) {
        return student.gal_paz_v() < 5;
        });

    gudruciu = std::vector<studentas>(partition_point, grupe.end());
    silpniuku = std::vector<studentas>(grupe.begin(), partition_point);

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - st;
    std::cout << "Laikas sugaistas padalinti duomenis i dvi grupes: " << diff.count() << " s\n\n";
}