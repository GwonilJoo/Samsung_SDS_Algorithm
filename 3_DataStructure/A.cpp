// 10828 스택

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
  int N, x;
  string str;
  stack<int> s;

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> str;
    if(str == "push"){
      cin >> x;
      s.push(x);
    }
    else if(str == "pop"){
      if(s.empty()){
        cout << -1 << endl;
      }
      else{
        cout << s.top() << endl;
        s.pop();
      }
    }
    else if(str == "size"){
      cout << s.size() << endl;
    }
    else if(str == "empty"){
      cout << s.empty() << endl;
    }
    else if(str == "top"){
      if(s.empty()){
        cout << -1 << endl;
      }
      else{
        cout << s.top() << endl;
      }
    }
  }
}

