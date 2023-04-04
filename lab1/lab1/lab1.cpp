#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void CreateRandomMatrix(int***, int, int);
void PrintMatrix(int**, int, int);
int Min(int*, int);
int Max(int*, int);
void ReverseRowBetweenMinMax(int*, int);
void ReverseMatrixBetweenMinMax(int** matrix, int, int);
bool IsDiagonalSymmetric(int**, int, int);
int SquarePositiveSum(int**, int, int);
bool MatrixIsEmpty(int**);
void Menu();
void LineSeparator();


const int ROWS = 10, COLS = 10;
const int RANGE_BOTTOM = 1, RANGE_TOP = 20;

int main()
{
    srand(time(NULL));

    int** matrix{};
    int select = 1;

    while (select)
    {

        Menu();

        cout << "Choose a number from 1 to 4" << endl;
        cin >> select;

        switch (select)

        {
        case 1:
            cout << "Your random matrix:" << endl << endl;

            CreateRandomMatrix(&matrix, ROWS, COLS);

            LineSeparator();

            break;


        case 2:

            cout << " Rearrange the elements located between the minimum and maximum elements in reverse order" << endl << endl;

            LineSeparator();

            
            break;

        case 3:

           cout << " Check whether the main diagonal is symmetric with respect to its middle element" << endl << endl;

            LineSeparator();

            
            break;


        case 4:

            cout << "Find the sum of the positive elements among the matrix elements that are highlighted in black (according to the task)" << endl << endl;

            LineSeparator();

            break;

        case 0:
            break;

        default:
            cout << "You entered something wrong, try again!" << endl;
            LineSeparator();

            break;

        }

    }
}

void CreateRandomMatrix(int*** matrix, int rows, int cols)
{
    (*matrix) = new int* [rows];

    for (int i = 0; i < rows; i++) {
        (*matrix)[i] = new int[cols];

        for (int j = 0; j < cols; j++) {
            (*matrix)[i][j] = rand() % RANGE_TOP + RANGE_BOTTOM;
        }
    }
}


void Menu()
{
    cout << "What do you want?" << endl << endl;
    cout << "1. Create and output a random matrix of size 10 by 10" << endl;
    cout << "2. Rearrange the elements located between the minimum and maximum elements in reverse order" << endl;
    cout << "3. Check whether the main diagonal is symmetric with respect to its middle element." << endl;
    cout << "4. Find the sum of the positive elements among the matrix elements that are highlighted in black (according to the task)" << endl;
    cout << "0. Exit" << endl << endl;

}

void LineSeparator()
{
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "---------------------------------------------------------------------------------------\n";
}