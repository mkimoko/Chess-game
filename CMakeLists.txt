cmake_minimum_required(VERSION 3.9)
project(echec)

set(CMAKE_CXX_STANDARD 11)

add_executable(echec main.cpp Position.cpp Position.h Piece.cpp Piece.h Pawn.cpp Pawn.h Rook.cpp Rook.h Bishop.cpp Bishop.h Queen.cpp Queen.h Knight.cpp Knight.h King.cpp King.h Player.cpp Player.h Board.cpp Board.h Out_of_Board.cpp Out_of_Board.h No_Piece.cpp No_Piece.h Obstruction.cpp Obstruction.h Check.cpp Check.h Check_Mate.cpp Check_Mate.h)