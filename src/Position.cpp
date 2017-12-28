//
// Created by Mathieu on 28/12/2017.
//

#include "../includes/Position.h"

//Construct
Position::Position(){
    m_col = 0;
    m_row = 0;

}

Position::Position(int col, int row) {
    m_col = col;
    m_row = row;

}

//Destruct
Position::~Position(){

}

void Position::operator()()
{
    std::cout << getCol() << ":" << getRow()<<std::endl;
}

bool Position::operator==(Position position) {

    if(m_col == position.getCol() && m_row == position.getRow())
        return true;

    return false;
}

bool Position::operator!=(Position position) {

    if(m_col == position.getCol() && m_row == position.getRow())
        return false;

    return true;
}

//Getter
int Position::getRow(){
    return m_row;
}

int Position::getCol(){
    return m_col;
}

//Setter
void Position::setCol(int col){
    m_col = col;
}

void Position::setRow(int row){
    m_row = row;
}

void Position::placement(int col, int row){
    Position::setCol(col);
    Position::setRow(row);

}

Position Position::traduction(std::string position){
    Position result;
    result = Position();

    if (position.length() == 2)
    {
        if ( ( (int)position.at(0)-65 <= 65 || (int)position.at(0)-65 >= 72 ) && ( (int)position.at(1)-48 <= 48 || (int)position.at(1)-48 >= 56 ) )
        {
            result.placement( ( (int)position.at(0)-65 )+1, ( (int)position.at(1)-48 ) );
        }
        else{
            std::cout << "Probleme with coordinate" << std::endl;
        }

    }
    return result;
}

std::string Position::traduction(Position position){
    std::string result;
    result = std::string();

    result.push_back( (char)(position.getCol()+64) );
    result.push_back( (char)(position.getRow()+48) );
    std::cout << result.at(0) << ":" << result.at(1) << std::endl;

    return result;


}
