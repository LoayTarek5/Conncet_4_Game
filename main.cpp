// File: Number_Scrabble.cpp - Game:2
/*
Purpose: scrabble is played with the list of numbers between 1 and 9. Each player takes
turns picking a number from the list. Once a number has been picked, it cannot be picked
again. If a player has picked three numbers that add up to 15, that player wins the game.
However, if all the numbers are used and no player gets exactly 15, the game is a draw.
*/
// Author: Loay Tarek Mostafa El-Nomani
// Version: 4.0
// Date: 2/29/2024


#include <bits/stdc++.h>
using namespace std;

// Global Varialbes
vector<int> number_scrabble_list;
vector<int> player_1, player_2;
// This Flage to To Check the Turn of the Player 1 or 2
bool flag;
string user_input;

void start_game();

// Function to reset global variables
void reset()
{
	number_scrabble_list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	player_1.clear(), player_2.clear();
	flag = false;
}

// Chech For Three number that sum of these is equal to 15
bool sum_three_number(vector<int> player, int n)
{
	int player_list[n];
	// To Determine whick list of player to check
	for (int i = 0; i < n; i++)
		player_list[i] = player.at(i);
	// Sort the list to make to search easier
	sort(player_list, player_list + n);
	// Take Every element and sum it with other two elements
	for (int i = 0; i < n - 2; i++)
	{
		int left = i + 1, right = n - 1;
		while (left < right)
		{
			int total = player_list[i] + player_list[left] + player_list[right];
			// Check if the total of three number is equal to 15
			if (total == 15)
				return true;
			else if (total < 15)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	return false;
}

// Function to check user input
void check_input()
{

	cin >> user_input;
	// This Boolean check if the user input a string or integer
	bool isString = false;
	// loop over the input and check if there any charachter
	for (int i = 0; i < user_input.length(); i++)
	{
		// if we found a charachter we break the loop
		if (isdigit(user_input[i]) != true)
		{
			isString = true;
			break;
		}
	}
	if (isString)
	{
		cout << "Please enter an positive integers only" << endl;
		start_game();
		return;
	}
	int right_input = stoi(user_input);
	auto iterator = find(number_scrabble_list.begin(), number_scrabble_list.end(), right_input);
	if (iterator == number_scrabble_list.end())
	{
		cout << "Please choose a number from the list" << endl;
		start_game();
		return;
	}
	if (flag == true)
	{
		flag = false;
		player_2.push_back(right_input);
	}
	else
	{
		flag = true;
		player_1.push_back(right_input);
	}
	number_scrabble_list.erase(iterator);

	start_game();
}

// Function to ask if the user wants to play again
void play_again()
{
	char again;
	cout << "Do you want to play again? (y/n): ";
	cin >> again;
	if (again == 'y' || again == 'Y')
	{
		reset();
		start_game();
	}
	else
	{
		exit(0);
	}
}

// Function to start the game
void start_game()
{
	if (flag && sum_three_number(player_1, player_1.size()))
	{
		cout << "Player 1 has won!" << endl;
		play_again();
	}
	else if (sum_three_number(player_2, player_2.size()))
	{
		cout << "Player 2 has won!" << endl;
		play_again();
	}
	else if (number_scrabble_list.empty())
	{
		cout << "The game is a draw." << endl;
		play_again();
	}
	if (flag == false)
	{
		cout << "Player 1 will choose: ";
	}
	else
	{
		cout << "Player 2 will choose: ";
	}
	for (int num : number_scrabble_list)
	{
		cout << num << " ";
	}
	cout << endl;
	cout << "Choose: ";
	if (!flag)
	{
		check_input();
	}
	else
	{
		check_input();
	}
}

int main()
{
	// Instruction Of The Game
	cout << "scrabble is played with the list of numbers between 1 and 9.\n"
	"Each player takes turns picking a number from the list.\n"
	"Once a number has been picked, it cannot be pickedagain.\n"
	"If a player has picked three numbers that add up to 15, that player wins the game.\n"
	"However, if all the numbers are used and no player gets exactly 15, the game is a draw.\n";
	reset();
	start_game();
	return 0;
}