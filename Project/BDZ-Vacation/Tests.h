#include<iostream>
#include"TaskManager.h"

TEST_CASE("Validate create SkipList: ") 
{
    TaskManager manager;

    //Cities
    std::vector<std::string> citiesNames = {"Sofia", "Pazardzhik", "Plovdiv", "Dimitrovgrad", "StaraZagora", "NovaZagora", "Yambol", "Karnobat", "Burgas"};
    manager.creatListOfCities(citiesNames);

    //Direct links
    std::vector<std::pair<std::string, std::string>> directLinls = {
        { "Sofia", "Plovdiv" },
        { "Plovdiv", "NovaZagora" },
        { "Dimitrovgrad", "NovaZagora" },
        { "StaraZagora", "Yambol" },
        { "NovaZagora", "Burgas" }
    };

    manager.addDirectLinks(directLinls);

    CHECK(manager.getListOfCities()->city == "Sofia");
    CHECK(manager.getListOfCities()->skip->city == "Plovdiv");
    CHECK(manager.getListOfCities()->next->next->skip->city == "NovaZagora");
    CHECK(manager.getListOfCities()->next->next->next->next->city == "StaraZagora");
    CHECK(manager.getListOfCities()->next->next->next->next->skip->city == "Yambol");
}
TEST_CASE("Validate the shortest sequence of cities such that yes all their desired destinations are visited: ") 
{
    TaskManager manager;

    //Cities
    std::vector<std::string> citiesNames = {"Sofia", "Pazardzhik", "Plovdiv", "Dimitrovgrad", "StaraZagora", "NovaZagora", "Yambol", "Karnobat", "Burgas"};

    manager.creatListOfCities(citiesNames);

    //Direct links
    std::vector<std::pair<std::string, std::string>> directLinls = {
        { "Sofia", "Plovdiv" },
        { "Plovdiv", "NovaZagora" },
        { "Dimitrovgrad", "NovaZagora" },
        { "StaraZagora", "Yambol" },
        { "NovaZagora", "Burgas" }
    };

    manager.addDirectLinks(directLinls);

    //Cities to visit
    std::vector<std::string> citiesToVisit = {"Plovdiv", "StaraZagora", "Yambol"};

    std::vector<std::string> output = manager.shortestSequence(citiesToVisit);

    CHECK(output[0] == "Sofia");
    CHECK(output[1] == "Plovdiv");
    CHECK(output[2] == "Dimitrovgrad");
    CHECK(output[3] == "StaraZagora");
    CHECK(output[4] == "Yambol");
    CHECK(output[5] == "Karnobat");
    CHECK(output[6] == "Burgas");
    CHECK(output.size() == 7);
}
