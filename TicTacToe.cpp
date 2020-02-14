#include "TicTacToe.h"

TicTacToe::TicTacToe(){
    rows_ = this -> get_rows();
    cols_ = this -> get_cols();
    return;
}

SquareType TicTacToe::get_square_value(Position pos) const{
    if((pos.row >= 0 && pos.row <rows_) && (pos.col >= 0 && pos.col < cols_)){
        return arr_[pos.row][pos.col];
    }
  
    return SquareType::Empty;
}

void TicTacToe::set_square_value(Position pos, SquareType value){
    if( (pos.row >= 0 && pos.row <rows_) && (pos.col >= 0 && pos.col < cols_)){
        arr_[pos.row][pos.col] = value;
    }
    return;
}

void TicTacToe::create_board(){
    for(int i = 0; i < rows_; i++){
        for(int j = 0; j < cols_; j++){
            Position new_pos = Position(i, j);
            this -> set_square_value(new_pos, SquareType::Empty);
        }
    }
}

std::string SquareTypeStringify(SquareType sq){
    std::map<SquareType, std::string> Emojify = {{SquareType::Empty, "🗆"}, {SquareType::X, "❌"}, {SquareType::O, "⭕"}};
    return Emojify[sq];
}

void TicTacToe::DisplayBoard(){
    std::string b;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            b = SquareTypeStringify(this -> get_square_value(Position(i, j)));
            std::cout << b;
        }
        std::cout << std::endl;
    }
}

int main(){
    TicTacToe *b = new TicTacToe();
    b -> create_board();
  
    return 0;
}