#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

bool check(int len, int n, int k)
{
    int count = 0;
    for(int i = 0; i < n; ++i)
    {
        count += a[i] / len;
    }
    return count >= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int maxLen = 0;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        maxLen = max(maxLen, a[i]);
    }

    int l = 1;
    int r = maxLen;
    while(l + 1 < r)
    {
        int mid = (l + r) / 2;
        if(check(mid, n, k))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if(l == 1 && !check(l, n, k))
    {
        cout << 0 << endl;
    }
    else
    {
        cout << l << endl;
    }

    system("pause");
    return 0;
}