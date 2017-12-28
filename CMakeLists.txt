cmake_minimum_required(VERSION 3.9)
project(Chess)

set(CMAKE_CXX_STANDARD 11)

add_executable(Chess main.cpp includes/Bishop.h includes/Board.h includes/King.h includes/Knight.h includes/Pawn.h includes/Piece.h includes/Player.h includes/Position.h includes/Queen.h includes/Rook.h includes/exception/Check.h includes/exception/Check_Mate.h includes/exception/No_Piece.h includes/exception/Obstruction.h includes/exception/Out_of_Board.h src/Bishop.cpp src/Board.cpp src/Check.cpp src/Check_Mate.cpp src/King.cpp src/Knight.cpp src/No_Piece.cpp src/Obstruction.cpp src/Out_of_Board.cpp src/Pawn.cpp src/Piece.cpp src/Player.cpp src/Position.cpp src/Queen.cpp src/Rook.cpp)