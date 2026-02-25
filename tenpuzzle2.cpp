#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


//RPN計算
double solve(const vector<char>& expr){
    stack<double> st;

    for(char c : expr){
      switch(c){
      
        case '+': {
          double right = st.top(); st.pop();
          double left = st.top(); st.pop();
          st.push(left + right);
          break;
        }

        case '-' :{
          double right = st.top(); st.pop();
          double left = st.top(); st.pop();
          st.push(left - right);
          break;
        }

        case '*' :{
          double right = st.top(); st.pop();
          double left = st.top(); st.pop();
          st.push(left * right);
          break;
        }

        case '/' :{
          double right = st.top(); st.pop();
          double left = st.top(); st.pop();
          st.push(left / right);
          break;
        }

        default:{
          st.push(c - '0');
          break;
        }
      }
    }
    
  return st.top();
}

//演算子の優先順位
int priority(char op){
  if(op == '+' || op == '-') return 2;
  if(op == '*' || op == '/') return 3;

  return 0;
}

//中置換→後置換
vector<char> replace(const vector<char>& exdr){
  vector<char> rpn_queue;
  stack<char> op_stack;

  for(char c : exdr){

    //数字の場合
    if(isdigit(c)){
      rpn_queue.push_back(c);
    }
    //演算子の場合
    else if(priority(c) > 0){
      //空ではなく且つop_stackの演算子の優先度が入力する演算子より高い場合に(*,/の場合) 
      while(!op_stack.empty() && priority(op_stack.top()) >= priority(c)){
        rpn_queue.push_back(op_stack.top());
        op_stack.pop();
      }
      op_stack.push(c);
    }
  }

  //残りの演算子をrpn_queueに
  while(!op_stack.empty()){
  rpn_queue.push_back(op_stack.top()); 
  op_stack.pop();
  }
  
  return rpn_queue;
}


int main(){

  string input;
  vector<char> num;

 //入力
  cout << "4桁の数字の入力" << endl;
  cin >> input;

  for(int i = 0; i < input.size(); i++){
    num.push_back(input[i]);
  }
  
  char a = num[0];
  char b = num[1];
  char c = num[2];
  char d = num[3];


  vector<char> ops = {'+','-','*','/'};

  for(char op1 : ops){
    for(char op2 : ops){
       for(char op3 : ops){
          //数字の順番は固定
          vector<char> exdr = {a,op1,b,op2,c,op3,d};

          vector<char> rpn = replace(exdr);

          double answer = solve(rpn);

          if(answer == 10){
            for(char t : rpn) cout << t;
            cout << "\n";
            cout << answer << endl;
          }

       }
    }
  }

}

//vector,queue問題