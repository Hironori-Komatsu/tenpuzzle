#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

//計算
double calc(double left, double right, char op){
  if(op == '+'){
    return left + right;
  }
  if(op == '-'){
    return left -right;
  }
  if(op == '*'){
    return left * right;
  }
  if(op == '/'){
    return left / right;
  }

  return 0;
}

//演算子の優先順位
int getPriority(char op){
  if(op == '+' || op == '-'){
    return 2;
  }  
  if(op == '*' || op == '/'){
    return 3;
  }  

  return 0;
}

//式の評価
double evaluateExpression(const std::vector<char>& expr){
  std::stack<double> num_stack;
  std::stack<char> op_stack;

    for(char c : expr){
        //数字の場合
        if(isdigit(c)){
          num_stack.push(c - '0');
        }//演算子の場合
        else if(getPriority(c) > 0){
          //空ではなく且つop_stackの演算子の優先度が入力する演算子より高い場合に(*,/の場合) 
          while(!op_stack.empty() && getPriority(op_stack.top()) >= getPriority(c)){
              double right = num_stack.top();
              num_stack.pop();

              double left = num_stack.top();
              num_stack.pop();

              char op = op_stack.top();
              op_stack.pop();

              num_stack.push(calc(left,right,op));
          }

          op_stack.push(c);
        }
    }//残りの演算子
    while(!op_stack.empty()){
        double right = num_stack.top();
        num_stack.pop();

        double left = num_stack.top();
        num_stack.pop();

        char op = op_stack.top();
        op_stack.pop();

        num_stack.push(calc(left,right,op));
    }

  return num_stack.top();
}

//修正中(全角の場合について)
//入力評価
bool evaluateInput(std::string input,std::vector<char>& num){
    
   if(input.size() < 4){
      std::cout << "4つより少なく入力されています\n4つの数字を入力してください" << std::endl;
      return false;
    }

    if(input.size() > 4){
      std::cout << "4つより多く入力されています\n4つの数字を入力してください" << std::endl;
      return false;
    }

    for(char c : input){
      if(!isdigit(c)){
        std::cout << "文字が入力されています\n4つの数字を入力してください" << std::endl; 
        return false;
      }
    }

    for(char c : input){
      num.push_back(c);
    }

    return true;
}
 



int main(){

  std::string input;
  std::vector<char> num;
  bool validated = false;

 //入力
  std::cout << "4つの数字を入力してください" << std::endl;
  while(!validated){

    std::cin >> input;
    validated = evaluateInput(input,num);

  }

  //64通り
  std::vector<char> arith_ops = {'+','-','*','/'};

      for(char op1 : arith_ops){
        for(char op2 : arith_ops){
          for(char op3 : arith_ops){
              
              char ops[] = {op1,op2,op3};

              for(int j = 0; j < sizeof(ops); j++){
                char op = ops[j];
              }

              std::vector<char> expr = {num[0],op1,num[1],op2,num[2],op3,num[3]};
              double answer = evaluateExpression(expr);
              double roundAnswer = round(answer * 100) / 100;

              if(roundAnswer == 10){
                for(char c : expr){
                  std::cout << c;
                }
                std::cout << "\n"; 
                std::cout << roundAnswer << std::endl;
              }
          }
        }
      }

  return 0;
}

