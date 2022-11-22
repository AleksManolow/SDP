#include<iostream>
#include<list>
#include<queue>
bool isSortedSequence(std::list<std::queue<int>> list)
{   
    int fisrtEl;
    for (std::queue<int> q : list)
    {
        if (fisrtEl > q.front() && !q.empty())
        {
            return false;
        }

        fisrtEl = q.front();
        while (q.size() > 1)
        {
            q.pop();
            if (q.front() < fisrtEl)
            {
                return false;
            }
            fisrtEl = q.front();
        }
    }
    return true;
}
int main()
{
    //First test
    std::list<std::queue<int>> l1;

	std::queue<int> q11;
	q11.push(1);
	q11.push(2);
	q11.push(3);
	std::queue<int> q21;
	q21.push(6);
	q21.push(9);
	q21.push(10);
	std::queue<int> q31;
	q31.push(11);
	q31.push(22);
	q31.push(23);
	std::queue<int> q41;

	l1.push_back(q11);
	l1.push_back(q21);
	l1.push_back(q31);
	l1.push_back(q41);

	std::cout << isSortedSequence(l1) << std::endl;

    //Secound test
    std::list<std::queue<int>> l2;

	std::queue<int> q12;
	q12.push(1);
	std::queue<int> q22;
	q22.push(6);
	q22.push(9);
	q22.push(10);
	std::queue<int> q32;
	q32.push(9);
	q32.push(22);

	l2.push_back(q12);
	l2.push_back(q22);
	l2.push_back(q32);

	std::cout << isSortedSequence(l2) << std::endl;

    //Third test
    std::list<std::queue<int>> l3;

	std::queue<int> q13;
	q13.push(1);
    q13.push(2);
    q13.push(3);
	std::queue<int> q23;
	q23.push(4);
	q23.push(5);
	q23.push(4);

	l3.push_back(q13);
	l3.push_back(q23);

	std::cout << isSortedSequence(l3) << std::endl;


    return 0;
}