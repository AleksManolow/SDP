#include<iostream>
#include<vector>
#include <sstream>
#include<map>
struct SkipList
{
    std::string city;
    SkipList* next;
    SkipList* skip;

    SkipList(std::string _city):city(_city), next(nullptr), skip(nullptr) {   }
};
void readInput(std::vector<std::string>& citiesNames,
    std::vector<std::pair<std::string, std::string>>& directLinls,
    std::vector<std::string>& citiesToVisit)
{
    //Read Cities
    int n;
    std::cout << "Enter number of cities: ";
    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::string city;
        std::cout << "Enter city name: ";
        std::cin >> city;
        citiesNames.push_back(city);
    }

    //Read direct links
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
SkipList* creatListOfCities(std::vector<std::string>& citiesNames)
{
    SkipList* cities = nullptr;
    for (int i = citiesNames.size() - 1; i >= 0; i--)
    {
        SkipList* newList = new SkipList(citiesNames[i]);
        newList->next = cities;
        cities = newList;
    }
    return cities;
}
SkipList* findCity(SkipList* cities, std::string name)
{
    while (cities->city != name)
    {
        cities = cities->next;
    }
    return cities;
}
void addDirectLinks(SkipList*& cities, std::vector<std::pair<std::string, std::string>> directLinls)
{
    for (auto citiesNamesDirect : directLinls)
    {
        SkipList* firstCity = findCity(cities, citiesNamesDirect.first);
        SkipList* secondCity = findCity(cities, citiesNamesDirect.second); 
        firstCity->skip = secondCity;
    }
}
bool canUseDirectRoute(SkipList* cities, std::vector<std::string> citiesToVisit)
{
    SkipList* afterSkipCity = cities->skip; 
    cities = cities->next;
    //it goes through any cities that I can skip by taking the direct route and 
    //checks if any of those cities have it in the city-to-visit vector
    while (cities != afterSkipCity)
    {
        for (auto item : citiesToVisit)
        {
            if (cities->city == item)
            {
                return false;
            }   
        }
        cities = cities->next;
    }
    return true;
}
void shortestSequence(SkipList* cities, std::vector<std::string> citiesToVisit)
{
    std::vector<std::string> sequenceOfCities;
    while(cities != nullptr)
    {
        //I check if the city they are in is there in the vector of cities to visit and if it is, I remove it
        for (auto it = citiesToVisit.begin(); it != citiesToVisit.end(); ++it)
        {
            if (*it == cities->city)
            {
                citiesToVisit.erase(it, it + 1);
                break;
            }
        }
        sequenceOfCities.push_back(cities->city); 
        //checking if I can use the shortcut if there is one
        if (cities->skip != nullptr && canUseDirectRoute(cities, citiesToVisit))
        {
            cities = cities->skip;
        }
        else
        {
            cities = cities->next;
        }
    }

    //Print
    if (!citiesToVisit.empty())
    {
        std::cout << "No such path found!" << std::endl;
    }
    else
    {
        for (auto city : sequenceOfCities)
        {
            std::cout << city << " ";
        }
        std::cout << std::endl;
    }
}
void printSkipList(SkipList* cities)
{
    while (cities)
    {
        std::cout << cities->city << std::endl;
        if (cities->skip != nullptr)
        {
            std::cout << "(" << cities->skip->city << ")" << std::endl;
        }
        cities = cities->next;  
    }
}
void clean(SkipList*& n) {
    if (n == nullptr) return;
    clean(n->next);
    delete n;
}
int main()
{
    std::vector<std::string> citiesNames;
    std::vector<std::pair<std::string, std::string>> directLinls;
    std::vector<std::string> citiesToVisit;

    //ReadInput
    //readInput(citiesNames, directLinls, citiesToVisit);
    exemplaryInput(citiesNames, directLinls, citiesToVisit);

    //Create list of cities
    SkipList* cities = creatListOfCities(citiesNames);
    addDirectLinks(cities, directLinls);

    //Print SkipList
    //printSkipList(cities);
    
    //Solution - A)
    shortestSequence(cities, citiesToVisit);

    //Delete Memory
    clean(cities);

    return 0;
}