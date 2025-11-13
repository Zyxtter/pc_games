#include <iostream>
#include <vector>

using namespace std;

// Функция для отображения игрового поля
void printBoard(const vector<char>& board) {
  cout << "     |     |     " << endl;
  cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  " << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  " << endl;
  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;
  cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  " << endl;
  cout << "     |     |     " << endl;
}

// Функция для проверки, есть ли победитель
char checkWinner(const vector<char>& board) {
  // Проверка строк
  for (int i = 0; i < 3; ++i) {
    if (board[i * 3] != ' ' && board[i * 3] == board[i * 3 + 1] && board[i * 3] == board[i * 3 + 2]) {
      return board[i * 3];
    }
  }

  // Проверка столбцов
  for (int i = 0; i < 3; ++i) {
    if (board[i] != ' ' && board[i] == board[i + 3] && board[i] == board[i + 6]) {
      return board[i];
    }
  }

  // Проверка диагоналей
  if (board[0] != ' ' && board[0] == board[4] && board[0] == board[8]) {
    return board[0];
  }
  if (board[2] != ' ' && board[2] == board[4] && board[2] == board[6]) {
    return board[2];
  }

  // Проверка на ничью
  for (char c : board) {
    if (c == ' ') {
      return ' '; // Есть еще свободные клетки
    }
  }

  return 'T'; // Ничья (Tie)
}

int main() {
  vector<char> board(9, ' '); // Игровое поле
  char currentPlayer = 'X';
  int move;
  char winner = ' ';

  cout << "Game: Tic-tac-toe" << endl;
  cout << "Players take turns entering the cell number (1-9)" << endl;

  while (winner == ' ') {
    printBoard(board);

    cout << "Player's turn " << currentPlayer << ". Enter the cell number (1-9): ";
    cin >> move;
    move--; // Преобразование к индексу массива (0-8)

    if (move < 0 || move > 8 || board[move] != ' ') {
      cout << "Invalid move. Try again." << endl;
      continue;
    }

    board[move] = currentPlayer;
    winner = checkWinner(board);

    // Смена игрока
    if (currentPlayer == 'X') {
    	currentPlayer = 'O';
	}
	else {
		currentPlayer = 'X';
	}
    
  }

  printBoard(board);

  if (winner == 'T') {
    cout << "Tie!" << endl;
  } else {
    cout << "The player " << winner << " won!" << endl;
  }

  return 0;
}
