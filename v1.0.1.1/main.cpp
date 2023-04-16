#include "mix.h"
#include "random.h"
#include "files.h"

extern std::vector<std::string> input_files;
extern std::vector<std::string> output_files;
//extern std::vector<std::string> sorted;

int stud_sk = 1000;

int main() {
	auto start = std::chrono::high_resolution_clock::now();

	std::vector<studentas> silpniuku;
	std::vector<studentas> gudruciu;
	std::vector<studentas> grupe;

	int n = 0;
	
	std::cout << "Ar norite generuoti failus? T/N: \n";
	char uzklausa;
	std::cin >> uzklausa;

	if (uzklausa == 't' || uzklausa == 'T') {
		for (auto& i : input_files) {
			generate(i, stud_sk);
			stud_sk *= 10;
		}
		std::cout << "\n";
			
	}

	stud_sk = 1000;

	for (auto& i : input_files) {
		mix(i, output_files[n], stud_sk, grupe);
		sort_f(stud_sk, silpniuku, gudruciu, grupe);
		print(silpniuku, silpniukai_out[n]);
		print(gudruciu, gudruciai_out[n]);
		
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
