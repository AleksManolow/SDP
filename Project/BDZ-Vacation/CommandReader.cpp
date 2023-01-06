#include"CommandReader.h"
void CommandReader::start()
{
    TaskManager taskManager;
    //Read Cities
    int n;
    std::cout << "Enter number of cities: ";
    std::cin >> n;
    std::vector<std::string> citiesNames;
    std::cin.ignore();
    std::string cities;
    std::cout << "Enter cities name: ";
	getline(std::cin, cities);
	std::istringstream istrCities(cities);
    std::string city;
    while (istrCities >> city)
	{
		citiesNames.push_back(city);
	}
    taskManager.creatListOfCities(citiesNames);

    //Read direct links
    std::vector<std::pair<std::string, std::string>> directLinls;
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
    taskManager.addDirectLinks(directLinls);

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
    std::vector<std::string> output = taskManager.shortestSequence(citiesToVisit);

    //Print-Output
    std::cout << "Answer: " << std::endl;
    for (std::string item : output)
    {
        std::cout << item << " ";
    }
    
    std::cout << std::endl;

}