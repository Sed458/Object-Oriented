//
//  rec03.cpp
//  rec03
//
//  Created by Sophia Danielsen on 9/21/17.
//  Copyright © 2017 Sophia Danielsen. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char randToken(){
    int randNum = rand();
    if (randNum % 10 == 0){
        return '*';
    }
    
    return '-';
}

struct Tile {
    char token = randToken();    // "*" = bomb,  "-" = empty
    int adjBombs;       // Number of bombs touching the tile
    int row;
    int col;
    bool visible = false;
};

struct Board {
    int rowCount;            // Number of rows on the board
    int colCount;            // Number of columns on the board
    vector<vector<Tile>> tiles;  // Tiles on the board
};


class Minesweeper{
public:
    Minesweeper() {
        makeBoard(gameBoard, rowCount, colCount);
        
        for (int row = 0; row < rowCount; row++) {
            for(int column = 0; column < colCount; column++) {
                gameBoard.tiles[row][column].adjBombs = setAdjBombs(gameBoard.tiles[row][column], gameBoard);
            }
        }
    }
    
    // Display board (parameter -> whether to show bombs or not)
    void display(bool showBombs){
        if (showBombs == true) {
            for (int row = 0; row < rowCount; row++) {
                for(int column = 0; column < colCount; column++) {
                    if (gameBoard.tiles[row][column].adjBombs != 0) {
                        cout << gameBoard.tiles[row][column].adjBombs << " ";
                    }
                    else{
                        cout << gameBoard.tiles[row][column].token << " ";
                    }
                }
                cout << endl;
            }
        }
        else {
            for (int row = 0; row < rowCount; row++) {
                for(int column = 0; column < colCount; column++) {
                    if (gameBoard.tiles[row][column].visible == false){
                        cout << '?' << " ";
                    }
                    else{
                        if (gameBoard.tiles[row][column].adjBombs != 0) {
                            cout << gameBoard.tiles[row][column].adjBombs << " ";
                        }
                        else{
                            cout << gameBoard.tiles[row][column].token << " ";
                        }
                    }
                }
                cout << endl;
            }
        }
    }
    
    // Returns true if game is over, false otherwise
    bool done() const {
        return gameFinished;
    }
    
    // Takes a row number and returns true is the row number is valid, false if otherwise
    bool validRow(int rowNum) const {
        if (rowNum >= 0 && rowNum < rowCount) {
            return true;
        }
        return false;
    }
    
    // Takes a column number and returns true if the column number is valid, false if otherwise
    bool validCol(int colNum) const {
        if (colNum >= 0 && colNum < colCount) {
            return true;
        }
        return false;
    }
    
    // Takes a row and column number and returns true if the cell is visible, false if otherwise
    bool isVisible(int rowNum, int colNum) const {
        return gameBoard.tiles[rowNum][colNum].visible;
    }
    
    // Takes a row and column number, makes changes to the board and returns false if the move results in an explosion
    bool play(int rowNum, int colNum) {
        if (gameBoard.tiles[rowNum][colNum].token == '*') {
            gameFinished = true;
            return false;
        }
        
        if (gameBoard.tiles[rowNum][colNum].adjBombs != 0){
            gameBoard.tiles[rowNum][colNum].visible = true;
        }
        
        else {
            gameBoard.tiles[rowNum][colNum].visible = true;
            
            vector<Tile> stack;
            stack.push_back(gameBoard.tiles[rowNum][colNum]);
            
            while (stack.size ()) {
                Tile current = stack.back();
                
                cout << current.adjBombs << " " << gameBoard.tiles[rowNum][colNum].adjBombs << endl;
                
                stack.pop_back();
                
                gameBoard.tiles[current.row][current.col].visible = true;

                //check if tile is already visible
                
                if (current.adjBombs == 0 ) {
                    if (validRow(current.row - 1) && validCol(current.col) == true)
                    {
                        if (gameBoard.tiles[current.row - 1][current.col].token == '-' && gameBoard.tiles[current.row - 1][current.col].visible == false)
                            stack.push_back(gameBoard.tiles[current.row - 1][current.col]);
                    }
                    
                    if (validRow(current.row + 1) && validCol(current.col) == true)
                    {
                        if (gameBoard.tiles[current.row + 1][current.col].token == '-' && gameBoard.tiles[current.row + 1][current.col].visible == false)
                            stack.push_back(gameBoard.tiles[current.row + 1][current.col]);
                    }
                    
                    if (validRow(current.row) && validCol(current.col + 1) == true)
                    {
                        if (gameBoard.tiles[current.row][current.col + 1].token == '-' && gameBoard.tiles[current.row][current.col + 1].visible == false)
                            stack.push_back(gameBoard.tiles[current.row][current.col + 1]);
                    }
                    
                    if (validRow(current.row) && validCol(current.col - 1) == true)
                    {
                        if (gameBoard.tiles[current.row][current.col - 1].token == '-' && gameBoard.tiles[current.row][current.col - 1].visible == false)
                            stack.push_back(gameBoard.tiles[current.row][current.col - 1]);
                    }
                    
                    if (validRow(current.row - 1) && validCol(current.col + 1) == true)
                    {
                        if (gameBoard.tiles[current.row - 1][current.col + 1].token == '-' && gameBoard.tiles[current.row - 1][current.col + 1].visible == false)
                            stack.push_back(gameBoard.tiles[current.row - 1][current.col + 1]);
                    }
                    
                    if (validRow(current.row - 1) && validCol(current.col - 1) == true)
                    {
                        if (gameBoard.tiles[current.row - 1][current.col - 1].token == '-' && gameBoard.tiles[current.row - 1][current.col - 1].visible == false)
                            stack.push_back(gameBoard.tiles[current.row - 1][current.col - 1]);
                    }
                    
                    if (validRow(current.row + 1) && validCol(current.col + 1) == true)
                    {
                        if (gameBoard.tiles[current.row + 1][current.col + 1].token == '-' && gameBoard.tiles[current.row + 1][current.col + 1].visible == false)
                            stack.push_back(gameBoard.tiles[current.row + 1][current.col + 1]);
                    }
                    
                    if (validRow(current.row + 1) && validCol(current.col - 1) == true)
                    {
                        if (gameBoard.tiles[current.row + 1][current.col + 1].token == '-' && gameBoard.tiles[current.row + 1][current.col + 1].visible == false)
                            stack.push_back(gameBoard.tiles[current.row + 1][current.col + 1]);
                    }
                }
            }
        }
        
        
        return true;
    }
    
    
private:
    bool gameFinished = false;
    Board gameBoard;
    int rowCount = 10;
    int colCount = 10;
    int cellCount = 100;            //10 x 10 board has 100 cells (tiles)
    
