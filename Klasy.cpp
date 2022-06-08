#include "Klasy.h"

class SingleField;
class Base;
class Computer;
class Player;

int Target::get_a() { return a; }
int Target:: get_b() { return b; }
void Target::set_a(int m) { a = m; }
void Target::set_b(int m) { b = m; }

void SingleField:: setvalue(int m)
	{
		value = m;
	}
int SingleField:: getvalue() { return value; }
void SingleField::setrow(int m)
	{
		row = m;
	} //setwiersz
void SingleField::setcolumn(int m)
	{
		column = m;
	}
void SingleField::sethit(int m)
	{
		hit = m;
	}//settrafione

int SingleField::getrow() { return row; }
int SingleField:: getcolumn() { return column; }
void SingleField::setgraphically(char m)
	{
		graphically = m;
	}
char SingleField::getgraphically() { return graphically; }
int SingleField::gethit() { return hit; }
SingleField::SingleField(): row(0), column(0), value(0), hit(0), graphically('-') {};//konstruktor domyslny
void SingleField:: show_the_value()
	{
		printf("%d ", value);
	}
void SingleField:: show_graphically()
	{
		printf("%c", graphically);
	}

int Base::get_points() { return points; };
Base::Base() :points(0) {//constuktor creats the empty board
		for (int i = 0; i <= 9; i++)
		{
			for (int k = 0; k <= 9; k++)
			{
				Board[i][k] = SingleField();
				Board[i][k].setrow(i);
				Board[i][k].setcolumn(k);
			}
		}
	};
void Base::Show_the_board()
	{
	printf("   A B C D E F G H I J\n");
	for (int i = 0; i <= 9; i++)
		{
		if (i == 9)
		{
			printf("%d ", i + 1);
		}
		else
			printf("%d  ", i + 1);
			for (int k = 0; k <= 9; k++)
			{				 
					printf("%d ", Board[i][k].getvalue());
			}
			printf("\n");
		}
	}

int Computer::getshooting_strategy() { return shooting_strategy; }
void Computer::setshooting_strategy(int m)
{
	shooting_strategy = m;
}

void show_the_board_player_and_enemy(SingleField Player_Board[10][10], SingleField Board[10][10], int nr)
{
	printf("\nComputers %d enemy's board:\t\tComputers %d board:\n   A B C D E F G H I J\t\t\t   A B C D E F G H I J\n", nr, nr);
	for (int i = 0; i <= 9; i++)
	{
		if (i == 9)
		{
			printf("%d ", i + 1);
		}
		else
			printf("%d  ", i + 1);
		for (int k = 0; k <= 9; k++)
		{
			printf("%c ", Player_Board[i][k].getgraphically());
		}
		printf("\t\t\t");
		if (i == 9)
		{
			printf("%d ", i + 1);
		}
		else
			printf("%d  ", i + 1);
		for (int k = 0; k <= 9; k++)
		{
			printf("%d ", Board[i][k].getvalue());
		}
		printf("\n");
	};
}

int Computer::gettarget_a() { return target_a; }
void Computer::settarget_a(int m)
{
	target_a = m;
}
int Computer::gettarget_b() { return target_b; }
void Computer::settarget_b(int m)
{
	target_b = m;
}

