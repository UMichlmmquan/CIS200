#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 5; //Number of max students = 5

//Declare structs
struct Date
{
	int day;
	int month;
	int year;
};

struct Student
{
	int id;
	string fname; //First name
	string lname; //Last name
	Date dob;
	float grade;
};

//This function will display the details of students
void display(Student temp[MAX_STUDENTS])
{
	cout << "\nDetails of all students:" << endl << endl;
	//Output all details of students
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		cout << "Student " << i + 1 << ":" << endl; //Number of student
		cout << "ID: " << temp[i].id << endl; //ID
		cout << "First Name: " << temp[i].fname << endl; //First name
		cout << "Last Name: " << temp[i].lname << endl; //Last name
		cout << "Date of Birth: " << temp[i].dob.day << "/" << temp[i].dob.month << "/" << temp[i].dob.year << endl; //Date of Birth
		cout << "Grade: " << temp[i].grade << endl; //Grade
		cout << endl;
	}
}

//This function will calculate and display the average grade of all students, minimum and maximum
void calculate(Student temp[MAX_STUDENTS])
{
	//Declare variables
	float sum = 0.0;
	float max = 0.0;
	float min = 9999.9;
	float average;
	
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		sum += temp[i].grade;
		//Update max
		if (temp[i].grade >= max)
			max = temp[i].grade;
		//Update min
		if (temp[i].grade <= min)
			min = temp[i].grade;
	}
	//Update average
	average = sum / MAX_STUDENTS;

	//Display average, max and min
	cout << "\nAverage grade: " << average << endl;
	cout << "Maximum grade: " << max << endl;
	cout << "Minimum grade: " << min << endl;
}

int main()
{
	//Declare variables
	Student stu[MAX_STUDENTS];

	cout << "Enter details of 5 students:" << endl;
	//Ask user to input the details of students
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		cout << "Student " << i + 1 << ":" << endl;

		//Enter ID 
		cout << "ID: ";
		cin >> stu[i].id;
		//Enter first name
		cout << "First name: ";
		cin >> stu[i].fname;
		//Enter last name
		cout << "Last name: ";
		cin >> stu[i].lname;
		//Enter date of birth
		cout << "Date of Birth (day month year): ";
		cin >> stu[i].dob.day; //Day
		cin >> stu[i].dob.month; //Month
		cin >> stu[i].dob.year; //Year
		//Enter grade
		cout << "Grade: ";
		cin >> stu[i].grade;

		cout << endl;
	}

	//Call function to display all the students' details
	display(stu);
	//Call function to calculate and display the average grade of all students, minimum and maximum
	calculate(stu);

	system("pause");
	return 0;
}