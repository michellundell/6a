#include <iostream>
using namespace std;

class myClass {
	    string name;
            int age;
        public:

            void setInfo(string name, int age)
	    {
	        this->name = name;
		this->age = age;
	    }

            void showInfo()
            {
                cout << "Hi my name is " << this->name << " and Im " << this->age << " years old." << endl;
            }

};

int main(int argc,char **argv)
{
        myClass me;
	string name;
	int age;
        cout << "What is my name?" << endl;
        cin >> name;
        cout << "What is my age?" << endl;
        cin >> age;

	me.setInfo(name, age);

        me.showInfo();

        return 0;
}
