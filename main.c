/********************************************************************************
* main.c: Programmet lägger till bilar i structen med olika egenskaper som
*         märke, model, färg, år den gjordes och om den är manuel eller
*         automatisk.
*         Det ska sedan gå att ändra färg och byta mellan manuel eller
*         automatisk. Efter det har gjorts ska informationen om bilarna skrivas
*         ut i textfilen cars.txt och sedan läsas där ifrån till terminalen.
********************************************************************************/
#include "car.h"

// Deklarerar statiska objekt med car structen och en cars array.
static struct car car1, car2, car3;
static struct car* cars[3];

/********************************************************************************
* file_read: Funktionen får in filvägen som argument. Med hjälp av denna filväg
*            läser den av vad som står i filen och skriver ut det i terminalen.
********************************************************************************/
void file_read(const char* filepath)
{
	FILE* istream = fopen(filepath, "r");

	if (!istream) return;

	char s[100] = { '\0' };

	while ((fgets(s, sizeof(s), istream)))
	{
		printf("%s", s);
	}

	fclose(istream);
	return;
}
/********************************************************************************
* main: Här börjar programmet.
********************************************************************************/
int main(void)
{	
	// Skapar en filpekare som pekar på filen cars.txt och gör den redo att bifoga text till.
	FILE* ostream = fopen("cars.txt", "a");

	// Initierar dem tre olika bilarna.
	car_init(&car1, "Volvo", "V70", "Black", 1995, CAR_TRANSMISSION_MANUAL);
	car_init(&car2, "BWM", "Z3", "Blue", 2001, CAR_TRANSMISSION_AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, CAR_TRANSMISSION_MANUAL);

	// Ändarar färg och växellåda på bil 3.
	car_change_color(&car3, "Green");
	car_change_transmission(&car3);
	
	// Lägger in alla bilarna i en array.
	static struct car* cars[3] = { &car1, &car2, &car3 };

	// Skriver ut alla bilarna till terminalen.
	for (int i = 0; i < 3; i++)
	{
		car_print(cars[i], ostream);
	}

	// Stänger pekaren ostream då vi ej ska använda den mer.
	fclose(ostream);

	file_read("cars.txt");

    return 0;
}

