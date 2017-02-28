#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

int main(){_
	int n, x, cont = 0;
	int maior, menor;
	vector<int> force;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> x;
		force.push_back(x);	
	}
	
	sort(force.begin(), force.end());
	
	menor = force[0];
	maior = force[n-1];
	
	for(int i = 1; i < n-1; i++){
		if( (force[i] > menor)  && (force[i] < maior))
			cont++;
	}
	
	cout << cont << endl;
	return 0;
}
