#include "Mylib.h"
#include "mix.h"

void mix(studentas &temp, std::string read_vardas, std::string write_vardas){
  std::vector<std::string> splited;
  std::string eil;
  std::string outputas="";
  //----------------------------------------------------------------------
  auto start = std::chrono::high_resolution_clock::now(); 
  auto st=start;
    std::ifstream open_f(read_vardas);
    std::getline(open_f, eil);
    while (open_f){ 
      if (!open_f.eof()) {
          std::getline(open_f, eil);
          splited.push_back(eil);}
      else break;
    }
    open_f.close();
  
  pild(temp, splited, outputas);
  
  //auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff;// = end-start; // Skirtumas (s)
  //std::cout << "Failo nuskaitymas tesiai į eilučių vektorių užtruko: "<< diff.count() << " s\n";  

  //start = std::chrono::high_resolution_clock::now();
    // std::string outputas="";
    // for (std::string &a: splited) (a.compare(*splited.rbegin()) !=0) ? outputas+=a+"\n": outputas+=a ;
  //diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
  //std::cout << "Eilučių vektoriaus konvertavimas į vieną eilutę užtruko: "<< diff.count() << " s\n";
  std::ofstream out_f(write_vardas);
  out_f << left << setw(10) << "Vardas" << setw(15) << "Pavarde";
  out_f << left << setw(20) << "Galutinis (Vid.)" << "Galutinis (Med.)" << endl;
  out_f << "--------------------------------------------------------" << endl; 
  //start = std::chrono::high_resolution_clock::now();
    
    out_f << outputas;
    out_f.close();
  //end = std::chrono::high_resolution_clock::now();
  //diff = end-start; // Skirtumas (s)
  //std::cout << "Failo įrašymas per vieną eilutę užtruko: "<< diff.count() << " s\n";
  //std::cout<<outputas;
  diff = std::chrono::high_resolution_clock::now()-st; // Skirtumas (s)
  std::cout << "Visas sugaištas laikas: "<< diff.count() << " s\n\n"; 
}