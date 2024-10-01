#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 10; //Number of max employees = 10

//Declare class and methods
class Employee
{
public:
	void setID(string temp);
	string getID();
	void setName(string temp);
	string getName();
	void setDepartment(string temp);
	string getDepartment();
	void setPosition(string temp);
	string getPosition();
private:
	string id = "0";
	string name  = "Unknown";
	string department = "Unknown";
	string position = "Unknown";
};

//Methods to set and get private components
void Employee::setID(string temp)
{
	id = temp;
}

string Employee::getID()
{
	return id;
}

void Employee::setName(string temp)
{
	name = temp;
}

string Employee::getName()
{
	return name;
}

void Employee::setDepartment(string temp)
{
	department = temp;
}

string Employee::getDepartment()
{
	return department;
}

void Employee::setPosition(string temp)
{
	position = temp;
}

string Employee::getPosition()
{
	return position;
}

//This function is used to check if the database is not empty
bool flag(Employee temp[MAX_EMPLOYEES])
{
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (temp[i].getName() != "Unknown")
			return true;
	}
	return false;
}

//This function is used to access employee record
void accessEmployee(Employee temp[MAX_EMPLOYEES], string temp_id)
{
	//Declare variable
	bool check = flag(temp);
	//Check if the database is not empty
	if (check == true)
	{
		for (int i = 0; i < MAX_EMPLOYEES; i++)
		{
			//Check the input ID
			if (temp[i].getID() == temp_id)
			{
				cout << "Name: " << temp[i].getName() << endl;
				cout << "ID Number: " << temp[i].getID() << endl;
				cout << "Department: " << temp[i].getDepartment() << endl;
				cout << "Position: " << temp[i].getPosition() << endl;
				cout << endl;
				break; //Save resources because once we found the requested ID, we don't need to find anymore
			}
		}
	}
	else
		cout << "The database is empty" << endl;
}

void addEmployee(Employee temp[MAX_EMPLOYEES])
{	
	//Declare variable
	string str_id;
	bool check;

	cout << "Input ID: ";
	cin >> str_id;

	//Check for the duplicated ID 
	for (int i = 0; i < MAX_EMPLOYEES; i++)
	{
		if (str_id == temp[i].getID())
		{
			check = false;
			cout << "DUPLICATED ID" << endl;
			break;
		}
		check = true;
	}

	if (check == true)
	{
		for (int i = 0; i < MAX_EMPLOYEES; i++)
		{
			//Declare variable
			string str;
			//Check if the element is used or not
			if (temp[i].getName() == "Unknown" )
			{
				//Ask user to input the details
				temp[i].setID(str_id);

				cout << "Input name: ";
				cin >> str;
				temp[i].setName(str);

				cout << "Input department: ";
				cin >> str;
				temp[i].setDepartment(str);

				cout << "Input position: ";
				cin >> str;
				temp[i].setPosition(str);

				//Notify the result
				cout << "ADDED SUCCESSFULLY" << endl;
				break; //Break the loop when finished
			}
		}
	}
}

//This function is used to access employee record
void deleteEmployee(Employee temp[MAX_EMPLOYEES], string temp_id)
{
	//Declare variable
	bool check = flag(temp);
	//Check if the database is not empty
	if (check == true)
	{
		for (int i = 0; i < MAX_EMPLOYEES; i++)
		{
			//Check the input ID
			if (temp[i].getID() == temp_id)
			{
				for (int j = i; j < (MAX_EMPLOYEES - 1); j++)
				{
					//Replace the current employee record with the next one, which means delete the current one
					temp[j].setID(temp[j + 1].getID());
					temp[j].setName(temp[j + 1].getName());
					temp[j].setDepartment(temp[j + 1].getDepartment());
					temp[j].setPosition(temp[j + 1].getPosition());
					
				}
				// Clear the last record as it's now a duplicate
				temp[MAX_EMPLOYEES - 1].setID("0");
				temp[MAX_EMPLOYEES - 1].setName("Unknown");
				temp[MAX_EMPLOYEES - 1].setDepartment("Unkown");
				temp[MAX_EMPLOYEES - 1].setPosition("Unknown");

				//Notify the result
				cout << "DELETED!!!" << endl;
				break;  //Save resources because once we found the requested ID, we don't need to find the following anymore
			}
		}
	}
	else
		cout << "The database is empty" << endl;
}

//This function operates as a menu, ask user to input and run the requested function
void Menu(Employee temp[MAX_EMPLOYEES])
{
	//Declare variables
	int choice;
	string temp_id;
	//Ask user to input their choice
	cout << "1. Access an employee record" << endl;
	cout << "2. Add a new employee" << endl;
	cout << "3. Delete an employee" << endl;
	cout << "4. Exit" << endl;
	cout << "Choice: ";
	cin >> choice;
	cout << endl;

	while (choice != 4)
	{
		if (choice == 1)
		{
			cout << "Input ID your want to access: ";
			cin >> temp_id;
			accessEmployee(temp, temp_id);
			//Ask user to enter the choice again
			cout << endl;
			cout << "1. Access an employee record" << endl;
			cout << "2. Add a new employee" << endl;
			cout << "3. Delete an employee" << endl;
			cout << "4. Exit" << endl;
			cout << "Choice: ";
			cin >> choice;
			cout << endl;
		}
		else if (choice == 2)
		{
			addEmployee(temp);
			//Ask user to enter the choice again
			cout << endl;
			cout << "1. Access an employee record" << endl;
			cout << "2. Add a new employee" << endl;
			cout << "3. Delete an employee" << endl;
			cout << "4. Exit" << endl;
			cout << "Choice: ";
			cin >> choice;
			cout << endl;
		}
		else if (choice == 3)
		{
			cout << "Input ID you want to delete: ";
			cin >> temp_id;
			deleteEmployee(temp, temp_id);
			//Ask user to enter the choice again
			cout << endl;
			cout << "1. Access an employee record" << endl;
			cout << "2. Add a new employee" << endl;
			cout << "3. Delete an employee" << endl;
			cout << "4. Exit" << endl;
			cout << "Choice: ";
			cin >> choice;
			cout << endl;
		}
		else if (choice != 4)
			cout << "Invalid choice. Please try again" << endl;
	}
}

int main()
{
	//Declare variables

	Employee emp[MAX_EMPLOYEES];
	Menu(emp);

	system("pause");
	return 0;
}