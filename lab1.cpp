#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

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

int main()
{
    ifstream DFA;
    string line;
    DFA.open("l1_inp.txt");
    int i = 0;
    int initial;
    vector<int> final;
    set<int> ff;
    vector<vector<int>> table;

    while (getline(DFA, line))
    {
        if (i == 0)
            initial = stringToInt(line);
        else if (i == 1)
        {
            int x = 0;
            string num = "";
            while (line[x] != 0)
            {
                if (line[x] == ' ')
                {
                    final.push_back(stringToInt(num));
                    num = "";
                    x++;
                    continue;
                }
                num += line[x++];
            }
            final.push_back(stringToInt(num));
            ff.insert(stringToInt(num));
        }
        else
        {
            vector<int> temp;
            int x = 0;
            string num = "";
            while (line[x] != 0)
            {
                if (line[x] == ' ')
                {
                    temp.push_back(stringToInt(num));
                    num = "";
                    x++;
                    continue;
                }
                num += line[x++];
            }
            temp.push_back(stringToInt(num));
            table.push_back(temp);
        }
        i++;
    }

    DFA.close();

    //------------PRINTING THE DFA----------
    cout << "\nInitial State : " << initial << "\n";
    cout << "\nFinal States : ";
    for (int i = 0; i < final.size(); i++)
        cout << final[i] << " ";
    cout << "\n\nTransition Table :\n";
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table[i].size(); j++)
        {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    //------------------------

    int curr = initial;
    bool acc = false;
    cout << "\nEnter String : ";
    string s = "";
    getline(cin, s);
    // cin >> s;
    if (s == "" && ff.count(initial))
    {
        cout << "\n|| String Accepted\n\n";
        cout << "Transition State\n\n-> ";
        cout << initial << "\n\n";
        return 0;
    }
    std::vector<int> statess;
    int size = s.size(), k = 0;
    while (curr != -1 && k < size)
    {
        string t = "";
        t += s[k++];
        curr = table[curr][stringToInt(t)];
        statess.push_back(curr);
    }
    for (int i = 0; i < final.size(); i++)
    {
        if (curr == final[i])
        {
            cout << "\nString Accepted\n\n";
            acc = true;
            // return 0;
        }
    }
    if (acc)
    {
        cout << "Transition states";
        cout << "\n";
        for (int i = 0; i < statess.size(); i++)
        {
            cout << " -> " << statess[i];
        }
        cout << "\n\n";
    }
    else
        cout << "\nString Rejected\n\n";
    return 0;
}