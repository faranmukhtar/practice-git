// Task 2 - Faran Mukhtar  24k-0646

#include <iostream>
using namespace std;

class BankAccount {
private:
    string accNum;
    string holderName;
    double currentBalance;

public:
    BankAccount(string num, string name, double bal) {
        accNum = num;
        holderName = name;
        currentBalance = bal;
    }

    BankAccount operator+(const BankAccount& other) {
        return BankAccount("N/A", "Merged", this->currentBalance + other.currentBalance);
    }

    BankAccount& operator-=(double amt) {
        if (amt <= currentBalance) {
            currentBalance -= amt;
        } else {
            cout << "Not enough balance" << endl;
        }
        return *this;
    }

    bool operator>(const BankAccount& other) {
        return currentBalance > other.currentBalance;
    }

    friend ostream& operator<<(ostream& out, const BankAccount& acc) {
        out << "Account#: " << acc.accNum << " | Name: " << acc.holderName << " | Balance: $" << acc.currentBalance << endl;
        return out;
    }

    void addFunds(double amt) {
        currentBalance += amt;
    }

    string getAccNum() const { return accNum; }
    string getName() const { return holderName; }
    double getBalance() const { return currentBalance; }
};

int main() {
    BankAccount acc1("A-101", "Ali", 5000);
    BankAccount acc2("A-202", "Ahmed", 3000);

    BankAccount mergedAcc = acc1 + acc2;
    cout << "New Balance: Total: "<<mergedAcc.getBalance() << endl << endl;

    acc1 -= 2000;
    acc2.addFunds(2000);

    cout << "Post Transfer Balances:\n";
    cout << acc1.getName() << ": $" << acc1.getBalance() << endl;
    cout << acc2.getName() << ": $" << acc2.getBalance() << endl << endl;

    cout << "Balance Comparison:\n";
    if (acc1 > acc2) {
        cout << acc1.getName() << " has more money than " << acc2.getName() << endl;
    } else {
        cout << acc1.getName() << " has less money than " << acc2.getName() << endl;
    }
    cout << endl;

    cout << "Account Summaries:\n";
    cout << acc1 << acc2;

    return 0;
}
