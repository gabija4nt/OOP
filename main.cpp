#include "mix.h"
#include "random.h"
#include "files.h"

extern std::vector<std::string> input_files;
extern std::vector<std::string> output_files;
//extern std::vector<std::string> sorted;

int stud_sk = 1000;

int main() {
	
	std::vector<studentas> silpniuku;
	std::vector<studentas> gudruciu;
	std::vector<studentas> grupe;

	int n = 0;
	
	std::cout << "Ar norite generuoti failus? T/N: \n";
	char uzklausa;
	std::cin >> uzklausa;

	auto start = std::chrono::high_resolution_clock::now();

	if (uzklausa == 't' || uzklausa == 'T') {
		for (auto& i : input_files) {
			generate(i, stud_sk);
			stud_sk *= 10;
		}
		std::cout << "\n";
		stud_sk = 1000;

		for (auto& i : input_files) {
			mix(i, output_files[n], stud_sk);
			stud_sk *= 10;
			n++;
		}
		std::cout << "\n";
	}

	n = 0;
	std::string eil;
	stud_sk = 1000;
	for (auto& i : output_files) {
		auto st = std::chrono::high_resolution_clock::now();
		std::ifstream open_f(i);
		std::getline(open_f, eil);    // ignoruoja pirmas 
		std::getline(open_f, eil);    // dvi eilutes
		while (open_f) {
			if (!open_f.eof()) {
				studentas temp;
				std::getline(open_f, eil);
				std::istringstream iss(eil);
				iss >> temp.vardas >> temp.pavarde >> temp.gal_paz_v;
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
		std::cout << "\n";
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Visas programos vykdymo laikas: " << diff.count() << " s\n";
}
