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