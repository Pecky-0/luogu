#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<int> number;
vector<int> temp;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    int len = s.length();
    
    while(k > 0)
    {
        int i;
        for(i = 0; i < len - 1; ++i)
        {
            if(s[i] > s[i + 1])
            {
                break;
            }
        }
        s.erase(i, 1);
        k--;
    }

    bool flag = true;
    len = s.length();
    for(int i = 0; i < len; ++i)
    {
        if(s[i] != '0')
        {
            flag = false;
        }
        if(!flag)
        {
            cout << s[i];
        }
    }

    if(flag)
    {
        cout << 0;
    }

    system("pause");
    return 0;
}