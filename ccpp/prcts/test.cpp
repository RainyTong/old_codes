#include <iostream>
#include <stack>
#include <string>
using namespace std;

/**
 *判断当前字符是否为数字
 */
bool isNumber(char s) {
    string opers = "+-*/()";
    for (int i = 0; i < opers.length(); i++) {
        if (s == opers.at(i)) {
            return false;
        }
    }
    return true;
}

/**
 * 判断当前运算符与栈顶运算符的优先级大小
 */
bool isPriorityLow(char currOper, char topOper) {
    if (currOper == '+' || currOper == '-') {
        if (topOper == '*' || topOper == '/' || topOper == '+' || topOper == '-') {
            return true;
        }
    }

    if (currOper == '*' || currOper == '/') {
        if (topOper == '*' || topOper == '/') {
            return true;
        }
    }

    return false;
}

/**
 * 如果当前运算符优先级小于或等于栈顶运算符, 将栈顶运算符弹出加到后缀表达式尾,
 * 并继续进行比较, 直到当前运算符优先级大于栈顶运算符优先级
 */
void loopPushOperator(string& s, char oper, stack<char>& operators) {
    if (operators.size() > 0 && isPriorityLow(oper, operators.top())) {
        s += operators.top();
        operators.pop();
        loopPushOperator(s, oper, operators);
    }
}

/**
 * 判断运算符是压入运算符栈还是加到后缀表达式尾
 */
void handleOperator(string& s, char oper,  stack<char>& operators) {
    switch (oper) {
    case '+':
    case '-':
    case '*':
    case '/':
        //如果运算符栈为空, 直接将当前运算符压栈
        if (operators.size() <= 0) {
            operators.push(oper);
        //如果当前运算符优先级小于等于栈顶运算符优先级, 将栈顶运算符加到后缀表达式尾
        } else if (isPriorityLow(oper, operators.top())) {
            loopPushOperator(s, oper, operators);
            operators.push(oper);
        ///如果当前运算符优先级大于栈顶运算符优先级, 将当前运算符压栈
        } else {
            operators.push(oper);
        }
        break;
    case '(':
        operators.push(oper);  //当前运算符为'('直接压栈
        break;
    case ')':
        //将栈中元素弹出加到后缀表达式尾,直到遇到运算符"("
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

/**
 * 中缀表达式转后缀表达式
 */
string infixToSuffix(string& s) {
    stack<char> operators;     //运算符栈
    string suffix;                        //后缀表达式

    for (int i = 0; i < s.length(); i++) {
        if (isNumber(s.at(i))) {   //如果是数字直接加到后缀表达式尾
            suffix += s.at(i);
        } else {
            handleOperator(suffix, s.at(i), operators);  //处理运算符
        }
    }

    if (suffix.length() > 0) {
        while (operators.size() > 0) {  //将运算符栈中留有的运算符全部出栈加到后缀表达式尾
            suffix += operators.top();
            operators.pop();
        }
        return suffix;
    } else {
        return "";
    }
}

/**
 * 根据运算符,计算栈顶两个数的值,并将计算的值压栈
 */
void CalculateResult( char oper, stack<int>& tmpStack) {
    if (tmpStack.size() < 2) {
        return;
    }
    //栈是先进后出,所以先弹出的是第二个值
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
    default:
        break;
    }

    tmpStack.push(result);
}

/**
 * 通过后缀表达式计算结果
 * 将后缀表达式依次入栈, 如果为操作符, 弹出栈中两个元素计算结果再压入栈中
 */
float getResultUseSuffix(string& s) {
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
    string infix;
    //输入的字符串不能有空格
    cin>>infix;
    string suffix = infixToSuffix(infix);
    float result = getResultUseSuffix(suffix);
    cout<<"计算结果为: "<<result<<endl;
    return 0;
}
