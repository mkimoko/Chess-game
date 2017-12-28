//
// Created by Mathieu on 28/12/2017.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H

#include <iostream>
#include <string>

class Position {
private:
    int m_col;
    int m_row;


public:
    //Construct - Destruct
    Position();
    Position(int col, int row);
    ~Position();



    //Getters
    int getRow();
    int getCol();

private:
    //Setters
    void setCol(int col);
    void setRow(int row);

public:
    //Convert: Position -> String
    Position traduction(std::string position);

    //Convert: String -> Position
    std::string traduction(Position position);

    //Set a position
    void placement(int col, int row);

    //Print the position
    void operator()();

    //Compare position
    bool operator==(Position position);
    bool operator!=(Position position);

};

#endif //CHESS_POSITION_H
