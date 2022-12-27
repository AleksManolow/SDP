#ifndef __TASKMANAGER_H
#define __TASKMANAGER_H

#include<vector>
#include "SkipList.h"


class TaskManager
{
private:
    SkipList* listOfCities;

    SkipList* findCity(std::string name);
    bool canUseDirectRoute(SkipList* cities, std::vector<std::string> citiesToVisit);
public:
    TaskManager();
    ~TaskManager();
    
    void creatListOfCities(std::vector<std::string>& citiesNames);
    void addDirectLinks(std::vector<std::pair<std::string, std::string>> directLinls);
    void printSkipList();
    void shortestSequence(std::vector<std::string> citiesToVisit);
};

#endif