#include "studentas.h"

extern std::vector<std::string> input_files;
extern std::vector<std::string> output_files;
extern std::vector<std::string> silpniukai_out;
extern std::vector<std::string> gudruciai_out;

int main() {
	studentas stud1("Vardas", "Pavardauskas", 10.);

	std::cout << "Copy konstruktorius : " << std::endl << std::endl;
	studentas stud2(stud1);
	std::cout << "     Studentas 1: " << stud1.vardas() << std::endl;
	std::cout << "     Studentas 2: " << stud2.vardas() << std::endl << std::endl;

	std::cout << "Move konstruktorius : " << std::endl << std::endl;
	studentas stud3(std::move(stud1));
	std::cout << "     Studentas 1: " << stud1.vardas() << std::endl;
	std::cout << "     Studentas 3: " << stud3.vardas() << std::endl << std::endl;

	std::cout << "Copy prieskyros operatorius : " << std::endl << std::endl;
	studentas stud4;
	std::cout << "Pries:" << std::endl;
	std::cout << "     Studentas 2: " << stud2.vardas() << std::endl;
	std::cout << "     Studentas 4: " << stud4.vardas() << std::endl;

	stud4 = stud2;
	std::cout << "Po:" << std::endl;
	std::cout << "     Studentas 2: " << stud2.vardas() << std::endl;
	std::cout << "     Studentas 4: " << stud4.vardas() << std::endl << std::endl;

	std::cout << "Move prieskyros operatorius : " << std::endl << std::endl;
	studentas stud5;
	std::cout << "Pries:" << std::endl;
	std::cout << "     Studentas 2: " << stud2.vardas() << std::endl;
	std::cout << "     Studentas 5: " << stud5.vardas() << std::endl;

	stud5 = std::move(stud2);
	std::cout << "Po:" << std::endl;
	std::cout << "     Studentas 2: " << stud2.vardas() << std::endl;
	std::cout << "     Studentas 5: " << stud5.vardas() << std::endl << std::endl;

	char uzkl;
	std::cout << "Ar norite generuoti ir apdoroti naujus failus? T/N: \n";
	std::cin >> uzkl;

	auto start = std::chrono::high_resolution_clock::now();

	std::vector<studentas> silpniuku;
	std::vector<studentas> gudruciu;
	std::vector<studentas> grupe;

	int n = 0;
	int stud_sk = 1000;
	if (uzkl == 't' || uzkl == 'T') {
		std::cout << "Generavimas:\n\n";
		for (auto& i : input_files) {
			generate(i, stud_sk);
			stud_sk *= 10;
		}
		std::cout << "\n";
		stud_sk = 1000;

		std::cout << "Apdorojimas:\n\n";

		for (auto& i : input_files) {
			mix(i, output_files[n], stud_sk);
			stud_sk *= 10;
			n++;
		}
	}

	std::cout << "Testavimas:\n\n";

	stud_sk = 1000;
	std::string eil, vardas, pavarde;
	double gal_paz_v; n = 0;

	for (auto& i : output_files) {
		auto st = std::chrono::high_resolution_clock::now();
		std::ifstream open_f(i);
		std::getline(open_f, eil);    // ignoruoja pirmas 
		std::getline(open_f, eil);    // dvi eilutes
		while (open_f) {
			if (!open_f.eof()) {
				std::getline(open_f, eil);
				std::istringstream iss(eil);
				iss >> vardas >> pavarde >> gal_paz_v;
				studentas temp(vardas, pavarde, gal_paz_v);
				grupe.push_back(std::move(temp));
			}
			else break;
		}
		open_f.close();
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - st;
		std::cout << "Laikas, sugaistas nuskaityti " << stud_sk << " irasu i vektoriu : " << diff.count() << " s\n";
		sort_f(stud_sk, silpniuku, gudruciu, grupe);
		//print(silpniuku, silpniukai_out[n]);
		//print(gudruciu, gudruciai_out[n]);

		stud_sk *= 10;
		n++;
		grupe.clear();
		silpniuku.clear();
		gudruciu.clear();
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Visas programos vykdymo laikas: " << diff.count() << " s\n";
}