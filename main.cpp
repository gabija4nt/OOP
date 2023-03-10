#include "mix.h"
#include "random.h"
#include "files.h"

extern std::vector<std::string> input_files;
extern std::vector<std::string> output_files;
extern std::vector<std::string> sorted;

int stud_sk = 1000;

int main() {
	auto start = std::chrono::high_resolution_clock::now();

	std::vector<studentas> silpniuku;
	std::vector<studentas> gudruciu;
	int n = 0;
	
	for (auto& i : input_files) {
		generate(i, stud_sk);
		mix(i, output_files[n], stud_sk);
		sort_f(output_files[n], sorted[n], stud_sk, silpniuku, gudruciu);
		print(silpniuku, silpniukai_out[n]);
		print(gudruciu, gudruciai_out[n]);
		std::cout << "\n";
		stud_sk *= 10;
		n++;
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Visas programos vykdymo laikas: " << diff.count() << " s\n";
}
