#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
 
vector<long long> lim = {0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 8888888889, 98888888889, 1088888888889, 11888888888889, 128888888888889, 1388888888888889, 14888888888888889, 158888888888888889, 1688888888888888889};
long long p[20];
int main()
{
    int q;
    long long n;
    string num;
    long long cnt = 1;
    cin >> q;
    p[0] = 1;
    for(int i = 1; i <= 18; i ++)
        p[i] = p[i - 1] * 10;
    for(int i = 0; i < q; i ++)
    {
        cin >> n;
        cnt = 0;
        for(int j = 0; j < (int)lim.size(); j ++)
            if(n > lim[j]) cnt ++;
        n -= (lim[cnt - 1] + 1);
        num = to_string((long long)(n / cnt + p[cnt - 1]));
        cout << num[n % cnt] << "\n";
    }
}
