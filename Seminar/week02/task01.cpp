#include<iostream>
#include<stack>
#include<string>
std::string removeStars(const std::string& s)
{
    std::stack<char> st;
    for (char item : s)
    {
        if(item == '*')
        {
            if (st.empty())
                throw "Invalid expr";
            else
                st.pop();
        } 
        else
        {
            st.push(item);
        }        
    }

    std::string result(st.size(),'\0');
    size_t idx = st.size() - 1;
    while (!st.empty())
    {
        result[idx--] = st.top();
        st.pop();
    }
    return result;
}
int main()
{
    std::cout << removeStars("aa*") << std::endl;
    std::cout << removeStars("erase*****") << std::endl;
    std::cout << removeStars("thi*s i*s exampl*e") << std::endl;

    return 0;
}