void Computer ::shot(SingleField Player_Board[10][10])//computer shoots with choosen strategy at the enemey's board
	{
		int stop = 0;
		while (stop != 1)
		{
			//hunt strategy, checks if all the spaces around target were already shooted, if yes: we abandon current target
			if (gettarget_a() != 15 && gettarget_b() != 15
				&& ((Player_Board[gettarget_a() - 1][gettarget_b()].getgraphically() == '*' || Player_Board[gettarget_a() - 1][gettarget_b()].getgraphically() == 'x' || gettarget_a() == 0)
					&& (Player_Board[gettarget_a() + 1][gettarget_b()].getgraphically() == '*' || Player_Board[gettarget_a() + 1][gettarget_b()].getgraphically() == 'x' || gettarget_a() == 9)
					&& (Player_Board[gettarget_a()][gettarget_b() + 1].getgraphically() == '*' || Player_Board[gettarget_a()][gettarget_b() + 1].getgraphically() == 'x' || gettarget_b() == 9)
					&& (Player_Board[gettarget_a()][gettarget_b() - 1].getgraphically() == '*' || Player_Board[gettarget_a()][gettarget_b() - 1].getgraphically() == 'x' || gettarget_b() == 0)))
			{
				settarget_a(15);//15 is default value of searching the target
				settarget_b(15);
			}
			int a;
			int b;
			a = random_number();
			b = random_number();
			if (shooting_strategy == 2)////parity strategy, shoot every second field
			{
				if ((a == 0) || (a == 2) || a == 4 || a == 6 || a == 8)
				{
					b = draw_even_number();//wylosuj liczbe parzyst¹
				}
				else
					b = draw_even_number() + 1;
			}
			if (gettarget_a() != 15 && gettarget_b() != 15 && (shooting_strategy == 2 || shooting_strategy == 3))//hunt strategy, check the recently hit
			{
				a = gettarget_a();
				b = gettarget_b();
				if (b != 0 && Player_Board[a][b - 1].getgraphically() == '-')//checks the field on the left and shoot at it if is not shooted yet
				{
					b = gettarget_b() - 1;
				}
				else if (b != 9 && Player_Board[a][b + 1].getgraphically() == '-')//checks the field on the right and shoot at it if is not shooted yet
				{
					b = gettarget_b() + 1;
				}
				else if (a != 0 && Player_Board[a - 1][b].getgraphically() == '-')//checks the field above the target and shoot at it if is not shooted yet
				{
					a = gettarget_a() - 1;
				}
				else if (a != 9 && Player_Board[a + 1][b].getgraphically() == '-')//checks the field below the target and shoot at it if is not shooted yet
				{
					a = gettarget_a() + 1;
				}
			}
			if (Player_Board[a][b].getgraphically() == '*' || Player_Board[a][b].getgraphically() == 'x')
			{
				////////If computer hit the same spot again it shoots again until it find not shooted spot
				if (shooting_strategy == 2 || shooting_strategy == 3)
				{
					settarget_a(15);
					settarget_b(15);
				}
				continue;
			}
			else if (Player_Board[a][b].getvalue() != 0)//if it's a succesfully hit
			{
				Player_Board[a][b].sethit(1);
				Player_Board[a][b].setgraphically('x');
				Player_Board[a][b].setvalue(0);
				points++;
				if (shooting_strategy == 2 || shooting_strategy == 3)//hunt strategy, the fields oblique to the target are changing into "shooted" because they are for sure empty 			
				{
				if (a != 0 && b!=9)
				{
					Player_Board[a - 1][b+1].sethit(0);
					Player_Board[a - 1][b+1].setgraphically('*');
					Player_Board[a - 1][b+1].setvalue(0);
				}
				if (a != 9 && b!=0)
				{
					Player_Board[a + 1][b-1].sethit(0);
					Player_Board[a + 1][b-1].setgraphically('*');
					Player_Board[a + 1][b-1].setvalue(0);
				}
				if (b != 9 && a!=9)
				{
					Player_Board[a+1][b + 1].sethit(0);
					Player_Board[a+1][b + 1].setgraphically('*');
					Player_Board[a+1][b + 1].setvalue(0);
				}
				if (b != 0&& a!=0)
				{
					Player_Board[a-1][b - 1].sethit(0);
					Player_Board[a-1][b - 1].setgraphically('*');
					Player_Board[a-1][b - 1].setvalue(0);
				}				
				if (gettarget_a() == 15 && gettarget_b() == 15)//if computer hits the ship and doesn't have a target it sets it
				{
					settarget_a(a);
					settarget_b(b);
				}
				}
				printf("\nComputer %d hit! ", nr);
				if (Player_Board[a][b].getvalue() == 0
					&& (Player_Board[a - 1][b].getvalue() == 0 || a == 0)
					&& (Player_Board[a + 1][b].getvalue() == 0 || a == 9)
					&& (Player_Board[a][b + 1].getvalue() == 0 || b == 9)
					&& (Player_Board[a][b - 1].getvalue() == 0 || b == 0)
					&& (Player_Board[a - 1][b - 1].getvalue() == 0 || b == 0 || a == 0)
					&& (Player_Board[a + 1][b - 1].getvalue() == 0 || b == 0 || a == 9)
					&& (Player_Board[a - 1][b + 1].getvalue() == 0 || b == 9 || a == 0)
					&& (Player_Board[a + 1][b + 1].getvalue() == 0 || b == 9 || a == 9))
				{

					printf("Hit ship sank!");//statek zaton¹³					
				}
				else
				{
					printf("Hit ship didn't sink! ");
				}
				if (points == WIN)
				{
					show_the_board_player_and_enemy(Player_Board, Board, nr);
					printf("\nxxxxxxxxxx Computer %d wins! xxxxxxxxxx\n\n", nr);
					break;
				}
			}
			else
			{
				Player_Board[a][b].sethit(0);
				Player_Board[a][b].setgraphically('*');
				printf("\nComputer %d missed!", nr);
				stop = 1;
			}
			printf("\nComputer %d: current points: %d", nr, points);			
			show_the_board_player_and_enemy(Player_Board, Board, nr);
			
		Sleep(1000);
		system("cls");
		}
		
	}
