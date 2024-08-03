//Snake And Ladder game
//Header files
#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>
#include<ctime>
using namespace std;

//function prototypes
void interface();
void info();
void start(int );
int random_gen(int );
void check_L_S (int &);
void board(char [], char []);  
void board(char [], char [], char []); 
void board(char [], char [], char [], char []);

int main()
{
	interface(); // calling the interface function
	
	int selection=0; //variable to store user selection
	cout<<"Enter the mode (number) : ";
	cin>>selection; //taking selection from user
	
	// if selection is wrong  while loop is used
	while(selection <=0 || selection >4)
	{
		cout<<"Sorry! selected mode "<<selection<<" do not exist."<<endl;
		cout<<"Select mode between 1 and 4 again: ";
		cin>>selection; //Getting again selection
	}
	cin.ignore(); //to avoid getline error
	cout<<endl<<endl;
	system("CLS"); 
	
	string p1, p2, p3, p4; //to store players name
	
	//to store postion
	char player_1[100];  
	char player_2[100];
	char player_3[100];
	char player_4[100];
	
	if (selection == 1) //if selection selected (2 player)
	{
		cout<<"\t =========================================================="<<endl;
		cout<<"\t|                                                          |"<<endl;
		cout<<"\t|            Read the instructions carefully!!!!           |"<<endl;
		cout<<"\t|      Player 1 position is indicated by 'A' on board.     |"<<endl;
		cout<<"\t|      Player 2 position is indicated by 'B' on board.     |"<<endl;
		cout<<"\t|                                                          |"<<endl;
		cout<<"\t =========================================================="<<endl<<endl;
		
		info(); //showing snake and ladder info
		
		system("PAUSE"); 
	    system("CLS");   //Clearing the sreen
		
		cout<<"Enter player 1 name: ";
		getline(cin,p1); //Getting player1 name
		cout<<"Enter player 2 name: ";
		getline(cin,p2); //Getting player2 name
		cout<<endl<<endl;
		
		start(selection); //Passing selection that will display as mode in start function
	    system("PAUSE"); 
	    system("CLS");   //Clearing the sreen
	    
	    int player1 =0, player2 =0;
	    int random_collect=0;
	    
	    while(player1<=100 || player2<=100) //using while loop  
	    {
		    for (int i=0; i<100; i++) //using for loop to store white space in player arrays
	        {
		        player_1[i]=' ';
		        player_2[i]=' ';
	        }
	        
		    cout<<p1<<" press any charater to roll dice: "<<endl;
		    getch(); //stoping screen 
		    cout<<endl;
		    random_collect=random_gen(random_collect);
		    cout<<"You got "<<random_collect<<" score on rolling dice."<<endl;
		    player1 += random_collect;                                //storing the generated random in player1 variable
		    random_collect=0;                                         // storing 0 for next time random
		    check_L_S (player1);                                      // calling check_L_S function and passing player1 which is storing postion of player
		    cout<<"Player 1 current score: "<<player1;                //displaying socre which is position
		    player_1[player1]='A';                                    //updating position and assining charater for to show on board
		    cout<<endl<<endl;
		
		    if (player1>=100) // condition to show winner when 100 or more than 100
		    {
		    	cout<<"\t*******************************"<<endl;
			    cout<<"\t\t "<<p1<<" is winner!!!!"<<endl;
			    cout<<"\t"<<"*******************************"<<endl;
			    
			    player_1[100]='A';
		        player_2[player2]='B';
		        board(player_1, player_2);
			     
			    break; //using break to get out of loop
		    }
		
		    cout<<p2<<" press any charater to roll dice: "<<endl;
		    getch(); //stoping screen
		    cout<<endl;
		    random_collect=random_gen(random_collect);
		    cout<<"You got "<<random_collect<<" score on rolling dice."<<endl;
		    player2 += random_collect;                              //storing the generated random in player2 variable
		    random_collect=0;                                       // storing 0 for next time random
		    check_L_S (player2);                                    // calling check_L_S function and passing player2 which is storing postion of player
		    cout<<"Player 2 current score: "<<player2;              //displaying socre which is position
		    player_2[player2]='B';                                  //updating position and assining charater for to show on board
		    cout<<endl<<endl;
		
	        if (player2>=100) // condition to show winner when 100 or more than 100
		    {
		    	cout<<"\t*******************************"<<endl;
			    cout<<"\t\t "<<p2<<" is winner!!!!"<<endl;
			    cout<<"\t"<<"*******************************"<<endl;
			    
			    player_1[player1]='A';
		        player_2[100]='B';
		        board(player_1, player_2);
		        
			    break; //using break to get out of loop
		    }
		    
		board(player_1,player_2); //showing positions of players
		system("PAUSE"); 
		system("CLS"); //clearing screen
		
	    }
	}
	else if (selection == 2) //if selection selected (3 player)
	{
		cout<<"\t =========================================================="<<endl;
		cout<<"\t|                                                          |"<<endl;
		cout<<"\t|            Read the instructions carefully!!!!           |"<<endl;
		cout<<"\t|      Player 1 position is indicated by 'A' on board.     |"<<endl;
		cout<<"\t|      Player 2 position is indicated by 'B' on board.     |"<<endl;
		cout<<"\t|      Player 3 position is indicated by 'C' on board.     |"<<endl;
		cout<<"\t|                                                          |"<<endl;
		cout<<"\t =========================================================="<<endl<<endl;
		
		info(); //showing snake and ladder info
		
		system("PAUSE"); 
	    system("CLS");   //Clearing the sreen
	    
		cout<<"Enter player 1 name: ";
		getline(cin,p1); //Getting player1 name
		cout<<"Enter player 2 name: ";
		getline(cin,p2); //Getting player2 name
		cout<<"Enter player 3 name: ";
		getline(cin,p3); //Getting player3 name
		cout<<endl<<endl;
		start(selection); //Passing selection that will display as mode in start function
	    system("PAUSE"); 
	    system("CLS"); //clearing screen
	    
	    int player1 =0, player2 =0, player3 =0;
	    int random_collect=0;
	    
	    while(player1<=100 || player2<=100 || player3<=100) //using while loop
	    {
		    for (int i=0; i<100; i++) //using for loop to store white space in player arrays
	        {
		        player_1[i]=' ';
		        player_2[i]=' ';
		        player_3[i]=' ';
	        }
		    cout<<p1<<" press any charater to roll dice: "<<endl;
		    getch();       //stoping screen
		    cout<<endl;
		    random_collect=random_gen(random_collect);
		    cout<<"You got "<<random_collect<<" score on rolling dice."<<endl;
		    player1 += random_collect;                   //storing the generated random in player1 variable
		    random_collect=0;                            // storing 0 for next time random
		    check_L_S (player1);                         // calling check_L_S function and passing player1 which is storing postion of player
		    cout<<"Player 1 current score: "<<player1;   //displaying socre which is position
		    player_1[player1]='A';                       //updating position and assining charater for to show on board
		    cout<<endl<<endl;
		
		    if (player1>=100) // condition to show winner when 100 or more than 100
		    {
			    cout<<"\t*******************************"<<endl;
			    cout<<"\t\t "<<p1<<" is winner!!!!"<<endl;
			    cout<<"\t"<<"*******************************"<<endl;
			    
			    player_1[100]='A';
		        player_2[player2]='B';
		        player_3[player3]='C';
		        board(player_1, player_2, player_3);
		        
			    break;
		    }
		
		    cout<<p2<<" press any charater to roll dice: "<<endl;
		    getch();
		    cout<<endl;
		    random_collect=random_gen(random_collect);
		    cout<<"You got "<<random_collect<<" score on rolling dice."<<endl;
		    player2 += random_collect;                    //storing the generated random in player2 variable
		    random_collect=0;                             // storing 0 for next time random
		    check_L_S (player2);                          // calling check_L_S function and passing player2 which is storing postion of player
		    cout<<"Player 2 current score: "<<player2;    //displaying socre which is position
		    player_2[player2]='B';                        //updating position and assining charater for to show on board
		    cout<<endl<<endl;
		
	        if (player2>=100) // condition to show winner when 100 or more than 100
		    {
			    cout<<"\t*******************************"<<endl;
			    cout<<"\t\t "<<p2<<" is winner!!!!"<<endl;
			    cout<<"\t"<<"*******************************"<<endl;
			    //showing the positions too  
			    player_1[player1]='A';
		        player_2[100]='B';
		        player_3[player3]='C';
		        board(player_1, player_2, player_3);
		        
			    break;
		    }
		    
		    cout<<p3<<" press any charater to roll dice: "<<endl;
		    getch();
		    cout<<endl;
		    random_collect=random_gen(random_collect);
		    cout<<"You got "<<random_collect<<" score on rolling dice."<<endl;
		    player3 += random_collect;                               //storing the generated random in player3 variable
		    random_collect=0;                                        // storing 0 for next time random
		    check_L_S (player3);                                     // calling check_L_S function and passing player3 which is storing postion of player
		    cout<<"Player 3 current score: "<<player3;               //displaying socre which is position
		    player_3[player3]='C';                                   //updating position and assining charater for to show on board
		    cout<<endl<<endl;
		
	        if (player3>=100) // condition to show winner when 100 or more than 100
		    {
			    cout<<"\t*******************************"<<endl;
			    cout<<"\t\t "<<p3<<" is winner!!!!"<<endl;
			    cout<<"\t"<<"*******************************"<<endl;
			    
			    player_1[player1]='A';
		        player_2[player2]='B';
		        player_3[100]='C';
		        board(player_1, player_2, player_3);
		        
			    break;
		    }
		    
		board(player_1,player_2,player_3); //showing positions of players
		
		system("PAUSE"); 
		system("CLS"); //clearing screen
		
	    }
	}
	else if (selection == 3) //if selection selected (4 player)
	{
		cout<<"\t =========================================================="<<endl;
		cout<<"\t|                                                          |"<<endl;
		cout<<"\t|            Read the instructions carefully!!!!           |"<<endl;
		cout<<"\t|      Player 1 position is indicated by 'A' on board.     |"<<endl;
		cout<<"\t|      Player 2 position is indicated by 'B' on board.     |"<<endl;
		cout<<"\t|      Player 3 position is indicated by 'C' on board.     |"<<endl;
		cout<<"\t|      Player 4 position is indicated by 'D' on board.     |"<<endl;
		cout<<"\t|                                                          |"<<endl;
		cout<<"\t =========================================================="<<endl<<endl;
		
		info(); //showing snake and ladder info
		
		system("PAUSE"); 
	    system("CLS");   //Clearing the sreen
	    
		cout<<"Enter player 1 name: ";
		getline(cin,p1); //Getting player1 name
		cout<<"Enter player 2 name: ";
		getline(cin,p2); //Getting player2 name
		cout<<"Enter player 3 name: ";
		getline(cin,p3); //Getting player3 name
		cout<<"Enter player 4 name: ";
		getline(cin,p4); //Getting player4 name
		cout<<endl<<endl;
		start(selection); //Passing selection that will display as mode in start function
	    system("PAUSE"); 
	    system("CLS"); //clearing screen
	    
	    int player1 =0, player2 =0, player3 =0, player4 =0;
	    int random_collect=0; // storing 0 for next time random
	    
	    while(player1<=100 || player2<=100 || player3<=100)
	    {
		    for (int i=0; i<100; i++) //using for loop to store white space in player arrays
	        {
		        player_1[i]=' ';
		        player_2[i]=' ';
		        player_3[i]=' ';
		        player_4[i]=' ';
	        }
		    cout<<p1<<" press any charater to roll dice: "<<endl;
		    getch(); //stoping screen
		    cout<<endl;
		    random_collect=random_gen(random_collect);
		    cout<<"You got "<<random_collect<<" score on rolling dice."<<endl;
		    player1 += random_collect;                      //storing the generated random in player1 variable
		    random_collect=0;                               // storing 0 for next time random
		    check_L_S (player1);                            // calling check_L_S function and passing player1 which is storing postion of player
		    cout<<"Player 1 current score: "<<player1;      //displaying socre which is position
		    player_1[player1]='A';                          //updating position and assining charater for to show on board
		    cout<<endl<<endl;
		
		    if (player1>=100) // condition to show winner when 100 or more than 100
		    {
			    cout<<"\t*******************************"<<endl;
			    cout<<"\t\t "<<p1<<" is winner!!!!"<<endl;
			    cout<<"\t"<<"*******************************"<<endl;
			    
			    player_1[100]='A';
		        player_2[player2]='B';
		        player_3[player3]='C';
		        player_4[player4]='D';
		        board(player_1, player_2, player_3, player_4);
		        
			    break;
		    }
		
		    cout<<p2<<" press any charater to roll dice: "<<endl;
		    getch();
		    cout<<endl;
		    random_collect=random_gen(random_collect);
		    cout<<"You got "<<random_collect<<" score on rolling dice."<<endl;
		    player2 += random_collect;                           //storing the generated random in player2 variable
		    random_collect=0;                                    // storing 0 for next time random
		    check_L_S (player2);                                 // calling check_L_S function and passing player2 which is storing postion of player
		    cout<<"Player 2 current score: "<<player2;           //displaying socre which is position
		    player_2[player2]='B';                               //updating position and assining charater for to show on board
		    cout<<endl<<endl;
		
	        if (player2>=100) // condition to show winner when 100 or more than 100
		    {
			    cout<<"\t*******************************"<<endl;
			    cout<<"\t\t "<<p2<<" is winner!!!!"<<endl;
			    cout<<"\t"<<"*******************************"<<endl;
			    
			    player_1[player1]='A';
		        player_2[100]='B';
		        player_3[player3]='C';
		        player_4[player4]='D';
		        board(player_1, player_2, player_3, player_4);
		        
			    break;
		    }
		    
		    cout<<p3<<" press any charater to roll dice: "<<endl;
		    getch();
		    cout<<endl;
		    random_collect=random_gen(random_collect);
		    cout<<"You got "<<random_collect<<" score on rolling dice."<<endl;
		    player3 += random_collect;                         //storing the generated random in player3 variable
		    random_collect=0;                                  // storing 0 for next time random
		    check_L_S (player3);                               // calling check_L_S function and passing player3 which is storing postion of player
		    cout<<"Player 3 current score: "<<player3;         //displaying socre which is position
		    player_3[player3]='C';                             //updating position and assining charater for to show on board
		    cout<<endl<<endl;
		
	        if (player3>=100) // condition to show winner when 100 or more than 100
		    {
			    cout<<"\t*******************************"<<endl;
			    cout<<"\t\t "<<p3<<" is winner!!!!"<<endl;
			    cout<<"\t"<<"*******************************"<<endl;
			    
			    player_1[player1]='A';
		        player_2[player2]='B';
		        player_3[100]='C';
		        player_4[player4]='D';
		        board(player_1, player_2, player_3, player_4);
		        
			    break;
		    }
		    
		    cout<<p4<<" press any charater to roll dice: "<<endl;
		    getch();
		    cout<<endl;
		    random_collect=random_gen(random_collect);
		    cout<<"You got "<<random_collect<<" score on rolling dice."<<endl;
		    player4 += random_collect;                      //storing the generated random in player4 variable
		    random_collect=0;                               // storing 0 for next time random
		    check_L_S (player4);                            // calling check_L_S function and passing player4 which is storing postion of player
		    cout<<"Player 4 current score: "<<player4;      //displaying socre which is position
		    player_4[player4]='D';                          //updating position and assining charater for to show on board
		    cout<<endl<<endl;
		
	        if (player4>=100) // condition to show winner when 100 or more than 100
		    {
			    cout<<"\t*******************************"<<endl;
			    cout<<"\t\t "<<p2<<" is winner!!!!"<<endl;
			    cout<<"\t"<<"*******************************"<<endl;
			    
			    player_1[player1]='A';
		        player_2[player2]='B';
		        player_3[player3]='C';
		        player_4[100]='D';
		        board(player_1, player_2, player_3, player_4);
		        
			    break;
		    }
		    
		board(player_1,player_2,player_3,player_4); //showing positions of players
		
		system("PAUSE"); 
		system("CLS");
		
	    }
	    
	}
	else if (selection == 4) //exit condition
		{
			return 0;
		}
	
	return 0;
}

