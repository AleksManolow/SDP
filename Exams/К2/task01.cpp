#include<iostream>
#include<vector>
#include<string>
template<typename T>
struct Node
{
    T data;
    Node<T>* left;
    Node<T>* right;
};
//1a
int sizeWord(const char* word)
{
    int count = 0;
    while (word[count] != '\0')
    {
        count++;
    }
    return count;
}
bool isConteins(const Node<char>* tree, char c)
{
    if (!tree)
    {
        return false;
    }
    if (tree->data == c)
    {
        return true;
    }
    return isConteins(tree->left, c) || isConteins(tree->right, c);   
}
bool readWord(const Node<char>* tree, const char* word)
{
    int size = sizeWord(word);
    if (size < 4)
    {
        throw "Invalid word";
    }
    //Проверявам за първите 2 и последните 2 букви от думата
    if (isConteins(tree->left, word[0]) && isConteins(tree->left, word[1] &&
    isConteins(tree->right, word[size - 1]) && isConteins(tree->right, word[size - 2])))
    {
        //проверявам за остананалите букви от думата
        for (int i = 2; i < size - 2; i++)
        {
            if (!(isConteins(tree->left, word[i])) && !(isConteins(tree->right, word[i])))
            {
                return false;
            } 
        }
        return true;
    }
    return false;
}
//1b
int height(const Node<char>* tree)
{
    if (!tree)
        return 0;
    return 1 + std::max(height(tree->left), height(tree->right));
    
}
void getElOnLevel(const Node<char>* tree, int level, std::vector<char>& elementsOnLevel)
{
    if (!tree)
        return;
    if (level == 1)
        elementsOnLevel.push_back(tree->data);
    getElOnLevel(tree->left, level-1, elementsOnLevel);
    getElOnLevel(tree->right, level-1, elementsOnLevel);    
}
bool isSortVector(std::vector<char> elementsOnLevel)
{
    for (int i = 0; i < elementsOnLevel.size() - 1; i++)
    {
        if (elementsOnLevel[i] < elementsOnLevel[i + 1])
        {
            return false;
        }
    }
    return true;
}
size_t minLevel(const Node<char>* tree)
{
    int h = height(tree);
    for (size_t i = 2; i <= h; i++)
    {
        std::vector<char> elementsOnLevel;
        //взимам елементите за всяко ниво и ги слагам във вектор
        getElOnLevel(tree, i, elementsOnLevel);
        //проверявам дали са сортирани
        if (isSortVector(elementsOnLevel))
        {
            return i;
        }
    }
   return 1; 
}
template<typename T>
void clear(Node<T>* tree)
{
    if (!tree)
        return;
    clear(tree->left);
    clear(tree->right);
    delete tree;
}
int main()
{
    //1а
    //Мямам време за тестване

    //1б
    Node<char>* tree = new Node<char>();
    tree->data = 'F';
    tree->left = new Node<char>();
    tree->right = new Node<char>();
    tree->left->data = 'G';
    tree->right->data = 'B';
    tree->left->left = nullptr;
    tree->left->right = nullptr;
    tree->right->left = nullptr;
    tree->right->right = nullptr;

    std::cout << minLevel(tree) << std::endl;

    clear(tree);

    return 0;
}