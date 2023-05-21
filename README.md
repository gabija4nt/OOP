# Eksperimentiniai Vector klasės tyrimai
Buvo realizuota Vector klasė, kuri funkcionalumo prasme atitinka std::vector. Žemiau pateikiami aprašymai kai kurių Vector klasės funkcijų.

Vector klasės funkcijos:
# funkcija "clear()"
Tai pagrindinė vektoriaus funkcija, skirtą išvalyti dinaminio masyvo duomenis ir atlaisvinti atmintį.

```cpp
 void clear() {
        delete[] data_ptr;
        data_ptr = nullptr;
        data_size = 0;
        data_capacity = 0;
    }
```
# funkcija "pop_back()"
Funkcija "pop_back()" naudojama pašalinti paskutinį elementą iš masyvo. Ši funkcija atlieka šiuos veiksmus:
- Patikrina, ar masyvas turi elementų. Jei masyvas yra tuščias, funkcija nedaro jokio veiksmo ir tiesiog grįžta.
- Jei masyvas turi elementų, funkcija sumažina "data_size" kintamąjį vienetu.
- Panaudojamas destruktorius "~T()" pašalinti paskutinio elemento reikšmę. Tai yra svarbu, jei elementai yra sudėtingo tipo arba reikalauja specialių operacijų pašalinimui.
```cpp
    void pop_back() {
        if (data_size > 0) {
            --data_size;
            data_ptr[data_size].~T();
        }
    }
```
# funkcija "front()"
"front()" funkcija leidžia lengvai pasiekti pirmąjį masyvo elementą, jei jis egzistuoja.
```cpp
reference front() {
        return data_ptr[0];
    }
```
# funkcija "begin()"
Grąžina iteratorių, rodantį į pirmąjį masyvo elementą, kuris yra saugomas adresu data_ptr.
 iterator begin() {
        return data_ptr;
    }
# operatorius "[]"
Galima naudoti operatorių [], kad pasiekti ir modifikuoti pridėtus elementus masyve.
```cpp
reference operator[](size_t index) {
        if (index >= data_size) {
            throw std::out_of_range("Index out of range");
        }
        return data_ptr[index];
    }
    
```
# std::vector vs Vector
Žemiau palyginamas std::vector ir Vector greitis norint užpildyt tuščius konteinerius skirtingu kiekiu elementų::

|Elementų sk.|std::vector|Vector|
|---|---|---|
|10000|0.0001186 s|0.0001548 s|
|100000|0.0032994 s|0.0009001 s|
|1000000|0.0098661 s|0.0063514 s|
|10000000|0.101212 s|0.0668307 s|
|100000000|1.36189 s|0.98853 s|

Atminties perskirstymai užpildant 100000000 elementų. Perskirstymas įvyksta tada, kai yra patenkinama sąlyga: capacity() == size():

std::vector : 47
Vector :      28

Taip pat buvo palyginta programos v2.0 sparta su std::vector ir Vector naudojant failą iš 100k studentų:

|Operacija|std::vector|Vector|
|Nuskaitymas|0.459289|0.203588|
|Rikiavimas|0.019901|0.0634126|
|Rūšiavimas|0.049706|0.0263321|
