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
		employeeNumber = e;
		age = a;
		salary = s;
	}

	void DisplayDetails() const {
		std::cout << "\nEmployee Details\n";
		std::cout << "-------------------\n";
		std::cout << "Name: " << name << "\n";
		std::cout << "Position: " << position << "\n";
		std::cout << "Employee number: " << employeeNumber << "\n";
		std::cout << "Age: " << age << "\n";
		std::cout << "Salary: " << salary << "$\n\n";
	}


};

class Company {
private:
	int numberEmployees = 0;
	std::vector<Employee> listEmployees;
public:

	void AppointEmployee(std::string n, std::string p, int a, int e, float s) {
		Employee EmployeeObj(n, p, a, e, s);
		listEmployees.push_back(EmployeeObj);
		numberEmployees++;
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

	//Info about employee
	std::string name = " ";
	std::string position = " ";
	int employeeNumber = 0;
	int age = 0;
	float salary = 0;



	Company MyCompany;

	while (option != -1) {
		std::cout << "Choose an option: \n";
		std::cout << "1.Appoint an employee\n";
		std::cout << "2.Display info of all employees\n";
		std::cout << "3.Display number of employees\n";
		std::cout << "4.Exit\n\n";
		std::cin >> option;
		std::cin.ignore();


		switch (option) {
		case 1:
			std::cout << "\nEnter the name of new employee: \n";
			std::getline(std::cin, name);
			std::cout << "Enter position: \n";
			std::getline(std::cin, position);
			std::cout << "Enter employee number(e.g 10001): \n";
			std::cin >> employeeNumber;
			std::cout << "Enter age of employee: \n";
			std::cin >> age;
			std::cout << "Enter salary of employee: \n";
			std::cin >> salary;
			std::cout << "\n";
			MyCompany.AppointEmployee(name, position, age, employeeNumber, salary);
			break;

		case 2:
			if (MyCompany.GetNumberEmployees() == 0) {
				std::cout << "\nCurrently there are no employees working in the company!\n\n";
				break;
			}
			MyCompany.DisplayAllEmployees();
			break;

		case 3:
			std::cout << "Number of employees in the company: ";
			std::cout << MyCompany.GetNumberEmployees() << "\n\n";
			break;

		case 4:
			option = -1;
			break;

		default:
			break;
		}
	}





}