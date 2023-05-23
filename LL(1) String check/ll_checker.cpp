#include <bits/stdc++.h>

using namespace std;
vector<pair<char, int>> terminals;
vector<pair<char, int>> variables;

void parse_inp(string s)
{
    int k = 1;
    map<string, int> mm;
    string temp = "";
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;
    }
}

int main()
{
    fstream file;
    file.open("input.txt");
    string dummy = "";
    file >> dummy;
    dummy.clear();
    int i = 0;
    while (getline(file, dummy))
    {
        if (i == 0)
        {
            parse_inp(dummy);
        }
        i++;
    }

    return 0;
}
