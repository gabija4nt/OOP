#include "mix.h"

bool compareByGalutinis(const studentas& a, const studentas& b) {
	return a.gal_paz_v < b.gal_paz_v;
}

void sort_f(int& n, std::list<studentas>& silpniuku, std::list<studentas>& gudruciu, std::list<studentas>& grupe) {
	//std::string eil = "";

	//std::getline(open_f, eil);
	//std::getline(open_f, eil); //ignoring first two lines

	auto start = std::chrono::high_resolution_clock::now();

	grupe.sort(compareByGalutinis);

	std::chrono::duration<double> differ = std::chrono::high_resolution_clock::now() - start;  // Skirtumas (s)
	std::cout << "Laikas sugaistas rikiuoti " << n << " irasu didejimo tvarka: " << differ.count() << " s\n";
	

	auto st = std::chrono::high_resolution_clock::now();
	auto i = grupe.begin();
	while (i != grupe.end()) {
		if (i->gal_paz_v < 5) {
			silpniuku.push_back(*i);
			i = grupe.erase(i);
		}
		else {
			++i;
		}
	}

	gudruciu.splice(gudruciu.end(), grupe);

	//sort(silpniuku.begin(), silpniuku.end(), compareByGalutinis);
	//std::ofstream out_f(sorted);
	//out_f << std::left << std::setw(15) << "Vardas" << std::setw(20) << "Pavarde";
	//out_f << "Galutinis (Vid.)" << std::endl;
	//out_f << "---------------------------------------------------" << std::endl;

	
	//for (const auto& temp : grupe) {
		//out_f << std::left << std::setw(15) << temp.vardas << std::setw(20) << temp.pavarde;
		//out_f << std::fixed << std::setprecision(2) << temp.gal_paz_v << "\n";
	//}

	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - st;  // Skirtumas (s)
	std::cout << "Laikas sugaistas padalinti duomenis i dvi grupes: " << diff.count() << " s\n";
	//divide(grupe, silpniuku, gudruciu);
	//grupe.clear();
}

//void divide(std::vector<studentas> grupe, std::vector<studentas>& silpniuku, std::vector<studentas>& gudruciu) {
	//auto st = std::chrono::high_resolution_clock::now();

	//for (const auto& temp : grupe) {
	//	if (temp.gal_paz_v < 5)
	//		silpniuku.push_back(temp);
	//	else gudruciu.push_back(temp);
	//}
	//std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - st;  // Skirtumas (s)
	//std::cout << "Laikas sugaistas padalinti studentu duomenis i dvi grupes: " << diff.count() << " s\n";
//}

void print(std::list<studentas> kategorijos_vec, std::string failas) {
	auto st = std::chrono::high_resolution_clock::now();
	std::ofstream out_f(failas);

	out_f << std::left << std::setw(15) << "Vardas" << std::setw(20) << "Pavarde";
	out_f << "Galutinis (Vid.)" << std::endl;
	out_f << "---------------------------------------------------" << std::endl;

	for (const auto& temp : kategorijos_vec) {
		out_f << std::left << std::setw(15) << temp.vardas << std::setw(20) << temp.pavarde;
		out_f << std::fixed << std::setprecision(2) << temp.gal_paz_v << "\n";
	}

	std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - st;  // Skirtumas (s)
	std::cout << "Laikas sugaistas isvesti " << failas << " duomenis i faila: " << diff.count() << " s\n";
}