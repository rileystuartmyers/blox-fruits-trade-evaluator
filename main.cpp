#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "comps.h"

int main() {

  PrintMessage();

  std::map<std::string, int> values;

  std::ifstream ifs("values.txt");

  std::string value_string;

  while (std::getline(ifs, value_string)) {

    std::istringstream sfs(value_string);

    std::string fruit;
    std::string fruit_value;

    sfs >> fruit;
    sfs >> fruit_value;

    values[fruit] = std::stoi(fruit_value);
  }

  std::string input_string;

  while (true) {

    std::cout << "=================================================="
              << std::endl;
    std::cout << "Enter your offer..." << std::endl << std::endl;
    std::getline(std::cin, input_string);

    if (input_string == "print") {

      PrintAll(values);

    } else if (input_string == "quit") {

      std::cout << "blarg blarg blarg" << std::endl;

      return 0;

    } else if (input_string == "trades") {

      std::ifstream trades("trades.txt");
      std::string temp;

      std::cout << std::endl;

      while (std::getline(trades, temp)) {

        std::cout << temp << std::endl;
      }

      std::cout << std::endl;

    } else if (input_string.length() < 1) {

      std::cout << "Invalid Input!" << std::endl << std::endl;

    } else {

      std::string receiving_string;
      std::cout << "Enter their offer..." << std::endl << std::endl;
      std::getline(std::cin, receiving_string);

      if (receiving_string.length() < 1) {

        std::cout << "Invalid Input!" << std::endl << std::endl;

      } else if (receiving_string == "quit") {

        std::cout << "smushing val rn" << std::endl;

        return 0;

      } else {

        TradeEval(input_string, receiving_string, values);
      }
    }
  }

  return 0;
}
