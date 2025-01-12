#include<bits/stdc++.h>
using namespace std;
// pascal triangle 
// Brute force

int nCr(int n, int r){
    long long res =  1;

    // calculating the ncr
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c){
    int element = nCr(r-1, c-1);
    return element;
}

int main(){
    int r = 5;
    int c = 3;
    int element = pascalTriangle(r, c);
    cout << "the element at position (r, c) is :" << element << endl;
    return 0;
}
int main(){
  return 0;
}
