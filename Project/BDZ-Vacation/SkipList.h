#ifndef __SKIPLIST_H
#define __SKIPLIST_H
#include<iostream>
struct SkipList
{
    std::string city;
    SkipList* next;
    SkipList* skip;

    SkipList(std::string _city):city(_city), next(nullptr), skip(nullptr) {   }
};

#endif