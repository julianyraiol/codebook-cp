#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);

using namespace std;

int main(){_
	int n, cont, x, questoes = 0;
	cin >> n;
	
	while(n--){
		cont = 0;
		for(int i = 0; i < 3; i++){
			cin >> x;
			cont+= (x == 1);
		}
		
		if(cont > 1)
			questoes++;
	}
	
	cout << questoes << endl;
	return 0;
}
