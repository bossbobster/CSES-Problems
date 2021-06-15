#include <iostream>
#include <string.h>
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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

int arr[8][8] = {{6, 19, 58, 37, 4, 17, 60, 47}, {57, 38, 5, 18, 59, 48, 15, 62}, {20, 7, 36, 3, 16, 61, 46, 49}, {39, 56, 29, 32, 35, 2, 63, 14}, {8, 21, 34, 1, 30, 27, 50, 45}, {55, 40, 31, 28, 33, 64, 13, 26}, {22, 9, 42, 53, 24, 11, 44, 51}, {41, 54, 23, 10, 43, 52, 25, 12}};
int main()
{
    input();
    int r, c;
    cin >> c >> r; r--; c--;
    int dif = arr[r][c]-1;
    for(int i = 0; i < 8; i ++)
        for(int j = 0; j < 8; j ++)
        {
            arr[i][j] -= dif;
            if(arr[i][j] < 1)
                arr[i][j] = 64 + arr[i][j];
            cout << arr[i][j] << ((j==7)?"\n":" ");
        }
}
