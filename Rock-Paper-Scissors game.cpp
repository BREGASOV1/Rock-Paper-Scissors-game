#include<iostream>
#include<cstdlib>

enum enWinner { Player, Computer, Draw };
enum enChoice { Rocket = 1, Paper = 2, Scissors = 3 };
struct stRoundInfo {
	enWinner winner;
	enChoice ComputerChoice;
	enChoice PlayerChoice;
	enWinner RoundResult;
	short RoundNumber;
};
struct stFinalResults {
	short PlayerWins = 0;
	short ComputerWins = 0;
	short Draws = 0;
};
using namespace std;
void Reset() {
	system("cls");
}
int ReadPositiveNumber(string message) {
	int number;
	do
	{
		cout << message;
		cin >> number;

	} while (number <= 0);
	return number;
}
int ReadChoiceNumber() {
	int number;
	do
	{
		cout << "\nChoose what to play:\t";
		cout << "[1] Rocket  [2] Paper  [3] Scissors\n";
		cin >> number;

	} while (number > 3 || number < 1);
	return number;
}
int RandomNumberInRange(int From, int To) {
	int random;
	random = rand() % (To - From) + From;
	return random;
}
enChoice PlayerChoice() {
	return enChoice(ReadChoiceNumber());

}
enChoice CopmuterChoice() {
	return enChoice(RandomNumberInRange(1, 3));
}
string Choice(enChoice Choice) {
	switch (Choice) {
	case Rocket:
		return "Rocket";
		break;
	case Paper:
		return"Paper";
		break;
	case Scissors:
		return "Scissors";
		break;
	}
}
string Result(enWinner Result) {
	switch (Result)
	{
	case Player:
		return "Player";
		break;
	case Computer:
		return "Computer";
		break;
	case Draw:
		return "Draw";
		break;

	}
}
enWinner RoundResult(stRoundInfo RoundInfo) {
	int result = (int)RoundInfo.PlayerChoice - (int)RoundInfo.ComputerChoice;
	switch (result) {
	case 0:
		system("color 6F");
		return Draw;
		break;
	case (1 || -2):
		system("color 2F");
		return Player;
		break;
	case 2:
		system("color 4F");
		cout << "\a";
		return Computer;
		break;
	default:
		system("color 4F");
		return Computer;
	}
}
string FinalWinner(stFinalResults FinalResults) {
	if (FinalResults.PlayerWins == FinalResults.ComputerWins)
		return "Draw";
	else if (FinalResults.PlayerWins > FinalResults.ComputerWins)
		return "Player";
	else
		return "Computer";

}
void PrintSingleRoundStatics(stRoundInfo RoundInfo) {
	cout << "\n-----------------Round[" << RoundInfo.RoundNumber << "]-----------------";
	cout << "\nPlayer Choice: " << Choice(RoundInfo.PlayerChoice);
	cout << "\nComputer Choice: " << Choice(RoundInfo.ComputerChoice);
	cout << "\nRound Winner: [" << Result(RoundInfo.RoundResult) << "]";
	cout << "\n------------------------------------------";
}
void FinalStatics(int NumberOFRounds, stFinalResults FinalResults) {
	system("color 0F");
	cout << "\n--------------------------------------------------------------";
	cout << "\n                   *** G a m e  O v e r ***                   ";
	cout << "\n--------------------------------------------------------------";
	cout << "\n------------------ [Game Results] ---------------------";
	cout << "\nGame Rounds         : " << NumberOFRounds;
	cout << "\nPlayers Wins Times  : " << FinalResults.PlayerWins;
	cout << "\nComputer Wins Times : " << FinalResults.ComputerWins;
	cout << "\nDraw Times          : " << FinalResults.Draws;
	cout << "\nFinal Winner        : " << FinalWinner(FinalResults);
}
void Rounds(int NumberOfRounds) {
	stRoundInfo RoundInfo;
	stFinalResults FinalResults;
	for (int i = 1; i <= NumberOfRounds; i++)
	{
		system("color 0F");
		cout << "\nRound[" << i << "] begins:";
		RoundInfo.RoundNumber = i;
		RoundInfo.PlayerChoice = PlayerChoice();
		RoundInfo.ComputerChoice = CopmuterChoice();
		RoundInfo.RoundResult = RoundResult(RoundInfo);
		switch (RoundInfo.RoundResult) {
		case Player:
			FinalResults.PlayerWins++;
			break;
		case Computer:
			FinalResults.ComputerWins++;
			break;
		case Draw:
			FinalResults.Draws++;
			break;
		}
		PrintSingleRoundStatics(RoundInfo);




	}
	FinalStatics(NumberOfRounds, FinalResults);


}
void OurGame() {
	int NumberOfRounds;
	bool PlayAgain;
	do
	{
		Reset();
		NumberOfRounds = ReadPositiveNumber("\nHow many rounds you want to play? ");
		Rounds(NumberOfRounds);
		cout << "\nDo you want to play again? [1] Yes    [0] No" << endl;
		cin >> PlayAgain;

	} while (PlayAgain);

}

int main() {
	srand((unsigned)time(NULL));
	OurGame();
}