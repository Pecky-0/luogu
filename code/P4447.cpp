#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

struct node
{
    int len;
    int lastVal;
    bool operator<(const node& other) const
    {
        return len > other.len;
    }
};

std::priority_queue<node> pq;
stack<node> s;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    
    int i = 0;
    while(i < n - 1)
    {
        if(a[i] == a[i + 1])
        {
            i++;
            node tmp = {1, a[i]};
            pq.push(tmp);
        }
        else
        {
            node tmp = {1, a[i]};
            pq.push(tmp);
            break;
        }
    }
    int ans = n;
    for(i = i + 1; i < n; ++i)
    {
        if(a[i] != a[i - 1])
        {
            while(!s.empty())
            {
                pq.push(s.top());
                s.pop();
            }
        }
        bool flag = false;
        while(!pq.empty())
        {
            node tmp = pq.top();
            pq.pop();
            if(tmp.lastVal + 1 == a[i])
            {
                tmp.len++;
                tmp.lastVal = a[i];
                s.push(tmp);
                flag = true;
                break;
            }
            else
            {
                ans = min(ans, tmp.len);
            }
        }
        if(flag == false)
        {
            node tmp = {1, a[i]};
            s.push(tmp);
        }
    }

    while(!s.empty())
    {
        ans = min(ans, s.top().len);
        s.pop();
    }

    while(!pq.empty())
    {
        ans = min(ans, pq.top().len);
        pq.pop();
    }

    cout << ans << endl;

    system("pause");
    return 0;
}