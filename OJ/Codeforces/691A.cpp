#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

int main(){_
	int n, cont = 0, x;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		cont+=(x == 0);
	}
	if(n == 1 && cont == 0)
		cout << "YES" << endl;
	
	else if(n == 1 && cont == 1)
		cout << "NO" << endl;
		
	else cout << (cont == 1? "YES":"NO") << endl;
	return 0;
}
