#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);
#define MAXN 50001

using namespace std;

typedef  vector<int> vi;

vi primos;

bitset<MAXN> ehprimo;

void crivo(int n){
	
	ehprimo.set();
	
	ehprimo[0] = ehprimo[1] = 0;
	for(int i = 2; i*i <= n; i++)
		if(ehprimo[i])
			for(int j = i*i; j <= n; j+=i)
				ehprimo[j] = 0;
	
	primos.push_back(2);
	for(int i = 3; i <= n; i++)
		if(ehprimo[i])
			primos.push_back(i);
}

int main(){_
	crivo(MAXN);
	cout << primos.size() << endl;
	/*cout << "primos[] = {" << endl;
	for(int i = 0; i < primos.size(); i++)
		cout << primos[i] << ",";
	cout << "}" << endl;*/
	return 0;
}
