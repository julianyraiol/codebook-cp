#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 100

using namespace std;

struct domino{
	int x, y;
};

domino pecas[MAXN];

int somatorio(int n, int pos){
	int sx,sy;
	sx = sy = 0;
	
	swap(pecas[pos].x, pecas[pos].y);
	
	for(int i = 0; i < n; i++){
		sx+=pecas[i].x;
		sy+=pecas[i].y;
	}	
	
	return ((sx%2 == 0) && (sy%2 == 0));
	
}

int main(){_
	int n, cont = 0;
	int sx,sy;
	sx = sy = 0;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> pecas[i].x >> pecas[i].y;
		sx+=pecas[i].x;
		sy+=pecas[i].y;
	}
	
	if((sx%2 == 0) && (sy%2 == 0))
		cout << "0";
		
	else{
		for(int i = 0; i < n; i++){
			cont+= somatorio(n, i);
			if(cont == 1) break;
		}	
		
		cout << (cont == 0? -1 : cont) << endl;
	}
	return 0;
}
