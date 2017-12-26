cmake_minimum_required(VERSION 3.9)
project(echec)

set(CMAKE_CXX_STANDARD 11)

add_executable(echec main.cpp Position.cpp Position.h Piece.cpp Piece.h Pawn.cpp Pawn.h Rook.cpp Rook.h Bishop.cpp Bishop.h Queen.cpp Queen.h Knight.cpp Knight.h King.cpp King.h Player.cpp Player.h Board.cpp Board.h)