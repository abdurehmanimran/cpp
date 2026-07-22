#pragma once

#include <cstdint>
#include <iostream>

using namespace std;

class Account {
public:
  Account() : id(p_id++), balance(0), name("Empty") {};
  Account(string accountName, uint64_t passCode)
      : id{p_id++}, pin(passCode), name{accountName}, balance{0} {};

  void deposit(uint64_t amount);
  int withdraw(uint64_t amount);
  uint64_t getId() const { return id; }
  string getName() const { return name; }
  uint64_t getBalance() const;
  bool matchPin(uint64_t passCode) const;

  friend std::ostream &operator<<(std::ostream &stream, const Account &acc) {
    stream << "ID => " << acc.id << "\t" << "Account Name => " << acc.name
           << "\t"
           << "Balance -> " << acc.balance << endl;
    return stream;
  }

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
