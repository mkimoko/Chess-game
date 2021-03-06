//
// Created by Mathieu on 28/12/2017.
//

#include "../includes/Knight.h"
#include "../includes/exception/Out_of_Board.h"

Knight::Knight(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

Knight::Knight(int col, int row) {
    m_position = Position(col, row);
    m_nb_moves = 0;
}

int Knight::getCode() {
    return 4;
}
void Knight::print(){
    std::cout << "k";
}

int Knight::deplacement(Position position ,int option){

    if( position.getRow() < 1 || position.getRow() > 8 || position.getCol() < 1 || position.getCol() > 8){
        throw Out_of_Board();
    }

    int col_decal = abs( getPosition().getCol()- position.getCol() );
    int row_decal = abs( getPosition().getRow()- position.getRow() );

    if ( col_decal == 2 || row_decal == 2){
        if( col_decal == 1 || row_decal == 1 ) {
            return 1;
        }
    }

    return 0;

}

int Knight::kill(Piece * piece, int option){

    if( piece->getPosition().getRow() < 1 || piece->getPosition().getRow() > 8 || piece->getPosition().getCol() < 1 || piece->getPosition().getCol() > 8){
        throw Out_of_Board();
    }


    int col_decal = abs( getPosition().getCol()- piece->getPosition().getCol() );
    int row_decal = abs( getPosition().getRow()- piece->getPosition().getRow() );

    if ( col_decal == 2 || row_decal == 2){
        if( col_decal == 1 || row_decal == 1 ) {

            return 1;
        }
    }
    return 0;
}

int Knight::specialMove(Position position){return 0;}