#include<iostream>
#include<vector>
#include <sstream>
#include<map>
struct SkipList
{
    std::string city;
    SkipList* next;
    SkipList* skip;
};
void readInput(std::vector<std::string>& cities,
    std::vector<std::pair<std::string, std::string>>& directLinls,
    std::vector<std::string>& citiesToVisit)
{
    //Read Cities
    int n;
    std::cout << "Enter number of cities: ";
    std::cin >> n;
    std::vector<std::string> cities;
    for (size_t i = 0; i < n; i++)
    {
        std::string city;
        std::cout << "Enter city name: ";
        std::cin >> city;
        cities.push_back(city);
    }

    //Read direct links
    std::vector<std::pair<std::string, std::string>> directLinls;
    std::cin.ignore();
    for (size_t i = 0; i < 5; i++)
    {
        std::string directLinlsLine;
        std::cout << "Enter direct linl: ";
        getline(std::cin, directLinlsLine);
        std::istringstream istr(directLinlsLine);
        std::string firstCity;
        std::string secondCity;
        istr >> firstCity;
        istr >> secondCity;
        directLinls.push_back(std::pair<std::string, std::string>(firstCity, secondCity));
    }

    //Read Cities to visit
    std::vector<std::string> citiesToVisit;
    std::string line;
    std::cout << "Enter list of cities of Anya and Vankata: ";
    std::cin.ignore();
	getline(std::cin, line);
	std::istringstream istr(line);
    std::string tempCity;
	while (istr >> tempCity)
	{
		citiesToVisit.push_back(tempCity);
	}

}
int main()
{
    std::vector<std::string> cities;
    std::vector<std::pair<std::string, std::string>> directLinls;
    std::vector<std::string> citiesToVisit;

    //ReadInput
    readInput(cities, directLinls, citiesToVisit);
    
    return 0;
}