#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int kth_largest(vector<int> values, int k){

    priority_queue<int> q;
    for (size_t i=0; i<values.size(); i++){
        q.push(values.at(i));
    }

    int result = INT_MIN;
    for (int i=1; i<=k; i++){
        if (i==k){
            result = q.top();
            q.pop();
        }
        q.pop();
    }

    return result;
}

int main(){

    int array[] = {5,10,6,9,2,0,1,7,3};
    vector<int> v;
    for (int i=0; i < sizeof(array)/sizeof(int); i++){
        v.push_back(array[i]);
    }
    
    int res = kth_largest(v, 4);
    cout << "k'th largest: "<<res<<endl;

    return 0;
}