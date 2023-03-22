#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int initial;
vector<vector<int>> table;
vector<string> OUT;
int stringToInteger(string line)
{
    int i = 0;
    int num = 0;
    while (line[i] != 0)
    {
        if (line[0] == '-')
        {
            return -1;
        }
        num *= 10;
        num += (line[i] - '0');
        i++;
    }
    return num;
}

void mooreMachine()
{
    int curr = initial;
    cout << "\nEnter String : ";
    bool f(true);
    getchar();
    string s = "";
    getline(cin, s);
    cout << "\n";
    // getline(cin, s);
    if (s == "")
    {
        f = false;
        cout << "\nEpsilon Input\nNo output string\n"
             << endl;
    }
    std::vector<int> states;
    int size = s.size(), k = 0;
    string output = OUT[curr];
    while (curr != -1 && k < size)
    {
        string t = "";
        t += s[k++];
        int x = stringToInteger(t);
        cout << "Current State : q" << curr << " || Next State : ";
        if (table[curr][x] == -1)
            cout << " φ";
        else
            cout << "q" << table[curr][x];
        cout << " || Input : " << x;
        curr = table[curr][x];
        states.push_back(curr);
        if (curr != -1)
            output += OUT[curr];
        cout << " Output : ";
        if (curr == -1)
            cout << "NULL" << endl;
        else
            cout << OUT[curr] << endl;
    }

    if (f)
    {
        cout << "\nOutput is : " << output << endl;
        cout << "\n\nTransition states";
        cout << "\n";
        for (int i = 0; i < states.size(); i++)
            cout << " -> " << states[i];
        cout << "\n\n";
    }
}

int main()
{
    ifstream MOORE;
    string line;
    MOORE.open("l3_inp.txt");
    int i = 0;
    while (getline(MOORE, line))
    {
        if (i == 0)
            initial = stringToInteger(line);
        else
        {
            vector<int> temp1;
            vector<string> temp2;
            int x = 0;
            int y = 0;
            string num = "";
            while (line[x] != 0)
            {
                if (line[x] == ' ')
                {
                    temp1.push_back(stringToInteger(num));
                    num = "";
                    x++;
                    continue;
                }
                num += line[x++];
            }
            table.push_back(temp1);
            OUT.push_back(num);
        }
        i++;
    }

    MOORE.close();

    while (1)
    {
        cout << "\n-----------------\n";
        cout << "1. Moore Machine\n";
        cout << "2. Exit\n";
        cout << "\nEnter choice : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            mooreMachine();
            break;
        case 2:
            cout << "\n--The End--\n\n";
            return 0;
        default:
            cout << "\nWrong Choice\n";
            break;
        }
    }
}