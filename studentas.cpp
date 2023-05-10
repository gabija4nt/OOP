#include "studentas.h"

studentas::studentas(std::istream& is) {
    skaityti(is);
}

std::istream& studentas::skaityti(std::istream& is) {
    std::string v, p;
    is >> v >> p;
    vardas_ = v;
    pavarde_ = p;

    std::transform(std::istream_iterator<int>(is), std::istream_iterator<int>(),
        std::back_inserter(paz_), [](int i) { return i; });
    egz_ = 0;
    if (!paz_.empty()) {
        egz_ = paz_.back();
        paz_.pop_back();
    }

    gal_paz_v_ = galutinis(vidurkis);
    return is;
}

// copy assignment
studentas& studentas::operator=(const studentas& studentas1) {
    if (&studentas1 == this) return *this;

    zmogus::operator=(studentas1);

    egz_ = studentas1.egz_;
    paz_ = studentas1.paz_;
    gal_paz_v_ = studentas1.gal_paz_v_;
    return *this;
}

// move assignment
studentas& studentas::operator=(studentas&& studentas1) noexcept {
    if (&studentas1 == this) return *this;

    zmogus::operator=(std::move(studentas1));

    egz_ = std::move(studentas1.egz_);
    paz_ = std::move(studentas1.paz_);
    gal_paz_v_ = std::move(studentas1.gal_paz_v_);
    return *this;
}

// copy constructor
zmogus& zmogus::operator=(const zmogus& zmogus1) {
    if (&zmogus1 == this) return *this;

    vardas_ = zmogus1.vardas_;
    pavarde_ = zmogus1.pavarde_;

    return *this;
}

//move assignment
zmogus& zmogus::operator=(zmogus&& zmogus1) noexcept {
    if (&zmogus1 == this) return *this;

    vardas_ = std::move(zmogus1.vardas_);
    pavarde_ = std::move(zmogus1.pavarde_);
    zmogus1.vardas_ = "";
    zmogus1.pavarde_ = "";
    return *this;
}

std::ostream& operator<<(std::ostream& os, const studentas& s) {
    os << "Vardas: " << s.vardas_ << "\n";
    os << "Pavarde: " << s.pavarde_ << "\n";
    os << "Egzamino pazymys: " << s.egz_ << "\n";
    os << "Pazymiai: ";
    for (auto& pazymys : s.paz_) {
        os << pazymys << " ";
    }
    os << "\nGalutinis pazymys (vid.): " << s.gal_paz_v_ << "\n";
    return os;
}

double vidurkis(std::vector<int> pazymiai) {
    return (double)std::accumulate(pazymiai.begin(), pazymiai.end(), 0) / pazymiai.size();
}

double studentas::galutinis(double (*vid) (std::vector<int>)) const {
    return 0.4 * vid(paz()) + 0.6 * egz();
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