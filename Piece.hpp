
#include "Position.hpp"

#ifndef ___PIECE___
#define ___PIECE___

class Piece{

    protected:

		Position  m_position;
        int m_nb_moves; // number of player's move with this piece
        
    public: 
        ~Piece();
        Position & getPosition();
        int getNbMoves();
        virtual int deplacement(Position position) = 0; 
        virtual int specialMove(Position position) = 0;
        virtual int kill(Piece & piece) = 0;
    

};

#endif // ___PIECE___
