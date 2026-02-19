#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

// ---------- ВВЕДЕННЯ МАТРИЦІ ----------
void inputMatrix(int matr[MAX_SIZE][MAX_SIZE], int &rows, int &cols)
{
    do {
        cout << "Введіть кількість рядків (2–20): ";
        cin >> rows;
        cout << "Введіть кількість стовпців (2–20): ";
        cin >> cols;
    } while (rows < 2 || rows > MAX_SIZE || cols < 2 || cols > MAX_SIZE);

    cout << "Введіть елементи матриці:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matr[i][j];
}

// ---------- ВИВЕДЕННЯ МАТРИЦІ ----------
void printMatrix(const int matr[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    cout << "\nМатриця:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matr[i][j] << "\t";
        cout << endl;
    }
}

// ---------- TASK Matrix23 ----------
// знайти мінімальний елемент у кожному рядку
void rowMinimums(const int matr[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    cout << "\nМінімальні елементи кожного рядка:\n";
    for (int i = 0; i < rows; i++) {
        int minVal = matr[i][0];
        for (int j = 1; j < cols; j++)
            if (matr[i][j] < minVal)
                minVal = matr[i][j];
        cout << "Рядок " << i + 1 << ": " << minVal << endl;
    }
}

void taskMatrix23()
{
    int matr[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    inputMatrix(matr, rows, cols);
    printMatrix(matr, rows, cols);
    rowMinimums(matr, rows, cols);
}

// ---------- ПЕРЕВІРКА СТОВПЦЯ НА ДОДАТНІ ЕЛЕМЕНТИ ----------
bool isPositiveColumn(const int matr[MAX_SIZE][MAX_SIZE], int rows, int col)
{
    for (int i = 0; i < rows; i++)
        if (matr[i][col] <= 0)
            return false;
    return true;
}

// ---------- TASK Matrix53 ----------
// поміняти місцями 1-й стовпець і
// останній стовпець з лише додатніми елементами
void swapColumnsMatrix53(int matr[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
    int posCol = -1;

    for (int j = cols - 1; j >= 0; j--)
        if (isPositiveColumn(matr, rows, j)) {
            posCol = j;
            break;
        }

    if (posCol == -1 || posCol == 0) {
        cout << "\nСтовпець з лише додатними елементами не знайдено.\n";
        cout << "Матриця залишилась без змін.\n";
        return;
    }

    for (int i = 0; i < rows; i++)
        swap(matr[i][0], matr[i][posCol]);

    cout << "\nСтовпці успішно поміняні місцями.\n";
}

void taskMatrix53()
{
    int matr[MAX_SIZE][MAX_SIZE];
    int rows, cols;

    inputMatrix(matr, rows, cols);

    cout << "\nПочаткова матриця:";
    printMatrix(matr, rows, cols);

    swapColumnsMatrix53(matr, rows, cols);

    cout << "\nРезультуюча матриця:";
    printMatrix(matr, rows, cols);
}

// ---------- МЕНЮ ----------
int main()
{
    int вибір;

    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1 - Matrix23 (мінімальні елементи рядків)\n";
        cout << "2 - Matrix53 (обмін стовпців)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> вибір;

        switch (вибір) {
        case 1:
            taskMatrix23();
            break;
        case 2:
            taskMatrix53();
            break;
        case 0:
            cout << "Завершення програми.\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }

    } while (вибір != 0);

    return 0;
}