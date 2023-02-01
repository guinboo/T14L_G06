// *******************************************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T14L
// Names: KIRTANAH A/P MANALAN | SHARVINTHIRAN A/L RAJAKUMAR | LAKULESHH LEVIS A/L A.SELVARAJAH
// IDs:       1211102813       |           1211103808        |            1211103794
// Emails: 1211102813@student.mmu.edu.my | 1211103808@student.mmu.edu.my | 1211103794@student.mmu.edu.my
// Phones:   011-2627 8517     |          017-572 1595       |           017-291 0250
// *******************************************************************************************************

#include <iostream>
#include <vector>
using namespace std;
// Using struct to carry multiple variables.
// Also use to make multiple zombies to make new input, (make sure attributes are randomized)
struct Zombies
{
    string identifier;
    int life;
    int attack;
    int range;
};

void displayboard(vector<vector<string>> &gameboard)
{
    int row = gameboard.size();
    int column = gameboard[0].size();
    cout << "=============================================================" << endl;
    for (int i = 0; i < row; i++)
    {

        cout << "|";
        for (int j = 0; j < column; j++)
        {
            cout << " " << gameboard[i][j] << " |";
        }
        cout << endl;
    }
    cout << "=============================================================" << endl;
}

// gameboard creation
vector<vector<string>> gameboard()
{

    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    vector<vector<string>> boardgame(rows, vector<string>(columns));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // set the coordinates of each box format (x,y)
            boardgame[i][j] = to_string(i) + "," + to_string(j);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            // this is to output
            cout << " " << boardgame[i][j] << " ";
        }
        cout << endl;
    }

    return boardgame;
}

vector<Zombies> spawnZombie(vector<vector<string>> &boardgame)
{

    int row, column, amount;
    row = boardgame.size();
    column = boardgame[0].size();

    cout << "How many zombies do you want?";
    cin >> amount;

    vector<Zombies> zombie;
    zombie.resize(amount);

    // amount == 9
    for (int i = 0; i < zombie.size(); i++)
    {
        zombie[i].identifier = "Z" + to_string(i);
        zombie[i].life = rand() % 50 + 20;
        zombie[i].attack = rand() % 10 + 5;
        zombie[i].range = rand() % 3 + 1;
    }

    for (int i = 0; i < zombie.size(); i++)
    {
        int xaxis = rand() % row;
        int yaxis = rand() % column;

        if (boardgame[xaxis][yaxis].find('Z') == string::npos)
        {
            boardgame[xaxis][yaxis] = zombie[i].identifier + " ";
        }
        else
        {
            i--;
        }
    }
    return zombie;
}

void alien(vector<vector<string>> &boardgame, vector<Zombies> &zombie)
{
    int row = boardgame.size();
    int column = boardgame[0].size();

    // vector<Zombies> zombie = zombies;

    int life = 90;
    int attack = 0;
    int AlienRow;
    int AlienColumn;
    string Alien = " A ";

    if (row % 2 == 0)
    {
        AlienRow = row / 2 - 1;
    }
    else
    {
        AlienRow = row / 2;
    }
    if (column % 2 == 0)
    {
        AlienColumn = column / 2 - 1;
    }
    else
    {
        AlienColumn = column / 2;
    }
    system("CLS");
    boardgame[AlienRow][AlienColumn] = Alien;

    // this is our board
    while (true)
    {
        system("CLS");
        displayboard(boardgame);
        cout << "Alien - > "
             << "life:" << life << "  attack:" << attack << endl;
        for (int i = 0; i < zombie.size(); i++)
        {
            cout << "\nZombie " << i + 1 << ":" << endl;
            cout << "Attack: " << zombie[i].attack << endl;
            cout << "Life: " << zombie[i].life << endl;
            cout << "Range: " << zombie[i].range << endl;
        }
        cout << "Enter direction (up,down,left,right): ";
        string input;
        cin >> input;

        if (input == "up")
        {
            if (AlienRow > 0)
            {
                boardgame[AlienRow][AlienColumn] = " . ";
                AlienRow--;
                boardgame[AlienRow][AlienColumn] = Alien;
            }
            else
            {
                cout << "ERROR" << endl;
            }
        }
        else if (input == "down")
        {
            if (AlienRow < row - 1)
            {
                boardgame[AlienRow][AlienColumn] = " . ";
                AlienRow++;
                boardgame[AlienRow][AlienColumn] = Alien;
            }
            else
            {
                cout << "ERROR" << endl;
            }
        }
        else if (input == "left")
        {
            if (AlienColumn > 0)
            {
                boardgame[AlienRow][AlienColumn] = " . ";
                AlienColumn--;
                boardgame[AlienRow][AlienColumn] = Alien;
            }
            else
            {
                cout << "ERROR" << endl;
            }
        }
        else if (input == "left")
        {
            if (AlienColumn > 0)
            {
                boardgame[AlienRow][AlienColumn] = " . ";
                AlienColumn--;
                boardgame[AlienRow][AlienColumn] = Alien;
            }
            else
            {
                cout << "ERROR" << endl;
            }
        }
        else if (input == "right")
        {
            if (AlienColumn < column - 1)
            {
                boardgame[AlienRow][AlienColumn] = " . ";
                AlienColumn++;
                boardgame[AlienRow][AlienColumn] = Alien;
            }
            else
            {
                cout << "ERROR" << endl;
            }
        }
        else
        {
            cout << "OOPS! Invalid move." << endl;
        }
    }
}

int main()
{
    srand(time(NULL));
    vector<vector<string>> startgame = gameboard();
    vector<Zombies> startzombie = spawnZombie(startgame);
    alien(startgame, startzombie);
}
