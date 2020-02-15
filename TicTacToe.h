#include <iostream>
#include <map> 


enum class SquareType { Empty, X, O };

struct Position{
	int row;
	int col;

	bool operator==(const Position &other) {
		return row == other.row && col == other.col;
	}
	bool operator!=(const Position &other) {
		return !(row == other.row && col == other.col);
	}

	Position():row(0),col(0){}
	Position(const int row_, const int col_):row(row_), col(col_){}
};

std::string SquareTypeStringify(SquareType sq);

class TicTacToe{

public:
	TicTacToe();

 	int get_rows() const {return sizeof(arr_) / sizeof(arr_[0]);}  
 	int get_cols() const {return sizeof(arr_[0]) / sizeof(int);}		

 	SquareType get_square_value(Position pos) const;

	void set_square_value(Position pos, SquareType value);

 	void create_board();
    
    void DisplayBoard();
 	void PlaceMarker(Position pos, SquareType value);

private:
  	SquareType arr_[3][3];
    int turn;
	int rows_; // might be convenient but not necessary
	int cols_;
};