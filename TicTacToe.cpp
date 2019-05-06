// TIC TAC TOE by Pawan Kolhe

#include<iostream>
using namespace std;

char placeholder[10] = {'-', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char place_mark[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int games_played = 0;
int score_p1 = 0;
int score_p2 = 0;

int menu();
void displayMenu();
void playGame();
void displayBoard();
void displayScore();
int checkResult();
void storeResult(char status, int winner);
void resetBoard();
void resetScore();

int main(){
	while(true){
		int option;	
		option = menu();
		
		switch(option){
			case 1:
				resetBoard();
				playGame();
				break;
			case 2:
				resetScore();
				menu();
				break;
			default:
				break;
		}
	}
}

// Runs main menu and returns menu option
int menu(){
	int opt;
	
	displayMenu();
	
	while(cout << "Enter option: " 
	&& cin >> opt 
	&& opt != 1 
	&& opt != 2){
		displayMenu();
	}
	
	return opt;
}

// Displays main menu
void displayMenu(){
	system("cls");
	cout << endl << endl << "\tTIC TAC TOE" << endl << endl;
	displayScore();
	cout << "MENU" << endl << endl;
	cout << "  1. New Game" << endl;
	cout << "  2. Reset Score" << endl << endl;
}

// Starts new game
void playGame(){
	int player = 0, choice, result, mark;
		
	displayBoard();
	
	do{
		player++;
		player = (player % 2) ? 1 : 2;
		
		while((cout << endl << "Player " << player << ": " 
		&& cin >> choice 
		&& choice != 1 
		&& choice != 2 
		&& choice != 3 
		&& choice != 4 
		&& choice != 5 
		&& choice != 6 
		&& choice != 7 
		&& choice != 8 
		&& choice != 9) 
		|| placeholder[choice] == ' '){
			cin.ignore();
			displayBoard();
			cout << endl << "Wrong input! Try again." << endl;
		}
		mark = (player == 1) ? 'X' : 'O';
		place_mark[choice] = mark;
		placeholder[choice] = ' ';
		result = checkResult();
		displayBoard();
	}while(result == -1);
	
	if(result == 1){
		storeResult('W', player);
		displayBoard();
		cout << endl << "Player " << player << " WINS! :D" << endl;
		
		games_played++;
		
		cin.ignore();
		cin.get();
		menu();
	}else{
		storeResult('D', 0);
		displayBoard();
		cout << endl << "Its a DRAW! :\\" << endl;
		
		games_played++;
		
		cin.ignore();
		cin.get();
		menu();
	}
}

// Displays the Tic Tac Toe board
void displayBoard(){
	system("cls");
	cout << endl << endl << "\tTIC TAC TOE" << endl << endl;
	displayScore();
	cout << placeholder[1] << "      |" << placeholder[2] << "      |" << placeholder[3] << "      " << endl;
	cout << "   " << place_mark[1] << "   |   " << place_mark[2] << "   |   " << place_mark[3] << "   " << endl;
	cout << "_______|_______|_______" << endl;
	cout << placeholder[4] << "      |" << placeholder[5] << "      |" << placeholder[6] << "      " << endl;
	cout << "   " << place_mark[4] << "   |   " << place_mark[5] << "   |   " << place_mark[6] << "   " << endl;
	cout << "_______|_______|_______" << endl;
	cout << placeholder[7] << "      |" << placeholder[8] << "      |" << placeholder[9] << "      " << endl;
	cout << "   " << place_mark[7] << "   |   " << place_mark[8] << "   |   " << place_mark[9] << "   " << endl;
	cout << "       |       |       " << endl;
}

void displayScore(){
	cout << "Scoreboard" << endl;
	cout << "____________________________" << endl;
	cout << "|        |   ||   |        |" << endl;
	cout << "| P1 [X] | " << score_p1 << " || " << score_p2 << " | [O] P2 |" << endl;
	cout << "|________|___||___|________|" << endl << endl;
}

// Checks if a players has won after each move
int checkResult(){
	if (place_mark[1] == place_mark[2] && place_mark[2] == place_mark[3] && (place_mark[3] == 'X' || place_mark[3] == 'O'))
        return 1;
    else if (place_mark[4] == place_mark[5] && place_mark[5] == place_mark[6] && (place_mark[6] == 'X' || place_mark[6] == 'O'))
        return 1;
    else if (place_mark[7] == place_mark[8] && place_mark[8] == place_mark[9] && (place_mark[9] == 'X' || place_mark[9] == 'O'))
        return 1;
    else if (place_mark[1] == place_mark[4] && place_mark[4] == place_mark[7] && (place_mark[7] == 'X' || place_mark[7] == 'O'))
        return 1;
    else if (place_mark[2] == place_mark[5] && place_mark[5] == place_mark[8] && (place_mark[8] == 'X' || place_mark[8] == 'O'))
        return 1;
    else if (place_mark[3] == place_mark[6] && place_mark[6] == place_mark[9] && (place_mark[9] == 'X' || place_mark[9] == 'O'))
        return 1;
    else if (place_mark[1] == place_mark[5] && place_mark[5] == place_mark[9] && (place_mark[9] == 'X' || place_mark[9] == 'O'))
        return 1;
    else if (place_mark[3] == place_mark[5] && place_mark[5] == place_mark[7] && (place_mark[7] == 'X' || place_mark[7] == 'O'))
        return 1;
    else if (placeholder[1] == ' ' && placeholder[2] == ' ' && placeholder[3] == ' ' 
                    && placeholder[4] == ' ' && placeholder[5] == ' ' && placeholder[6] == ' ' 
                  && placeholder[7] == ' ' && placeholder[8] == ' ' && placeholder[9] == ' ')
        return 0;
    else
        return -1;
}

// Stores results of each game
void storeResult(char status, int winner){
	if(status == 'W'){
		if(winner == 1)
			score_p1++;
		else if(winner == 2)
			score_p2++;
	}
}

// Resets variables after game ends
void resetBoard(){
	for(int i = 1; i <= 9; i++){
		placeholder[i] = i + 48;
	}
	
	for(int i = 1; i <= 9; i++){
		place_mark[i] = ' ';
	}
}

// Reset score
void resetScore(){
	score_p1 = 0;
	score_p2 = 0;
}
