#pragma once

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Account {
public:
  Account();
  Account(string accountName, uint64_t passCode);

  void deposit(uint64_t amount);
  int withdraw(uint64_t amount);
  uint64_t getId() const;
  string getName() const;
  uint64_t getBalance() const;
  bool matchPin(uint64_t passCode) const;

  friend std::ostream &operator<<(std::ostream &stream, const Account &acc);

private:
  uint64_t id;
  uint64_t pin;
  string name;
  uint64_t balance;
  inline static uint64_t p_id = 1;
};

class CheckingAccount : public Account {
public:
  CheckingAccount(string accountName, uint64_t pin, uint64_t chargeFee)
      : Account(accountName, pin), fee(chargeFee) {}

  void deposit(uint64_t amount);
  int withdraw(uint64_t amount);

  friend std::ostream &operator<<(std::ostream &stream,
                                  const CheckingAccount &acc) {
    stream << "ID => " << acc.getId() << "\t" << "Account Name => "
           << acc.getName() << "\t"
           << "Balance -> " << acc.getBalance() << endl;
    return stream;
  }

private:
  uint64_t fee{};
};

// -> Transaction Class <-
class Transaction {
public:
  Transaction(Account &sender, Account &receiver, uint64_t transferAmount);

  friend ostream &operator<<(ostream &stream, const Transaction &transac);

private:
  uint64_t id;
  uint64_t from;
  uint64_t to;
  uint64_t amount;

  inline static uint64_t p_id = 0;
};
// -> Transaction Class <-

// -> Bank Class<-
class Bank {

public:
  Bank();

  void newAccount(string accountName, uint64_t initialDesposit);
  void transferMoney(uint64_t sender, uint64_t receiver, uint64_t amount);
  Account &getAccountById(uint64_t id);

  void displayOptions();
  void loginAccount();
  bool isLoggedIn();
  Account &getLoggedInAccount();

  void logOut();
  void displayTransactions();
  void deleteAccount(uint64_t id);

private:
  uint64_t totalAccounts{};
  uint64_t loggedIn = 0;
  unordered_map<uint64_t, Account> map;
  vector<Transaction> transactions;
};

// -> Bank Class<-
