#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int>prices={8,4,6,2,3};
    vector<int>result=prices;

    stack<int> stack;
    int i=0,j=1;
    while((i<j) && ( i < prices.size()) && ( j < prices.size()) ){
        
        if(prices[i]>prices[j])
        {
            stack.push(prices[i]-prices[j]);
            i++;
            j=i+1;
            continue;
        }
        else{
            j++;
            continue;
        }

    }
    while(i<prices.size())
    {
        stack.push(result[i]);
        i++;
    }
    for (int i = 0; i < prices.size(); i++)
    {
        cout<<stack.top()<<endl;
        stack.pop();
    }
    

    return 0;
}