#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);
#define MAXN 100000

using namespace std;

int num[MAXN], freq[MAXN];

int binarys(int n, int x){
	int meio, inicio = 0, fim = n;
	while(inicio < fim){
	
		meio = (inicio + fim)/2;
		
		if (num[meio] < x) inicio = meio + 1;
		else if (num[meio] > x) fim = meio;
		else{ 
			return meio;
		}
	}
	return -1;
}

int verifica(int meio, int x){
	while(num[meio-1] == x){
		meio = binarys(meio, x);
	}
	return meio;
}

int main(){_
	
	int caso = 0, n, q, x, pos;
	
	while( (cin >> n >> q), (n || q) ){
		for(int i = 0; i < n; i++){
			cin >> num[i];
			freq[num[i]]++;
		}
		sort(num, num+n);
		
		cout << "CASE# " << ++caso << ":" << endl;
		while(q--){
			cin >> x;
			pos = binarys(n, x);
			if(pos == -1)
				cout << x << " not found"<< endl;
			else{ 
				cout << x << " found at " << verifica(pos, x) + 1<< endl;
			}
		}		
	}
	return 0;
}
