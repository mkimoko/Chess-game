//
// Created by Mathieu on 23/12/2017.
//

#include "King.h"
#include "Out_of_Board.h"

King::King(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

King::King(int col, int row) {
    m_position = Position(col, row);
    m_nb_moves = 0;
}

int King::getCode() {
    return 6;
}

void King::print(){
    std::cout << "K";
}

int King::deplacement(Position position){

    if( position.getRow() < 1 || position.getRow() > 8 || position.getCol() < 1 || position.getCol() > 8){
        throw Out_of_Board();
    }

    int col_decal = abs( getPosition().getCol()- position.getCol() );
    int row_decal = abs( getPosition().getRow()- position.getRow() );

    switch (col_decal){
        case 1:
            switch (row_decal){
                case 0:

                    /*m_position.placement(position.getCol(), position.getRow());
                    m_nb_moves++;*/

                    return 1;


                case 1:
                    /*m_position.placement(position.getCol(), position.getRow());
                    m_nb_moves++;*/

                    return 1;
            }
            break;

        case 0:
            switch (row_decal){
                case 1:
                    /*m_position.placement(position.getCol(), position.getRow());
                    m_nb_moves++;*/

                    return 1;
            }
            break;

        default:
            return 0;

    }



}

int King::kill(Piece & piece){

    if( piece.getPosition().getRow() < 1 || piece.getPosition().getRow() > 8 || piece.getPosition().getCol() < 1 || piece.getPosition().getCol() > 8){
        throw Out_of_Board();
    }

    int col_decal = abs( getPosition().getCol()- piece.getPosition().getCol() );
    int row_decal = abs( getPosition().getRow()- piece.getPosition().getRow() );

    if ( col_decal == 2 || row_decal == 2){
        if( col_decal == 1 || row_decal == 1 ) {

            /*m_position.placement(piece.getPosition().getCol(), piece.getPosition().getRow());
            m_nb_moves++;*/

            return 1;
        }
    }

    return 0;
}

int King::specialMove(Position position){return 0;}