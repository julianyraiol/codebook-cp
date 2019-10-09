#include <bits/stdc++.h>

using namespace std;

int main(){
		double meal, tip, tax, total;

		cin >> meal >> tip >> tax;
		total = meal + (meal*tip)/100 + (meal*tax)/100;
		cout << nearbyint(total) << endl;

		return 0;
}
