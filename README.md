# versija 1.1

Patobulinta v1.0 taip, kad vietoje studento tipo struktūros (struct), dabar naudojama studento tipo klasė (class)

Perėjus nuo struct į class, pasikeitė programos veikimo laikas. Rezultatai pateikiami lentelėse.

|Optimizacija| Žingsniai | Duom. tipas | 100 000 | 1 000 000 |
| --- | --- | --- | --- | --- |
|-O3| Nuskaitymas (s)|Struct|0.470578|4.54415|
|||Class|0.458693|4.56802|
|| Rikiavimas (s) |Struct|0.022428|0.316242|
|||Class|0.025604|0.311407|
|| Rūšiavimas (s) |Struct|0.005217|0.055913|
|||Class|0.005419|0.0453|

|Optimizacija| Žingsniai | Duom. tipas | 100 000 | 1 000 000 |
| --- | --- | --- | --- | --- |
|-O2| Nuskaitymas (s)|Struct|0.466438|4.59078|
|||Class|0.466103|4.5919|
|| Rikiavimas (s) |Struct|0.024286|0.291218|
|||Class|0.032087|0.398362|
|| Rūšiavimas (s) |Struct|0.004991|0.057826|
|||Class|0.004912|0.046636|

|Optimizacija| Žingsniai | Duom. tipas | 100 000 | 1 000 000 |
| --- | --- | --- | --- | --- |
|-O1| Nuskaitymas (s)|Struct|0.45294|4.60282|
|||Class|0.460728|4.63452|
|| Rikiavimas (s) |Struct|0.029981|0.350734|
|||Class|0.037179|0.469698|
|| Rūšiavimas (s) |Struct|0.006316|0.052258|
|||Class|0.004593|0.045317|

v1.1 versijos exe failų dydžiai priklausomai nuo optimizacijos vėliavėlės:
- O3: 3128 KB
- O2: 3116 KB
- O1: 3121 KB

# Naudojimosi instrukcija

Šiai programai naudojama:
- C++ 17 versija
- optimizavimo vėliavėlės -O3, -O2, -O1 pagal preferenciją.

Dėl to priklausomai nuo IDE ar OS norint paleisti programą reikėtų atsižvelgti į šiuos parametrus.

Paleista programa vartotojui leidžia pasirinkti generuoti naujus failus ir atlikti skaičiavimus su jais arba tik testuoti programos veikimą.
Jeigu pasirenkama generuoti naujus failus, toliau atliekami visi praėjusiose versijoje įgyvendinti skaičiavimai, matuojamas jų laikas:

vartotojui pasirinkus, sugeneruojami penki atsitiktinių studentų sąrašų failai, sudaryti iš:
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

- visos programos veikimo laikas.
