#include<iostream>
#include<string>
#include<stack>
int charToInt(char c)
{
    return (int)c - '0';
}
int calculate(const std::string& str)
{
    std::stack<int> st;
    for (char c : str)
    {
        if(isdigit(c))
        {
            st.push(charToInt(c));
        }
        else
        {
            int snd = st.top();
            st.pop();
            int fst = st.top();
            st.pop();
            switch (c)
            {
            case '+':
                st.push(fst + snd);
                break;
            case '-':
                st.push(fst - snd);
                break;
             case '*':
                st.push(fst * snd);
                break;
            case '/':
                st.push(fst / snd);
                break;
            }
        }          
    }
    return st.top();
}
int main()
{
    std::cout << calculate("123+-") << std::endl;
    std::cout << calculate("934*-25*-") << std::endl;
    return 0;
}