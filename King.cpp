//
// Created by Mathieu on 23/12/2017.
//

#include "King.h"

King::King(Position position)
{
    m_position = position;
    m_nb_moves = 0;
}

int King::deplacement(Position position){

    int col_decal = abs( getPosition().getCol()- position.getCol() );
    int row_decal = abs( getPosition().getRow()- position.getRow() );

    std::cout << "------------------Before Deplacement King -------------- " << std::endl;
    getPosition()();
    std::cout << "----------------------------------------------------" << std::endl;

    switch (col_decal){
        case 1:
            switch (row_decal){
                case 0:

                    m_position.placement(position.getCol(), position.getRow());
                    m_nb_moves++;
                    std::cout << "--------------During Deplacement King:------------- " << std::endl;
                    getPosition()();
                    std::cout << "----------------------------------------------------" << std::endl;
                    return 1;


                case 1:
                    m_position.placement(position.getCol(), position.getRow());
                    m_nb_moves++;
                    std::cout << "--------------During Deplacement King:------------- " << std::endl;
                    getPosition()();
                    std::cout << "----------------------------------------------------" << std::endl;
                    return 1;
            }
            break;

        case 0:
            switch (row_decal){
                case 1:
                    m_position.placement(position.getCol(), position.getRow());
                    m_nb_moves++;
                    std::cout << "--------------During Deplacement King:------------- " << std::endl;
                    getPosition()();
                    std::cout << "----------------------------------------------------" << std::endl;
                    return 1;
            }
            break;

        default:
            std::cout << "------------------After Deplacement King-------------- " << std::endl;
            getPosition()();
            std::cout << "----------------------------------------------------" << std::endl<< std::endl;
            return 0;

    }



}

int King::kill(Piece & piece){
    int col_decal = abs( getPosition().getCol()- piece.getPosition().getCol() );
    int row_decal = abs( getPosition().getRow()- piece.getPosition().getRow() );

    std::cout << "------------------Before Deplacement King -------------- " << std::endl;
    getPosition()();
    std::cout << "----------------------------------------------------" << std::endl;

    if ( col_decal == 2 || row_decal == 2){
        if( col_decal == 1 || row_decal == 1 ) {

            m_position.placement(piece.getPosition().getCol(), piece.getPosition().getRow());
            m_nb_moves++;
            std::cout << "--------------During Deplacement King:------------- " << std::endl;
            getPosition()();
            std::cout << "----------------------------------------------------" << std::endl;
            return 1;
        }
    }
    std::cout << "------------------After Deplacement King-------------- " << std::endl;
    getPosition()();
    std::cout << "----------------------------------------------------" << std::endl<< std::endl;
    return 0;
}

int King::specialMove(Position position){return 0;}