# v1.0

Release'ų aprašymai:

# v0.1 (C masyvas arba Vector)

Ši programos versija saugo vartotojo įvestus pažymius į dinaminį masyvą arba vektorių.

Vartotojas gali pasirinkti įvesti pasirinktą skaičių namų darbų pažymių arba ir vieną egzamino pažymį arba leisti programai sugeneruoti tai atsitiktinai.
Iš namų darbų vartotojas pasirinktinai skaičiuoja vidurkį arba medianą.

Galiausiai apskaičiuojamas galutinis pažymys pagal tokią formulę:

![image](https://user-images.githubusercontent.com/115726083/220991712-63c31e1c-38d7-419f-b5a6-2912668ad0c3.png)


# versija 0.2

versijos atnaujinimas: 

  - nuo šiol programoje galima naudoti ne tik naudotojo įvestus,
    bet ir iš failo nuskaitytus duomenis.
    
  - taip pat išvesčiai sukuriamas išvesties failas. Konsolė naudojama
    tik laikui, per kurį buvo įvykdyta programa, išvesti.
    
  - dideliam duomenų kiekiui apdoroti buvo panaudotas mišrus metodas,
    t. y., failas skaitomas eilutėmis, o įrašomas per buferį.
  
# versija 0.3

  - daug spartesnis didelių failų apdorojimas.
    
  - failai apdorojami dviem būdais:
    1. Nuskaitant ir įrašant per buferį.
    2. Nuskaitant eilutėmis, įrašant per buferį.
    
  - pakoreguotas išimčių valdymas: bandant nuskaityti tuščią failą metama klaida.
  
  # versija 0.4

sukurtas failų generatorius. 
vartotojui pasirinkus, sugeneruojami penki atsitiktinių studentų sąrašų failaii, sudaryti iš: 1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Su kiekvienu failu atskirai atliekami tokie veiksmai.
Surūšiuojami studentai į dvi kategorijas:
- Studentai, kurių galutinis balas < 5.0.
- Studentai, kurių galutinis balas >= 5.0.

Surūšiuoti studentai išvedami į du naujus failus.

Išmatuojama programos sparta išskiriant kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
- (pasirinktinai) failo generavimo laikas;
- duomenų nuskaitymas iš failo;
- duomenų vektoriaus rikiavimas didėjimo tvarka;
- duomenų vektoriaus padalijimas į dvi grupes;
- duomenų išvedimas į du atskirus failus;
- visos programos veikimo laikas.

# versija 0.5

Programos testavimas panaudojant skirtingų tipų konteinerius:
 - std::vector
 - std::list
 - std::deque
 
 Rezultatai:

| Žingsniai | Kont. tipas | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
| --- | --- | --- | --- | --- | --- | --- |
| Nuskaitymas (s)|Vector|0.010682|0.0854|0.623621|3.60492|40.8821|
||List|0.007375|0.044485|0.374652|3.88704|42.2414|
||Deque|0.012539|0.044168|0.362999|5.42481|46.9974|
| Rūšiavimas (s) |Vector|0.000266|0.005282|0.026576|0.260004|3.97401|
||List|0.000144|0.002066|0.040561|0.643091|10.7094|
||Deque|0.000425|0.004451|0.046844|0.484939|5.84639|
| Skirstymas (s) |Vector|0.000796|0.003738|0.010275|0.115189|1.04849|
||List|0.000172|0.002558|0.024627|0.267473|4.58699|
||Deque|0.000423|0.001185|0.024627|0.127211|2.3182|

Testavimo sistemos parametrai:

CPU: Intel Core i5-7200U (2 branduoliai, 2.5 GHz)

RAM: 8 GB (2133 MHz)

HDD: 128 GB TOSHIBA THNSNK128GCS8 SATA SSD

# versija 1.0

Optimizuota studentų rūšiavimo (dalijimo) į dvi kategorijas ("vargšiukų" ir "kietiakų") realizaciją:
t.y. visiems trims konteinerių tipams (vector, list ir deque) išmatuota programos veikimo sparta
priklausomai nuo studentų dalijimo į dvi kategorijas strategijos:

 - 1 strategija: Bendro studentai konteinerio (vector, list ir deque tipų)
skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius: "silpniukų" ir "gudručių".

 - 2 strategija: Bendro studentų konteinerio (vector, list ir deque) skaidymas (rūšiavimas)
panaudojant tik vieną naują konteinerį: "silpniukai".

Rūšiavimo rezultatai : 

| Kont. tipas | Strategija | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|--- | --- | --- | --- | --- | --- | --- |
|Vector|1 str.|0.000284|0.002456|0.010574|0.121434|1.10751|
||2 str.|0.01061|0.327516|55.5592|-|-|
|List|1 str.|0.000343|0.00351|0.026915|0.261055|4.72714|
||2 str.|0.000122|0.001569|0.01325|0.140333|2.08003|
|Deque|1 str.|0.00019|0.001155|0.010588|0.092601|2.27641|
||2 str.|9.7e-05|0.001387|0.006499|0.062924|0.728491|

2-oji strategija veikia greičiau, naudoja mažiau atminties, bet tinkama tik List ir Deque tipo konteineriams.

Todėl naudojant partition algoritmą buvo patobulinta programa, naudojanti Vector tipo konteinerius.

Rezultatai palyginimui su kitomis strategijomis matomi lentelėje (3 str.):

| Kont. tipas | Strategija | 1 000  | 10 000 | 100 000 | 1 000 000 | 10 000 000 |
|--- | --- | --- | --- | --- | --- | --- |
|Vector|1 str.|0.000284|0.002456|0.010574|0.121434|1.10751|
||2 str.|0.01061|0.327516|55.5592|-|-|
||3 str.|0.000151|0.00134|0.007058|0.059453|0.687298|

# Naudojimosi instrukcija

Šiai programai naudojama:
- C++ 17 versija
- optimizavimo vėliavėlės -O3

Dėl to priklausomai nuo IDE ar OS norint paleisti programą reikėtų atsižvelgti į šiuos parametrus.

Paleista programa vartotojui leidžia pasirinkti generuoti naujus failus arba atlikti skaičiavimus su jau repozitorijoje esamais failais.
Toliau atliekami visi praėjusiose versijoje įgyvendinti skaičiavimai, matuojamas jų laikas:

vartotojui pasirinkus, sugeneruojami penki atsitiktinių studentų sąrašų failaii, sudaryti iš:
1 000, 10 000, 100 000, 1 000 000, 10 000 000 įrašų. Su kiekvienu failu atskirai atliekami tokie veiksmai:

Surūšiuojami studentai į dvi kategorijas:
- Studentai, kurių galutinis balas < 5.0.
- Studentai, kurių galutinis balas >= 5.0.

Surūšiuoti studentai išvedami į du naujus failus.

Išmatuojama programos sparta išskiriant kiek laiko užtruko kiekvienas iš žemiau išvardintų žingsnių:
- (pasirinktinai) failo generavimo laikas;
- duomenų nuskaitymas iš failo;
- duomenų vektoriaus rikiavimas didėjimo tvarka;
- duomenų vektoriaus padalijimas į dvi grupes;
- duomenų išvedimas į du atskirus failus;
- visos programos veikimo laikas.
