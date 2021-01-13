// 10845 큐

#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
  int N, x;
  string str;
  queue<int> s;

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
        cout << s.front() << endl;
        s.pop();
      }
    }
    else if(str == "size"){
      cout << s.size() << endl;
    }
    else if(str == "empty"){
      cout << s.empty() << endl;
    }
    else if(str == "front"){
      if(s.empty()){
        cout << -1 << endl;
      }
      else{
        cout << s.front() << endl;
      }
    }
    else if(str == "back"){
      if(s.empty()){
        cout << -1 << endl;
      }
      else{
        cout << s.back() << endl;
      }
    }
  }
}

