#include <iostream>
#include <vector>
#include <string>


class Employee {

private:

	std::string name;
	std::string position;
	int age = 0;
	int employeeNumber = 0;
	float salary = 0;

public:

	Employee(std::string n, std::string p, int a, int e, float s) {
		name = n;
		position = p;
		age = a;
		employeeNumber = e;
		salary = s;
	}

	int getEmpNum() const { return employeeNumber; };

	void SetEmployeeNumber(int num) {
		employeeNumber = num;
	}

	void DisplayDetails() const {
		std::cout << "\nEmployee Details\n";
		std::cout << "-------------------\n";
		std::cout << "Name: " << name << "\n";
		std::cout << "Position: " << position << "\n";
		std::cout << "Age: " << age << "\n";
		std::cout << "Employee number: " << employeeNumber << "\n";
		std::cout << "Salary: " << salary << "$\n\n";
	}


};

class Company {
private:

	int numberEmployees = 0;
	std::vector<Employee> listEmployees;

public:


	//Will create an employee and add the info in a vector
	void AppointEmployee(std::string n, std::string p, int a, int e, float s) {
		Employee EmployeeObj(n, p, a, e, s);
		listEmployees.push_back(EmployeeObj);
		numberEmployees++;
	}

	void DischargeEmployee(int empNum) {
		if (numberEmployees <= 0) {
			std::cout << "Currently there are no employees working in the company!\n";
			return;
		}

		listEmployees.erase(std::remove_if(listEmployees.begin(),listEmployees.end(), [empNum](const Employee& employee) { return employee.getEmpNum() == empNum; }), listEmployees.end());

			numberEmployees--;
	}

	int GetNumberEmployees() {
		return numberEmployees;
	}

	void DisplayAllEmployees() {
		for (const auto& employee : listEmployees) {
			employee.DisplayDetails();
		}
	}
};


int main() {

	int option = 0;

	//Will be used for employee info
	std::string name = " ";
	std::string position = " ";
	int employeeNumber = 0;
	int age = 0;
	float salary = 0;


	Company MyCompany;

	std::cout << "Welcome to the HR system of 'MyCompany'\n\n";
	while (option != -1) {
		
		while (true) {
			//This is the menu of the program
			std::cout << "Choose an option: \n";
			std::cout << "1.Appoint an employee\n";
			std::cout << "2.Discharge an employee\n";
			std::cout << "3.Display info of all employees\n";
			std::cout << "4.Display number of employees\n";
			std::cout << "5.Exit\n\n";
			std::cin >> option;
			
			if (std::cin.fail()) {
				std::cout << "You need to choose an option between 1 and 5!\n\n";
				std::cin.clear();
				
			}
			else {
				break;
			}

			std::cin.ignore();
		}

		//Clears the cin stream;
		std::cin.ignore();

		switch (option) {
		case 1:
			std::cout << "\nEnter the name of new employee: \n";
			std::getline(std::cin, name);
			std::cout << "Enter position: \n";
			std::getline(std::cin, position);
			std::cout << "Enter age of employee: \n";
			std::cin >> age;
			std::cout << "Enter employee number(e.g 10001): \n";
			std::cin >> employeeNumber;
			std::cout << "Enter salary of employee: \n";
			std::cin >> salary;
			std::cout << "\n\n";

			std::cout << "Appointing employee...\n";
			std::cout << "Employee successfully appointed!\n\n";

			MyCompany.AppointEmployee(name, position, age, employeeNumber, salary);
			break;

		case 2:
			std::cout << "Enter Employee Number(e.g 10001) of the employee that you want removed: \n";
			std::cin >> employeeNumber;
			MyCompany.DischargeEmployee(employeeNumber);
			break;

		case 3:
			if (MyCompany.GetNumberEmployees() == 0) {
				std::cout << "\nCurrently there are no employees working in the company!\n\n";
				break;
			}
			MyCompany.DisplayAllEmployees();
			break;

		case 4:
			std::cout << "Number of employees in the company: ";
			std::cout << MyCompany.GetNumberEmployees() << "\n\n";
			break;

		case 5:
			option = -1;
			std::cout << "Exiting...\n";
			std::cout << "Exit succsessful!\n";
			break;

		default:
			break;
		}
	}





}