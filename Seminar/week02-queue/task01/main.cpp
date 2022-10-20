#include<iostream>
#include<queue>
#include"Player.h"
int kittens(std::string cardsString, int countPlayer)
{
    std::queue<Player> players;
    std::queue<char> cards;

    for (size_t i = 0; i < cardsString.size(); i++)
    {
        cards.push(cardsString[i]);
    }
    

    for (size_t i = 1; i <= countPlayer; i++)
    {
        players.push(Player(i));
    }
    
    while (players.size() > 1)
    {
        Player player = players.front();
        if (cards.front() == 'B')
        {
            if (player.getCountS() == 0)
            {
                players.pop();
            }
            else
            {
                players.pop();
                player.setCountS(player.getCountS() - 1);
                players.push(player);
                cards.push('B');
            }    
            
        }
        else if (cards.front() == 'S')
        {
            players.pop();
            player.setCountS(player.getCountS() + 1);
            players.push(player);
        }
        else if (cards.front() == 'O')
        {
            players.pop();
            players.push(player);
        }
        cards.pop();
    }
    return players.front().getID();
}
int main()
{
    std::cout << kittens("BB", 3) << std::endl;
    std::cout << kittens("SSBB", 3) << std::endl; 
    std::cout << kittens("SSBBOOOOOOOSBOOOOOOOOOSB", 5) << std::endl; 
    std::cout << kittens("SOOSBBOOOOSOOOSBOSOOBOSOSOOBOSOSOOB", 7) << std::endl;

    return 0;
}