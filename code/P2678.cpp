#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 5 * 1e4 + 10;
int stone[maxn];

bool check(int minLen, int n, int m)
{
    int count = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        int j;
        bool flag = false;
        for(j = i + 1; j < n; ++j)
        {
            if(stone[j] - stone[i] >= minLen)
            {
                flag = true;
                break;
            }
        }
        if(flag == false) // j循环自行结束
        {
            return false;
        }
        count += (j - i - 1);

        //cout << "i: " << i << ", j: " << j << ", count: " << count << endl;
        i = j - 1; // 更新i到j的位置

        if(count > m)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int len, n, m;
    cin >> len >> n >> m;
    stone[0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        cin >> stone[i];
    }
    stone[n + 1] = len;
    stone[n + 2] = 0x3f3f3f3f;
    
    int l = 1;
    int r = len + 1;
    while(l + 1 < r)
    {
        int mid = (l + r) >> 1;
        //cout << "l: " << l << ", r: " << r << ", mid: " << mid << endl;
        bool checkResult = check(mid, n + 3, m);
        //cout << "checkResult: " << checkResult << endl;
        if(checkResult)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }

    cout << l << endl;

    system("pause");
    return 0;
}