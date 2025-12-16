#include <iomanip>
#include <iostream>
#include <string>

void setupOutputFormatting() {
  std::cout << std::fixed << std::setprecision(2);
}

class Employee {
private:
  std::string name;
  std::string employeeNumber; 
  std::string hireDate;

public:
 
  Employee(const std::string &n, const std::string &num,
           const std::string &date)
      : name(n), employeeNumber(num), hireDate(date) {
   
  }

 
  std::string getName() const { return name; }

 
  std::string getEmployeeNumber() const { return employeeNumber; }

  std::string getHireDate() const { return hireDate; }

 
  void setName(const std::string &newName) { name = newName; }

  void setEmployeeNumber(const std::string &newNum) { employeeNumber = newNum; }

 
  void setHireDate(const std::string &newDate) { hireDate = newDate; }

  void printEmployee() const {
    std::cout << "  Name: " << name << "\n";
    std::cout << "  Employee Number: " << employeeNumber << "\n";
    std::cout << "  Hire Date: " << hireDate << "\n";
  }
};

class ProductionWorker : public Employee {
private:
  int shift; 
  double hourlyPayRate;

public:
  
  ProductionWorker(const std::string &n, const std::string &num,
                   const std::string &date, int s, double rate)
      : Employee(n, num, date), shift(s), hourlyPayRate(rate) {
   
  }
 
  int getShift() const { return shift; }

  double getHourlyPayRate() const { return hourlyPayRate; }

  void setShift(int newShift) { shift = newShift; }

  void setHourlyPayRate(double newRate) { hourlyPayRate = newRate; }

  void printProductionWorker() const {
    Employee::printEmployee(); 
    std::cout << "  Shift: " << (shift == 1 ? "Day" : "Night") << "\n";
    std::cout << "  Hourly Pay Rate: $" << hourlyPayRate << "\n";
  }
};

class ShiftSupervisor : public Employee {
private:
  double annualSalary;
  double annualProductionBonus;

public:
  
  ShiftSupervisor(const std::string &n, const std::string &num,
                  const std::string &date, double salary, double bonus)
      : Employee(n, num, date), annualSalary(salary),
        annualProductionBonus(bonus) {
   
  }

  double getAnnualSalary() const { return annualSalary; }

  double getAnnualProductionBonus() const { return annualProductionBonus; }

  void setAnnualSalary(double newSalary) { annualSalary = newSalary; }

  void setAnnualProductionBonus(double newBonus) {
    annualProductionBonus = newBonus;
  }

  void printShiftSupervisor() const {
    Employee::printEmployee();
    std::cout << "  Annual Salary: $" << annualSalary << "\n";
    std::cout << "  Annual Production Bonus: $" << annualProductionBonus
              << "\n";
  }
};

class TeamLeader : public ProductionWorker {
private:
  double monthlyBonus;
  int requiredTrainingHours;
  int attendedTrainingHours;

public:
  
  TeamLeader(const std::string &n, const std::string &num,
             const std::string &date, int s, double rate, double bonus,
             int required, int attended)
      
      : ProductionWorker(n, num, date, s, rate), monthlyBonus(bonus),
        requiredTrainingHours(required), attendedTrainingHours(attended) {
    
  }

  double getMonthlyBonus() const { return monthlyBonus; }

  int getRequiredTrainingHours() const { return requiredTrainingHours; }

  int getAttendedTrainingHours() const { return attendedTrainingHours; }

  void setMonthlyBonus(double newBonus) { monthlyBonus = newBonus; }

  void setRequiredTrainingHours(int newRequired) {
    requiredTrainingHours = newRequired;
  }

  
  void setAttendedTrainingHours(int newAttended) {
    attendedTrainingHours = newAttended;
  }

  void printTeamLeader() const {
   
    ProductionWorker::printProductionWorker();
    std::cout << "  Monthly Bonus: $" << monthlyBonus << "\n";
    std::cout << "  Required Training Hours: " << requiredTrainingHours
              << " hrs\n";
    std::cout << "  Attended Training Hours: " << attendedTrainingHours
              << " hrs\n";
  }
};

int main() {
  setupOutputFormatting();
  std::cout << "FACTORY WORKER MANAGEMENT SYSTEM\n";
  std::cout << "================================\n\n";

  std::cout << "--- PRODUCTION WORKERS ---\n";

  ProductionWorker pw1("Alice Smith", "1001", "2020-05-20", 1, 15.50);
  std::cout << "Worker 1 (Day Shift):\n";
  pw1.printProductionWorker();

  std::cout << "\n";

  ProductionWorker pw2("Bob Johnson", "2002", "2019-11-01", 2, 18.75);
  std::cout << "Worker 2 (Night Shift):\n";
  pw2.printProductionWorker();

  std::cout << "\n--- SHIFT SUPERVISOR ---\n";

  ShiftSupervisor ss1("Carol Davis", "3003", "2018-03-10", 65000.00, 5000.00);
  std::cout << "Supervisor 1:\n";
  ss1.printShiftSupervisor();

  std::cout << "\n--- TEAM LEADER ---\n";

  TeamLeader tl1("David Lee", "4004", "2021-08-25", 1, 22.00, 250.00, 40, 35);
  std::cout << "Team Leader 1:\n";
  tl1.printTeamLeader();

  std::cout << "\n================================\n";
  std::cout << "Program Execution Complete.\n";

  return 0;
}