    void makeBoard(Board& board, int rowCount, int colCount){
        board.rowCount = rowCount;
        board.colCount = colCount;
        
        for (int row = 0; row < rowCount; row++) {
            vector<Tile> rowVector;
            gameBoard.tiles.push_back(rowVector);
            for(int column = 0; column < colCount; column++) {
                Tile tile;
                tile.row = row;
                tile.col = column;
                gameBoard.tiles[row].push_back(tile);
            }
        }
    }
    
    int setAdjBombs(const Tile& tile, const Board& board){
        int numOfNeighbors = 0;
        int row = tile.row;
        int column = tile.col;
        
        if (board.tiles[row][column].token == '*'){
            return numOfNeighbors;
        }
        
        if (validRow(row - 1) && validCol(column) == true)
        {
            if (board.tiles[row - 1][column].token == '*')
                numOfNeighbors++;
        }
        
        if (validRow(row + 1) && validCol(column) == true)
        {
            if (board.tiles[row + 1][column].token == '*')
                numOfNeighbors++;
        }

        if (validRow(row) && validCol(column + 1) == true)
        {
            if (board.tiles[row][column + 1].token == '*')
                numOfNeighbors++;
        }

        if (validRow(row) && validCol(column - 1) == true)
        {
            if (board.tiles[row][column - 1].token == '*')
                numOfNeighbors++;
        }
        
        if (validRow(row - 1) && validCol(column + 1) == true)
        {
            if (board.tiles[row - 1][column + 1].token == '*')
                numOfNeighbors++;
        }
        
        if (validRow(row - 1) && validCol(column - 1) == true)
        {
            if (board.tiles[row - 1][column - 1].token == '*')
                numOfNeighbors++;
        }
        
        if (validRow(row + 1) && validCol(column + 1) == true)
        {
            if (board.tiles[row + 1][column + 1].token == '*')
                numOfNeighbors++;
        }

        if (validRow(row + 1) && validCol(column - 1) == true)
        {
            if (board.tiles[row + 1][column + 1].token == '*')
                numOfNeighbors++;
        }
        
        return numOfNeighbors;
    }
    
    
};

int main() {
    srand (time(NULL));
    
    Minesweeper sweeper;
    sweeper.display(false);
    cout << endl;
    // Continue until the only invisible cells are bombs
    while (!sweeper.done()) {
        sweeper.display(false); // display the board without bombs
        
        int row_sel = -1, col_sel = -1;
        while (row_sel == -1) {
            // Get a valid move
            int r, c;
            cout << "row? ";
            cin >> r;
            if (!sweeper.validRow(r)) {
                cout << "Row out of bounds\n";
                continue;
            }
            cout << "col? ";
            cin >> c;
            if (!sweeper.validCol(c)) {
                cout << "Column out of bounds\n";
                continue;
            }
            if (sweeper.isVisible(r,c)) {
                cout << "Square already visible\n";
                continue;
            }
            row_sel = r;
            col_sel = c;
        }
        
        // Set selected square to be visible. May effect other cells.
        if (!sweeper.play(row_sel,col_sel)) {
            cout << "BOOM!!!\n";
            sweeper.display(true);
            // We're done! Should consider ending more "cleanly",
            // eg. Ask user to play another game.
            exit(0);
        }
    }
    // Ah! All invisible cells are bombs, so you won!
    cout << "You won!!!!\n";
    sweeper.display(true); // Final board with bombs shown
}




