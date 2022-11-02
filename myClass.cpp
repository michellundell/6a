#include <iostream>
#include <string>

using namespace std;

class myClass
{
    string name;
    int age;

public:
    void getInfo()
    {
        cout << "What is your name? ";
        getline(cin, this->name);
        cout << "What is your age? ";
        cin >> this->age;
    }
    
    void showInfo()
    {
        cout << "Hi, my name is " << this->name << " and I'm " << this->age << " years old." << endl;
    }
};

int main(int argc, char **argv)
{
    myClass me;

    me.getInfo();

    me.showInfo();

    return 0;
}
