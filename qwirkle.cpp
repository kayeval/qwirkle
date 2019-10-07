#include <iostream>
#include <

#include "Game.h"
#include "Helper.h"

void displayMenu();
void showStudentInfo();
void loadGameMenu();
void newGameMenu();
void exitGame();
void readFile(std::string filename);

int main(void) {
  std::cout << "Welcome to Qwirkle!\n";
  displayMenu();
  exitGame();

  return EXIT_SUCCESS;
}

void displayMenu() {
  int choice = 0;
  std::string choiceString;
  bool quit = false;

  do {
    std::cout << "\n"
              << "Menu\n"
              << "-------\n"
              << "1. New Game\n"
              << "2. Load Game\n"
              << "3. Show student information\n"
              << "4. Quit\n"
              << "\n> ";

    while (std::cin.peek() == '\n') {
      std::cin.ignore();
    }

    getline(std::cin, choiceString);
    choice = std::stoi(choiceString);

    if (choice == 1)
      newGameMenu();
    else if (choice == 2)
      loadGameMenu();
    else if (choice == 3)
      showStudentInfo();
    else if (choice == 4)
      exitGame();
    else if (std::cin.eof())
      quit = true;
    else
      std::cout << "This option does not exist, please try again\n";

  } while (!quit && choice != 4);
}

void newGameMenu() {
  std::string player1Name;
  std::string player2Name;
  std::cout << "\nStarting a new game of Qwirkle!\n";

  int end1 = 0;
  while (!end1) {
    std::cout << "\nEnter a name for player 1: \n";
    std::cout << "\n> ";

    while (std::cin.peek() == '\n') {
      std::cout << "Please input the name\n> ";
      std::cin.ignore();
    }
    getline(std::cin, player1Name);

    if (!Helper::isASCII(player1Name)) {
      std::cout << "Error: name must only contain letters. Please input your "
                   "name again\n";
      // needs a test case
    } else {
      end1 = 1;
    }
  }

  std::cout << std::endl;

  int end2 = 0;
  while (!end2) {
    std::cout << "\nEnter a name for player 2: \n";
    std::cout << "\n> ";

    while (std::cin.peek() == '\n') {
      std::cout << "Please input the name\n> ";
      std::cin.ignore();
    }

    getline(std::cin, player2Name);

    if (!Helper::isASCII(player2Name)) {
      std::cout << "Error: name must only contain letters. Please input your "
                   "name again\n";
    } else {
      end2 = 1;
    }
  }
  std::cout << std::endl;

  std::cout << "Let's play!" << std::endl;

  Game game(player1Name, player2Name);
  game.run();
}

void loadGameMenu() {
  std::string fileName;
  bool valid = false;
  std::cout << "Enter the name of the file from which to load the game:\n";
  while (!valid) {
    while (std::cin.peek() == '\n') {
      std::cout << "Please input the name of the file\n> ";
      std::cin.ignore();
    }
    getline(std::cin, fileName);
    if (Helper::isValidFormat(fileName)) {
      readFile(fileName);
      Game game("test", "test2");
      std::cout << "Qwirkle game loaded successfully. \n";
      valid = true;
      game.run();
    } else {
      std::cout << "The format of this file is not correct. Please try again\n";
    }
  }
}

void exitGame() { std::cout << "\n\nGoodbye! \n"; }

void showStudentInfo() {
  std::cout << "----------------------------------\n"
            << "Name: Tan Do\n"
            << "Student ID: s3712467\n"
            << "Email: s3712467@student.rmit.edu.au\n"
            << "\n"
            << "Name: Kaye Ng\n"
            << "Student ID: s3766374\n"
            << "Email: s3766374@student.rmit.edu.au\n"
            << "\n"
            << "Name: Ewa Rusiecka\n"
            << "Student ID: s3797191\n"
            << "Email: s3797191@student.rmit.edu.au\n"
            << "\n"
            << "Name: Vincent Gallo\n"
            << "Student ID: s3602478\n"
            << "Email: s3602478@student.rmit.edu.au\n"
            << "----------------------------------\n";
}

void readFile(std::string filename) {
  std::ifstream file(filename);
  std:string line;
  if (file.is_open())
  {
    while (getline(file,line) )
    {
      std::cout << line << '\n';
    }
    file.close();
  }

  else std::cout << "Unable to open file"; 
  
}


