#include <bits/stdc++.h>
using namespace std;

int main() {

    int valid=0;
    stack <char> requied;
    string input;
    cin>>input;

    int maxim=0,count=0;

    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='(' )
        {
            requied.push(')');
        }
        else if(input[i]=='{' )
        {
            requied.push('}');
        }
        else if(input[i]=='[')
        {
            requied.push(']');
        }
        // tobe done
    }
    return 0;
}