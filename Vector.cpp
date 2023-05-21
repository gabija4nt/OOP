#include "Vector.h"

int main()
{
    // push_back-----------------------------------------------------------------
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    std::cout << "Vector size: " << v1.size() << '\n';  // Output: Vector size: 3

    Vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    std::cout << "Vector size: " << v2.size() << '\n' << '\n';  // Output: Vector size: 3
    //---------------------------------------------------------------------------



    // resize-------------------------------------------------------------------
    std::vector<std::string> v3;
    v3.resize(5, "Hello");
    std::cout << "Element at index 2: " << v3[2] << '\n';  // Output: Element at index 2: Hello

    Vector<std::string> v4;
    v4.resize(5, "Hello");
    std::cout << "Element at index 2: " << v4[2] << '\n' << '\n';  // Output: Element at index 2: Hello
    //---------------------------------------------------------------------------



    // insert and erase----------------------------------------------------------
    std::vector<int> v5{ 1, 2, 3, 4, 5 };
    std::cout << "std::vector before modification: ";
    for (const auto& element : v5) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    v5.insert(v5.begin() + 2, 10);
    v5.erase(v5.begin() + 3);
    std::cout << "std::vector after modification: ";
    for (const auto& element : v5) {
        std::cout << element << ' ';
    }
    std::cout << '\n';  // Output: std::vector after modification: 1 2 10 4 5

    Vector<int> v6{ 1, 2, 3, 4, 5 };
    std::cout << "Vector before modification: ";
    for (const auto& element : v6) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    v6.insert(v6.begin() + 2, 10);
    v6.erase(v6.begin() + 3);
    std::cout << "Vector after modification: ";
    for (const auto& element : v6) {
        std::cout << element << ' ';
    }
    std::cout << '\n' << '\n';  // Output: Vector after modification: 1 2 10 4 5
    //---------------------------------------------------------------------------



    // shrink_to_fit-------------------------------------------------------------
    std::vector<int> v7{ 1, 2, 3, 4, 5 };
    v7.resize(3);
    std::cout << "Capacity of v7 after resize: " << v7.capacity() << std::endl;
    v7.shrink_to_fit();
    std::cout << "Capacity of v7 after shrink_to_fit: " << v7.capacity() << std::endl;

    Vector<int> v8{ 1, 2, 3, 4, 5 };
    v8.resize(3);
    std::cout << "Capacity of v8 after resize: " << v8.capacity() << std::endl;
    v8.shrink_to_fit();
    std::cout << "Capacity of v8 after shrink_to_fit: " << v8.capacity() << std::endl << std::endl;



    // filling the vector--------------------------------------------------------------------------

    auto st = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - st;

    unsigned int sz = 10000;
    for (int j = 0; j < 5; ++j) {
        st = std::chrono::high_resolution_clock::now();
        std::vector<int> v9;
        for (int i = 0; i < sz; ++i)
            v9.push_back(i);
        end = std::chrono::high_resolution_clock::now();
        diff = end - st;
        std::cout << "std::vector uzpildyti " << sz << " elementu uztruko: " << diff.count() << " s\n";

        st = std::chrono::high_resolution_clock::now();
        Vector<int> v10;
        for (int i = 0; i < sz; ++i)
            v10.push_back(i);
        end = std::chrono::high_resolution_clock::now();
        diff = end - st;
        std::cout << "Vector uzpildyti " << sz << " elementu uztruko: " << diff.count() << " s\n" << "\n";

        sz *= 10;
    }


    // measuring reallocations--------------------------------------------------------------------------

    sz = 100000000;

    std::vector<int> v11;
    std::size_t v11_reallocations = 0;
    std::size_t v11_capacity = 0;
    for (int i = 1; i <= sz; ++i) {
        v11.push_back(i);
        if (v11_capacity != v11.capacity()) {
            v11_capacity = v11.capacity();
            ++v11_reallocations;
        }
    }
    std::cout << "number of reallocations in std::vector: " << v11_reallocations << '\n';

    Vector<int> v12;
    std::size_t v12_reallocations = 0;
    std::size_t v12_capacity = 0;
    for (int i = 1; i <= sz; ++i) {
        v12.push_back(i);
        if (v12_capacity != v12.capacity()) {
            v12_capacity = v12.capacity();
            ++v12_reallocations;
        }
    }
    std::cout << "number of reallocations in vector: " << v12_reallocations << '\n';

    //---------------------------------------------------------------------------



    return 0;
}