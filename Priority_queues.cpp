#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> p;
    priority_queue<int, vector<int>, greater<int>> q;
    p.push(1);
    p.push(2);  
    p.push(3);
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;

    q.push(1);
    q.push(2);  
    q.push(3);
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
    q.pop();
    cout << q.top() << endl;
}