void Computer::load_ship(int n)//wylosowanie wspolrzednych statku, czy jest pionowo czy poziomo 
	{								//i sprawdzenie poprawnosci ustawienia na planszy wzgledem innych statkow
		int wczytano = 0;
		int a;
		int b;
		int wybor = 0;
		while (wczytano != 1)
		{
			int a = random_number();
			int b = random_number();
			//usuniêta funkcja dla jednomasztowca, zmieniamy zasady na od dwumasztowca do 5- masztowca
			if (n != 1)
			{
				wybor = random_choice();
				if (wybor == 1)
				{
					for (int i = -1; i <= n; i++)
					{
						if (Board[a][b].getvalue() == 0////////////nie sprawdzamy rzêdu poprawnoœci jak zaczynamy od samej góry i œrodka jak 
							&& (Board[a + i][b].getvalue() == 0 || (a + i == -1) /*|| (b == 0) /*/|| (a + i == 10))
							&& (Board[a + i][b - 1].getvalue() == 0 || (a + i == -1) || (b == 0) || (a + i == 10))
							&& (Board[a + i][b + 1].getvalue() == 0 || (a + i == -1) || (b == 9) || (a + i == 10))
							&& (9 - a >= n - 1))
						{
							wczytano = 1;
						}
						else
						{
							wczytano = 0;
							break;
						}
					}
					if (wczytano == 1)
					{
						for (int i = 0; i < n; i++)
						{
							Board[a + i][b].setvalue(n);
						}
					}
				}
				if (wybor == 2)
				{
					for (int i = -1; i <= n; i++)
					{
						if (Board[a][b].getvalue() == 0
							&& (Board[a][b + i].getvalue() == 0 ||/* (b == 0) ||*/ (b + i == -1) || (b + i == 10))
							&& (Board[a - 1][b + i].getvalue() == 0 || (a == 0) || (b + i == -1) /*ograniczenie po lewej wychodzi*/|| (b + i == 10))/*ograniczenie po prawej*/
							&& (Board[a + 1][b + i].getvalue() == 0 || (a == 9) || (b + i == -1) || (b + i == 10))
							&& (9 - b >= n - 1))
						{
							wczytano = 1;
						}
						else
						{
							wczytano = 0;
							break;
						}
					}
					if (wczytano == 1)
					{
						for (int i = 0; i < n; i++)
						{
							Board[a][b + i].setvalue(n);
						}
					}
				}

			}
		}
	}
void Computer::load_ships() //wczytanie 8 statkow
{
		load_ship(5);
		for (int i = 0; i < 2; i++)
		{
			load_ship(4);
		}
		for (int i = 0; i < 2; i++)
		{
			load_ship(3);
		}
		for (int i = 0; i < 3; i++)
		{
			load_ship(2);
		}
	}
Computer::~Computer() {};

