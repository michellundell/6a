#include <iostream>
#include <cstring>
using namespace std;

class myClass {
            char name[25];
            int age;
        public:

            void setName(char name[25])
            {
                strncpy(this->name, name, 25);
            }

            void setAge(int age)
            {
                this->age = age;
            }

            void showInfo()
            {
                cout << "Hi my name is " << this->name << " and Im " << this->age << " old." << endl;
            }

};

int main(int argc,char **argv)
{
        myClass me;
        char name[25];
        int age;

        cout << "What is my name?" << endl;
        cin >> name;
        me.setName(name);
        cout << "What is my age?" << endl;
        cin >> age;
        me.setAge(age);

        me.showInfo();

        return 0;
}
