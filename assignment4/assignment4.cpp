// 23303
/*Implement a program to convert an infix expression to prefix and postfixnotation. • Evaluate both prefix and postfix expressions. Use STL for implementation*/

#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

struct numberStruct
{
    bool isNumber;
    int n; 
    char op;

    numberStruct(int x){
        isNumber = true;
        n = x;
        op = '\0';
    }
    numberStruct(char c){
        isNumber = false;
        n = -1;
        op = c;
    }
};

typedef struct numberStruct numberStruct;

class converter
{
private:
    string expression;

public:
    int precedence(char x);
    bool isRightAssociative(char x);
    bool isOperator(char x);
    string infixToPostfix();
    string infixToPrefix();
    int postfixResult(string expressionPostfix);
    int prefixResult(string expressionPrefix);
    int operationEngine(int a, int b, char o);
    string displayStrings(stack<numberStruct> st);

    converter(string x)
    {
        expression = x;
    }
};

string converter::displayStrings(stack<numberStruct> st)
{
    string expressionOut;
    while (!st.empty())
    {
        for (int i = 0; i < st.size(); i++)
        {
            if (st.top().op != 'a')
            {
            }
            else if (st.top().n != -1)
            {
            }
        }
    }
    return expressionOut;
}

int converter::operationEngine(int a, int b, char o)
{
    switch (o)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    case '^':
        return pow(a, b);
        break;
    default:
        break;
    }
}

int converter::precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
    if (x == '^')
    {
        return 3;
    }
    return 0;
}

bool converter::isRightAssociative(char x)
{
    return (x == '^');
}

bool converter::isOperator(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

string converter::infixToPostfix()
{
    stack<numberStruct> st;
    string postfix = "";
    int num = -1;

    for (size_t i = 0; i<expression.size(); i++)
    {
        char x = expression[i];

        if (isspace(x))
        {
            continue;
        }
        if (isdigit(x))
        {
            if(num == -1)
            {
                num = x - '0';
            }
            else
            {
                num = num * 10 + (x-'0');
            }
        }
        else
        {
            if(num != -1)
            {
                postfix += to_string(num) + " ";
                num = -1;
            }

            if (x == '(')
            {
                st.push(numberStruct('('));
            }
            else if (x == ')')
            {
                while (!st.empty() && st.top().op != '(')
                {
                    postfix += st.top().op;
                    postfix += " ";
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else if (isOperator(x))
            {
                while (!st.empty() && isOperator(st.top().op) && (precedence(x) <= precedence(st.top().op)) && !isRightAssociative(x))
                {
                    postfix += st.top().op;
                    postfix += " ";
                    st.pop();
                }
                st.push(numberStruct(x));
            }
        }
    }
    if(num != -1)
    {
        postfix += to_string(num) + " ";
    }
    while (!st.empty())
    {
        postfix += st.top().op;
        postfix += " ";
        st.pop();
    }
    return postfix;
}

string converter::infixToPrefix()
{
    reverse(expression.begin(), expression.end());

    for (char &x : expression)
    {
        if (x == '(')
        {
            x = ')';
        }
        else if (x == ')')
        {
            x = '(';
        }
    }

    string prefix = infixToPostfix();

    string result = "";
    stack<string> st;
    string token = "";
    for(char c : prefix)
    {
        if(c == ' ')
        {
            if(!token.empty())
            {
                st.push(token);
                token = "";
            }
        }
        else
        {
            token += c;
        }
    }
    if(!token.empty()) st.push(token);

    while(!st.empty())
    {
        result += st.top() + " ";
        st.pop();
    }

    return result;
}

int converter::postfixResult(string expressionPostfix)
{
    stack<numberStruct> st;
    int num = -1;

    for(size_t i = 0; i <= expressionPostfix.size(); i++)
    {
        char y = (i == expressionPostfix.size()) ? ' ' : expressionPostfix[i];

        if(isdigit(y))
        {
            if(num == -1)
            {
                num = y - '0';
            }
            else
            {
                num = num * 10 + (y - '0');
            }
        }
        else if(y == ' ')
        {
            if(num != -1)
            {
                st.push(numberStruct(num));
                num = -1;
            }
        }
        else if(isOperator(y))
        {
            int b = st.top().n;
            st.pop();
            int a = st.top().n;
            st.pop();
            int result = operationEngine(a, b, y);
            st.push(numberStruct(result));
        }
    }
    return st.top().n;
}

int converter::prefixResult(string expressionPrefix)
{
    stack<numberStruct> st;
    stack<string> tokens;
    string token = "";

    for (char c : expressionPrefix)
    {
        if (c == ' ')
        {
            if (!token.empty())
            {
                tokens.push(token);
                token = "";
            }
        }
        else token += c;
    }
    if (!token.empty()) tokens.push(token);

    while (!tokens.empty())
    {
        string t = tokens.top();
        tokens.pop();

        if (isdigit(t[0]))
        {
            st.push(numberStruct(stoi(t)));
        }
        else if (isOperator(t[0]))
        {
            int b = st.top().n; st.pop();
            int a = st.top().n; st.pop();
            int result = operationEngine(a, b, t[0]);
            st.push(numberStruct(result));
        }
    }

    return st.top().n;
}

int main()
{
    string infix;
    cout << "Enter expression : ";
    getline(cin, infix);
    converter converterObj(infix);

    string postfix = converterObj.infixToPostfix();
    string prefix = converterObj.infixToPrefix();

    cout << "Postfix : " << postfix << endl;
    cout << "Prefix : " << prefix << endl;

    cout << "postfix eval : " << converterObj.postfixResult(postfix) << endl;
    cout << "prefix eval : " << converterObj.prefixResult(prefix) << endl;
}