Player ::Player() : Base(), nick("nikt"), number(1) {};//konstruktor domyslny
void Player :: setnumber(int m)
	{
		number = m;
	}
int Player:: getnumber() { return number; }char* Player :: getnick() { return nick; }
void Player :: load_ship(int n)//pobranie wspolrzednych statku, czy jest pionowo czy poziomo 
							//i sprawdzenie poprawnosci ustawienia na planszy wzgledem innych statkow(checking if the ship is right placed with another ships)
	{
		int loaded = 0;
		int a;
		int b;
		int choice = 0;
		while (loaded != 1)
		{
			printf("row:");//wpisuje cyfre która zamieniana jest na o 1 mniejsza
			int a = load_int()-1;
			printf("column: ");//wpisuje litere, pobieram cyfre
			int b = load_letter_column();
			///////2-spaces ship do 5-spaces ship
			if (n != 1)
			{
				printf("orientation of the ship(please type number):\n1 - vertically\n2 - horizontally\n");//pionowo lub poziomo
				choice = load_choice();
				if (choice == 1)
				{
					for (int i = -1; i <= n; i++)
					{
						if (Board[a][b].getvalue() == 0
							&& (Board[a + i][b].getvalue() == 0 || (a + i == -1) || (a + i == 10))
							&& (Board[a + i][b - 1].getvalue() == 0 || (a + i == -1) || (b == 0) || (a + i == 10))
							&& (Board[a + i][b + 1].getvalue() == 0 || (a + i == -1) || (b == 9) || (a + i == 10))
							&& (9 - a >= n - 1))
						{
							loaded = 1;
						}
						else
						{
							printf("\nYou can't place your ship here, try again!\n");
							loaded = 0;
							break;
						}
					}
					if (loaded == 1)
					{
						for (int i = 0; i < n; i++)
						{
							Board[a + i][b].setvalue(n);
						}
					}
				}
				if (choice == 2)
				{
					for (int i = -1; i <= n; i++)
					{
						if (Board[a][b].getvalue() == 0
							&& (Board[a][b + i].getvalue() == 0 || (b + i == -1) || (b + i == 10))
							&& (Board[a - 1][b + i].getvalue() == 0 || (a == 0) || (b + i == -1) || (b + i == 10))
							&& (Board[a + 1][b + i].getvalue() == 0 || (a == 9) || (b + i == -1) || (b + i == 10))
							&& (9 - b >= n - 1))
						{
							loaded = 1;
						}
						else
						{
							printf("\nYou can't place your ship here, try again!\n");
							loaded = 0;
							break;
						}
					}
					if (loaded == 1)
					{
						for (int i = 0; i < n; i++)
						{
							Board[a][b + i].setvalue(n);
						}
					}
				}

			}
		}
	}
void Player :: load_ships()//wczytanie 8 statkow od uzytkownika
	{
	Sleep(2000);
	system("cls");
		printf("\nPlayer %s: Please enter coordinates of the ships\n", nick);//wspó³rzêdne statku
		printf("Coordinates of the 5-spaces ship\n");
		load_ship(5);
		Show_the_board();
		for (int i = 0; i < 2; i++)
		{
			printf("Coordinates of the 4-spaces ship\n");
			load_ship(4);
			system("cls");
			Show_the_board();
		}
		for (int i = 0; i < 2; i++)
		{
			printf("Coordinates of the 3-spaces ship\n");
			load_ship(3);
			system("cls");
			Show_the_board();
		}
		for (int i = 0; i < 3; i++)
		{
			printf("Coordinates of the 2-spaces ship\n");
			load_ship(2);
			system("cls");
			Show_the_board();	
		}
		Sleep(1500);
		system("cls");
	}
void Player :: load_nick(int m)//pobiera nick, sprawdza poprawnoœæ wprowadzonych danych
	{
		printf("\nPlayer %d please enter the nick : \t", m);
		while (scanf_s("%s", nick, HOW_MANY) == 0 || getchar() != '\n')
		{
			printf("The incorrect nick. Try again\n");
			while (getchar() != '\n')
				;
		}
		printf("\nYou entered the nick:\t %s\n", nick);
	}
