#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class myClass 
{
    private:
        char name[25];
        int age;
    public:
        void setName(char *nam) {strncpy(this->name, nam, 25);}
        void setAge(int iAge) {this->age = iAge;}

        void showInfo()
        {
            cout << "Hi my name is " << this->name << " and Im " << this->age << " years old." << endl;
        }

};

int main(int argc,char **argv)
{
        myClass me;
        char name[25];
        int age;

        cout << "What is my name? " << endl;
        cin >> name;
        cout << "What is my age? " << endl;
        cin >> age; 
        
        me.setName(name);
        me.setAge(age);

        me.showInfo();

        return 0;
}
