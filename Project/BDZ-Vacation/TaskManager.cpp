#include"TaskManager.h"

TaskManager::TaskManager()
{
    listOfCities = nullptr;
}
TaskManager::~TaskManager()
{
    //delete list of cities
    SkipList* temp;
    while (listOfCities != nullptr)
    {
        temp = listOfCities;
        listOfCities = listOfCities->next;
        delete temp;
    }
}

void TaskManager::creatListOfCities(std::vector<std::string>& citiesNames)
{
    for (int i = citiesNames.size() - 1; i >= 0; i--)
    {
        SkipList* newList = new SkipList(citiesNames[i]);
        newList->next = listOfCities;
        listOfCities = newList;
    }
}
SkipList* TaskManager::findCity(std::string name)
{
    SkipList* cities = listOfCities;
    while (cities->city != name)
    {
        cities = cities->next;
    }
    return cities;
}
void TaskManager::addDirectLinks(std::vector<std::pair<std::string, std::string>> directLinls)
{
    for (auto citiesNamesDirect : directLinls)
    {
        SkipList* firstCity = findCity(citiesNamesDirect.first);
        SkipList* secondCity = findCity(citiesNamesDirect.second); 
        firstCity->skip = secondCity;
    }
}
void TaskManager::printSkipList()
{
    SkipList* cities = listOfCities;
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
bool TaskManager::canUseDirectRoute(SkipList* cities, std::vector<std::string> citiesToVisit)
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
void TaskManager::shortestSequence(std::vector<std::string> citiesToVisit)
{
    SkipList* cities = listOfCities;
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