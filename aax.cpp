#include <iostream>
using namespace std;

// Variables
char board[3][3];
string player1, player2;
char symbol1, symbol2;
int turn = 0;

// Functions
void initializeBoard();
void displayBoard();
void getNames();
void chooseSymbol();
void playerMove();
bool checkWinner();
bool checkDraw();

int main()
{
getNames();

chooseSymbol();

initializeBoard();

while (true)
{
    displayBoard();

    playerMove();

    if (checkWinner())
    {
        displayBoard();

        if (turn % 2 == 1)
            cout << "\n" << player1 << " you are success\n";
        else
            cout << "\n" << player2 << " you are success\n";

        break;
    }

    if (checkDraw())
    {
        displayBoard();
        cout << "\nDraw Game\n";
        break;
    }

    turn++;
}

return 0;
}

void getNames()
{
cout << "player one please Enter your name: ";
cin >> player1;

cout << "player two please Enter your name: ";
cin >> player2;
}

void chooseSymbol()
{
while (true)
{
cout << "\n" << player1 << " please choose (x or o)? ";
cin >> symbol1;

    if (symbol1 == 'x' || symbol1 == 'X')
    {
        symbol1 = 'X';
        symbol2 = 'O';
        break;
    }
    else if (symbol1 == 'o' || symbol1 == 'O')
    {
        symbol1 = 'O';
        symbol2 = 'X';
        break;
    }
    else
    {
        cout << "\nplease choose (x or o) only !\n";
    }
}

cout << "\n" << player1 << " You are " << symbol1 << endl;
cout << player2 << " You are " << symbol2 << endl;
}

void initializeBoard()
{
char number = '1';

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        board[i][j] = number++;
    }
}
}

void displayBoard()
{
cout << endl;

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        cout << board[i][j] << " ";
    }
    cout << endl;
}

cout << endl;
}

void playerMove()
{
int position;

if (turn % 2 == 0)
    cout << player1 << " choose position: ";
else
    cout << player2 << " choose position: ";

cin >> position;

while (position < 1 || position > 9)
{
    cout << "invalid position, Try again\n";

    if (turn % 2 == 0)
        cout << player1 << " choose position: ";
    else
        cout << player2 << " choose position: ";

    cin >> position;
}

int row = (position - 1) / 3;
int col = (position - 1) % 3;

while (board[row][col] == 'X' || board[row][col] == 'O')
{
    cout << "invalid position, Try again\n";

    if (turn % 2 == 0)
        cout << player1 << " choose position: ";
    else
        cout << player2 << " choose position: ";

    cin >> position;

    while (position < 1 || position > 9)
    {
        cout << "invalid position, Try again\n";

        if (turn % 2 == 0)
            cout << player1 << " choose position: ";
        else
            cout << player2 << " choose position: ";

        cin >> position;
    }

    row = (position - 1) / 3;
    col = (position - 1) % 3;
}

if (turn % 2 == 0)
    board[row][col] = symbol1;
else
    board[row][col] = symbol2;
}

bool checkWinner()
{
for (int i = 0; i < 3; i)
{
if (board[i][0]== board[i][1] &&
    board[i][1]==board[i][2])


return true;

}

for (int i = 0; i < 3; i++)
{
    if (board[0][i] == board[1][i] &&
        board[1][i] == board[2][i])
        return true;
}

if (board[0][0] == board[1][1] &&
    board[1][1] == board[2][2])
    return true;

if (board[0][2] == board[1][1] &&
    board[1][1] == board[2][0])
    return true;

return false;
}

bool checkDraw()
{
for (int i = 0; i < 3; i)
{
for (int j = 0; j < 3; j++)
{
if (board[i][j] != 'X' && board[i][j] != 'O')
return false;
}
}

return true;
}
