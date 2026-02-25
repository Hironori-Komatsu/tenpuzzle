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
vector<char> replace(const vector<char>& expr){
  vector<char> rpn_queue;
  stack<char> op_stack;

  for(char c : expr){

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
  bool validated = false;

 //修正中
 //入力
  while(!validated){
    cout << "4つの数字を入力してください" << endl;
    cin >> input;

    if(input.size() == 4){
        for(int i = 0; i < input.size(); i++){
          if(isdigit(input[i])){
            num.push_back(input[i]);
            validated = true;
          }
          else{
            cout << "文字が入力されています" << endl;
            break;
          }
        }
    }
    else if(input.size() < 4){
      cout << "4つより少なく入力されています" << endl;
    }
    else{
      cout << "4つより多く入力されています" << endl;
    }
  }

  
  
  char a = num[0];
  char b = num[1];
  char c = num[2];
  char d = num[3];


  //64通り
  vector<char> ops = {'+','-','*','/'};

  for(char op1 : ops){
    for(char op2 : ops){
       for(char op3 : ops){
          vector<char> expr = {a,op1,b,op2,c,op3,d};

          vector<char> rpn = replace(expr);

          double answer = solve(rpn);

          if(answer == 10){
            for(char rpn_expr : rpn) 
            cout << rpn_expr;
            cout << "\n";
            cout << answer << endl;
          }

       }
    }
  }

  return 0;
}

