#include <iostream>
using namespace std;

class Test{
private:
    int val;
public:
    Test(int val) : val(val) {}

    friend void display(Test& obj);
};

void display(Test& obj){
    cout << "Value: " << obj.val << endl;
}

int main(){
    Test t1(5);
    display(t1);
}