void interface() //function to show starting interface
{
	cout<<"\t============================================================"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|                SNAKE AND LADDER GAME                     |"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|----------------------------------------------------------|"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|                   !! Rules !!                            |"<<endl;
	cout<<"\t|       1. Roll dice by pressing any charater.             |"<<endl;
	cout<<"\t|       2. Three six will result in 0 score.               |"<<endl;
	cout<<"\t|       3. Ladder will boost your score.                   |"<<endl;
	cout<<"\t|       4. Snake will reduce your score.                   |"<<endl;
	cout<<"\t|       5. The one who will make hundred will be winner.   |"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|----------------------------------------------------------|"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|                  !!  Select Mode  !!                     |"<<endl;
	cout<<"\t|          Press 1 to play Two players game                |"<<endl;
	cout<<"\t|          Press 2 to play three players game              |"<<endl;
	cout<<"\t|          Press 3 to play four players game               |"<<endl;
	cout<<"\t|          Press 4 to exit game                            |"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t============================================================"<<endl;
	cout<<endl<<endl;
}

void start(int select) //function to show starting of game
{
    cout<<"\t============================================================"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|            Game Started  in mode "<<select<<"                       |"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t============================================================"<<endl;
	cout<<endl<<endl;
}

void info() // function to show positions of snakes and ladders
{
	cout<<"\t =========================================================="<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|             Positions of Ladders are:                    |"<<endl;
	cout<<"\t|             1. Ladder (L1) at 13 to 57                   |"<<endl;
	cout<<"\t|             2. Ladder (L2) at 36 to 62                   |"<<endl;
	cout<<"\t|             3. Ladder (L3) at 53 to 93                   |"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|----------------------------------------------------------|"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t|             Positions of Snakes are:                     |"<<endl;
	cout<<"\t|             1. Snake (S1) at 29 to 4                     |"<<endl;
	cout<<"\t|             2. Snake (S2) at 66 to 17                    |"<<endl;
	cout<<"\t|             3. Snake (S3) at 95 to 41                    |"<<endl;
	cout<<"\t|                                                          |"<<endl;
	cout<<"\t =========================================================="<<endl;
	cout<<endl<<endl;
}

