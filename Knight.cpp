//
// Created by Mathieu on 23/12/2017.
//

#include "Knight.h"

Knight::Knight(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

Knight::Knight(int col, int row) {
    m_position = Position(col, row);
    m_nb_moves = 0;
}

void Knight::print(){
    std::cout << "k";
}

int Knight::deplacement(Position position){

    int col_decal = abs( getPosition().getCol()- position.getCol() );
    int row_decal = abs( getPosition().getRow()- position.getRow() );

    if ( col_decal == 2 || row_decal == 2){
        if( col_decal == 1 || row_decal == 1 ) {

            m_position.placement(position.getCol(), position.getRow());
            m_nb_moves++;
            return 1;
        }
    }

    return 0;

}

int Knight::kill(Piece & piece){
    int col_decal = abs( getPosition().getCol()- piece.getPosition().getCol() );
    int row_decal = abs( getPosition().getRow()- piece.getPosition().getRow() );

    if ( col_decal == 2 || row_decal == 2){
        if( col_decal == 1 || row_decal == 1 ) {

            m_position.placement(piece.getPosition().getCol(), piece.getPosition().getRow());
            m_nb_moves++;
            return 1;
        }
    }
    return 0;
}

int Knight::specialMove(Position position){return 0;}