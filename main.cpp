#include "fast.h"
#include "mix.h"

int main() {
 
	std::cout << "Greitas variantas (per bufer'i):\n";
	bufer_nusk("tuscias.txt", "studentai_copy.txt");

	std::cout << "Miksuotas variantas (skaito eilutemis, iraso per buferi):\n";
	mix("tuscias.txt", "studentai_copy.txt");

}
