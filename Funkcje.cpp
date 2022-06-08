
#include "Funkcje.h"

int load_int(void)//number <1,10>
{
	int liczba;
	while (scanf_s("%d", &liczba) != 1 || liczba < 1 || liczba > 10 || getchar() != '\n')
	{
		printf("\nIncorrect data. Try again: ");
		while (getchar() != '\n')
			;
	}
	return liczba;
}

int load_letter_column(void)//number  <0,9>
{
	int number;
	char letter;
	number = 0;
	while (scanf("%c", &letter) != 1 || letter < 65 || letter > 74 || getchar() != '\n')
	{
		printf("\nIncorrect data. Try again: ");
		while (getchar() != '\n');	
	}
	if (letter == 65)
		number = 0;
	if (letter == 66)
		number = 1;
	if (letter == 67)
		number = 2;
	if (letter == 68)
		number = 3;
	if (letter == 69)
		number = 4;
	if (letter == 70)
		number = 5;
	if (letter == 71)
		number = 6;
	if (letter == 72)
		number = 7;
	if (letter == 73)
		number = 8;
	if (letter == 74)
		number = 9;
	return number;
}

int wczytaj_jeden(void)//loads number 1
{
	int number; 
	while (scanf_s("%d", &number) != 1 || number != 1 || getchar() != '\n')
	{
		printf("\nIncorrect data. Try again: ");
		while (getchar() != '\n')
			;
	}
	return number;
}

int load_choice(void)//number <1,2>)
{
	int liczba;
	while (scanf_s("%d", &liczba) != 1 || liczba < 1 || liczba > 2 || getchar() != '\n')
	{
		printf("\nIncorrect data. Try again: ");
		while (getchar() != '\n')
			;
	}
	return liczba;
}

int random_number()//random number 0-9
{
	int liczba;
	liczba = rand() % 10;
	return liczba;
}

int draw_even_number()//random even number 0-9
{
	int liczba;
	liczba = (rand() % 5 )* 2;
	return liczba;
}

int random_choice()//random number 1 or 2
{
	int liczba;
	liczba = rand() % 2 + 1;
	return liczba;
}

int load_choice_3(void)//number <1,3>
{
	int liczba; 
	while (scanf_s("%d", &liczba) != 1 || liczba < 1 || liczba > 3 || getchar() != '\n')
	{
		printf("\nIncorrect data. Try again: ");
		while (getchar() != '\n')
			;
	}
	return liczba;
}

int choose_game_mode()
{
	printf("Please choose the game mode:\n");
	printf("1 - Human vs Computer\n2 - Human vs Human\n3 -Computer vs Computer\n");
	int game;
	game = load_choice_3();
	return game;
}

int choose_strategy()
{
	printf("Please choose the computer shooting strategy:\n1 - random shooting\n 2 - hunt strategy\n 3 - parity +hunt strategy\n");
	printf("Enter the number of the strategy: \n");
	int strategy;
	strategy = load_choice_3();//wybranie liczby z przedzia³u 1-3
	return strategy;
}

void clean_the_screen()//czysci dane z konsoli
{
	printf("Enter 1 to continue(player change):");
	int jeden = wczytaj_jeden();
	if(jeden==1)
	system("cls");
	Sleep(2000);
}

