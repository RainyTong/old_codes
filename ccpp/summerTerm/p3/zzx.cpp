#include <iostream>
using namespace std;

class ObjectType {
private:
string _name;
public:
ObjectType(string name){
_name = name;
cout << "Creating object " << _name << endl;
}
ObjectType() {
_name = "unnamed";
cout << "Creating object " << _name << endl;
}
~ObjectType() {
cout << "Destroying object " << _name << endl;
}
};

int main() {
ObjectType o1;
ObjectType* o2p = new ObjectType("o2");
cout << "in main()" << endl;
o2p->~ObjectType();
return 0;
}
