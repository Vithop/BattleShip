#include <iostream>
#include <ctime>

using namespace std;

const int sizeofboard = 10;
const int numtries = 10;
char board[sizeofboard][sizeofboard];
const int numberofships = 3;

int player1ships[numberofships][2];
int player2ships[numberofships][2];
int player1guess[numtries][2];
int player2guess[numtries][2];




void Printboard(){
    for (int x; x < sizeofboard; x++ ){
        for (int i = 0; i < sizeofboard; ++i) {
            cout << board[x][i] << " ";
        }
        cout << endl;
    }
}


int battleshipcreator(){
    srand(time(NULL));
    return rand() % sizeofboard;
}
void shipassigner(){
    for (int i = 0; i < numberofships ; ++i) {
        for (int j = 0; j <2; ++j) {
            player1ships[i][j] = battleshipcreator();
            player2ships[j][i] = battleshipcreator();
        }
    }
}
int winchecker(){
    int p1wins = 0;
    int p2wins = 0;

    for (int j = 0; j < numtries ; ++j) {
        for (int i = 0; i < numberofships ; ++i) {
            if (player1guess[j][1]==player2ships[i][1]){
                if (player1guess[j][2]==player2ships[i][2]){
                    p1wins++;
                }
            }
            if (player2guess[j][1]==player1ships[i][1]){
                if (player2guess[j][2]==player1ships[i][2]){
                    p2wins++;
                }
            }
        }
    }
    if(p1wins == numberofships){
        return 1;
    }else if(p2wins == numberofships){
        return 2;
    }else{
        return 0;
    }


}
int main() {
    bool p = false;
    for (int x =0; x < sizeofboard; x++ ){
        for (int i = 0; i < sizeofboard; ++i) {
            board[x][i] = 'O';
        }
    }
    cout << "Hello, World! You shall play a game of battleships" <<  endl;
    cout << endl;
    cout << endl;

    shipassigner();
    for (int i = 0; i < numtries; ++i) {
        cout << "Round "<< i+1 <<endl;
        Printboard();
        cout << "Player one choose your attack coordinates" << endl;
        do {
            p = false;
            cout << "Choose Row" << endl;
            cin >> player1guess[i][1];
            cout << "Choose Column" << endl;
            cin >> player1guess[i][2];

            for (int x = 0; x < numberofships; ++x) {
                if (player1guess[i][1] == player1ships[x][1] || player1guess[i][1] > sizeofboard ||
                    player1guess[i][2] > sizeofboard) {
                    if (player1guess[i][2] == player1ships[x][2] || player1guess[i][1] > sizeofboard ||
                        player1guess[i][2] > sizeofboard) {
                        cout << "Wrong Commands Sargent choose different coordinates " << endl;
                        x = numberofships;
                        p = true;
                    }
                }
            }

        }while(p == true);

        board[player1guess[i][1]][player1guess[i][2]] = 'X';
        cout << "Player two choose your attack coordinates" << endl;
        do {
            p = false;
            cout << "Choose Row"<< endl;
            cin >> player2guess[i][1];
            cout << "Choose Column"<< endl;
            cin >> player2guess[i][2];

            for (int x = 0; x < numberofships; ++x) {
                if (player2guess[i][1] == player2ships[x][1] || player2guess[i][1] > sizeofboard ||
                    player2guess[i][2] > sizeofboard) {
                    if (player2guess[i][2] == player2ships[x][2] || player2guess[i][1] > sizeofboard ||
                        player2guess[i][2] > sizeofboard) {
                        cout << "Wrong Commands Sargent choose different coordinates " << endl;
                        x = numberofships;
                        p = true;
                    }
                }
            }
        }while(p == true);
        board[player2guess[i][1]][player2guess[i][2]] = 'X';

        if(winchecker() == 1){
            cout << "player one wins !!!" << endl;
            i = numtries;
        }else if(winchecker() == 2){
            cout << "player two wins !!!" << endl;
            i = numtries;
        }else{
            cout << "victory has yet to be reached, try again commanders" << endl;
            for (int j = 0; j < 10 ; ++j) {
                cout << " " << endl;
            }
        }

    }
    if(winchecker() == 0){
        cout << "You GUYS SUCK IT IS A TIE" << endl;
    }

    return 0;
}