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

// Given the row number n.Print the n-th row of pascal's triangle
int nCr(int n, int r){
    long long res = 1;

    // calculating the ncr
    for(int i = 0; i < r; i++){
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n){
    // printing the entire row n:
    for(int c = 1; c <= n; c++){
        cout << nCr(n-1, c-1) << " ";
    }
    cout << "n";
}

//Time Complexity: O(n*r
int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}

// Optimal approach
int nCr(int n, int r){
    long long res = 1;

    // calculating the ncr
    for(int i =0; i < r; i++){
        res = res * (n -1);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;

    // store the entire pascal's triangle
    for(int row = 1; row <= n; row++){
        vector<int> tempList; // temporary list
        for(int col = 1; col <= row; col++){
            tempList.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempList);
    }
    return ans;
}

int main(){

    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for(auto it : ans){
        for(auto ele : it){
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}

// Optimal approach 2
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    // calculate the rest of the element
    for(int col = 1; col < row; col++){
        ans = ans * (row - col) / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;

    // store the entire pascal triangle 
    for(int row = 1; row <= n; row++){
        ans.push_back(generateRow(row));
    }
    return ans;
}

int main(){

    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for(auto it : ans){
        for(auto ele : it){
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}

// Majority element of N/3 times 
// Brute force
vector<int> majorityElement(vector<int> v){
    int n = v.size();
    vector<int> ls;

    for(int i = 0; i < n; i++){
        // selected element is v[i]
        // checking if v[i] is not already a part of the answer;
        if(ls.size() == 0 || ls[0] != v[i]){
            int count =0;
            for(int j = 0; j < n; j++){
                // counting the frequency of v[i]
                if(v[j] == v[i]){
                    count++;
                }
            }
            // check if the frequency if greater than  n/3
            if(count > (n/3)) ls.push_back(v[i]);
        }
        if(ls.size() == 2) break;
    }
    return ls;
}

int main(){
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "the majority element are :";
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
int main(){
  return 0;
}
