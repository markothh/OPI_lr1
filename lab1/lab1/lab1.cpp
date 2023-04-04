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

            PrintMatrix(matrix, ROWS, COLS);

            LineSeparator();

            break;


        case 2:
            if (MatrixIsEmpty(matrix))
            {
                cout << "A matrix has not been created yet\n";
            }
            else
            {
                cout << "The output of the matrix in which the elements \nare swapped between minimum and maximum in each row:" << endl << endl;
                ReverseMatrixBetweenMinMax(matrix, ROWS, COLS);
                PrintMatrix(matrix, ROWS, COLS);
            }

            LineSeparator();
            break;

        case 3:

            if (MatrixIsEmpty(matrix))
            {
                cout << "A matrix has not been created yet\n";
            }
            else
            {
                cout << "Main diagonal is symmetric relative to the middle: " << boolalpha << IsDiagonalSymmetric(matrix, ROWS, COLS) << endl << endl;
            }

            LineSeparator();
            break;


        case 4:

            if (MatrixIsEmpty(matrix))
            {
                cout << "A matrix has not been created yet\n";
            }
            else
            {
                cout << "Sum of the positive elements in the square is " << SquarePositiveSum(matrix, ROWS, COLS) << endl;
            }

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

void PrintMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int Min(int* array, int size)
{
    int min = 21, minIndex = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] < min)
        {
            min = array[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int Max(int* array, int size)
{
    int max = 0, maxIndex = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > max)
        {
            max = array[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

void ReverseRowBetweenMinMax(int* array, int size)
{
    int minIndex = Min(array, size), maxIndex = Max(array, size);
    int buf = 0;

    if (minIndex > maxIndex)
    {
        buf = minIndex;
        minIndex = maxIndex;
        maxIndex = buf;
    }

    for (int i = minIndex + 1; i < (maxIndex + minIndex) / 2 + 1; i++) {
        buf = array[i];
        array[i] = array[maxIndex + minIndex - i];
        array[maxIndex + minIndex - i] = buf;
    }
}

void ReverseMatrixBetweenMinMax(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        ReverseRowBetweenMinMax(matrix[i], cols);
    }
};

bool MatrixIsEmpty(int** matrix)
{
    return matrix == nullptr;
}

bool IsDiagonalSymmetric(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        if (matrix[i][i] != matrix[rows - i - 1][rows - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int SquarePositiveSum(int** matrix, int rows, int cols)
{
    int sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > 0)
            {
                sum += matrix[i][j];
            }
        }
    }

    return sum;
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