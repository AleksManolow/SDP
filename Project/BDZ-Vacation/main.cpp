#include<iostream>
#include<vector>
#include<sstream>
#include<map>
#include "TaskManager.h"

// void readInput(std::vector<std::string>& citiesNames,
//     std::vector<std::pair<std::string, std::string>>& directLinls,
//     std::vector<std::string>& citiesToVisit)
// {
//     //Read Cities
//     int n;
//     std::cout << "Enter number of cities: ";
//     std::cin >> n;
//     for (size_t i = 0; i < n; i++)
//     {
//         std::string city;
//         std::cout << "Enter city name: ";
//         std::cin >> city;
//         citiesNames.push_back(city);
//     }

//     //Read direct links
//     std::cin.ignore();
//     for (size_t i = 0; i < 5; i++)
//     {
//         std::string directLinlsLine;
//         std::cout << "Enter direct linl: ";
//         getline(std::cin, directLinlsLine);
//         std::istringstream istr(directLinlsLine);
//         std::string firstCity;
//         std::string secondCity;
//         istr >> firstCity;
//         istr >> secondCity;
//         directLinls.push_back(std::pair<std::string, std::string>(firstCity, secondCity));
//     }

//     //Read Cities to visit
//     std::string line;
//     std::cout << "Enter list of cities of Anya and Vankata: ";
//     std::cin.ignore();
// 	getline(std::cin, line);
// 	std::istringstream istr(line);
//     std::string tempCity;
// 	while (istr >> tempCity)
// 	{
// 		citiesToVisit.push_back(tempCity);
// 	}
// }
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
    std::vector<std::string> citiesNames;
    std::vector<std::pair<std::string, std::string>> directLinls;
    std::vector<std::string> citiesToVisit;

    //ReadInput
    //readInput(citiesNames, directLinls, citiesToVisit);
    exemplaryInput(citiesNames, directLinls, citiesToVisit);

    TaskManager taskManager;

    taskManager.creatListOfCities(citiesNames);
    taskManager.addDirectLinks(directLinls);
    std::vector<std::string> sequenceOfCities = taskManager.shortestSequence(citiesToVisit);
    //Print-A
    for (auto city : sequenceOfCities)
    {
        std::cout << city << " ";
    }
    std::cout << std::endl;

    return 0;
}