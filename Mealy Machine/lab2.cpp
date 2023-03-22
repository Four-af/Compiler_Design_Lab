#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int initial;
vector<vector<int>> table;
vector<vector<string>> OUT;

int stringToInt(string line)
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

void mealyMachine()
{
    int curr = initial;
    getchar();
    cout << "\nEnter String : ";
    bool f(true);
    string s = "";
    // cin>>s;
    getline(cin, s);
    if (s == "")
    {
        f = false;
        cout << "\nEpsilon Input\nNo output string\n"
             << endl;
    }
    std::vector<int> states;
    int size = s.size(), k = 0;
    string output = "";
    while (curr != -1 && k < size)
    {
        string t = "";
        t += s[k++];
        if (OUT[curr][stringToInt(t)] != "-1")
        {
            output += OUT[curr][stringToInt(t)];
        }
        curr = table[curr][stringToInt(t)];
        states.push_back(curr);
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
    ifstream MEALY;
    string line;
    MEALY.open("inp2m.txt");
    int i = 0;

    while (getline(MEALY, line))
    {
        if (i == 0)
        {
            initial = stringToInt(line);
        }
        else
        {
            vector<int> temp1;
            vector<string> temp2;
            int x = 0;
            int y = 0;
            string num = "";
            string outNum = "";
            while (line[x] != 0)
            {
                if (line[x] == ' ')
                {
                    if (y % 2 == 0)
                    {
                        temp1.push_back(stringToInt(num));
                        num = "";
                    }
                    else
                    {
                        temp2.push_back(outNum);
                        outNum = "";
                    }
                    x++;
                    y++;
                    continue;
                }
                if (y % 2 == 0)
                {
                    num += line[x++];
                }
                else
                {
                    outNum += line[x++];
                }
            }
            temp2.push_back(outNum);
            table.push_back(temp1);
            OUT.push_back(temp2);
        }
        i++;
    }

    MEALY.close();
    while (1)
    {
        cout << "\n-----------------\n";
        cout << "1. Mealy Machine\n";
        cout << "2. Exit\n";
        cout << "\nEnter choice : ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            mealyMachine();
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