int random_gen(int dice) //Random Number Generating Function
{
	srand(time(0));
	dice= rand()%6 + 1; //storing random number 
	if (dice == 6) //two six condition
	{
		cout<<"You got 6 !!...Press any charater to roll again..."<<endl;
		getch();
		int n=0;
	    n = rand()%6 + 1;
	    cout<<"You got: "<<n<<endl;
		if (n == 6) //consective 3 six condiion
		{
			cout<<"Three consective 6's are 0."<<endl;
			dice=0;
			n=0;
		}
		dice+=n;
	}
	return dice;
}

void check_L_S (int &p) // function to check snake and ladder 
{
	switch (p) // L1  at 13 to 57, l2 at 36 to 62, l3 at 53 to 93 & s1 at 29 to 4, s2 at 66 to 17, s3 at 95 to 41  
	{
		case 13: // Ladder 1
		{
			p=57;  
			cout<<"You got ladder!!! from 13-57"<<endl;
			break; 
		}
		case 29: //snake 1
		{
		    p=4;  
		    cout<<"You got bitten by snake!!! from 29-4"<<endl;
		    break;
		}
		case 36: //Ladder 2
		{
		    p=62;  
		    cout<<"You got ladder!!! from 36-62"<<endl;
		    break;
		}
		case 53: //ladder 1
		{
		    p=93;  
		    cout<<"You got ladder!!! from 53-93"<<endl;
		    break;
		}	
		case 66: //snake 2 
		{
		    p=17; 
		    cout<<"You got bitten by snake!!! from 66-17"<<endl;
		    break;
		}	
		case 95: //snake 3
		{
		    p=41; 
		    cout<<"You got bitten by snake!!! from 95-41"<<endl;
		    break;
		}
	}
}

