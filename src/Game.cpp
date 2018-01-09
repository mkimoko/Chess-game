//
// Created by Mathieu on 28/12/2017.
//

#include <limits>
#include <chrono>
#include <thread>
#include "../includes/Game.h"
#include "../includes/exception/Check_Mate.h"

Game::Game() {
    m_board = Board();
    m_tour = 1;
}

void Game::print() {
    m_board.printTab();


}


int Game::choice() {

    int choice = 0;
    std::cout << "What do you want to do ? \nPress the option of the action you want to do.\n\n";
    std::cout << "1: Move a piece\n\n2: Move a piece and kill another piece\n\n3: Give up\n\n";

    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while(choice != 1 && choice != 2 && choice != 3 ){
        std::system("cls");
        std::cout << "Error choose an option\n";
        std::cout << "What do you want to do ? \nPress the option of the action you want to do.\n\n";
        std::cout << "1: Move a piece\n\n2: Move a piece and kill another piece\n\n3: Give up\n\n";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return choice;
}

bool Game::action(int id) {
    int choix = choice();
    Position pstart = Position();
    Position pend = Position();
    bool var = false;

        print();
        if( choix == 1){
            do{
                try {
                    var = false;
                    std::cout<<"Choose the position of the piece you want to move\n";
                    pstart = positionChoice();

                    std::cout<<"Choose where you want this piece move\n";
                    pend = positionChoice();

                    var = m_board.deplacement(id,pstart, pend );

                }catch (const std::exception &e){
                    return false;

                }

            }while(pstart == Position(0,0) || pend == Position(0,0) );
        }

        if(choix == 2){
            do{
                try {
                    var = false;
                    std::cout<<"Choose the position of the piece you want to move\n";
                    pstart = positionChoice();

                    std::cout<<"Choose position of the piece you want to kill\n";
                    pend = positionChoice();

                    var = m_board.kill(id,pstart, pend );
                }catch (const std::exception &e){
                    return false;

                }

            }while(pstart == Position(0,0) || pend == Position(0,0) );
        }

        if (choix == 3){
            if (id == 1){
                std::cout << "Player 2 win! Check Mate ! \n";
                m_board.getPlayer2().classement();
                throw Check_Mate();
            }

            if (id == 2){
                std::cout << "Player 1 win! Check Mate ! \n";
                m_board.getPlayer1().classement();
                throw Check_Mate();
            }
        }
    std::system("cls");
    print();
    return var;


}

Position Game::positionChoice() {
    std::string choice = std::string();
    Position result = Position();
    Position tmp = result;
    int exception = 0;
    std::cout << "Choose the position you want (ex: A4 or C6) \n";
    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    do{

        try {
            result = tmp.traduction(choice);

        }catch (const std::exception &e){
            std::system("cls");
            std::cout << e.what();
            std::cout << "Write a correct position\n";
            std::cout << "Choose the position you want (ex: A4 or C6) \n";
            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    }while( result == Position(0,0));

    std::system("cls");
    return result;




}

void Game::play() {

    int id = 1;
    bool act = false;
    bool party_over = false;
    Check_Mate exception = Check_Mate();

    while(party_over == false) {
        if (m_tour % 2 == 1) {
            id = 1;
            std::cout << "Player 1 turn \n";
        }

        if (m_tour % 2 == 0) {
            id = 2;
            std::cout << "Player 2 turn \n";
        }

        try {
            do {
                act = action(id);
                if (act == true){
                    m_tour++;
                }

            } while (act == false);

            if (id == 1) {
                m_board.threatned(2);
                if (m_board.win(2) == true) {
                    std::cout << "Check Mate !\nPlayer 1 win !\n";
                    return;
                }
            }

            if (id == 2) {
                m_board.threatned(1);
                if (m_board.win(1) == true) {
                    std::cout << "Check Mate !\nPlayer 2 win !\n";
                    return;
                }
            }
        } catch (const Check_Mate &e) {
            return;
        }
        catch (const std::exception & exception1){
            exception1.what();
        }
    }
}


