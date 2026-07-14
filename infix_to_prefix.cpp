#include <bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (isalnum(c))
            result += c;

        else if (c == '(')
            st.push(c);

        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && prec(c) < prec(st.top()))
            {
                result += st.top();
                st.pop();
            }

            while (!st.empty() && prec(c) == prec(st.top()) && c != '^')
            {
                result += st.top();
                st.pop();
            }

            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    string postfix = infixToPostfix(s);

    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main()
{
    string exp = "(p+q)*(m-n)";

    cout << "Infix  : " << exp << endl;
    cout << "Prefix : " << infixToPrefix(exp);

    return 0;
}