// 2504 괄호의 값

#include<iostream>
#include<stack>
#include<string>
using namespace std;

class node{
public:
  bool isValue;
  char command;
  int value;
  
  node(int value){
    this->isValue = true;
    this->value = value;
  }
  node(char command){
    this->isValue = false;
    this->command = command;
  }
};

string str;
stack<node> s;

void solution(){
  for(int i=0;i<str.length();i++){
    int sum =0;
    bool isInvalid = true;
    
    if(str[i] == '(' || str[i] == '['){
      s.push(node(str[i]));
    }
    else if(str[i] == ')'){
      while(!s.empty()){
        node element = s.top();
        s.pop();
        
        if(element.isValue){
          sum += element.value;
        }
        else if(element.command == '('){
          if(sum == 0){
            s.push(node(2));
          }
          else{
            s.push(node(2*sum));
          }
          isInvalid = false;
          break;
        }
        else{
          isInvalid = true;
          break;
        }
      }
      if(isInvalid){
        cout << 0 << "\n";
        return;
      }
    }
    else if(str[i] == ']'){
      while(!s.empty()){
        node element = s.top();
        s.pop();
        
        if(element.isValue){
          sum += element.value;
        }
        else if(element.command == '['){
          if(sum == 0){
            s.push(node(3));
          }
          else{
            s.push(node(3*sum));
          }
          isInvalid = false;
          break;
        }
        else{
          isInvalid = true;
          break;
        }
      }
      if(isInvalid){
        cout << 0 << "\n";
        return;
      }
    }
  }
  
  int sum = 0;
  while(!s.empty()){
    node element = s.top();
    s.pop();
    
    if(!element.isValue){
      cout << 0 << "\n";
      return;
    }
    else{
      sum += element.value;
    }
  }
  
  cout << sum << endl;
}

int main(){
  cin >> str;
  solution();
}
