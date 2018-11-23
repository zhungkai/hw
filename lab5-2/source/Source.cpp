#include<stdio.h>
#include<stdlib.h>
#define students 3
#define exams 4

void minmum(int grades[][exams], int pupils, int tests);
void maxmum(int grades[][exams], int pupils, int tests);
void average(int grades[][exams], int pupils, int tests);
void printarray(int grades[][exams], int pupils, int tests);
void printmemu(void);

int main()
{
	void(*processgrades[4])(int[][exams], int, int) = { printarray,minmum,maxmum,average };
	int choice = 0;

	int studentgrades[students][exams] = { {77,68,86,73},{96,87,8,78},{70,90,86,81} };

	while (choice != 4)
	{
		do
		{
			printmemu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
		{
			(*processgrades[choice])(studentgrades, students, exams);
		}
		else 
		{
			printf("program Ended.\n");
		}
	}
	system("pause");
	return 0;
}

void minmum(int grades[][exams], int pupils, int tests)
{
	int j; int i; int lowgrade = 100;

	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grades[i][j] < lowgrade)
			{
				lowgrade = grades[i][j];
			}
		}
	}
	printf("\n\tthe lowest grade is %d\n", lowgrade);
}

void maxmum(int grades[][exams], int pupils, int tests)
{
	int i; int j; int highgrade = 0;

	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grades[i][j] > highgrade)
			{
				highgrade = grades[i][j];
			}
		}
	}
	printf("\n\tthe highest grade is %d\n", highgrade);
}

void average(int grades[][exams], int pupils, int tests)
{
	int i; int j; int total;

	printf("\n");

	for (i = 0; i <= pupils - 1; i++)
	{
		total = 0;
		for (j = 0; j <= tests - 1; j++)
		{
			total += grades[i][j];
		}
		printf("\nthe average for student %d is %.1f\n", i + 1, (double)total / tests);
	}
}

void printarray(int grades[][exams], int pupils, int tests)
{
	int i; int j;

	printf("\n\t                [0]  [1]  [2]  [3]");
	for (i = 0; i <= pupils - 1; i++)
	{
		printf("\n\tstudentgrades[%d]", i);
		for (j = 0; j <= tests - 1; j++)
		{
			printf("%d-7d", grades[i][j]);
		}
	}
	printf("\n");
}

void printmemu(void)
{
	printf("\n\tenter a choice:\n"
		"\t  0 print the array of grades\n"
		"\t  1 find the minmum grade\n"
		"\t  2 find the maximum grade\n"
		"\t  3 print the average on all"
		" tests for each student\n"
		"\t  4 end program\n"
		"\t?");
}