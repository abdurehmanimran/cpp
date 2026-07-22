#include "bank.hpp"

#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <sys/types.h>
#include <unordered_map>
#include <vector>

using namespace std;

// Account Class Imp Start
uint64_t Account::getBalance() const { return balance; }
void Account::deposit(uint64_t amount) { balance += amount; }

int Account::withdraw(uint64_t amount) {
  if (balance < amount) {
    throw runtime_error{"does not have enough money !!"};
  }

  balance -= amount;
  return amount;
}

bool Account::matchPin(uint64_t passCode) const { return pin == passCode; }
// Account Class Imp End

// Checking Account Imp Start
void CheckingAccount::deposit(uint64_t amount) {
  Account::deposit(amount - fee);
}

int CheckingAccount::withdraw(uint64_t amount) {
  Account::withdraw(amount + fee);
  return amount;
}
// Checking Account Imp End

// -> Transaction Class <-

class Transaction {
public:
  Transaction(Account &sender, Account &receiver, uint64_t transferAmount)
      : id(p_id++), from(sender.getId()), to(receiver.getId()), amount(0) {
    try {
      sender.withdraw(transferAmount);
    } catch (runtime_error) {
      cout << "Transaction failed due to insufficient balance !!" << endl;
      return;
    }

    receiver.deposit(transferAmount);
    amount = transferAmount;
  };

  friend ostream &operator<<(ostream &stream, const Transaction &transac) {
    stream << ":: ID => " << transac.id << "\t" << transac.from << "<=>"
           << transac.to << "\tAmount -> " << transac.amount << endl;
    return stream;
  }

private:
  uint64_t id;
  uint64_t from;
  uint64_t to;
  uint64_t amount;

  inline static uint64_t p_id = 0;
};

// -> Transaction Class <-

// Bank Class Imp Start

class Bank {

public:
  Bank() : totalAccounts() {};

  void newAccount(string accountName, uint64_t initialDesposit) {
    uint64_t pin;
    cout << "Enter the pin: ";
    cin >> pin;

    Account acc{accountName, pin};
    acc.deposit(initialDesposit);
    cout << "----------------- Account Creation -----------------" << endl;
    cout << acc;
    cout << "----------------------------------------------------" << endl;
    map.insert({acc.getId(), acc});
  }

  void transferMoney(uint64_t sender, uint64_t receiver, uint64_t amount) {

    try {
      Transaction transfer(map.at(sender), map.at(receiver), amount);
      transactions.push_back(transfer);
    } catch (out_of_range map_err) {
      cout << "Error: the recipient does not exist !!" << endl;
    }
  }

  Account &getAccountById(uint64_t id) { return map.at(id); }

  void displayOptions() {
    cout << "Choose an option !!" << endl;
    cout << "[1] -> Display Info" << endl;
    cout << "[2] -> Desposit Money" << endl;
    cout << "[3] -> Withdraw Money" << endl;
    cout << "[4] -> Transfer Money" << endl;
    cout << "[0] -> Logout" << endl;
  }

  void loginAccount() {
    uint64_t account = 0;
    uint64_t pass = 0;
    cout << "Enter your Account ID (0 to end): ";
    cin >> account;

    if (!account)
      return;

    cout << "Enter the pin code: ";
    cin >> pass;

    if (this->getAccountById(account).matchPin(pass))
      loggedIn = account;
    else
      cout << "Failed to login !!" << endl;
  }

  bool isLoggedIn() { return loggedIn != 0; }

  Account &getLoggedInAccount() { return getAccountById(loggedIn); };

  void logOut() { loggedIn = 0; }

  void displayTransactions() {
    cout << "------------------- Transactions -------------------" << endl;
    for (Transaction &trans : transactions) {
      cout << trans;
    }
    cout << "----------------------------------------------------" << endl;
  }

  void deleteAccount(uint64_t id) { map.erase(id); }

private:
  uint64_t totalAccounts{};
  uint64_t loggedIn = 0;
  unordered_map<uint64_t, Account> map;
  vector<Transaction> transactions;
};

// Bank Class Imp End

int main() {
  Bank MainBank;
  MainBank.newAccount("Subhani", 2000);
  MainBank.newAccount("Usman", 0);

  while (1) {
    MainBank.loginAccount();

    if (!MainBank.isLoggedIn())
      break;

    Account &acc = MainBank.getLoggedInAccount();

    while (1) {
      uint64_t opt = 0;
      MainBank.displayOptions();
      cout << "-> ";
      cin >> opt;

      switch (opt) {
      case 1:
        cout << acc;
        break;
      case 2: {
        uint64_t amount = 0;
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        acc.deposit(amount);
      } break;
      case 3: {
        uint64_t amount = 0;
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        try {
          acc.withdraw(amount);
        } catch (runtime_error err) {
          cout << "Error: " << err.what() << endl;
        }
      } break;
      case 4: {
        uint64_t receiver = 0;
        cout << "Enter the recipient's Account No: ";
        cin >> receiver;
        if (!receiver)
          break;

        uint64_t amount = 0;
        cout << "Enter the desired amount: ";
        cin >> amount;

        MainBank.transferMoney(acc.getId(), receiver, amount);

      } break;
      case 0:
        MainBank.logOut();
        break;
      }

      if (!opt)
        break;
    }
  }

  cout << "-------------------- Final Info --------------------" << endl;
  cout << MainBank.getAccountById(1);
  cout << MainBank.getAccountById(2);
  cout << "----------------------------------------------------" << endl;

  MainBank.displayTransactions();

  return 0;
}
