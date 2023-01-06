#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include "CommandReader.h"

void exemplaryInput(std::vector<std::string>& citiesNames,
    std::vector<std::pair<std::string, std::string>>& directLinls,
    std::vector<std::string>& citiesToVisit)
{
    //Cities
    citiesNames = {"Sofia", "Pazardzhik", "Plovdiv", "Dimitrovgrad", "StaraZagora", "NovaZagora", "Yambol", "Karnobat", "Burgas"};

    //Direct links
    directLinls = {
        { "Sofia", "Plovdiv" },
        { "Plovdiv", "NovaZagora" },
        { "Dimitrovgrad", "NovaZagora" },
        { "StaraZagora", "Yambol" },
        { "NovaZagora", "Burgas" }
    };

    //Cities to visit
    citiesToVisit = {"Plovdiv", "StaraZagora", "Yambol"};
}
int main()
{

    CommandReader commandReader;
    commandReader.start();
    
    return 0;
}