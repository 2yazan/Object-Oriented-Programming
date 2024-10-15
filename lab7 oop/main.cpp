// Develop an abstract class for solving equations. Implement a class for solving trigonometric
// equations (a descendant of the abstract class), providing exception handling for solving
//  trigonometric equations (domain of definition of trigonometric functions).

#include <iostream>
#include <locale.h>
#include <math.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

class EquatException {
protected:
    string str;
public:
    EquatException(string mess) :
        str(mess) {};
    string error() {
        return (" !!!" + str);
    };
};

class FirstNull : public EquatException {
public:
    FirstNull(string) :
        EquatException(" Equation is not quadratic! ") {};
};

class NegDiscr : public EquatException {
public:
    NegDiscr(string) :
        EquatException(" Discriminant is negative ") {};
};

class TrigODZ : public EquatException {
public:
    TrigODZ(string) :
        EquatException(" does not satisfy the domain: [-1;1] ") {};
};

class Equations {
public:
    virtual void print() = 0;
    virtual void write() = 0;
    virtual void root() = 0;
    virtual double findDiscrim() = 0;
    virtual void print_solution() = 0;
    virtual void solve_equation() = 0;
};

class Square_Trig_equation : public Equations {
private:
    double a, b, c, x1, x2;
    int m;
public:
    void print() {
        cout << "a = " << a << " b = " << b << " c = " << c;
    };

    void write() {
        cout << "Enter the coefficients a, b, c of the trigonometric quadratic equation: " << endl;
        cin >> a;
        cin >> b;
        cin >> c;
        cout << "Enter the type of equation you want to solve sin - 1, cos - 2, tg - 3 " << endl;
        cin >> m;
    };

    void test_null_a() {
        if (a == 0.0)
            throw FirstNull("");
    }

    void test_discr(double discr) {
        if (discr < 0.0) {
            cout << "D = " << discr << endl;
            throw NegDiscr("");
        }
    }

    void test_trig(double x) {
        if (fabs(x) > 1.0) {
            cout << "Root " << x;
            throw TrigODZ("");
        }
    }

    void root() {
        double d = findDiscrim();
        test_null_a();
        x1 = (-b + (sqrt(d))) / (2 * a);
        x2 = (-b - (sqrt(d))) / (2 * a);
    }

    double findDiscrim() {
        double d;
        d = (b * b) - (4 * a * c);
        test_discr(d);
        return d;
    }

    void print_solution() {
        cout << "Roots:" << endl;
        switch (m) {
        case 1:
            cout << "x1=((-1)^n)arcsin(" << x1 << ")+pi*n" << endl;
            cout << "x2=((-1)^n)arcsin(" << x2 << ")+pi*n" << endl;
            test_trig(x1);
            test_trig(x2);
            break;
        case 2:
            cout << "x1=+-arccos(" << x1 << ")+2pi*n" << endl;
            cout << "x2=+-arccos(" << x2 << ")+2pi*n" << endl;
            test_trig(x1);
            test_trig(x2);
            break;
        default:
            cout << "x1=arctg" << x1 << "+pi*n" << endl;
            cout << "x2=arctg" << x2 << "+pi*n" << endl;
            break;
        }
    }

    void solve_equation() {
        write();
        root();
        print_solution();
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);//Подключение русского языка
    Square_Trig_equation eq;
    try {
        eq.solve_equation();
    }
    catch (EquatException& r) {
        cout << r.error() << endl;
        exit(0);
    }
    return 0;
}