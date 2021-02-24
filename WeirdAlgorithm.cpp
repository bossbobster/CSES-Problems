#include <iostream>
using namespace std;
 
int main()
{
    long long n;
    cin >> n;
    if(n != 1) cout << n << " ";
    else cout << n << endl;
    while(n != 1)
    {
        if(n % 2 == 0) n = n / 2;
        else n = n * 3 + 1;
        if(n == 1) cout << n << " ";
        else cout << n << endl;
    }
}