void board(char player_1[100], char player_2[100]) //showing position for two players
{
	cout << "\t ______________________________________________________________________" << endl;
	cout << "\t|  " << "100  " << "|  " << "99  " << "|  " << "98  "  << "|  " << "97  " << "|  " << "96  " << "|  " << "95  " << "|  " << "94  " << "|  " << "93  " << "|  " << "92  " << "|  " << "91  |" <<endl;
	cout << "\t|" << "  " << "   " <<  player_1[100] << player_2[100]  << "  |" << "  " << " " <<  player_1[99] << player_2[99]  << " |" << "  " << " " <<  player_1[98] << player_2[98]  << " |" << "  " << " " <<  player_1[97] << player_2[97]  << " |" << "  " << " " <<  player_1[96] << player_2[96]  << " |" << "S3" << " " <<  player_1[95] << player_2[95] << " |" << "  " << " " <<  player_1[94] << player_2[94]<< " |" << "  " << " " <<  player_1[93] << player_2[93]<< " |" << "  " << " " <<  player_1[92] << player_2[92] << " |" << "  " << " " <<  player_1[91] << player_2[91] << " |"; 
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
	cout << "\t|  " << "81   " << "|  " << "82  " << "|  " << "83  "  << "|  " << "84  " << "|  " << "85  " << "|  " << "86  " << "|  " << "87  " << "|  " << "88  " << "|  " << "89  " << "|  " << "90  |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[81] << player_2[81]  << "  |" << "  " << " " <<  player_1[82] << player_2[82]  << " |" << "  " << " " << player_1[83] <<player_2[83]  << " |" << "  " << " " <<  player_1[84] << player_2[84]  << " |" << "  " << " " <<  player_1[85] << player_2[85]  << " |" << "  " << " " <<  player_1[86] << player_2[86] << " |" << "  " << " " <<  player_1[87] << player_2[87]<< " |" << "  " << " " <<  player_1[88] << player_2[88]<< " |" << "  " << " " <<  player_1[89] << player_2[89] << " |" << "  " << " " <<  player_1[90] << player_2[90] << " |";
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
	cout << "\t|  " << "80   " << "|  " << "79  " << "|  " << "78  "  << "|  " << "77  " << "|  " << "76  " << "|  " << "75  " << "|  " << "74  " << "|  " << "73  " << "|  " << "72  " << "|  " << "71  |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[80] << player_2[80]  << "  |" << "  " << " " <<  player_1[79] << player_2[79]  << " |" << "  " << " " <<  player_1[78] <<player_2[78]  << " |" << "  " << " " <<  player_1[77] << player_2[77]  << " |" << "  " << " " <<  player_1[76] << player_2[76]  << " |" << "  " << " " <<  player_1[75] << player_2[75] << " |" << "  " << " " <<  player_1[74] << player_2[74]<< " |" << "  " << " " <<  player_1[73] << player_2[73]<< " |" << "  " << " " <<  player_1[72] << player_2[72] << " |" << "  " << " " <<  player_1[71] << player_2[71] << " |";
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
	cout << "\t|  " << "61   " << "|  " << "62  " << "|  " << "63  "  << "|  " << "64  " << "|  " << "65  " << "|  " << "66  " << "|  " << "67  " << "|  " << "68  " << "|  " << "69  " << "|  " << "70  |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[61] << player_2[61]  << "  |" << "  " << " " <<  player_1[62] << player_2[62]  << " |" << "  " << " " <<  player_1[63] <<player_2[63]  << " |" << "  " << " " <<  player_1[64] << player_2[64]  << " |" << "  " << " " <<  player_1[65] << player_2[65]  << " |" << "S2" << " " <<  player_1[66] << player_2[66] << " |" << "  " << " " <<  player_1[67] << player_2[67]<< " |" << "  " << " " <<  player_1[68] << player_2[68]<< " |" << "  " << " " <<  player_1[69] << player_2[69] << " |" << "  " << " " <<  player_1[70] << player_2[70] << " |";
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
	cout << "\t|  " << "60   " << "|  " << "59  " << "|  " << "58  "  << "|  " << "57  " << "|  " << "56  " << "|  " << "55  " << "|  " << "54  " << "|  " << "53  " << "|  " << "52  " << "|  " << "51  |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[60] << player_2[60]  << "  |" << "  " << " " <<  player_1[59] << player_2[59]  << " |" << "  " << " " <<  player_1[58] <<player_2[58]  << " |" << "  " << " " <<  player_1[57] << player_2[57]  << " |" << "  " << " " <<  player_1[56] << player_2[56]  << " |" << "  " << " " <<  player_1[55] << player_2[55] << " |" << "  " << " " <<  player_1[54] << player_2[54]<< " |" << "L3" << " " <<  player_1[53] << player_2[53]<< " |" << "  " << " " <<  player_1[52] << player_2[52] << " |" << "  " << " " <<  player_1[51] << player_2[51] << " |";
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
	cout << "\t|  " << "41   " << "|  " << "42  " << "|  " << "43  "  << "|  " << "44  " << "|  " << "45  " << "|  " << "46  " << "|  " << "47  " << "|  " << "48  " << "|  " << "49  " << "|  " << "50  |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[41] << player_2[41]  << "  |" << "  " << " " <<  player_1[42] << player_2[42]  << " |" << "  " << " " <<  player_1[43] <<player_2[43]  << " |" << "  " << " " <<  player_1[44] << player_2[44]  << " |" << "  " << " " <<  player_1[45] << player_2[45]  << " |" << "  " << " " <<  player_1[46] << player_2[46] << " |" << "  " << " " <<  player_1[47] << player_2[47]<< " |" << "  " << " " <<  player_1[48] << player_2[48]<< " |" << "  " << " " <<  player_1[49] << player_2[49] << " |" << "  " << " " <<  player_1[50] << player_2[50] << " |";
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
	cout << "\t|  " << "40   " << "|  " << "39  " << "|  " << "38  "  << "|  " << "37  " << "|  " << "36  " << "|  " << "35  " << "|  " << "34  " << "|  " << "33  " << "|  " << "32  " << "|  " << "31  |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[40] << player_2[40]  << "  |" << "  " << " " <<  player_1[39] << player_2[39]  << " |" << "  " << " " <<  player_1[38] <<player_2[38]  << " |" << "  " << " " <<  player_1[37] << player_2[37]  << " |" << "L2" << " " <<  player_1[36] << player_2[36]  << " |" << "  " << " " <<  player_1[35] << player_2[35] << " |" << "  " << " " <<  player_1[34] << player_2[34]<< " |" << "  " << " " <<  player_1[33] << player_2[33]<< " |" << "  " << " " <<  player_1[32] << player_2[32] << " |" << "  " << " " <<  player_1[31] << player_2[31] << " |";
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
	cout << "\t|  " << "21   " << "|  " << "22  " << "|  " << "23  "  << "|  " << "24  " << "|  " << "25  " << "|  " << "26  " << "|  " << "27  " << "|  " << "28  " << "|  " << "29  " << "|  " << "30  |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[21] << player_2[21]  << "  |" << "  " << " " <<  player_1[22] << player_2[22]  << " |" << "  " << " " <<  player_1[23] <<player_2[23]  << " |" << "  " << " " <<  player_1[24] << player_2[24]  << " |" << "  " << " " <<  player_1[25] << player_2[25]  << " |" << "  " << " " <<  player_1[26] << player_2[26] << " |" << "  " << " " <<  player_1[27] << player_2[27]<< " |" << "  " << " " <<  player_1[28] << player_2[28]<< " |" << "S1" << " " <<  player_1[29] << player_2[29] << " |" << "  " << " " <<  player_1[30] << player_2[30] << " |";
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
	cout << "\t|  " << "20   " << "|  " << "19  " << "|  " << "18  "  << "|  " << "17  " << "|  " << "16  " << "|  " << "15  " << "|  " << "14  " << "|  " << "13  " << "|  " << "12  " << "|  " << "11  |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[20] << player_2[20]  << "  |" << "  " << " " <<  player_1[19] << player_2[19]  << " |" << "  " << " " <<  player_1[18] <<player_2[18]  << " |" << "  " << " " <<  player_1[17] << player_2[17]  << " |" << "  " << " " <<  player_1[16] << player_2[16]  << " |" << "  " << " " <<  player_1[15] << player_2[15] << " |" << "  " << " " <<  player_1[14] << player_2[14]<< " |" << "L1" << " " <<  player_1[13] << player_2[13]<< " |" << "  " << " " <<  player_1[12] << player_2[12] << " |" << "  " << " " <<  player_1[11] << player_2[11] << " |";
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
	cout << "\t|  " << "1    " << "|  " << "2   " << "|  " << "3   "  << "|  " << "4   " << "|  " << "5   " << "|  " << "6   " << "|  " << "7   " << "|  " << "8   " << "|  " << "9   " << "|  " << "10  |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[1] << player_2[1]  << "  |" << "  " << " " <<  player_1[2] << player_2[2]  << " |" << "  " << " " <<  player_1[3] << player_2[3]  << " |" << "  " << " " <<  player_1[4] << player_2[4]  << " |" << "  " << " " <<  player_1[5] << player_2[5]  << " |" << "  " << " " <<  player_1[6] << player_2[6] << " |" << "  " << " " <<  player_1[7] << player_2[7]<< " |" << "  " << " " <<  player_1[8] << player_2[8]<< " |" << "  " << " " <<  player_1[9] << player_2[9] << " |" << "  " << " " <<  player_1[10] << player_2[10] << " |";
	cout << endl << "\t ----------------------------------------------------------------------" << endl;
}

