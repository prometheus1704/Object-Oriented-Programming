#include <iostream>
using namespace std;

class Stud
{
public:
    int roll;
    string name, clas, dob, address, dlno;
    static int cnt=0;
    long int phon;

    void set_data();
    void display();

    int retroll()
    {
        return roll;
    }
    // string retname()
    // {
    //     return name;
    // }
    void getclass()
    {
        cin >> clas;
    }

    void getname()
    {
        cin >> name;
    }

    void getadd()
    {
        cin >> address;
    }

    void getdob()
    {
        cin >> dob;
    }

    void getdlno();
    void getphon();
};

// int Stud ::cnt = 0;

inline void Stud::getdlno()
{
    cin >> dlno;
}

inline void Stud::getphon()
{
    cin >> phon;
}

void Stud ::set_data()
{
    cnt++;
    roll = cnt;
    cout << "Enter the name :" << endl;
    cin >> name;
    cout << "Enter the address :" << endl;
    cin >> address;
    cout << "Enter the date of birth :" << endl;
    cin >> dob;
    cout << "Enter the class :" << endl;
    cin >> clas;
    cout << "Enter the dl number :" << endl;
    cin >> dlno;
    cout << "Enter the phone number :" << endl;
    cin >> phon;
}

void Stud ::display()
{
    cout << "---------------------------------------" << endl;
    cout << "The roll no. of student is     : " << roll << endl;
    cout << "The name of student is         : " << name << endl;
    cout << "The class of student is        : " << clas << endl;
    cout << "The address of student is      : " << address << endl;
    cout << "The date of birth of student is: " << dob << endl;
    cout << "The dial no. of student is     : " << dlno << endl;
    cout << "The phone no. of student is    : " << phon << endl;
    cout << "---------------------------------------" << endl;
}

int main()
{
    int n, i, k;
    cout << "Enter the number of records: ";
    cin >> n;

    Stud s[n];
    for (i = 0; i < n; i++)
    {
        s[i].set_data();
    }

    cout << "\n--------------------Menu--------------------" << endl;

    do
    {
        cout << endl;
        cout << "\n1.display   2.search   3.update  4.delete  5.exit" << endl;

        cout << "\nEnter your choice: " << endl;
        cin >> k;

        switch (k)
        {
        case 1:

            for (i = 0; i < n; i++)
            {
                s[i].display();
            }

            break;

        case 2:
            int flag;
            flag = 0;
            int key, r;
            cout << "Enter the roll you want to search:" << endl;
            cin >> key;

            for (i = 0; i < n; i++)
            {
                r = s[i].retroll();
                if (r == key)
                {
                    cout << "record found" << endl;
                    s[i].display();
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                cout << "record not found";
            }
            break;

        case 3:
            int modify, option, flags;
            cout << "Enter the Roll number of student to updates the details: " << endl;
            cin >> modify;
            flags = 1;
            while (flags == 1)
            {

                for (i = 0; i < n; i++)
                {
                    r = s[i].retroll();
                    if (r == modify)
                    {
                        cout << endl;
                        cout << "\n---------MENU----------" << endl;
                        cout << "1:Change the name " << endl;
                        cout << "2:Change the Address of the student " << endl;
                        cout << "3:Change the Date of Birth" << endl;
                        cout << "4.Change the Class of the student" << endl;
                        cout << "5:Change the Driving license of the student " << endl;
                        cout << "6:Change the Phone number of the student " << endl;
                        cout << "7: Exit" << endl;
                        cout << "ENTER YOUR CHOICE :" << endl;
                        cin >> option;
                        switch (option)
                        {
                        case 1:
                            s[i].getname();
                            s[i].display();
                            break;

                        case 2:
                            s[i].getadd();
                            s[i].display();
                            break;

                        case 3:
                            s[i].getdob();
                            s[i].display();
                            break;

                        case 4:
                            s[i].getclass();
                            s[i].display();
                            break;

                        case 5:
                            s[i].getdlno();
                            s[i].display();
                            break;
                        case 6:
                            s[i].getphon();
                            s[i].display();
                            break;

                        case 7:
                            flags = 0;
                            break;

                        default:
                            cout << "Incorrect choice Please enter the appropiate choice ";
                        }
                    }
                }
            }
            break;

            if (flags == 0)
                break;
        case 4:
            int del;
            cout << "The Roll number of student whose data should be delete: ";
            cin >> del;

            for (i = 0; i < n; i++)
            {
                r = s[i].retroll();
                if (r == del)
                {
                    for (int j = i; j < n - 1; j++)
                    {
                        s[j] = s[j + 1];
                    }
                    n--;
                }
            }
            for (i = 0; i < n; i++)
            {

                s[i].display();
            }

            break;

        case 5:
            cout << "thank you!";
            break;

        default:
            cout << "Wrong choice";
            break;
        }

    } while (k != 5);
    return 0;
}
