#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#ifndef VALUES_H
#define VALUES_H

void PrintMessage() {

  std::cout << "Type 'print' for values, 'trades' to view history, and 'quit' "
               "to exit."
            << std::endl
            << std::endl;
  std::cout << "******Type all fruits in lowercase******" << std::endl
            << std::endl;

  return;
}

void PrintAll(std::map<std::string, int> hashings) {

  for (auto print_cycle = hashings.begin(); print_cycle != hashings.end();
       ++print_cycle) {

    std::cout << print_cycle->first << ": " << print_cycle->second << std::endl;
  }
}

float ValueComp(int give, int receive) {

  float ratio = receive;
  ratio /= give;

  return ratio;
}

void TradeEval(std::string give, std::string receive,
               std::map<std::string, int> hashings) {

  int give_score = 0;
  int receive_score = 0;

  std::istringstream sfs(give);
  std::string temp_string;

  while (sfs >> temp_string) {

    if ((hashings.find(temp_string) == hashings.end())) {

      std::cout << "Invalid Fruit: " << temp_string << "." << std::endl;

      return;

    } else {

      give_score += hashings[temp_string];
    }
  }

  std::istringstream hfs(receive);
  std::string temp_string2;

  while (hfs >> temp_string2) {

    if ((hashings.find(temp_string2) == hashings.end())) {

      std::cout << "Invalid Fruit: " << temp_string2 << "." << std::endl;

      return;

    } else {

      receive_score += hashings[temp_string2];
    }
  }

  if (ValueComp(give_score, receive_score) < 0.80) { // 0 to 0.79

    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "                 CHAT HUGE L" << std::endl;
    std::cout << "Your value: " << give_score
              << ".  Their Value: " << receive_score << ". "
              << std::setprecision(3) << ValueComp(give_score, receive_score)
              << "x original value." << std::endl
              << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl
              << std::endl;

  } else if (ValueComp(give_score, receive_score) < 0.95) { // 0.79 to 0.94

    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "                 CHAT SMALL L" << std::endl;
    std::cout << "Your value: " << give_score
              << ".  Their Value: " << receive_score << ". "
              << std::setprecision(3) << ValueComp(give_score, receive_score)
              << "x original value." << std::endl
              << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl
              << std::endl;

  } else if (ValueComp(give_score, receive_score) < 1.05) { // 0.95 to 1.04

    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "                 CHAT CRAZY TIE" << std::endl;
    std::cout << "Your value: " << give_score
              << ".  Their Value: " << receive_score << ". "
              << std::setprecision(3) << ValueComp(give_score, receive_score)
              << "x original value." << std::endl
              << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl
              << std::endl;

  } else if (ValueComp(give_score, receive_score) < 1.20) { // 1.05 to 1.19

    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "                 CHAT SMALL W" << std::endl;
    std::cout << "Your value: " << give_score
              << ".  Their Value: " << receive_score << ". "
              << std::setprecision(3) << ValueComp(give_score, receive_score)
              << "x original value." << std::endl
              << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl
              << std::endl;

  } else { // 1.19 to inf

    std::cout << "--------------------------------------------------"
              << std::endl;
    std::cout << "                 CHAT HUGE W" << std::endl;
    std::cout << "Your value: " << give_score
              << ".  Their Value: " << receive_score << ". "
              << std::setprecision(3) << ValueComp(give_score, receive_score)
              << "x original value." << std::endl
              << std::endl;
    std::cout << "--------------------------------------------------"
              << std::endl
              << std::endl;
  }

  std::cout << "Save trade? 'y' to save trade, any other key to continue"
            << std::endl
            << std::endl;

  std::string save_string;
  std::getline(std::cin, save_string);

  if (save_string == "y") {

    std::ofstream ofs("trades.txt", std::ios_base::app);
    ofs << give << " -> " << receive << std::endl;

  } else {

    return;
  }
}

#endif
