#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1e5 + 10;
int pos[maxn];

bool check(int minLen, int n, int k)
{
    if(minLen == 0) 
    {
        return false;
    }
    int count = 0;
    for(int i = 0; i < n - 1; ++i)
    {
        if(pos[i + 1] - pos[i] > minLen)
        {
            // cout << "pos[i + 1]" << pos[i + 1] << ", pos[i]: " << pos[i] << ", minLen: " << minLen << endl;
            // cout << "count" << count << endl;
            count += (pos[i + 1] - pos[i] - 1) / minLen;
        }
    }
    return count <= k;
}

int main()
{
    int len, n, k;
    cin >> len >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> pos[i];
    }

    int l = 0;
    int r = len + 1;
    while(l + 1 < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid, n, k))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }

    cout << l + 1 << endl;

    system("pause");
    return 0;
}