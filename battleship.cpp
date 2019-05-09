/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "battleship.h"
CellContent _my_field[FIELDSIZE][FIELDSIZE];
CellContent _other_field[FIELDSIZE][FIELDSIZE];
CellContent _my_guess[FIELDSIZE][FIELDSIZE];

void load_game(){
  FILE* myShip = fopen("battleship.my", "rw");
  FILE* otherShip = fopen("battleship.op", "rw");

  for (int i = 0; i < FIELDSIZE; i++) {
    for (int j = 0; j < FIELDSIZE; j++) {
      fread(&_my_field[i][j], sizeof(CellContent), 1, myShip);
      fread(&_other_field[i][j], sizeof(CellContent), 1, otherShip);
      _my_guess[i][j] = Unknown;
    }
  }
}

CellContent get_shot(int row, int col){
  if (row >= FIELDSIZE || col >= FIELDSIZE || col < 0 || row < 0) {
    return OutOfRange;
  }
  return _my_field[row][col];
}
void fill(int row, int col){
  if (row >= FIELDSIZE || col >= FIELDSIZE || col < 0 || row < 0) {
    return;
  }
  _my_guess[row][col] = Water;
}
bool shoot(int row, int col){
  if (row >= FIELDSIZE || col >= FIELDSIZE || col < 0 || row < 0) {
    return false;
  }
  _my_guess[row][col] = _other_field[row][col];
  fill(row+1, col);
  fill(row+1, col+1);
  fill(row, col+1);
  fill(row-1, col);
  fill(row-1, col-1);
  fill(row-1, col+1);
  fill(row+1, col-1);
  fill(row, col-1);
  return true;
}

CellContent get_my_guess(int row, int col){
  if (row >= FIELDSIZE || col >= FIELDSIZE || col < 0 || row < 0) {
    return OutOfRange;
  }
  return _my_guess[row][col];
}

#include "battleship.h"
