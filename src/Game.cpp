//
// Created by Mathieu on 28/12/2017.
//

#include <limits>
#include "../includes/Game.h"

Game::Game() {
    m_board = Board();
}

void Game::print() {
    m_board.printTab();
    m_tour = 0;

}

int Game::choice() {

    int choice = 0;
    std::cout << "What do you want to do ? \nPress the option of the action you want to do.\n\n";
    std::cout << "1: Move a piece\n\n2: Move a piece and kill another piece\n\n3: Give up\n\n";

    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(choice != 1 && choice != 2 && choice != 3 ){
        std::cout << "Error choose an option\n";
        std::cout << "What do you want to do ? \nPress the option of the action you want to do.\n\n";
        std::cout << "1: Move a piece\n\n2: Move a piece and kill another piece\n\n3: Give up\n\n";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return choice;

}
