#include <iostream>
using namespace std;
class Number {
private:
    int value;
public:
    Number(int val=0):value(val){}
    Number& operator--(){
        value*=4;
        return *this;
    }
    Number operator--(int){
        Number temp=*this;
        value/=4;
        return temp;
    }
    int getValue() const{return value;}
};
int main(){
    int input;
    cout<<"Enter a number: ";
    cin>>input;
    Number num1(input);
    --num1;
    cout<<"Prefix -- on "<<input<<": "<<num1.getValue()<<endl;
    Number num2(input);
    num2--;
    cout<<"Postfix -- on "<<input<<": "<<num2.getValue()<<endl;
    return 0;
}