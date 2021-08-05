#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <valarray>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int to[200010][35];
int main()
{
    input();
    int n, q, num = 2, a, b, pw = 0;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
        cin >> to[i][0], to[i][0] --;
    for(int j = 1; j <= 31; j ++)
    {
        for(int i = 0; i < n; i ++)
            to[i][j] = to[to[i][j-1]][j-1];
        num *= 2;
    }
    while(q--)
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
