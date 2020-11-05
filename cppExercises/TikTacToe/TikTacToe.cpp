#include <iostream>
#include <cstdlib>
#include <array>
#include <time.h>
#include <algorithm>
#include <cmath>

using namespace std;

char blocks[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };

void grid()
{
    // Print Grid //
    system("cls");

    cout << "\n\n\ttic-tac-toe \n" << endl;

    cout << "    Get 3 in a row to win" << endl;
    cout << " player_1 (x)   player_2 (o) \n" << endl;

    cout << "\t" << "" << blocks[0] << "  |" << blocks[1] << "  |" << blocks[2] << endl;
    cout << "\t" << "___|___|___" << endl;

    cout << "\t" << "" << blocks[3] << "  |" << blocks[4] << "  |" << blocks[5] << endl;
    cout << "\t" << "___|___|___" << endl;

    cout << "\t" << "" << blocks[6] << "  |" << blocks[7] << "  |" << blocks[8] << endl;
    cout << "\t" << "   |   | " << endl << endl;

}

        ////////////////////////

int win()
{
    if (blocks[0] == blocks[1] && blocks[1] == blocks[2])
    {
        return 1;
    }

    if (blocks[3] == blocks[4] && blocks[4] == blocks[5])
    {
        return 1;
    }

    if (blocks[6] == blocks[7] && blocks[7] == blocks[8])
    {
        return 1;
    }

    if (blocks[0] == blocks[3] && blocks[3] == blocks[6])
    {
        return 1;
    }

    if (blocks[1] == blocks[4] && blocks[4] == blocks[7])
    {
        return 1;
    }

    if (blocks[2] == blocks[5] && blocks[5] == blocks[8])
    {
        return 1;
    }

    if (blocks[0] == blocks[4] && blocks[4] == blocks[8])
    {
        return 1;
    }

    if (blocks[2] == blocks[4] && blocks[4] == blocks[6])
    {
        return 1;
    }

    if (blocks[0] != '0' && blocks[1] != '1' && blocks[2] != '2' && blocks[3] != '3'
        && blocks[4] != '4' && blocks[5] != '5' && blocks[6] != '6' && blocks[7] != '7'
        && blocks[8] != '8')
    {
        return 0;
    }

    else
    {
        return -1;
    }
}

        ////////////////////////

int alphabeta(int depth, int nodeIndex, char blocks[], int alpha, int beta, bool maxPlayer)  // The minimax function
{
    int winner = win();
    int best_score;
    depth = 9;

    if (winner != 1)
    {
        return winner;
    }

    else if (winner != 0)
    {
        return winner;
    }

    else
    {
        if (maxPlayer)
        {
            best_score = INT_MIN;
            for (int i = 0; i < depth; i++)
            {
                if (blocks[i] == i && best_score < beta)
                {
                    int score = alphabeta(depth + 1, nodeIndex, blocks, alpha, beta, false);
                    best_score = max(best_score, score);
                    alpha = max(alpha, best_score);
                    if (alpha >= beta)
                    {
                        break;
                    }
                }
            }
            return best_score;
        }
        else
        {
            best_score = INT_MAX;
            for (int i = 0; i < depth; i++)
            {
                if (blocks[i] == i && best_score > alpha)
                {
                    int score = alphabeta(depth + 1, nodeIndex, blocks, alpha, beta, true);
                    best_score = min(best_score, score);
                    beta = min(beta, best_score);
                    if (beta <= alpha)
                    {
                        break;
                    }
                }
            }
            return best_score;
        }
    }
}

          ////////////////////////

int main()
{
    //char blocks[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8' };
    int player = 1, i, play;

          // Get input //

    char move;

    i = -1;

    do
    {
        grid();

        player = (player % 2) ? 1 : 2;                                                        // ? = conditional = returns one of two values 

        cout << alphabeta(9, 0, blocks, INT_MIN, INT_MAX, true) << "\n\n" << endl;

        cout << "player_" << player << ", enter a corresponding number: ";
        cin >> play;

        move = (player == 1) ? 'x' : 'o';

        if (player == 1)

        {
            if (play == 0 && blocks[0] == '0')
            {
                blocks[0] = move;
            }

            else if (play == 1 && blocks[1] == '1')
            {
                blocks[1] = move;
            }

            else if (play == 2 && blocks[2] == '2')
            {
                blocks[2] = move;
            }

            else if (play == 3 && blocks[3] == '3')
            {
                blocks[3] = move;
            }

            else if (play == 4 && blocks[4] == '4')
            {
                blocks[4] = move;
            }

            else if (play == 5 && blocks[5] == '5')
            {
                blocks[5] = move;
            }

            else if (play == 6 && blocks[6] == '6')
            {
                blocks[6] = move;
            }

            else if (play == 7 && blocks[7] == '7')
            {
                blocks[7] = move;
            }

            else if (play == 8 && blocks[8] == '8')
            {
                blocks[8] = move;
            }

            else
            {
                cout << "\n     That does nothing, sorry.";
                cin.ignore();                                        // ignore input 
                player--;                                            // skip player switch
                cin.get();
            }
        }

        else
        {
           char move = alphabeta(9, 0, blocks, INT_MIN, INT_MAX, true);

           cout << alphabeta(9, 0, blocks, INT_MIN, INT_MAX, true) << endl;

           if (move == 0 && blocks[0] == '0')
           {
               blocks[0] = move;
           }

           else if (move == 1 && blocks[1] == '1')
           {
               blocks[1] = move;
           }

           else if (move == 2 && blocks[2] == '2')
           {
               blocks[2] = move;
           }

           else if (move == 3 && blocks[3] == '3')
           {
               blocks[3] = move;
           }

           else if (move == 4 && blocks[4] == '4')
           {
               blocks[4] = move;
           }

           else if (move == 5 && blocks[5] == '5')
           {
               blocks[5] = move;
           }

           else if (move == 6 && blocks[6] == '6')
           {
               blocks[6] = move;
           }

           else if (move == 7 && blocks[7] == '7')
           {
               blocks[7] = move;
           }

           else if (move == 8 && blocks[8] == '8')
           {
               blocks[8] = move;
           }

           else
           {
               cin.ignore();                                        // ignore input 
               player--;                                            // skip player switch
           }
        }

        i = win();
        player++;
        
    } 
    while (i == -1);
    grid();

          // Create win //
    
    if (i == 1)
    {
        cout << "Player_" << --player << " Has Won" << endl;
    }
    else
    {
        cout << "\t   DRAW" << endl;
    }

	return 0;
}
