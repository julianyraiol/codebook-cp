#include <bits/stdc++.h>
#define maxn 10000
using namespace std;

/*Fatoração prima de Fatorial*/

typedef vector<int> vi;

vi primos;
bitset<maxn> ehprimo;

void crivo(int n){

    ehprimo.set();
    ehprimo[0] = ehprimo[1] = 0;
    for(int i = 2; i*i<= n; i++)
        if(ehprimo[i])
            for(int j = i*i; j<= n; j+=i)
                ehprimo[j] = 0;
    for(int i = 2; i <= n; i++)
        if(ehprimo[i])
            primos.push_back(i);
}

vi decomposicao(int n){
    vi exp;
    exp.assign(primos.size(), 0);
    for(int i = 0; primos[i] <= n && i < primos.size(); i++){

        for(int j = primos[i]; j<= n; j*=primos[i]){
            exp[i]+= (n/j);
        }
    }
    return exp;
}

int main(){

    int n;
    vi exp;
    cin >> n;
    crivo(n);

    exp = decomposicao(n);

    cout << "A fatoracao de 5! eh" << endl;
    for(int i = 0; i < primos.size(); i++)
        cout << primos[i] << " ^ " << exp[i] << endl;
    return 0;
}
