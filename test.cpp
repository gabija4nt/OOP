#include "studentas.h"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_test_macros.hpp"

TEST_CASE("Tuscias vektorius", "[vidurkis]") {
    studentas a("Vardas", "Pavardauskas", 10.);
    studentas b("Vardas", "Pavardauskas", 5.);
    REQUIRE(compareByGalutinis(a, b) == false);
}

TEST_CASE("vidurkis") {
    std::vector<int> paz;
    REQUIRE(vidurkis(paz) == 1.0);

    paz = { 1,2,3,4,5 };
    REQUIRE(vidurkis(paz) == 3.0);

    paz = { 5 };
    REQUIRE(vidurkis(paz) == 5.0);
}

TEST_CASE("studentas") {
    SECTION("default constructor") {
        studentas s;
        REQUIRE(s.vardas() == "");
        REQUIRE(s.pavarde() == "");
        REQUIRE(s.paz().empty());
        REQUIRE(s.gal_paz_v() == 0);
    }

    SECTION("constructor with parameters") {
        studentas s("Vardas", "Pavarde", 8.5);
        REQUIRE(s.vardas() == "Vardas");
        REQUIRE(s.pavarde() == "Pavarde");
        REQUIRE(s.paz().empty());
        REQUIRE(s.gal_paz_v() == 8.5);
    }

    SECTION("copy constructor") {
        studentas s1("Vardas", "Pavarde", 8.5);
        studentas s2 = s1;
        REQUIRE(s2.vardas() == "Vardas");
        REQUIRE(s2.pavarde() == "Pavarde");
        REQUIRE(s2.paz().empty());
        REQUIRE(s2.gal_paz_v() == 8.5);
    }

    SECTION("move constructor") {
        studentas s1("Vardas", "Pavarde", 8.5);
        studentas s2(std::move(s1));
        REQUIRE(s2.vardas() == "Vardas");
        REQUIRE(s2.pavarde() == "Pavarde");
        REQUIRE(s2.paz().empty());
        REQUIRE(s2.gal_paz_v() == 8.5);
        REQUIRE(s1.vardas() == "");
        REQUIRE(s1.pavarde() == "");
        REQUIRE(s1.paz().empty());
        REQUIRE(s1.gal_paz_v() == 0);
    }

    SECTION("copy assignment operator") {
        studentas s1("Vardas", "Pavarde", 8.5);
        studentas s2;
        s2 = s1;
        REQUIRE(s2.vardas() == "Vardas");
        REQUIRE(s2.pavarde() == "Pavarde");
        REQUIRE(s2.paz().empty());
        REQUIRE(s2.gal_paz_v() == 8.5);
    }

    SECTION("move assignment operator") {
        studentas s1("Vardas", "Pavarde", 8.5);
        studentas s2;
        s2 = std::move(s1);
        REQUIRE(s2.vardas() == "Vardas");
        REQUIRE(s2.pavarde() == "Pavarde");
        REQUIRE(s2.paz().empty());
        REQUIRE(s2.gal_paz_v() == 8.5);
        REQUIRE(s1.vardas() == "");
        REQUIRE(s1.pavarde() == "");
        REQUIRE(s1.paz().empty());
        REQUIRE(s1.gal_paz_v() == 0);
    }
}