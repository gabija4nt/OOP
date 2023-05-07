#include "studentas.h"

studentas::studentas(std::istream& is) {
    skaityti(is);
}

studentas::studentas(std::string vardas, std::string pavarde, double gal_paz_v) {
    vardas_ = vardas;
    pavarde_ = pavarde;
    gal_paz_v_ = gal_paz_v;
}

// copy konstruktorius
studentas::studentas(const studentas& studentas1) :
    vardas_{ studentas1.vardas_ },
    pavarde_{ studentas1.pavarde_ },
    egz_{ studentas1.egz_ },
    gal_paz_v_{ studentas1.gal_paz_v_ },
    paz_{ studentas1.paz_.begin(), studentas1.paz_.end() }
{
}

// copy assignment
studentas& studentas::operator=(const studentas& studentas1) {
    if (&studentas1 == this) return *this;

    vardas_ = studentas1.vardas_;
    pavarde_ = studentas1.pavarde_;
    egz_ = studentas1.egz_;
    paz_ = studentas1.paz_;
    gal_paz_v_ = studentas1.gal_paz_v_;
    return *this;
}

// move konstruktorius
studentas::studentas(studentas&& studentas1) noexcept :
    vardas_{ studentas1.vardas_ },
    pavarde_{ studentas1.pavarde_ },
    egz_{ studentas1.egz_ },
    gal_paz_v_{ studentas1.gal_paz_v_ },
    paz_{ std::move(studentas1.paz_) }
{
    studentas1.vardas_ = "";
    studentas1.pavarde_ = "";
    studentas1.egz_ = 0;
    studentas1.gal_paz_v_ = 0;
    studentas1.paz_.clear();
}

// move assignment
studentas& studentas::operator=(studentas&& studentas1) noexcept {
    if (&studentas1 == this) return *this;

    vardas_ = std::move(studentas1.vardas_);
    pavarde_ = std::move(studentas1.pavarde_);
    egz_ = std::move(studentas1.egz_);
    paz_ = std::move(studentas1.paz_);
    gal_paz_v_ = std::move(studentas1.gal_paz_v_);
    return *this;
}

std::istream& studentas::skaityti(std::istream& is) {
    is >> vardas_ >> pavarde_;
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