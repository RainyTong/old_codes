#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

bool isNumber(char s) {
    string opers = "+-*/()^";
    for (int i = 0; i < opers.length(); i++) {
        if (s == opers.at(i)) {
            return false;
        }
    }
    return true;
}


bool isPriorityLow(char currOper, char topOper) {
    if (currOper == '+' || currOper == '-') {
        if (topOper == '*' || topOper == '/' || topOper == '+' || topOper == '-') {
            return true;
        }
    }

    if (currOper == '*' || currOper == '/') {
        if (topOper == '^' || topOper == '*' || topOper == '/') {
            return true;
        }
    }

    if(currOper == '^') {
      return true;
    }

    return false;
}

void loopPushOperator(string& s, char oper, stack<char>& operators) {
    if (operators.size() > 0 && isPriorityLow(oper, operators.top())) {
        s += operators.top();
        operators.pop();
        loopPushOperator(s, oper, operators);
    }
}


void handleOperator(string& s, char oper,  stack<char>& operators) {
    switch (oper) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        if (operators.size() <= 0) {
            operators.push(oper);
        } else if (isPriorityLow(oper, operators.top())) {
            loopPushOperator(s, oper, operators);
            operators.push(oper);
        } else {
            operators.push(oper);
        }
        break;
    case '(':
        operators.push(oper);  //当前运算符为'('直接压栈
        break;
    case ')':
        while (operators.top() != '(') {
            s += operators.top();
            operators.pop();
        }
        operators.pop();
        break;
    default:
        break;
    }
}


string infixToSuffix(string& s) {
    stack<char> operators;
    string suffix;

    for (int i = 0; i < s.length(); i++) {
        if (isNumber(s.at(i))) {
            suffix += s.at(i);
        } else {
            handleOperator(suffix, s.at(i), operators);
        }
    }

    if (suffix.length() > 0) {
        while (operators.size() > 0) {
            suffix += operators.top();
            operators.pop();
        }
        return suffix;
    } else {
        return "";
    }
}

void CalculateResult( char oper, stack<int>& tmpStack) {
    if (tmpStack.size() < 2) {
        return;
    }

    int secondVal = tmpStack.top();
    tmpStack.pop();
    int firstVal = tmpStack.top();
    tmpStack.pop();

    int result = 0;
    switch (oper) {
    case '+':
        result = firstVal + secondVal;
        break;
    case '-':
        result = firstVal - secondVal;
        break;
    case '*':
        result = firstVal * secondVal;
        break;
    case '/':
        result = firstVal / secondVal;
        break;
    case '^':
        result = pow(firstVal,secondVal);
    default:
        break;
    }

    tmpStack.push(result);
}


int getResultUseSuffix(string& s) {
    if (s.length() <= 0) {
        return 0;
    }

    stack<int> tmpStack;
    for (int i = 0; i < s.length(); i++) {
        if (isNumber(s.at(i))) {
            tmpStack.push(s.at(i) - '0');
        } else {
            CalculateResult(s.at(i), tmpStack);
        }
    }
    return tmpStack.top();
}


int main() {
  int t = 0;
  cin>>t;


  for(int num = 0;num < t;num++){

  string infix;
  cin>>infix;
  string postfix = infixToSuffix(infix);
  int result = getResultUseSuffix(postfix);
  cout<<result<<endl;

}
  return 0;

}
