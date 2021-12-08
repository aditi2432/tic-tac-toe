#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

using namespace std;

bool check_availibility(char arr[3][3], int i, int j)      //function to check the space availability at the entered indices by the player
{
	if(arr[i][j]=='X' || arr[i][j]=='O')
	{
		return false;
	}
	return true;
}

bool check_winner(char arr[3][3])             // function to check the winner as per the rules
{
	int i=0,j=0;
	for(i=0; i<3; i++)
	{                                    
		if((arr[i][j]==arr[i][j+1]&&arr[i][j+1]==arr[i][j+2]&&arr[i][j+2]=='X')||(arr[i][j]==arr[i][j+1]&&arr[i][j+1]==arr[i][j+2]&&arr[i][j+2]=='O'))
		{
			return true;
		}
	}

	i=0;
	for(j=0; j<3; j++)
	{                                      
	   if((arr[i][j]==arr[i+1][j]&&arr[i+1][j]==arr[i+2][j]&&arr[i+2][j]=='X')||(arr[i][j]==arr[i+1][j]&&arr[i+1][j]==arr[i+2][j]&&arr[i+2][j]=='O'))
	   {
			return true;
		}
	}

	i=0,j=0;
	if((arr[i][j]==arr[i+1][j+1]&&arr[i+1][j+1]==arr[i+2][j+2]&&arr[i+2][j+2]=='X')||(arr[i][j]==arr[i+1][j+1]&&arr[i+1][j+1]==arr[i+2][j+2]&&arr[i+2][j+2]=='O'))
	{
		return true;
	}
		
	if((arr[i][j+2]==arr[i+1][j+1]&&arr[i+1][j+1]==arr[i+2][j]&&arr[i+2][j]=='X')||(arr[i][j+2]==arr[i+1][j+1]&&arr[i+1][j+1]==arr[i+2][j]&&arr[i+2][j]=='O'))
	{
		return true;
	}

   return false; 
} 

void print_grid(char arr[3][3])                                    //function to print the game board after every input by the palyers
{  
	cout<<"\n "<< arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
	cout<<"---|---|---\n";
	cout<<" "<< arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
	cout<<"---|---|---\n";
	cout<<" "<< arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;

}


int main()                                                                 //main funtion 
{
	while(1){
		 
		int rules=0;
		int moves=0;

		cout<<"\n \n                                            Welcome to the game \n" ;
		cout<<"                                    ------------TIC TAC TOE----------- \n  \n";
		cout<<"                              Are you familiar with the rules of the game ?\n";
		cout<<"                                   Press 1 for 'YES' and 2 for 'NO' " ;
		cin>>rules;

		if(rules==2)
		{

			cout<<"Here are the rules for the game:- \n \n";
			cout<<" 1. This game can be played by two players only. \n";
			cout<<" 2. The game will be played on a grid of 3 x 3. \n";
			cout<<" 3. Players have to choose between 'X' & 'O' , \n ";
			cout<<" - if player A chooses 'X' then player B will automatically be given 'O' and vice-versa. \n";
			cout<<" 4. When all the 9 squares are full, game is over. \n \n"; 
		}

		cout<<"NOTE: \n";
		cout<<"Please enter the indices(i,j) of cell of the grid (matrix) to make your move \n";

		cout<<" _________________________\n";
		cout<<"|       |        |        |\n";
		cout<<"| (0,0) |  (0,1) |  (0,2) |\n";  
		cout<<"|_______|________|________|\n";  
		cout<<"|       |        |        |\n"; 
		cout<<"| (1,0) |  (1,1) |  (1,2) |\n"; 
		cout<<"|_______|________|________|\n"; 
		cout<<"|       |        |        |\n"; 
		cout<<"| (2,0) |  (2,1) |  (2,2) |\n"; 
		cout<<"|_______|________|________|\n"; 

		cout<<(" Press ENTER to start the game \n");

		cout<<("\n                 LET THE BATTLE BEGIN                    \n");

		char arr[3][3] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
		char A[20], B[20];
		char playerA, playerB;

		cout<<"\nEnter your name Player A:  ";
		cin>>A;
		cout<<"\nEnter your name Player B:  ";
		cin>>B;
		cout<< endl << A <<" choose between 'X' or 'O' : ";
		cin>>playerA;

		if (toupper(playerA) == 'X')
			playerB = 'O';
		else
			playerB = 'X';

		cout<< endl << B << " is given : "<< playerB << endl;    

		while(moves<9)
		{ 
			int i=0,j=0;
		
			while(1)
			{    
				cout<< endl << A << ", make your move :- "<< endl;
				cout<<"i: ";
				cin>>i;
				cout<<"j: ";
				cin>>j;

				if(i>2 || j>2){
					cout<<"Please enter a valid index\n\n";
				}

				else {
					if(check_availibility(arr,i,j)){
						moves++;
						arr[i][j] = toupper(playerA);
						break;
					}

					else{ 
						cout<<"The position is already occupied , please enter a valid index \n";
					}
				}
			}
		
			print_grid(arr);

			if(moves >3){
				if(check_winner(arr))
				{
					cout<< A <<" is the winner\n";     
					break;
				}
			}
				

			if(moves==9)
			{
				break;
			}
		
			while(1)
			{
				cout<< endl << B << ", make your move :- "<< endl;
				cout<<"i: ";
				cin>>i;
				cout<<"j: ";
				cin>>j;

				if(i>2 || j>2){
					cout<<("Please enter a valid index\n\n");
				}

			   else {
					if(check_availibility(arr,i,j)){
						moves++;
						arr[i][j]= toupper(playerB);
						break;
				}

					else{
						cout<<"The position is already occupied , please enter a valid index \n";
					}
				}
				
			}

			print_grid(arr);
		
			if(check_winner(arr)==true){
				cout<< B <<" is the winner\n";        
				break;
			}
				

		}
		
		if(moves>3){
			if(check_winner(arr)==false)
				cout<<"It's a TIE\n";

		}

		int again;
		cout<<"Do you want to play again ?\n";
		cout<<"1 for 'YES' & 0 for 'NO' :\n";
		cin>>again;

		if(again==1)
			continue;
		
		if(again==0)
			exit(1);

	}

	return 0;
}