#include <bits/stdc++.h>
using namespace std;

int main() {

    int valid=0;
    stack <char> requied;
    string input;
    cin>>input;


    for(int i=0;i<input.size();i++)
    {
        if(input[i]=='(' )
        {
            requied.push(')');
            valid=0;
        }
        else if(input[i]=='{' )
        {
            requied.push('}');
            valid=0;
        }
        else if(input[i]=='[')
        {
            requied.push(']');
            valid=0;
        }
        // multiple condition check:

        else{

            if(requied.empty() && i==input.size()-1 && valid){ // the last element of the stack where the parenthesis is already valid
                valid=0;
                break;
            }

            else if(requied.empty() && valid){ // like the first lement of the stack is not valid
                valid=0;
                break;
            }
            else if(requied.empty() && !valid ) // at any point where stack is empty but not valid 
                {
                    valid=0;
                    break;
                }
            else if(!requied.empty()) // stack is not empty and reverse parenthesis appeared
            {
                char req=requied.top();
                if(input[i]==req)
                {
                    requied.pop();
                    if(requied.empty()) // after popping the element the stack becomes empty 
                    {
                        valid=1;
                    }
                }
                else // where the cases doesnt match ( != ) 
                {
                    valid=0;
                    break;
                }
            }

            
        }
    }
    bool ans= valid==1;
    cout<<ans << endl;
    return 0;
}