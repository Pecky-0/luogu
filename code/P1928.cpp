#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

string update(int num, string s)
{
    string temp = "";
    for(int i = 0; i < num; ++i)
    {
        temp = temp + s;
    }
    return temp;
}

int i = 0;

string solve(int n, string s, int pos)
{
    bool flag = true;
    int len = s.length();
    string answer = "";
    string temp = "";
    int num = 0;
    for(i = pos; i < len; ++i)
    {
        if(s[i] == '[')
        {
            num = (int)(s[i + 1] - '0');
            if('0' <= s[i + 2] && s[i + 2] <= '9')
            {
            	num = num * 10 + (int)(s[i + 2] - '0');
            	i++;
			}
            answer = answer + solve(num, s, i + 2);
            continue;
        }
        if(s[i] == ']')
        {
        	//cout << i << ' ' << n << ' ' << answer << endl;
            return update(n, answer);
        }
        if(s[i] != '[' && s[i] != ']')
        {
        	answer = answer + s[i];
		}
    }
    return update(n, answer);
}

int main()
{
    string s;
    cin >> s;

    string answer = solve(1, s, 0);
    cout << answer << endl;

    system("pause");
    return 0;
}