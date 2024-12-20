#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

const int minEmployeeNumber = 10000;
const int maxEmployeeNumber = 99999;


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
		std::cout << "Employee Details: \n";
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

	//This will be used to validate that all EmployeeNumbers are unique
	bool EmployeeNumberExists(int empNum) const {
		return std::any_of(listEmployees.begin(), listEmployees.end(),
			[empNum](const Employee& employee) {
				return employee.getEmpNum() == empNum;
			});
	}

	void DischargeEmployee(int empNum) {
		if (numberEmployees <= 0) {
			std::cout << "Currently there are no employees working in the company!\n";
			return;
		}

		//This is used to find the employee with the coresponding EmployeeNumber in the vector listEmployees and remove it
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

		std::cin.ignore();

		switch (option) {
		//Case 1 is taking the information about the employee
		case 1:
			std::cout << "\nEnter the name of new employee: \n";
			std::getline(std::cin, name);
			std::cout << "\nEnter position of employee: \n";
			std::getline(std::cin, position);

			//This validates that the age is entered in the correct format
			std::cout << "\nEnter age of employee: \n";
			while (true) {
				std::cin >> age;
				if (std::cin.fail()) {
					std::cout << "Invalid format!\n";
					std::cout << "Try again: ";
					std::cin.clear();
					std::cin.ignore();
					continue;
				}
				break;
			}

			//This validates that the employee number does not repeat itself and it is in the right format
			std::cout << "\nEnter employee number(e.g 10001): \n";
			while (true) {

				std::cin >> employeeNumber;
			
				if (std::cin.fail() || employeeNumber < minEmployeeNumber || employeeNumber > maxEmployeeNumber) {
					std::cout << "Invalid number format! Employee Number must be in 5-digit format(e.g 10001)!\n";
					std::cout << "Try again: ";
					std::cin.clear();
					std::cin.ignore();
					continue;
				}

				if (MyCompany.EmployeeNumberExists(employeeNumber)) {
					std::cout << "Employee Number already exist!\n";
					std::cout << "Enter another number: ";
					continue;
				}

				break;
			}
			//This validates that the salary is entere in the correct format
			std::cout << "\nEnter salary of employee: \n";
			while (true) {
				std::cin >> salary;
				if (std::cin.fail() || salary <= 0) {
					std::cout << "Invalid value!\n";
					std::cout << "Try again: ";
					std::cin.clear();
					std::cin.ignore();
					continue;
				}

				std::cout << "\n\n";
				break;
			}

			std::cout << "Appointing employee...\n";
			std::cout << "Employee successfully appointed!\n\n";

			MyCompany.AppointEmployee(name, position, age, employeeNumber, salary);
			break;

		case 2:
			if (MyCompany.GetNumberEmployees() <= 0) {
				std::cout << "\nCurrently there are no employees working in the company!\n\n";
				break;
			}

			//This validates the format of employeeNumber
			std::cout << "Enter Employee Number(e.g 10001) of the employee that you want discharged: \n";
			while (true) {
				std::cin >> employeeNumber;
				if (std::cin.fail() || employeeNumber < minEmployeeNumber || employeeNumber > maxEmployeeNumber) {
					std::cout << "Invalid number format! Employee Number must be in 5-digit format(e.g 10001)!\n";
					std::cout << "Try again: ";
					std::cin.clear();
					std::cin.ignore();
					continue;
				}
				if (!MyCompany.EmployeeNumberExists(employeeNumber)) {
					std::cout << "Employee Number does not exist!\n";
					std::cout << "Try again: \n";
					continue;
				}

				break;
			}



			MyCompany.DischargeEmployee(employeeNumber);
			std::cout << "\nDischarging employee...\n";
			std::cout << "Employee successfully discharged!\n\n";
			break;

		case 3:
			std::cout << "\nList of employees: \n";
			std::cout << "------------------\n";
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