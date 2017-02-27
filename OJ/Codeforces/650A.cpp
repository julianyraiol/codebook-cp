#include <bits/stdc++.h>
#define MAXN 200001
#define _ ios_base::sync_with_stdio(false);

using namespace std;

typedef long long int ll;

struct coord{
	int x, y;
};

coord num[MAXN];

ll daniel(int x1, int y1, int x2, int y2){
	ll x = x1 - x2;
	ll y = y1 - y2;
	ll resp = sqrt(x*x + y*y);	
	
	return resp;
}

ll doctor(int x1, int y1, int x2, int y2){
	ll resp = abs(x1 - x2) + abs(y1 - y2);
	return resp;	
}

bool cmp(coord a, coord b){
	if (a.x == b.x) return(a.y < b.y);
	else return (a.x < b.x);
}

int binarys(int n, int i){
	int meio, inicio = i, fim = n;
	int x, y;
	
	while(inicio < fim-1 ){
		meio = (inicio + fim)/2;
		
		x = daniel(num[i].x, num[i].y, num[meio].x, num[meio].y);
		y = doctor(num[i].x, num[i].y, num[meio].x, num[meio].y);
		
		if(x < y)
			inicio = meio + 1;
		else if(x > y)
			fim = meio;
		else{
			cout << i << " " << meio << endl;
			return 1;
		}
	}
	return 0;
}

int main(){_
	int n, cont = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i].x >> num[i].y;
	}
	
	sort(num, num + n, cmp);
	
	for(int i = 0; i < n; i++){
		cont+= binarys(n, i);
	}
	
	cout << cont << endl;
	return 0;
}