void Player:: shot(SingleField Enemy_Board[10][10])//shooting at the enemy board
	{
		int stop = 0;
		printf("\nPLAYER %s, your enemy's board:\t\tyour board right now:\n   A B C D E F G H I J\t\t\t   A B C D E F G H I J\n", nick);//show the board of the player and the board of the enemy
		for (int i = 0; i <= 9; i++)
		{
			if (i == 9)
			{
				printf("%d ", i + 1);
			}
			else
				printf("%d  ", i + 1);
			for (int k = 0; k <= 9; k++)
			{
				printf("%c ", Enemy_Board[i][k].getgraphically());
			}
			printf("\t\t\t");
			if (i == 9)
			{
				printf("%d ", i + 1);
			}
			else
				printf("%d  ", i + 1);
			for (int k = 0; k <= 9; k++)
			{
				printf("%d ", Board[i][k].getvalue());
			}
			printf("\n");
		}
		while (stop != 1)
		{
			printf("\nPlayer %s: Please enter coordinates of the shot:", nick);
			printf("row:");
			int a = load_int()-1;
			printf("column: ");
			int b = load_letter_column();
			system("cls");
			if (Enemy_Board[a][b].gethit() == 1 || Enemy_Board[a][b].gethit() == 2)
			{
				printf("You had already shot at this field\n");
				Enemy_Board[a][b].sethit(2);
				stop = 1;
			}
			else if (Enemy_Board[a][b].getvalue() != 0)
			{
				Enemy_Board[a][b].sethit(1);
				Enemy_Board[a][b].setgraphically('x');
				Enemy_Board[a][b].setvalue(0);
				points++;
				printf("\nYou hit! ");
				if (Enemy_Board[a][b].getvalue() == 0
					&& (Enemy_Board[a - 1][b].getvalue() == 0 || a == 0)
					&& (Enemy_Board[a + 1][b].getvalue() == 0 || a == 9)
					&& (Enemy_Board[a][b + 1].getvalue() == 0 || b == 9)
					&& (Enemy_Board[a][b - 1].getvalue() == 0 || b == 0)
					&& (Enemy_Board[a - 1][b - 1].getvalue() == 0 || b == 0 || a == 0)
					&& (Enemy_Board[a + 1][b - 1].getvalue() == 0 || b == 0 || a == 9)
					&& (Enemy_Board[a - 1][b + 1].getvalue() == 0 || b == 9 || a == 0)
					&& (Enemy_Board[a + 1][b + 1].getvalue() == 0 || b == 9 || a == 9))
				{
					printf("Hit ship sank!\n");
				}
				else
				{
					printf("Hit ship didn't sink yet! ");
				}
				if (points == WIN)
				{
					for (int i = 0; i <= 9; i++)
					{
						for (int k = 0; k <= 9; k++)
						{
							printf("%c ", Enemy_Board[i][k].getgraphically());
						}
						printf("\n");
					}
					printf("\n");
					printf("\nPlayer %s won! CONGRATULATIONS!", nick);
					break;
				}
			}
			else
			{
				Enemy_Board[a][b].sethit(0);
				Enemy_Board[a][b].setgraphically('*');
				printf("\nYou missed! ");
				stop = 1;
			}
			printf("Player %s, current points: %d", nick, points);
			printf("\nPLAYER %s it is your enemy's board:\t\tyour board right now:\n   A B C D E F G H I J\t\t\t   A B C D E F G H I J\n", nick);//show the board of the player and the board of the enemy
			for (int i = 0; i <= 9; i++)
			{
				if (i == 9)
				{
					printf("%d ", i + 1);
				}
				else
					printf("%d  ", i + 1);
				for (int k = 0; k <= 9; k++)
				{
					printf("%c ", Enemy_Board[i][k].getgraphically());
				}
				printf("\t\t\t");
				if (i == 9)
				{
					printf("%d ", i + 1);
				}
				else
					printf("%d  ", i + 1);
				for (int k = 0; k <= 9; k++)
				{
					printf("%d ", Board[i][k].getvalue());
				}
				printf("\n");
			}
			printf("\n");
		}
		clean_the_screen();
	}
Player:: ~Player() {};