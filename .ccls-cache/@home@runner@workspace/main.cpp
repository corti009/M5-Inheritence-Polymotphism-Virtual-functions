#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

class Employee {
private:
    std::string employeeName;
    std::string employeeNumber; 
    std::string hireDate;

protected:
    double hourlyPayRate;

public:
    
    Employee(std::string name, std::string number, std::string date, double rate)
        : employeeName(name), employeeNumber(number), hireDate(date), hourlyPayRate(rate) {
        if (employeeNumber.length() != 5 || employeeNumber[3] != '-') {
            std::cerr << "Warning: Employee number format should be XXX-L.\n";
        }
    }

    virtual ~Employee() {}

    std::string getName() const { return employeeName; }
    std::string getNumber() const { return employeeNumber; }
    std::string getHireDate() const { return hireDate; }
    double getHourlyPayRate() const { return hourlyPayRate; }

    
    void setName(const std::string& name) { employeeName = name; }
    void setNumber(const std::string& number) { employeeNumber = number; }
    void setHireDate(const std::string& date) { hireDate = date; }
    void setHourlyPayRate(double rate) { hourlyPayRate = rate; }
    virtual double calculateGrossPay(double hoursWorked) const {
        return hoursWorked * hourlyPayRate;
    }
};

class TeamLeader : public Employee {
private:
    double monthlyBonus;
    int requiredTrainingHours;
    int trainingHoursAttended;

public:
   
    TeamLeader(std::string name, std::string number, std::string date, double rate,
               double bonus, int requiredHours, int attendedHours)
        : Employee(name, number, date, rate),
          monthlyBonus(bonus),
          requiredTrainingHours(requiredHours),
          trainingHoursAttended(attendedHours) {}

   
    double getMonthlyBonus() const { return monthlyBonus; }
    int getRequiredTrainingHours() const { return requiredTrainingHours; }
    int getTrainingHoursAttended() const { return trainingHoursAttended; }

   
    void setMonthlyBonus(double bonus) { monthlyBonus = bonus; }
    void setRequiredTrainingHours(int hours) { requiredTrainingHours = hours; }
    void setTrainingHoursAttended(int hours) { trainingHoursAttended = hours; }

    
    bool hasCompletedTraining() const {
        return trainingHoursAttended >= requiredTrainingHours;
    }

   
    double calculateGrossPay(double hoursWorked) const override {
        double basePay = hoursWorked * hourlyPayRate;

        if (hasCompletedTraining()) {
            std::cout << "  (Training requirement met. Monthly bonus included.)\n";
            return basePay + monthlyBonus;
        } else {
            std::cout << "  (Training requirement NOT met. Monthly bonus excluded.)\n";
            return basePay;
        }
    }
};

void displayEmployeeDetails(const Employee& emp, double hours) {
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "\n----------------------------------------\n";
    std::cout << "Employee Type: " << (dynamic_cast<const TeamLeader*>(&emp) ? "Team Leader" : "Standard Worker") << "\n";
    std::cout << "Name: " << emp.getName() << "\n";
    std::cout << "Number: " << emp.getNumber() << "\n";
    std::cout << "Hire Date: " << emp.getHireDate() << "\n";
    std::cout << "Hourly Rate: $" << emp.getHourlyPayRate() << "\n";

    const TeamLeader* leader = dynamic_cast<const TeamLeader*>(&emp);
    if (leader) {
        std::cout << "Monthly Bonus: $" << leader->getMonthlyBonus() << "\n";
        std::cout << "Req. Training: " << leader->getRequiredTrainingHours() << " hrs\n";
        std::cout << "Attended: " << leader->getTrainingHoursAttended() << " hrs\n";
        std::cout << "Training Status: " << (leader->hasCompletedTraining() ? "COMPLETE" : "PENDING") << "\n";
    }

    std::cout << "----------------------------------------\n";
    std::cout << "Hours Worked: " << hours << " hrs\n";
    double grossPay = emp.calculateGrossPay(hours);
    std::cout << "GROSS PAY: $" << grossPay << "\n";
    std::cout << "----------------------------------------\n";
}

int main() {
    
    Employee worker("Alice Johnson", "123-A", "2022-08-15", 18.50);
    double workerHours = 40.0;

    
    TeamLeader leader1("Bob Smith", "456-T", "2021-03-20", 25.00, 500.00, 10, 12);
    double leader1Hours = 40.0;

   
    TeamLeader leader2("Charlie Davis", "789-L", "2023-11-01", 26.00, 500.00, 10, 8);
    double leader2Hours = 45.0; 
  
    std::cout << "--- Factory Employee Payroll Simulation ---\n";

    displayEmployeeDetails(worker, workerHours);
    displayEmployeeDetails(leader1, leader1Hours);
    displayEmployeeDetails(leader2, leader2Hours);

    
    std::cout << "\n--- DEMO: Changing Pay Rate for Alice ---\n";
    worker.setHourlyPayRate(20.00);
    displayEmployeeDetails(worker, workerHours);

    return 0;
}