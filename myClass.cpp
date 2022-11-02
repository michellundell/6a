#include <iostream>
#include <string>

using namespace std;

class myClass
{
    string name;
    int age;

public:
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void showInfo()
    {
        cout << "Hi, my name is " << this->name << " and I'm " << this->age << " years old." << endl;
    }
};

int main(int argc, char **argv)
{
    string name;
    int age;
    
    myClass me;

    cout << "What is your name? ";
    getline(cin, name);
    me.setName(name);

    cout << "What is your age? ";
    cin >> age;
    me.setAge(age);

    me.showInfo();

    return 0;
}
