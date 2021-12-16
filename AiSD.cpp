// AiSD.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

bool checker(vector<char> arr, char n)
{
    char tmp = '1';

    if (n == '}')
        tmp = '{';
    else
    {
        if (n == ']')
            tmp = '[';
        else
        {
            if (n == ')')
                tmp = '(';
        }
    }
    if (!arr.empty() && arr.back() == tmp)
    {
        arr.pop_back();
        return true;
    }
    else
        return false;
}

int main()
{
    vector<char> arr;
    string inputStr;
    
    cin >> inputStr;
    for (int i = 0; i < inputStr.length(); i++)
    {  
        if (inputStr[i] == '{' ||
            inputStr[i] == '[' ||
            inputStr[i] == '(')
        {
            arr.push_back(inputStr[i]);
        }
        else
        {
            if (inputStr[i] == '}' ||
                inputStr[i] == ']' ||
                inputStr[i] == ')')
            {
                if (!checker(arr, inputStr[i]))
                {
                    cout << i + 1 << endl;
                    arr.clear();
                    vector<char>().swap(arr);
                    return 0;
                }
                else
                    arr.pop_back();
            }
        }
    }
    if (arr.empty())
        cout << "success" << endl;
    arr.clear();
    vector<char>().swap(arr);
}

