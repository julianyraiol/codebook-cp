#include <bits/stdc++.h>

using namespace std;

int main(){
		int n;

		cin >> n;

    if ((n&1) || (n >= 6 && n <= 20))
        cout << "Weird";
    else
        cout << "Not Weird";
		return 0;
}
