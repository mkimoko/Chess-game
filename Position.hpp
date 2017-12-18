#include <iostream>
#include <string>

#ifndef ___POSITION___
#define ___POSITION___

class Position{
	
	private:
		int m_col;
		int m_row;
		
		
	public:
		//Construct - Destruct
		Position();
		~Position();
		
		//Getters
		int getRow();
		int getCol();

	private:
		//Setters
		void setCol(int col);
		void setRow(int row);

	public:
		//Convert: Position -> String
		Position traduction(std::string position);

		//Convert: String -> Position 
		std::string traduction(Position position);

		//Set a position 
		void placement(int col, int row);

		//Print the position
		void operator()();

	};

#endif // ___POSITION___