void board(char player_1[100], char player_2[100], char player_3[100]) //showing position for 3 players 
{
	cout << "\t ________________________________________________________________________________" << endl;
	cout << "\t|  " << "100   " << "|  " << "99   " << "|  " << "98   "  << "|  " << "97   " << "|  " << "96   " << "|  " << "95   " << "|  " << "94   " << "|  " << "93   " << "|  " << "92   " << "|  " << "91   |" <<endl;
	cout << "\t|" << "  " << "   " <<  player_1[100] << player_2[100]  << player_3[100]  << "   |" << "  " << " " <<  player_1[99] << player_2[99]  << player_3[99]  << " |" << "  " << " " <<  player_1[98] << player_2[98]  << player_3[98]  << " |" << "  " << " " <<  player_1[97] << player_2[97]  << player_3[97]  << " |" << "  " << " " <<  player_1[96] << player_2[96]  << player_3[96]  << " |" << "S3" << " " <<  player_1[95] << player_2[95] << player_3[95]  << " |" << "  " << " " <<  player_1[94] << player_2[94]<< player_3[94]  << " |" << "  " << " " <<  player_1[93] << player_2[93]<< player_3[93]  << " |" << "  " << " " <<  player_1[92] << player_2[92] << player_3[92]  << " |" << "  " << " " <<  player_1[91] << player_2[91] << player_3[91]  << " |"; 
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "81    " << "|  " << "82   " << "|  " << "83   "  << "|  " << "84   " << "|  " << "85   " << "|  " << "86   " << "|  " << "87   " << "|  " << "88   " << "|  " << "89   " << "|  " << "90   |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[81] << player_2[81]  << player_3[81]  << "  |" << "  " << " " <<  player_1[82] << player_2[82]  << player_3[82]  << " |" << "  " << " " << player_1[83] <<player_2[83]  << player_3[83]  << " |" << "  " << " " <<  player_1[84] << player_2[84]  << player_3[84]  << " |" << "  " << " " <<  player_1[85] << player_2[85]  << player_3[85]  << " |" << "  " << " " <<  player_1[86] << player_2[86] << player_3[86]  << " |" << "  " << " " <<  player_1[87] << player_2[87]<< player_3[87]  << " |" << "  " << " " <<  player_1[88] << player_2[88]<< player_3[88]  << " |" << "  " << " " <<  player_1[89] << player_2[89] << player_3[89]  << " |" << "  " << " " <<  player_1[90] << player_2[90] << player_3[90]  << " |";
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "80    " << "|  " << "79   " << "|  " << "78   "  << "|  " << "77   " << "|  " << "76   " << "|  " << "75   " << "|  " << "74   " << "|  " << "73   " << "|  " << "72   " << "|  " << "71   |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[80] << player_2[80]  << player_3[80]  << "  |" << "  " << " " <<  player_1[79] << player_2[79]  << player_3[79]  << " |" << "  " << " " <<  player_1[78] <<player_2[78]  << player_3[78]  << " |" << "  " << " " <<  player_1[77] << player_2[77]  << player_3[77]  << " |" << "  " << " " <<  player_1[76] << player_2[76]  << player_3[76]  << " |" << "  " << " " <<  player_1[75] << player_2[75] << player_3[75]  << " |" << "  " << " " <<  player_1[74] << player_2[74]<< player_3[74]  << " |" << "  " << " " <<  player_1[73] << player_2[73]<< player_3[73]  << " |" << "  " << " " <<  player_1[72] << player_2[72] << player_3[72]  << " |" << "  " << " " <<  player_1[71] << player_2[71] << player_3[71]  << " |";
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "61    " << "|  " << "62   " << "|  " << "63   "  << "|  " << "64   " << "|  " << "65   " << "|  " << "66   " << "|  " << "67   " << "|  " << "68   " << "|  " << "69   " << "|  " << "70   |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[61] << player_2[61]  << player_3[61]  << "  |" << "  " << " " <<  player_1[62] << player_2[62]  << player_3[62]  << " |" << "  " << " " <<  player_1[63] <<player_2[63]  << player_3[63]  << " |" << "  " << " " <<  player_1[64] << player_2[64]  << player_3[64]  << " |" << "  " << " " <<  player_1[65] << player_2[65]  << player_3[65]  << " |" << "S2" << " " <<  player_1[66] << player_2[66] << player_3[66]  << " |" << "  " << " " <<  player_1[67] << player_2[67]<< player_3[67]  << " |" << "  " << " " <<  player_1[68] << player_2[68]<< player_3[68]  << " |" << "  " << " " <<  player_1[69] << player_2[69] << player_3[69]  << " |" << "  " << " " <<  player_1[70] << player_2[70] << player_3[70]  << " |";
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "60    " << "|  " << "59   " << "|  " << "58   "  << "|  " << "57   " << "|  " << "56   " << "|  " << "55   " << "|  " << "54   " << "|  " << "53   " << "|  " << "52   " << "|  " << "51   |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[60] << player_2[60]  << player_3[60]  << "  |" << "  " << " " <<  player_1[59] << player_2[59]  << player_3[59]  << " |" << "  " << " " <<  player_1[58] <<player_2[58]  << player_3[58]  << " |" << "  " << " " <<  player_1[57] << player_2[57]  << player_3[57]  << " |" << "  " << " " <<  player_1[56] << player_2[56]  << player_3[56]  << " |" << "  " << " " <<  player_1[55] << player_2[55] << player_3[55]  << " |" << "  " << " " <<  player_1[54] << player_2[54]<< player_3[54]  << " |" << "L3" << " " <<  player_1[53] << player_2[53]<< player_3[53]  << " |" << "  " << " " <<  player_1[52] << player_2[52] << player_3[52]  << " |" << "  " << " " <<  player_1[51] << player_2[51] << player_3[51]  << " |";
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "41    " << "|  " << "42   " << "|  " << "43   "  << "|  " << "44   " << "|  " << "45   " << "|  " << "46   " << "|  " << "47   " << "|  " << "48   " << "|  " << "49   " << "|  " << "50   |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[41] << player_2[41]  << player_3[41]  << "  |" << "  " << " " <<  player_1[42] << player_2[42]  << player_3[42]  << " |" << "  " << " " <<  player_1[43] <<player_2[43]  << player_3[43]  << " |" << "  " << " " <<  player_1[44] << player_2[44]  << player_3[44]  << " |" << "  " << " " <<  player_1[45] << player_2[45]  << player_3[45]  << " |" << "  " << " " <<  player_1[46] << player_2[46] << player_3[46]  << " |" << "  " << " " <<  player_1[47] << player_2[47]<< player_3[47]  << " |" << "  " << " " <<  player_1[48] << player_2[48]<< player_3[48]  << " |" << "  " << " " <<  player_1[49] << player_2[49] << player_3[49]  << " |" << "  " << " " <<  player_1[50] << player_2[50] << player_3[50]  << " |";
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "40    " << "|  " << "39   " << "|  " << "38   "  << "|  " << "37   " << "|  " << "36   " << "|  " << "35   " << "|  " << "34   " << "|  " << "33   " << "|  " << "32   " << "|  " << "31   |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[40] << player_2[40]  << player_3[40]  << "  |" << "  " << " " <<  player_1[39] << player_2[39]  << player_3[39]  << " |" << "  " << " " <<  player_1[38] <<player_2[38]  << player_3[38]  << " |" << "  " << " " <<  player_1[37] << player_2[37]  << player_3[37]  << " |" << "L2" << " " <<  player_1[36] << player_2[36]  << player_3[36]  << " |" << "  " << " " <<  player_1[35] << player_2[35] << player_3[35]  << " |" << "  " << " " <<  player_1[34] << player_2[34]<< player_3[34]  << " |" << "  " << " " <<  player_1[33] << player_2[33]<< player_3[33]  << " |" << "  " << " " <<  player_1[32] << player_2[32] << player_3[32]  << " |" << "  " << " " <<  player_1[31] << player_2[31] << player_3[31]  << " |";
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "21    " << "|  " << "22   " << "|  " << "23   "  << "|  " << "24   " << "|  " << "25   " << "|  " << "26   " << "|  " << "27   " << "|  " << "28   " << "|  " << "29   " << "|  " << "30   |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[21] << player_2[21]  << player_3[21]  << "  |" << "  " << " " <<  player_1[22] << player_2[22]  << player_3[22]  << " |" << "  " << " " <<  player_1[23] <<player_2[23]  << player_3[23]  << " |" << "  " << " " <<  player_1[24] << player_2[24]  << player_3[24]  << " |" << "  " << " " <<  player_1[25] << player_2[25]  << player_3[25]  << " |" << "  " << " " <<  player_1[26] << player_2[26] << player_3[26]  << " |" << "  " << " " <<  player_1[27] << player_2[27]<< player_3[27]  << " |" << "  " << " " <<  player_1[28] << player_2[28]<< player_3[28]  << " |" << "S1" << " " <<  player_1[29] << player_2[29] << player_3[29]  << " |" << "  " << " " <<  player_1[30] << player_2[30] << player_3[30]  << " |";
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "20    " << "|  " << "19   " << "|  " << "18   "  << "|  " << "17   " << "|  " << "16   " << "|  " << "15   " << "|  " << "14   " << "|  " << "13   " << "|  " << "12   " << "|  " << "11   |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[20] << player_2[20]  << player_3[20]  << "  |" << "  " << " " <<  player_1[19] << player_2[19]  << player_3[19]  << " |" << "  " << " " <<  player_1[18] <<player_2[18]  << player_3[18]  << " |" << "  " << " " <<  player_1[17] << player_2[17]  << player_3[17]  << " |" << "  " << " " <<  player_1[16] << player_2[16]  << player_3[16]  << " |" << "  " << " " <<  player_1[15] << player_2[15] << player_3[15]  << " |" << "  " << " " <<  player_1[14] << player_2[14]<< player_3[14]  << " |" << "L1" << " " <<  player_1[13] << player_2[13]<< player_3[13]  << " |" << "  " << " " <<  player_1[12] << player_2[12] << player_3[12]  << " |" << "  " << " " <<  player_1[11] << player_2[11] << player_3[11]  << " |";
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "1     " << "|  " << "2    " << "|  " << "3    "  << "|  " << "4    " << "|  " << "5    " << "|  " << "6    " << "|  " << "7    " << "|  " << "8    " << "|  " << "9    " << "|  " << "10   |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[1] << player_2[1]  << player_3[1]  << "  |" << "  " << " " <<  player_1[2] << player_2[2]  << player_3[2]  << " |" << "  " << " " <<  player_1[3] << player_2[3]  << player_3[3]  << " |" << "  " << " " <<  player_1[4] << player_2[4]  << player_3[4]  << " |" << "  " << " " <<  player_1[5] << player_2[5]  << player_3[5]  << " |" << "  " << " " <<  player_1[6] << player_2[6] << player_3[6]  << " |" << "  " << " " <<  player_1[7] << player_2[7] << player_3[7]  << " |" << "  " << " " <<  player_1[8] << player_2[8]  << player_3[8]  << " |" << "  " << " " <<  player_1[9] << player_2[9]  << player_3[9]  << " |" << "  " << " " <<  player_1[10] << player_2[10] << player_3[10] << " |";
	cout << endl << "\t ---------------------------------------------------------------------------------" << endl;
}

