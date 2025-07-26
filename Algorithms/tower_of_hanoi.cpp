#include <bits/stdc++.h>
using namespace std;

void hanoi_stack(int n, char beg, char aux, char end) {
    stack<pair<int, vector<char>>> st;
    st.push({n, {beg, aux, end}});

    while (!st.empty()) {
        int n = st.top().first;
        char beg = st.top().second[0];
        char aux = st.top().second[1];
        char end = st.top().second[2];
        st.pop();
        if (n == 1) {
            cout << beg << " -> " << end << endl;
        } else {
            st.push({n-1, {aux, beg, end}});
            st.push({1, {beg, aux, end}});
            st.push({n-1, {beg, end, aux}});
        }
    }
}

int main() {
    cout << "=== Tower of Hanoi Problem ===" << endl;
    cout << "Enter number of disks: ";
    int n;
    cin >> n;
    
    cout << "Enter source rod (A, B, or C): ";
    char source;
    cin >> source;
    
    cout << "Enter auxiliary rod (A, B, or C): ";
    char auxiliary;
    cin >> auxiliary;
    
    cout << "Enter destination rod (A, B, or C): ";
    char destination;
    cin >> destination;
    
    cout << "\nSolution steps to move " << n << " disks from " << source 
         << " to " << destination << " using " << auxiliary << ":" << endl;
    cout << "------------------------------------------------------" << endl;
    
    hanoi_stack(n, source, auxiliary, destination);
    
    cout << "\nTotal moves required: " << (1 << n) - 1 << endl; // 2^n - 1
    
    return 0;
}