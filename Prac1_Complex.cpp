#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }
    friend ostream &operator<<(ostream &out, const Complex &c);
    friend istream &operator>>(istream &in, Complex &c);
    friend Complex operator-(Complex c1,Complex c);
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
   
    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = real * c.real;
        temp.imag = imag * c.imag;
        return temp;
    }
    Complex operator/(Complex c)
    {
        Complex temp;
        temp.real = real / c.real;
        temp.imag = imag / c.imag;
        return temp;
    }
};

ostream &operator<<(ostream &out, const Complex &c)
{
    out << c.real;
    out << "+" << c.imag << "i" << endl;
    return out;
}

istream &operator>>(istream &in, Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.imag;
    return in;
}

Complex operator-(Complex c1,Complex c)
{
    Complex temp;
    temp.real = c1.real - c.real;
    temp.imag = c1.imag - c.imag;
    return temp;
}

int main()
{
    Complex c1, c2, c3;
    cin >> c1;
    cin >> c2;
    cout << "The two complex numbers are as follows:" << endl;
    cout << c1 << c2 << endl;
    int flag = 1, option;
    do
    {
        cout << "\nMENU" << endl;
        cout << "1.ADD" << endl;
        cout << "2.SUBTRACT" << endl;
        cout << "3.MULTIPLY" << endl;
        cout << "4.DIVISION" << endl;
        cout << "5.EXIT" << endl;

        cout << "\nEnter the option you want:" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            c3 = c1 + c2;
            cout << c3;
            break;
        case 2:
            c3 = c1 - c2;
            cout << c3;
            break;
        case 3:
            c3 = c1 * c2;
            cout << c3;
            break;
        case 4:
            c3 = c1 / c2;
            cout << c3;
            break;
        case 5:
            cout << "Thank you!";
            break;
        default:
            cout << "You enter the wrong option";
            break;
        }

    } while (option != 5);

    return 0;
}
