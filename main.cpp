#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Employee struct to store employee information
struct Employee {
    string name;
    double hourlyRate;
    double hoursWorked;
    double taxes;
    double netPay;
};

// Function to calculate net pay for an employee
void calculateNetPay(Employee& emp) {
    double grossPay = emp.hourlyRate * emp.hoursWorked;
    emp.taxes = 0.25 * grossPay; // Assuming a 25% tax rate
    emp.netPay = grossPay - emp.taxes;
}

int main() {
    vector<Employee> employees;
    int numEmployees;

    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    // Get employee information
    for (int i = 0; i < numEmployees; i++) {
        Employee emp;
        cout << "Enter employee name: ";
        cin >> emp.name;
        cout << "Enter hourly rate: ";
        cin >> emp.hourlyRate;
        cout << "Enter hours worked: ";
        cin >> emp.hoursWorked;
        calculateNetPay(emp);
        employees.push_back(emp);
    }

    // Display payroll information
    cout << "\nPayroll Information:\n";
    for (const auto& emp : employees) {
        cout << "Name: " << emp.name << "\n";
        cout << "Hourly Rate: $" << emp.hourlyRate << "\n";
        cout << "Hours Worked: " << emp.hoursWorked << "\n";
        cout << "Taxes: $" << emp.taxes << "\n";
        cout << "Net Pay: $" << emp.netPay << "\n\n";
    }

    return 0;
}