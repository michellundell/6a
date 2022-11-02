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
            void getInfo()
            {
                cout << "What is my name?" << endl;
                cin >> name;
                cout << "What is my age?" << endl;
                cin >> age;
            }

};

int main(int argc,char **argv)
{
        myClass me;

        me.getInfo();

        me.showInfo();

        return 0;
}
