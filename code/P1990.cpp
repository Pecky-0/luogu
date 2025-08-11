#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int mod = 1e4;
const int maxn = 1e6 + 10;

int dp[maxn]; //dp[i] 表示第 i 块填满的总组合数量
int dp2[maxn]; //dp2[i] 表示第 i 块前填满的总组合数量, 但是第 i 块多了一块

int main()
{
    int n;
    cin >> n;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    dp2[0] = 0;
    dp2[1] = 0;
    dp2[2] = 2;

    for(int i = 3; i <= n; ++i)
    {
        dp[i] += dp[i - 1]; //竖着的一个
        dp[i] += dp[i - 2]; //横着的两个
        
        dp[i] += dp2[i - 1]; //L型的一个

        dp[i] %= mod;

        dp2[i] += dp[i - 2] * 2;
        dp2[i] += dp2[i - 1]; //L型的一个

        dp2[i] %= mod;
    }

    cout << dp[n] << endl;

    system("pause");

    return 0;
}