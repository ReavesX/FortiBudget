#include <string>
#include <vector>
#include <iostream>
#include <date/date.h> 


// budget.cpp// This file contains the implementation of various classes related to budgeting,
// including Expense, Income, SavingsBucket, and Goal.
// Each class encapsulates properties and methods relevant to managing personal finances.


class Expense {
    private:
        std::string name;
        double amount;
        std::string type;   

    public:
        Expense(const std::string& name, double amount, const std::string& type) 
            : name(name), amount(amount), type(type) {}

        std::string getName() const { return name; }
        std::string getType() const { return type; }
        double getAmount() const { return amount; }
}; 


class Income {
    private:
        std::string source;
        double amount;
        double stateTaxRate;

    public:
        Income(const std::string& source, double amount, double stateTaxRate)
            : source(source), amount(amount), stateTaxRate(stateTaxRate) {} 

        double getStateTaxRate() const { return stateTaxRate; }
        std::string getSource() const { return source; }
        double getAmount() const { return amount; }
};

class SavingsBucket {
    private:
        std::string name;
        double amount;

    public:
        SavingsBucket(const std::string& name, double amount) 
            : name(name), amount(amount) {}

        std::string getName() const { return name; }
        
        double getAmount() const { return amount; }
        
        bool bucketExists() const { return amount > 0; }
        

        void addAmount(double additionalAmount) {
            if (additionalAmount < 0) {
                std::cerr << "Additional amount cannot be negative." << std::endl;
                return;
            }

            if (additionalAmount == 0) {
                std::cerr << "Additions cannot be 0" << std::endl;
                return;
            }

            amount += additionalAmount;
}
        
        
        void removeAmount(double deduction) {   
            if  (deduction < 0) {
                std::cerr << "Deduction cannot be negative." << std::endl;
                return;
            }

            if (deduction > amount) {
                std::cerr << "Not enough funds in bucket." << std::endl;
                return;
            }
            
            amount -= deduction;
        }  
};


class Goal{
    private:
        std::string name;
        double targetAmount;
        double currentAmount;
        double progress;
        date deadline;

    public:
        Goal(const std::string& name, double targetAmount, double currentAmount = 0.0, const date& deadline = date{})
        : name(name), targetAmount(targetAmount), currentAmount(currentAmount), deadline(deadline) {}


        std::string getName() const { return name; }
        
        double getTargetAmount() const { return targetAmount; }
        
        double getCurrentAmount() const { return currentAmount; }
        
        void addToGoal(double amount) {
            if (amount < 0) {
                std::cerr << "Cannot add negative amount." << std::endl;
                return;
            }
            currentAmount += amount;
        }
        
        bool isGoalMet() const { return currentAmount >= targetAmount; }    

        double getProgress() const {
            if (targetAmount == 0) return 0;
            if (currentAmount < 0) {
                std::cerr << "Current amount cannot be negative." << std::endl;
                return 0;
            }
            if (currentAmount > targetAmount) {
                std::cerr << "Current amount exceeds target amount." << std::endl;
                return 100.0; // Consider it fully met if current exceeds target
            }

            progress = (currentAmount / targetAmount) * 100.0;
            return progress;
        }
        
        void setDeadline(const date& newDeadline) {
            deadline = newDeadline;
        }
        
        date getDeadline() const {
            return deadline;
        }
};

class Debt{
    private:
        std::string name;
        double amount;
        double interestRate;
        date dueDate;

    public:
        Debt(const std::string& name, double amount, double interestRate, const date& dueDate)
            : name(name), amount(amount), interestRate(interestRate), dueDate(dueDate) {}

        std::string getName() const { return name; }
        
        double getAmount() const { return amount; }
        
        double getInterestRate() const { return interestRate; }
        
        date getDueDate() const { return dueDate; }
        
        void makePayment(double payment) {
            if (payment < 0) {
                std::cerr << "Payment cannot be negative." << std::endl;
                return;
            }
            if (payment > amount) {
                std::cerr << "Payment exceeds debt amount." << std::endl;
                return;
            }
            amount -= payment;
        }
};