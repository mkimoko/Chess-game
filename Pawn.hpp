#include "Piece.hpp"

#ifndef ___PAWN___
#define ___PAWN___


class Pawn : public Piece{
    
    public:
        Pawn(Position position);
        int deplacement(Position position);
        int specialMove(Position position);
        int kill(Piece & piece);
};

#endif // ___PAWN___
