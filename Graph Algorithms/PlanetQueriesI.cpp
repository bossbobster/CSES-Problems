#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int to[200010][40];
int main()
{
    int n, q, num = 2, a, b, pw = 0;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> to[i][0]; to[i][0] --;
    }
    for(int j = 1; j <= log2(10000000000); j ++)
    {
        for(int i = 0; i < n; i ++)
            to[i][j] = to[to[i][j-1]][j-1];
        num *= 2;
    }
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b; a--;
        if(b == 0) { cout << a+1 << "\n"; continue; }
        pw = 0;
        while(b != 0)
        {
            if(b % 2 == 1) a = to[a][pw];
            pw ++;
            b /= 2;
        }
        cout << a+1 << "\n";
    }
}
