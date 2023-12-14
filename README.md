# blox-fruits-trade-evaluator
Trading evaluator made for Blox Fruits. 

Creates a string map that reads all fruit values from "values.txt" and allows for searching and comparison of specific fruit values.

Inputs consist of command-lines, which are read once "Enter your offer..." is printed. Possible inputs are:

  'print' - prints all fruit values, calls the 'PrintAll()' function
  'quit' - exits
  'trades' - opens "trades.txt" and prints line by line

  *Any other input lines are read as invalid and will prompt the user to provide another input.
  
Functions consist of:

  PrintMessage() - prints initial guide for commands

  PrintAll() - prints all fruit names along with their corresponding values

  ValueComp() - ending evaluation function of trade values, takes two integers 'give' and 'receive' which are the total fruit                  values that you are recieving in exchange for what you're trading away.

  TradeEval() - takes given fruit inputs of respective traders, and searches the value map for each fruit              
                (catches invalid inputs) and provides the final trade evaluation, printing the approximate gain/loss of the
                trade along with both value sums.


Thank you for reading!!!
