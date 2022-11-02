#include <iostream>
using namespace std;

class myClass {
            char name[25];
            int age;
        public:

            void showInfo()
            {
                cout << "Hi my name is " << this->name << " and Im " << this->age << " old." << endl;
            }

};

int main(int argc,char **argv)
{
        myClass me;

        cout << "What is my name?" << endl;
        cin >> me.name;
        cout << "What is my age?" << endl;
        cin >> me.age;

        me.showInfo();

        return 0;
}
