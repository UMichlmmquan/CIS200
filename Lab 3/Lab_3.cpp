#include <iostream>

using namespace std;

//Class for real number
class Number
{
public:
	Number() : value(0) {};
	Number(int rNum);
	int getReal() const;
	Number operator+(Number temp);
	Number operator-(Number temp);
	void display() const;
protected:
	int value;
};

//Class for imaginary number
class ComplexNumber : public Number
{
public:
	ComplexNumber(int rNum, int iNum);
	int getImaginary();
	ComplexNumber operator+(ComplexNumber temp);
	ComplexNumber operator-(ComplexNumber temp);
	void display() const;
private:
	int imaginary;
};

//Constructor of real number
Number::Number(int rNum)
{
	value = rNum;
}

//Access the real number
int Number::getReal() const
{
	return value;
}

//This function overloads the operator + between 2 real numbers
Number Number::operator+(Number temp)
{
	return (value + temp.value);
}

//This function overloads the operator - between 2 real numbers
Number Number::operator-(Number temp)
{
	return (value - temp.value);
}

//This function displays the result of 2 real numbers
void Number::display() const
{
	cout << "Output: " << value << endl;
}

//Constructor of imaginary number
ComplexNumber::ComplexNumber(int rNum, int iNum)
{
	value = rNum;
	imaginary = iNum;
}

//Access the imaginary number
int ComplexNumber::getImaginary()
{
	return imaginary;
}

//This function overloads the operator + between 2 complex numbers
ComplexNumber ComplexNumber::operator+(ComplexNumber temp)
{
	ComplexNumber result(0,0);
	result.value = value + temp.value;
	result.imaginary = imaginary + temp.imaginary;
	return result;
}

//This function overloads the operator - between 2 real numbers
ComplexNumber ComplexNumber::operator-(ComplexNumber temp)
{
	ComplexNumber result(0, 0);
	result.value = value - temp.value;
	result.imaginary = imaginary - temp.imaginary;
	return result;
}

//This function displays the result of 2 complex numbers
void ComplexNumber::display() const
{
	if (imaginary >= 0)
		cout << "Output: " << value << " + " << imaginary << "i" << endl;  // Format: a + bi
	else
		cout << "Output: " << value << " - " << -imaginary << "i" << endl; // Format: a - bi
}

int main()
{
	//TEST CASE 1
	
	//Declare variables and testing units
	Number num1(5);
	Number num2(3);
	//Addition and substraction
	Number resultAdd1 = num1 + num2; // 5 + 3 = 8
	Number resultSub1= num1 - num2; // 5 - 3 = 2
	//Output results
	resultAdd1.display();
	resultSub1.display();

	//TEST CASE 2

	//Declare variables and testing units
	ComplexNumber complex1(4,2); // 4 + 2i
	ComplexNumber complex2(1,7); // 1 + 7i
	//Addition and substraction
	ComplexNumber resultAdd2 = complex1 + complex2; // (4 + 2i) + (1 + 7i) = 5 + 9i
	ComplexNumber resultSub2 = complex1 - complex2; // (4 + 2i) - (1 + 7i) = 3 - 5i
	//Output results
	resultAdd2.display();
	resultSub2.display();

	system("pause");
	return 0;
}