#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int pibo[30] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597,2584,4181,6765};
    cout << pibo[n];

    return 0;
}