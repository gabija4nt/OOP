#include "random.h"

void generate(const std::string& write_vardas, int& n) {
	auto start = std::chrono::high_resolution_clock::now();

	std::ofstream out_f(write_vardas);
	std::random_device rd;
	std::mt19937_64 mt(rd());
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
		if (i!=n) out_f << "\n";
	}
	out_f.close();

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> diff = end - start;
	diff = end - start; // Skirtumas (s)
	std::cout << "Laikas sugaistas generuoti " << n << " studentu duomenis: " << diff.count() << " s\n";
}