void board(char player_1[100], char player_2[100], char player_3[100], char player_4[100]) //showing position for 4 players
{
	cout << "\t __________________________________________________________________________________________" << endl;
	cout << "\t|  " << "100    " << "|  " << "99    " << "|  " << "98    "  << "|  " << "97    " << "|  " << "96    " << "|  " << "95    " << "|  " << "94    " << "|  " << "93    " << "|  " << "92    " << "|  " << "91    |" <<endl;
	cout << "\t|" << "  " << "    " <<  player_1[100] << player_2[100]  << player_3[100] << player_4[100]  << "   |" << "  " << " " <<  player_1[99] << player_2[99]  << player_3[99]  << player_4[99]  << " |" << "  " << " " <<  player_1[98] << player_2[98]  << player_3[98]  << player_4[98]  << " |" << "  " << " " <<  player_1[97] << player_2[97]  << player_3[97]  << player_4[97]  << " |" << "  " << " " <<  player_1[96] << player_2[96]  << player_3[96]  << player_4[96]  << " |" << "S3" << " " <<  player_1[95] << player_2[95] << player_3[95]  << player_4[95]  << " |" << "  " << " " <<  player_1[94] << player_2[94]<< player_3[94]  << player_4[94]  << " |" << "  " << " " <<  player_1[93] << player_2[93]<< player_3[93]  << player_4[93]  << " |" << "  " << " " <<  player_1[92] << player_2[92] << player_3[92]  << player_4[92]  << " |" << "  " << " " <<  player_1[91] << player_2[91] << player_3[91]  << player_4[91]  << " |"; 
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "81     " << "|  " << "82    " << "|  " << "83    "  << "|  " << "84    " << "|  " << "85    " << "|  " << "86    " << "|  " << "87    " << "|  " << "88    " << "|  " << "89    " << "|  " << "90    |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[81] << player_2[81]  << player_3[81]  << player_4[81]  << "  |" << "  " << " " <<  player_1[82] << player_2[82]  << player_3[82]  << player_4[82]  << " |" << "  " << " " << player_1[83] <<player_2[83]  << player_3[83]  << player_4[83]  << " |" << "  " << " " <<  player_1[84] << player_2[84]  << player_3[84]  << player_4[84]  << " |" << "  " << " " <<  player_1[85] << player_2[85]  << player_3[85]  << player_4[85]  << " |" << "  " << " " <<  player_1[86] << player_2[86] << player_3[86]  << player_4[86]  << " |" << "  " << " " <<  player_1[87] << player_2[87]<< player_3[87]  << player_4[87]  << " |" << "  " << " " <<  player_1[88] << player_2[88]<< player_3[88]  << player_4[88]  << " |" << "  " << " " <<  player_1[89] << player_2[89] << player_3[89]  << player_4[89]  << " |" << "  " << " " <<  player_1[90] << player_2[90] << player_3[90]  << player_4[90]  << " |";
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "80     " << "|  " << "79    " << "|  " << "78    "  << "|  " << "77    " << "|  " << "76    " << "|  " << "75    " << "|  " << "74    " << "|  " << "73    " << "|  " << "72    " << "|  " << "71    |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[80] << player_2[80]  << player_3[80]  << player_4[80]  << "  |" << "  " << " " <<  player_1[79] << player_2[79]  << player_3[79]  << player_4[79]  << " |" << "  " << " " <<  player_1[78] <<player_2[78]  << player_3[78]  << player_4[78]  << " |" << "  " << " " <<  player_1[77] << player_2[77]  << player_3[77]  << player_4[77]  << " |" << "  " << " " <<  player_1[76] << player_2[76]  << player_3[76]  << player_4[76]  << " |" << "  " << " " <<  player_1[75] << player_2[75] << player_3[75]  << player_4[75]  << " |" << "  " << " " <<  player_1[74] << player_2[74]<< player_3[74]  << player_4[74]  << " |" << "  " << " " <<  player_1[73] << player_2[73]<< player_3[73]  << player_4[73]  << " |" << "  " << " " <<  player_1[72] << player_2[72] << player_3[72]  << player_4[72]  << " |" << "  " << " " <<  player_1[71] << player_2[71] << player_3[71]  << player_4[71]  << " |";
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "61     " << "|  " << "62    " << "|  " << "63    "  << "|  " << "64    " << "|  " << "65    " << "|  " << "66    " << "|  " << "67    " << "|  " << "68    " << "|  " << "69    " << "|  " << "70    |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[61] << player_2[61]  << player_3[61]  << player_4[61]  << "  |" << "  " << " " <<  player_1[62] << player_2[62]  << player_3[62]  << player_4[62]  << " |" << "  " << " " <<  player_1[63] <<player_2[63]  << player_3[63]  << player_4[63]  << " |" << "  " << " " <<  player_1[64] << player_2[64]  << player_3[64]  << player_4[64]  << " |" << "  " << " " <<  player_1[65] << player_2[65]  << player_3[65]  << player_4[65]  << " |" << "S2" << " " <<  player_1[66] << player_2[66] << player_3[66]  << player_4[66]  << " |" << "  " << " " <<  player_1[67] << player_2[67]<< player_3[67]  << player_4[67]  << " |" << "  " << " " <<  player_1[68] << player_2[68]<< player_3[68]  << player_4[68]  << " |" << "  " << " " <<  player_1[69] << player_2[69] << player_3[69]  << player_4[69]  << " |" << "  " << " " <<  player_1[70] << player_2[70] << player_3[70]  << player_4[70]  << " |";
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "60     " << "|  " << "59    " << "|  " << "58    "  << "|  " << "57    " << "|  " << "56    " << "|  " << "55    " << "|  " << "54    " << "|  " << "53    " << "|  " << "52    " << "|  " << "51    |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[60] << player_2[60]  << player_3[60]  << player_4[60]  << "  |" << "  " << " " <<  player_1[59] << player_2[59]  << player_3[59]  << player_4[59]  << " |" << "  " << " " <<  player_1[58] <<player_2[58]  << player_3[58]  << player_4[58]  << " |" << "  " << " " <<  player_1[57] << player_2[57]  << player_3[57]  << player_4[57]  << " |" << "  " << " " <<  player_1[56] << player_2[56]  << player_3[56]  << player_4[56]  << " |" << "  " << " " <<  player_1[55] << player_2[55] << player_3[55]  << player_4[55]  << " |" << "  " << " " <<  player_1[54] << player_2[54]<< player_3[54]  << player_4[54]  << " |" << "L3" << " " <<  player_1[53] << player_2[53]<< player_3[53]  << player_4[53]  << " |" << "  " << " " <<  player_1[52] << player_2[52] << player_3[52]  << player_4[52]  << " |" << "  " << " " <<  player_1[51] << player_2[51] << player_3[51]  << player_4[51]  << " |";
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "41     " << "|  " << "42    " << "|  " << "43    "  << "|  " << "44    " << "|  " << "45    " << "|  " << "46    " << "|  " << "47    " << "|  " << "48    " << "|  " << "49    " << "|  " << "50    |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[41] << player_2[41]  << player_3[41]  << player_4[41]  << "  |" << "  " << " " <<  player_1[42] << player_2[42]  << player_3[42]  << player_4[42]  << " |" << "  " << " " <<  player_1[43] <<player_2[43]  << player_3[43]  << player_4[43]  << " |" << "  " << " " <<  player_1[44] << player_2[44]  << player_3[44]  << player_4[44]  << " |" << "  " << " " <<  player_1[45] << player_2[45]  << player_3[45]  << player_4[45]  << " |" << "  " << " " <<  player_1[46] << player_2[46] << player_3[46]  << player_4[46]  << " |" << "  " << " " <<  player_1[47] << player_2[47]<< player_3[47]  << player_4[47]  << " |" << "  " << " " <<  player_1[48] << player_2[48]<< player_3[48]  << player_4[48]  << " |" << "  " << " " <<  player_1[49] << player_2[49] << player_3[49]  << player_4[49]  << " |" << "  " << " " <<  player_1[50] << player_2[50] << player_3[50]  << player_4[50]  << " |";
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "40     " << "|  " << "39    " << "|  " << "38    "  << "|  " << "37    " << "|  " << "36    " << "|  " << "35    " << "|  " << "34    " << "|  " << "33    " << "|  " << "32    " << "|  " << "31    |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[40] << player_2[40]  << player_3[40]  << player_4[40]  << "  |" << "  " << " " <<  player_1[39] << player_2[39]  << player_3[39]  << player_4[39]  << " |" << "  " << " " <<  player_1[38] <<player_2[38]  << player_3[38]  << player_4[38]  << " |" << "  " << " " <<  player_1[37] << player_2[37]  << player_3[37]  << player_4[37]  << " |" << "L2" << " " <<  player_1[36] << player_2[36]  << player_3[36]  << player_4[36]  << " |" << "  " << " " <<  player_1[35] << player_2[35] << player_3[35]  << player_4[35]  << " |" << "  " << " " <<  player_1[34] << player_2[34]<< player_3[34]  << player_4[34]  << " |" << "  " << " " <<  player_1[33] << player_2[33]<< player_3[33]  << player_4[33]  << " |" << "  " << " " <<  player_1[32] << player_2[32] << player_3[32]  << player_4[32]  << " |" << "  " << " " <<  player_1[31] << player_2[31] << player_3[31]  << player_4[31]  << " |";
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "21     " << "|  " << "22    " << "|  " << "23    "  << "|  " << "24    " << "|  " << "25    " << "|  " << "26    " << "|  " << "27    " << "|  " << "28    " << "|  " << "29    " << "|  " << "30    |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[21] << player_2[21]  << player_3[21]  << player_4[21]  << "  |" << "  " << " " <<  player_1[22] << player_2[22]  << player_3[22]  << player_4[22]  << " |" << "  " << " " <<  player_1[23] <<player_2[23]  << player_3[23]  << player_4[23]  << " |" << "  " << " " <<  player_1[24] << player_2[24]  << player_3[24]  << player_4[24]  << " |" << "  " << " " <<  player_1[25] << player_2[25]  << player_3[25]  << player_4[25]  << " |" << "  " << " " <<  player_1[26] << player_2[26] << player_3[26]  << player_4[26]  << " |" << "  " << " " <<  player_1[27] << player_2[27]<< player_3[27]  << player_4[27]  << " |" << "  " << " " <<  player_1[28] << player_2[28]<< player_3[28]  << player_4[28]  << " |" << "S1" << " " <<  player_1[29] << player_2[29] << player_3[29]  << player_4[29]  << " |" << "  " << " " <<  player_1[30] << player_2[30] << player_3[30]  << player_4[30]  << " |";
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "20     " << "|  " << "19    " << "|  " << "18    "  << "|  " << "17    " << "|  " << "16    " << "|  " << "15    " << "|  " << "14    " << "|  " << "13    " << "|  " << "12    " << "|  " << "11    |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[20] << player_2[20]  << player_3[20]  << player_4[20]  << "  |" << "  " << " " <<  player_1[19] << player_2[19]  << player_3[19]  << player_4[19]  << " |" << "  " << " " <<  player_1[18] <<player_2[18]  << player_3[18]  << player_4[18]  << " |" << "  " << " " <<  player_1[17] << player_2[17]  << player_3[17]  << player_4[17]  << " |" << "  " << " " <<  player_1[16] << player_2[16]  << player_3[16]  << player_4[16]  << " |" << "  " << " " <<  player_1[15] << player_2[15] << player_3[15]  << player_4[15]  << " |" << "  " << " " <<  player_1[14] << player_2[14]<< player_3[14]  << player_4[14]  << " |" << "L1" << " " <<  player_1[13] << player_2[13]<< player_3[13]  << player_4[13]  << " |" << "  " << " " <<  player_1[12] << player_2[12] << player_3[12]  << player_4[12]  << " |" << "  " << " " <<  player_1[11] << player_2[11] << player_3[11]  << player_4[11]  << " |";
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
	cout << "\t|  " << "1      " << "|  " << "2     " << "|  " << "3     "  << "|  " << "4     " << "|  " << "5     " << "|  " << "6     " << "|  " << "7     " << "|  " << "8     " << "|  " << "9     " << "|  " << "10    |" <<endl;
	cout << "\t|" << "  " << " " <<  player_1[1] << player_2[1]  << player_3[1]  << player_4[1]  << "  |" << "  " << " " <<  player_1[2] << player_2[2]  << player_3[2]  << player_4[2]  << " |" << "  " << " " <<  player_1[3] << player_2[3]  << player_3[3]  << player_4[3]  << " |" << "  " << " " <<  player_1[4] << player_2[4]  << player_3[4]  << player_4[4]  << " |" << "  " << " " <<  player_1[5] << player_2[5]  << player_3[5]  << player_4[5]  << " |" << "  " << " " <<  player_1[6] << player_2[6] << player_3[6]  << player_4[6]  << " |" << "  " << " " <<  player_1[7] << player_2[7] << player_3[7]  << player_4[7]  << " |" << "  " << " " <<  player_1[8] << player_2[8]  << player_3[8]  << player_4[8]  << " |" << "  " << " " <<  player_1[9] << player_2[9]  << player_3[9]  << player_4[9]  << " |" << "  " << " " <<  player_1[10] << player_2[10] << player_3[10] << player_4[10]  << " |";
	cout << endl << "\t -------------------------------------------------------------------------------------------" << endl;
}
