#include <bits/stdc++.h>
using namespace std;

int main() {
    string path;
    cin>>path;
    stack <string> filepath;

    string name="";
    for(int i=1;i<=path.size()-1;i++)
    {   
        if (path[i]=='/')
        {
            if(name.size())
            {   
                if(name==".")
                {   
                    name="";
                    continue;
                } 
                else if(name=="..")
                {   
                    if(!filepath.empty())
                        filepath.pop();
                    name="";
                    continue;
                }                 

                filepath.push(name);
                name="";
            }
        }
        else{
            name+=path[i];
        }
        
    }
    if(name.size())
    {   
        if(name==".")
        {   
        } 
        else if(name=="..")
        {   
            if(!filepath.empty())
                filepath.pop();
        } 
        else{
            filepath.push(name);
            name="";
        }                

    }
    
    string newpath="";
    while(!filepath.empty())
    {
        newpath=filepath.top()+"/"+newpath;
        filepath.pop();
    }
    newpath="/"+newpath;
    if(newpath.size()>1)
        newpath.pop_back();
    
    cout<<newpath<<endl;
    return 0;
}