#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 5 * 1e3 + 10;
const int mod = 1e9 + 7;
int data[maxn] = {};

int main()
{
    int n;
    int maxValue = 0;
    int minValue = maxn;
    int answer = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
    {
        int temp;
        scanf("%d", &temp);
        data[temp]++;
        maxValue = max(maxValue, temp);
        minValue = min(minValue, temp);
    }

    // for(int i = minValue; i <= maxValue; ++i)
    // {
    //     if(data[i] == 0)
    //     {
    //         continue;
    //     }
    //     if(data[i] >= 3)
    //     {
    //         int deltaNum = n - data[i];
    //         answer += deltaNum * (data[i] * (data[i] - 1) * (data[i] - 2) / 6) % mod; // 组合数 C(n, 3)
    //         answer %= mod;

    //         if(data[i] >= 4)
    //         {
    //             answer += (data[i] * (data[i] - 1) * (data[i] - 2) * (data[i] - 3) / 24) % mod; // 组合数 C(n, 4)
    //             answer %= mod;
    //         }
    //     }
    //     if(data[i] >= 2)
    //     {
    //         int mulValue = data[i] * (data[i] - 1) / 2;
    //         for(int j = minValue; j <= i / 2; ++j)
    //         {
    //             int k = i - j;
    //             if(data[j] == 0 || data[k] == 0)
    //             {
    //                 continue;
    //             }
    //             if(j == k)
    //             {
    //                 answer += mulValue * (data[j] * (data[j] - 1) / 2) % mod; // 组合数 C(n, 2)
    //                 answer %= mod;
    //                 continue;
    //             }
    //             else
    //             {
    //                 if(data[j] >= 1 && data[k] >= 1)
    //                 {
    //                     answer += mulValue * (data[j] * data[k]) % mod;
    //                     answer %= mod;
    //                 }
    //             }
    //         }
    //     }
    // }

    for(int i = minValue; i <= maxValue; ++i)
    {
        if(data[i] < 2)
        {
            continue;
        }
        int mulValue = data[i] * (data[i] - 1) / 2; // 组合数 C(n, 2)
        for(int j = minValue; j <= i / 2; ++j)
        {
            int k = i - j;
            if(data[j] == 0 || data[k] == 0)
            {
                continue;
            }
            if(j == k)
            {
                answer += mulValue * (data[j] * (data[j] - 1) / 2) % mod; // 组合数 C(n, 2)
                answer %= mod;
                continue;
            }
            else
            {
                if(data[j] >= 1 && data[k] >= 1)
                {
                    answer += mulValue * (data[j] * data[k]) % mod;
                    answer %= mod;
                }
            }
        }
    }

    printf("%d\n", answer);

    system("pause");
    return 0;
}