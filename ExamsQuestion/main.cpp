#include <iostream>

using namespace std;

class Fraction {
protected:
    int numerator;
    int denominator;
    int whole_number;

public:
    Fraction(int new_whole_number = 0, int new_numerator = 0, int new_denominator = 0):numerator(new_numerator), denominator(new_denominator), whole_number(new_whole_number) {}

void setValues(int new_whole_number, int new_numerator, int new_denominator){
        whole_number = new_whole_number;
        numerator = new_numerator;
        denominator = new_denominator;
}

Fraction operator +(const Fraction &op2) const {// Overloading the + operator.
        Fraction newFraction;
        int theNumerator = whole_number * denominator + numerator;
        int op2Numerator = op2.whole_number * op2.denominator + op2.numerator;

        int lcm = denominator * op2.denominator;
        int numera = theNumerator * op2.denominator + op2Numerator * denominator;
        newFraction.denominator = lcm;
        newFraction.numerator = numera;

        return newFraction;
    }

Fraction operator *(const Fraction &op2) const {// Overloading the * operator
        Fraction newFraction;

        int theNumerator = whole_number * denominator + numerator;
        int op2Numerator = op2.whole_number * op2.denominator + op2.numerator;

        newFraction.numerator = theNumerator * op2Numerator;
        newFraction.denominator = denominator * op2.denominator;

        return newFraction;
    }

float toDecimal() {
    if (numerator == 0)
        return 0;
    else if (denominator == 0) {
        cout << "Math error" << endl;
    }
    else {
        if (whole_number == 0) {
        cout << (float)numerator / denominator << endl;
        return (float)numerator / denominator;
}
        }
}

    virtual void showFraction() {
        if (whole_number != 0) {
            cout << whole_number << " whole number ";
        }
        cout << numerator << "/" << denominator << endl;
    }
};

class ProperFraction : public Fraction {
public:
    ProperFraction(int new_numerator = 0, int new_denominator = 0, int new_whole_number = 0) : Fraction(new_whole_number, new_numerator, new_denominator) {}
};

class ImproperFraction : public Fraction {
private:
bool mixed;

public:
    ImproperFraction(int new_numerator = 0, int new_denominator = 0, int new_whole_number = 0) : Fraction(new_whole_number, new_numerator, new_denominator) {}

    void toMixedFraction() {
        int mod = numerator % denominator;
        int intermid = numerator - mod;
        whole_number = intermid / denominator;
        numerator = mod;
    }

    void toImproperFraction() {
        numerator = (denominator * whole_number) + numerator;
        whole_number = 0;
    }

    void showFraction() {
        if (whole_number != 0)
        Fraction::showFraction();
    }
};

int main() {
    ProperFraction prop1(1, 2, 0);
    prop1.showFraction();
    (prop1 + prop1).showFraction();
    (prop1 + prop1).toDecimal();

    ImproperFraction improp1(3, 4, 2);
    improp1.showFraction();

    ImproperFraction improp2(5, 3, 0);
    improp2.showFraction();

    (improp1 + improp2).showFraction();
    (prop1 + improp2).showFraction();

    improp1.setValues(3, 4, 2);


    return 0;
}
