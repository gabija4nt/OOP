#include "Mylib.h"
#include "mix.h"

void mix(studentas &temp, std::string read_vardas, std::string write_vardas){
  std::vector<std::string> splited;
  std::string eil;
  std::string outputas="";
  //----------------------------------------------------------------------
  auto start = std::chrono::high_resolution_clock::now(); 
  auto st=start;
  
  try {
    std::ifstream open_f(read_vardas);
    std::getline(open_f, eil);
    while (open_f){ 
      if (!open_f.eof()) {
          std::getline(open_f, eil);
          splited.push_back(eil);}
      else break;
    }
    open_f.close();

    if (splited.empty()) {
      throw std::runtime_error("Įvesties failas yra tuščias!");
    }
  
    pild(temp, splited, outputas);
  
    std::ofstream out_f(write_vardas);
    out_f << left << setw(10) << "Vardas" << setw(15) << "Pavarde";
    out_f << left << setw(20) << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
    out_f << "--------------------------------------------------------" << endl; 
  
    out_f << outputas;
    out_f.close();
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << "Visas sugaištas laikas: "<< diff.count() << " s\n\n";
  } catch (const std::exception& e) {
    std::cerr << "Klaida: " << e.what() << std::endl;
  }
}