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

// Better approach
vector<int> majorityElement(vector<int> v){
    int n = v.size();
    vector<int> ls; // list fo answers

    // declaring the map
    map<int, int> mpp;

    // least occurrence of majority element
    int min = int(n / 3) + 1;
    for(int i = 0; i < n; i++){
        mpp[v[i]]++;

    // checking if v[i] di the majority element
    if(mpp[v[i]] == mini){
        ls.push_back(v[i]);
    }
    if(ls.size() == 2) break;
    }
    return ls;
}
int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
//Time Complexity: O(N*logN)

// Optimal approach
vector<int> majorityElement(vector<int> v){
    int n = v.size();

    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;

    // applying the extended boyer moores voting algorithm
    for(int i = 0; i < n; i++){
        if(cnt1 == 0 && el2 != v[i]){
            cnt = 1;
            el1 = v[i];
        }
        else if(cnt2 == 0 && el1 != v[i]){
            cnt2 = 1;
            el2 = v[i];
        }
        else if(v[i] == el1) cnt1++;
        else if(v[i] == el2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }
    vector<int> ls;

    // manually check if the stored elements in el1 and el2 are the majority elements
    cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == el1) cnt1++;
        if(v[i] == el2) cnt2++;
    }
    
    int mini = int(n / 3) + 1;
    if(cnt1 >= mini) ls.push_back(el1);
    if(cnt2 >= mini) ls.push_back(el2);

    return ls;
}

//Time Complexity: O(N) + O(N)

int main(){
  return 0;
}
