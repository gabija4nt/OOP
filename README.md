# Asociatyvių konteinerių naudojimas

Ši programa išanalizuoja tekstinį failą ir atlieka tokius veiksmus:

- Suskaičiuoja kiek kartų tekste pasikartoja kiekvienas žodis, praleidžiant skaičius, datas ar žodžius sudarytus iš vienos raidės.
- Sukuria cross-reference lentelę, kuri parodo kurioje eilutėje tam tikras žodis pasikartojo.
- Ištraukia iš teksto URL adresus ir atspausdina juos konsolėje.

# Sąlygos

Ši programa veikia nuo C++ 11 versijos.

# Naudojimas

- Atsisiųsti papildoma.cpp failą.
- Patalpinti tekstinį failą, kurį norite išanalizuoti į tą pačią direktyvą kaip ir papildoma.cpp. Pavadinkite tekstinį failą tekstas.txt
- Sukompiliuokite ir paleiskite programą.

# Išvestis

Programa generuoja du išvesties failus:

- rezultatai.txt: Šiame faile išvedami žodžiai su jų pasikartojimo tekste kiekiu.
- crossreference.txt: Šiame faile išvedama crossreference tipo lentelė, kuri rodo žodžius ir eilučių numerius, jei žodis pasikartojo daugiau nei kartą.

Taip pat, programa atspausdina URL adresus rastus tekste į konsolę.

# Pastabos

Tekstinis failas privalo būti išsaugotas kaip UTF-8 koduotė, kad programa teisingai pasielgtų su ne-ASCII simboliais.
