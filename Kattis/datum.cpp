//
// https://open.kattis.com/problems/datum
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

string day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int dom[12] = {3, 6, 6, 2, 4, 0, 2, 5, 1, 3, 6, 1};

int main() {
    
    int d, m;
    cin >> d >> m;
    cout << day[(dom[m - 1] + d - 1 + 7) % 7] << '\n';
    

    return 0;
}
