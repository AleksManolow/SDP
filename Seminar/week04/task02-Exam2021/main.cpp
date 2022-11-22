#include <iostream>
#include <vector>
#include <stack>
#include <list>
void equalize(std::list<std::stack<int>>& list)
{
    int numberOfStacks= list.size();
    int numberOfElemets = 0;
    for (std::stack<int>& x : list)
    {
        numberOfElemets += x.size();
    }

    int median = numberOfElemets / numberOfStacks;
    bool eq = numberOfElemets % numberOfStacks;

    std::vector<std::stack<int>> overMedian;
    std::vector<std::stack<int>> underMedian;

    for (std::stack<int>& x : list)
    {
        if (x.size() < median)
        {
            underMedian.push_back(x);
        }
        else if (x.size() >= median)
        {
            overMedian.push_back(x);
        }
    }
    
    int iteratorOverMedian = 0;
	int iteratorUnderMedian = 0;
    for (std::stack<int>& x : underMedian)
    {   
        while (x.size() <= median - !(eq))
        {
            while (overMedian[iteratorOverMedian].size() == median)
            {
                if (overMedian.size() == iteratorOverMedian + 1)
                {
                    overMedian.push_back(underMedian[iteratorUnderMedian++]);
                }
                ++iteratorOverMedian;
            }
            x.push(overMedian[iteratorOverMedian].top());
            overMedian[iteratorOverMedian].pop();
        }
    }
    
    for (int i = 0; i < iteratorUnderMedian; i++)
		overMedian.pop_back();

	list.clear();

	for (int i = 0; i < overMedian.size(); i++)
		list.push_back(overMedian[i]);

	for (int i = 0; i < underMedian.size(); i++)
		list.push_back(underMedian[i]);
}
int main()
{
    std::list<std::stack<int>> l;
	std::stack<int> a;
	std::stack<int> d;
	std::stack<int> e;
	std::stack<int> c;
	std::stack<int> b;

	for (int i = 0; i < 4; i++)
		a.push(i);

	for (int i = 0; i < 9; i++)
		b.push(i);

	for (int i = 0; i < 12; i++)
		c.push(i);

	for (int i = 0; i < 16; i++)
		d.push(i);

	for (int i = 0; i < 20; i++)
		e.push(i);

	l.push_back(a);
	l.push_back(b);
	l.push_back(c);
	l.push_back(d);
	l.push_back(e);
	
	equalize(l);

	for (std::stack<int> a : l) 
	{
		std::cout << a.size() << ": ";
		while (!a.empty()) 
		{
			std::cout << a.top() << " ";
			a.pop();
		}
		std::cout << std::endl;
	}
    
    return 0;
}