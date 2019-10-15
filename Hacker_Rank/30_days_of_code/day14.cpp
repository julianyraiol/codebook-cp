#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
  	int maximumDifference;

    Difference(vector<int> elements){
        this->elements = elements;
    }

	int computeDifference(){
        int size = this->elements.size();
        sort(this->elements.begin(), this->elements.end()); //N*log2(N)
        maximumDifference = abs(this->elements[0] - this->elements[size-1]); 
        return maximumDifference;
    }

}; 