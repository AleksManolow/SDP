#include<iostream>
#include<string>
#include<map>
#include<vector>
int countOfLettersOnPosition(std::string word, std::map<char, int> numberOfLetterInAlphabet)
{
    int count = 0;
    for (int i = 0; i < word.size(); i++)
    {
        if (numberOfLetterInAlphabet[tolower(word[i])] == i + 1)
        {
            count++;
        }
    }
    return count;
}
std::vector<int> solve(std::vector<std::string> words)
{   
    std::vector<int> countOfLetterInWord;
    std::map<char, int> numberOfLetterInAlphabet;
    for (int i = 1; i <= 26; i++)
    {
        numberOfLetterInAlphabet[char(96 + i)] = i;
    }
    
    for (auto word : words)
    {
        countOfLetterInWord.push_back(countOfLettersOnPosition(word, numberOfLetterInAlphabet));
    }
    
    return countOfLetterInWord;
}
int main()
{
    std::vector<std::string> words1
    {
        "abode",
        "ABc",
        "xyzD"
    };
    std::vector<std::string> words2
    {
        "IAMDEFANDJKL",
        "thedefgh",
        "xyzDEFghijabc"
    };
    std::vector<std::string> words3
    {
        "encode",
        "abc",
        "xyzD",
        "ABmD"
    };

    std::vector<int> countOfLetterInWord1 = solve(words1);

    for (auto count : countOfLetterInWord1)
    {
        std::cout << count << " ";
    }

    std::cout << std::endl;

    std::vector<int> countOfLetterInWord2 = solve(words2);

    for (auto count : countOfLetterInWord2)
    {
        std::cout << count << " ";
    }

    std::cout << std::endl;
    
    std::vector<int> countOfLetterInWord3 = solve(words3);

    for (auto count : countOfLetterInWord3)
    {
        std::cout << count << " ";
    }
    
    std::cout << std::endl;

    return 0;
}