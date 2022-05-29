#include <iostream>
using namespace std;

char board[9] = { '-','-', '-', '-', '-', '-', '-', '-', '-' };

bool has_won(char igrok)
{
    int wins[][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
    for (int i = 0; i < 8; i++)
    {
        int count = 0;
        for (int j = 0; j <= 2; j++)
        {
            if (board[wins[i][j]] == igrok)
                count++;
            if (count == 3)
                return true;
        }
    }
    return false;
}

void print_board()
{
    cout << "Поле битвы:" << endl;
    cout << "_____________" << endl;
    cout << "|-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "-|" << endl;
    cout << "|---|---|---|" << endl;
    cout << "|-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "-|" << endl;
    cout << "|---|---|---|" << endl;
    cout << "|-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "-|" << endl;
    cout << "Действуйте!!! -> " << endl;
}

int get_move()
{
    system("cls");
    setlocale(0, "ru");
    cout << "Розшифрованое поле:" << endl;
    cout << "_____________" << endl;
    cout << "|-7-|-8-|-9-|" << endl;
    cout << "|---|---|---|" << endl;
    cout << "|-4-|-5-|-6-|" << endl;
    cout << "|---|---|---|" << endl;
    cout << "|-1-|-2-|-3-|" << endl;
    cout << endl;

    print_board();

    int move;
    cin >> move;
    while (move > 9 || move < 1 || board[move - 1] != '-')
    {
        cout << "!!!ERROR!!!" << endl;
        cin >> move;
    }
    return move;

}

char play()
{

    int verdict = 0;
    while (!has_won('X') && !has_won('O') && verdict < 9)
    {
        int move = get_move();
        if (verdict % 2 == 0)
        {
            board[move - 1] = 'X';
            if (has_won('X'))
            {
                cout << "Победа за игроком 'X' игрок 'Y' проиграл!" << endl;
                return 'X';
            }
        }
        else
        {
            board[move - 1] = 'O';
            if (has_won('O'))
            {
                cout << "Победа за игроком 'Y' игрок 'X' !" << endl;
                return 'O';
            }
        }

        verdict++;
    }
    cout << "Победитель не обноружен!" << endl;
    return 'D';
}

int main()
{

    system("Title TicTacToe");
    system("color 3");

    play();
    int a;
    cin >> a;
    return 0;
}