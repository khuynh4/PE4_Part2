#include "TicTacToe.h"

TicTacToe::TicTacToe(){
    rows_ = this -> get_rows();
    cols_ = this -> get_cols();
    turn = 0;
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
    std::map<SquareType, std::string> Emojify = {{SquareType::Empty, " 🗆 "}, {SquareType::X, "❌ "}, {SquareType::O, "⭕ "}};
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


Position TicTacToe::GetPlayerChoice(){
    int row = -1;
    int col = -1;
    while((row < 0 || row > rows_) || (col < 0 || col > cols_)){
        std::cout << "Select the Square you wish to mark" << std::endl;
        std::string choice = "";
        std::cin>> choice;

        if(choice == "tl"){
            row = 0;
            col = 0;
            return Position(row, col);
        }
        else if(choice == "tm"){
            row = 0;
            col = 1;
            return Position(row, col);
        }
        else if(choice == "tr"){
            row = 0;
            col = 2;
            return Position(row, col);
        }
        else if(choice == "ml"){
            row = 1;
            col = 0;
            return Position(row, col);
        }
        else if(choice == "mm"){
            row = 1;
            col = 1;
            return Position(row, col);
        }
        else if(choice == "mr"){
            row = 1;
            col = 2;
            return Position(row, col);
        }
        else if(choice == "bl"){
            row = 2;
            col = 0;
            return Position(row, col);
        }
        else if(choice == "bm"){
            row = 2;
            col = 1;
            return Position(row, col);
        }
        else if(choice == "br"){
            row = 2;
            col = 2;
            return Position(row, col);
        }
    }
}


void TicTacToe::PlaceMarker(Position pos, SquareType value){
    set_square_value(pos, value);
}

int main(){
    TicTacToe *b = new TicTacToe();
    SquareType x = SquareType::X;
    SquareType o = SquareType::O;
    b -> create_board();
    b -> DisplayBoard();
    b -> PlaceMarker(b -> GetPlayerChoice(), x);
    b -> DisplayBoard();
    b -> PlaceMarker(b -> GetPlayerChoice(), o);
    b -> DisplayBoard();
    b -> PlaceMarker(b -> GetPlayerChoice(), x);
    b -> DisplayBoard();
    b -> PlaceMarker(b -> GetPlayerChoice(), o);
    b -> DisplayBoard();
    b -> PlaceMarker(b -> GetPlayerChoice(), x);
    b -> DisplayBoard();
    b -> PlaceMarker(b -> GetPlayerChoice(), o);
    b -> DisplayBoard();
    b -> PlaceMarker(b -> GetPlayerChoice(), x);
    b -> DisplayBoard();
    b -> PlaceMarker(b -> GetPlayerChoice(), o);
    b -> DisplayBoard();
    return 0;
}
