#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 5;
const int N = 4;


// у програмному проєкті розробити функцію, яка дозволить вивести на екран вміст текстового файлу F1
void read_from_file(const char *file1)
{
  ifstream show_matrix(file1);
  if (!show_matrix.is_open()) { //перевірка на те, чи відкритий файл
    cout << "Can't open this file! ";
  } else {
    cout << "File opened!\n ";
    char f1;
    while (show_matrix.get(f1)) { //цикл для виведення вмісту файлу F1
      cout << f1;
    }
    cout << endl;
  }
  cout << "==================================================================" << endl;
  show_matrix.close(); //закриття файлу
}


//формування числової матриці розмірності M на N зчитуванням її значень із файлу F1. Для базового та підвищеного рівня (*) розмірність матриці M та N задати константами
vector<vector<double>> create_array(const char *file1)
{
  fstream input(file1);
  if (!input.is_open()) { //перевірка на те, чи відкритий файл
    cout << "Can't open this file! " << endl;
    return {};
  } else {
    cout << "File opened!\n ";

  vector<vector<double>>matrix(M, vector<double>(N)); //за допомогою бібліотеки vector створення масиву, який автоматично визначає розмірність
    
  //цикли для збереження елементів матриці
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      input >> matrix[i][j];
    }
  }
    
  input.close(); //закриття файлу
    cout << "Matrix: " << endl;
  //цикли для виведення матриці
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
    cout << "==================================================================" << endl;
  return matrix;
}
}


//створити функцію для опрацювання числової матриці з обчисленням значень відповідно до індивідуального варіанта (завдання а та б (*) у табл. 1). Результати обчислень записати у файл F2;

//Запис створеної матриці у файл
void write_matrix_to_file(const vector<vector<double>> &matrix, const char *file2)
{
  ofstream output(file2);
  if (!output.is_open()) { //перевірка на те, чи відкритий файл
    cout << "Can't open this file! " << endl;
    return;
  } else {
    cout << "File opened!\n ";
    output << "==================================================================" << endl;
    output << "Matrix: " << endl;
    //запис матриці у файл F2
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      output << matrix[i][j] << " ";
    }
    output << endl;
  }
    cout << "Matrix successfully wrote to file! " << endl;
    cout << "==================================================================" << endl;
    output << "==================================================================" << endl;
  output.close(); //закриття файлу
}
}


//створити функцію для опрацювання числової матриці з обчисленням значень відповідно до індивідуального варіанта (завдання а та б (*) у табл. 1). Результати обчислень записати у файл F2

//а) Обчислити значення суми додатних показників вимірювань датчиків (елементів матриці)
void sum(const vector<vector<double>> &matrix, const char *file2)
{
  double sum = 0;

  //знаходження суми елементів, що більші 0
  for (int i = 0; i < M; i++)
    for (int j = 0; j < N; j++) {
      if (matrix[i][j] > 0) {
        sum += matrix[i][j];
      }
    }
    ofstream output;
  if (!output.is_open()) { //перевірка на те, чи відкритий файл
    cout << "Can't open this file! ";
  } else {
    cout << "File opened!\n ";
    // додаємо нові данні в файл F2, не видаляючи минулі
    output.open(file2, ios_base::app);
    output << "Sum of elements (that > 0) ==> " << sum << endl;
    output << "==================================================================" << endl;
    output.close(); //закриття файлу
  }
  //виведення суми на екран
  cout << "Sum of elements (that > 0) ==> ";
  cout << sum << endl;
  cout << "==================================================================" << endl;
}



//* Визначити номер стовпця, в якому є щонайдовша серія однакових елементів.
void find_longest_sequence_column(const vector<vector<double>> &matrix, const char *file2)
{
  int longest_sequence_column = 0;
  int longest_sequence_length = 0;
//пошук стовпця з найдовшою серією однакових елементів
  for (int j = 0; j < N; j++) {
    //Функція проходиться по всіх стовпцях матриці. Для кожного стовпця функція рахує довжину поточної серії однакових елементів current_sequence_length
    int current_sequence_length = 1;
    for (int i = 1; i < M; i++) {
      if (matrix[i][j] == matrix[i - 1][j]) {
        //Якщо елемент поточного рядка матриці дорівнює елементу попереднього рядка, то збільшується довжина поточної серії на 1
        current_sequence_length++;
      } else {
        if (current_sequence_length > longest_sequence_length) {
          longest_sequence_length = current_sequence_length;
          longest_sequence_column = j + 1;
        }
        current_sequence_length = 1;
      }
    }
  }
  fstream output;
  output.open(file2, ios_base::app);
  if (!output.is_open()) //перевірка на те, чи відкритий файл
  {
    cout << "Can't open this file! " << endl;
    return;
  } else {
    cout << "File opened! " << endl;
    //запис результату у файл F2
    output << "Column that has the longest series of similary numbers is - " << longest_sequence_column << endl;
      output << "==================================================================" << endl;
    output.close(); //закриття файлу
  }
  //виведення результату на екран
  cout << "Column that has the longest series of similary numbers is - ";
  cout << longest_sequence_column << endl;
  cout << "==================================================================" << endl;
}


//Обчислити елементи вектора як середнє арифметичне показників датчиків (рядків матриці)
void avg(vector<vector<double>> matrix, const char *file2)
{
  int rows = matrix.size(); // кількість рядків у матриці
 fstream output;
  output.open(file2, ios_base::app);
  if (!output.is_open()) //перевірка на те, чи відкритий файл
  {
    cout << "Can't open this file! " << endl;
  } else {
    cout << "File opened! " << endl;
  for (int i = 0; i < rows; i++) {
    double sum = 0, avg;
    int count = matrix[i].size(); // кількість елементів у даному рядку
    for (int j = 0; j < count; j++) {
      sum += matrix[i][j]; // сума елементів у даному рядку
    }
    avg = sum / count; // середнє значення для даного рядка
    output << "Average of elements in row " << i+1 << " is " << avg << endl; // запис середнього значення у файл
    cout << "Average of elements in row " << i+1 << " is " << avg << endl;
  }
    output << "==================================================================" << endl;
    cout << "==================================================================" << endl;
    output.close(); // закрытие файла
}
}



void create_new_array(vector<vector<double>> matrix, const char *file2)
{
   fstream output;
  output.open(file2, ios_base::app);
  if (!output.is_open()) //перевірка на те, чи відкритий файл
  {
    cout << "Can't open this file! " << endl;
  } else {
    cout << "File opened! " << endl;
    int index = -1; // індекс першого нульового значення
    for(int i = 0; i < matrix.size(); i++)
    {
        for(int j = 0; j < matrix[i].size(); j++)
        {
            if(matrix[i][j] == 0)
            {
                index = i;
                break;
            }
        }
        if(index != -1) break;
    }
    int size;
    if(index == -1) // якщо нульових чисел немає, вибрати всі
    {
        size = matrix.size() * matrix[0].size();
    }
    else
    {
        size = (matrix.size() - index - 1) * matrix[0].size();
    }
    vector<double> new_arr(size); // створення вектору з чисел після першого нульового значення
    if(index == -1) // якщо нульових чисел немає, вибрати всі
    {
        int k = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                new_arr[k] = matrix[i][j];
                k++;
            }
        }
    }
    else
    {
        int k = 0;
        for(int i = index + 1; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                new_arr[k] = matrix[i][j];
                k++;
            }
        }
    }
  cout << "New array: " << endl;
     output << "New array: " << endl;
  for ( int i = 0; i < size; i++ )
    {
      cout << new_arr[i] << "\t";
      output << new_arr[i] << "\t";
    }
}
  cout << endl;
  output << endl;
  output << "==================================================================" << endl;
  cout << "==================================================================" << endl;
  output.close();
}



//Створити нову матрицю з тих показників датчиків (рядків матриці), які містять елементи лише в діапазоні [50, 100].
void filter_matrix(vector<vector<double>> matrix, const char* file2)
{
  int filter = 0;
  //цикли в яких шукається кількість елементів, що задовольняє умову
  for (int i = 0; i < M; i++) {
    int filter_count = 0;
    for (int j = 0; j < N; j++) {
      if (matrix[i][j] >= 50 && matrix[i][j] <= 100) {
        filter_count++;
      }
    }
    if (filter_count > 0) {
      filter++;
    }
  }

  // створення нової матриці, що задовльняє умову
  double **newMatrix = new double *[filter];
  int newRow = 0;
  for (int i = 0; i < M; i++) {
    int filter_count = 0;
    for (int j = 0; j < N; j++) {
      if (matrix[i][j] >= 50 && matrix[i][j] <= 100) {
        filter_count++;
      }
    }
    if (filter_count > 0) {
      newMatrix[newRow] = new double[N]; //збереження рядка матриці в одновимірному масиві
      for (int j = 0; j < N; j++) {
        newMatrix[newRow][j] = matrix[i][j]; //збереження нової матриці
      }
      newRow++;
    }
  }

  fstream output(file2, ios_base::app);
  if (!output.is_open()) { //перевірка на те, чи відкритий файл
    cout << "Can't open this file!" << endl;
    return;
  } else {
    cout << "File opened!\n";
  }
    output << "New matrix:\n";
  // запис нового масиву до файлу F2
  for (int i = 0; i < filter; i++) {
    for (int j = 0; j < N; j++) {
      output << newMatrix[i][j] << " ";
    }
    output << endl;
  }
  output << "==================================================================" << endl;
  output.close(); //закриття файлу

  // вивід нової матриці
  cout << "New matrix:\n";
  for (int i = 0; i < filter; i++) {
    for (int j = 0; j < N; j++) {
      cout << newMatrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << "==================================================================" << endl;
  // звільнення пам'яті
  for (int i = 0; i < filter; i++)
  {
    delete[] newMatrix[i];
  }
  delete[] newMatrix;
  
}


//програмно переглянути на екрані вміст текстового файлу F3.txt, ім’я якого передаватиметься як аргумент із функції main();
void look(const char *file3)
{
  ifstream look(file3);
   if (!look.is_open()) { //перевірка на те, чи відкритий файл
     cout << "Can't open this file!" << endl;
  } else {
     cout << "File opened!\n";
         string line;
    while (getline(look, line)) { //цикл для виведення вмісту файлу F3 на екран
      cout << line << endl;
    }
     cout << "==================================================================" << endl;
    look.close(); //закриття файлу
  }
}

//Перетворити регістр літер рядків: якщо перша літера рядка є великою (верхній регістр) перевести до верхнього регістру весь рядок, і навпаки, якщо перша літера мала – до нижнього
void change_line(const char *file3, const char *file2)
{
ifstream input(file3);
ofstream output(file2, ios_base::app);
if (!input.is_open()) { //перевірка на те, чи відкритий файл F3
cout << "Can't open input file!" << endl;
return;
}

if (!output.is_open()) { //перевірка на те, чи відкритий файл F2
cout << "Can't open output file!" << endl;
return;
} else {
cout << "Files opened!" << endl;
string line;
while (getline(input, line)) { //цикл за допомогою якого ми отримуємо вміст файлу F3 та піддаємо змінам, що задоволняють умови
if (!line.empty()) { //перевірка на кінець рядка
if (isupper(line[0])) { //перевірка на те, чи починається рядок з великої літери
transform(line.begin(), line.end(), line.begin(), ::toupper); //переведення до верхнього регістру всього рядка
} else if (islower(line[0])) { //перевірка на те, чи починажться рядок з маленької літери
transform(line.begin(), line.end(), line.begin(), ::tolower); //переведення до нижнього регістру вського рядка
}
}
  output << line << endl;
}
   output << "==================================================================" << endl;
  cout << "Text from F3.txt was changed successfully and outputed in F2.txt! " << endl;
cout << "==================================================================" << endl;
input.close();
output.close();
}
}


void show_result(const char *file2)
{
  ifstream show(file2);
   if (!show.is_open()) { //перевірка на те, чи відкритий файл
     cout << "Can't open this file!" << endl;
  } else {
     cout << "File opened!\n";
     cout << "Outputting results of all functions..." << endl;
         string line;
    while (getline(show, line)) { //цикл для виведення вмісту файлу F3 на екран
      cout << line << endl;
    }
    show.close(); //закриття файлу
  }
}

int main() {
  const char *file1 = "F1.txt";
  const char *file2 = "F2.txt";
  const char *file3 = "F3.txt";

  //Виклик функцій
  read_from_file(file1); //функція для виведення вмісту файлу F1

  vector<vector<double>> matrix = create_array(file1); //функція для створення матриці за допомогою даних з файлу F1

  write_matrix_to_file(matrix, file2); //функція для запису матриці у файл F2

  sum(matrix, file2); //функція для знаходження суми елементів, що більші 0

  find_longest_sequence_column(matrix, file2); //функція для знаходження стовпця з найдовшою серією однакових елементів

  avg(matrix, file2); //знаходження середнього арифметичного всіх елементів матриці

  create_new_array(matrix, file2); // створення масиву з елементiв пiсля нульового

  filter_matrix(matrix, file2); //створення нового масиву з чисел, що потрапляють знаходяться в діапазоні [50;100]

  look(file3); //функція для перегляду вмісту файлу F3

  change_line(file3, file2); //функція для зміни регістру усього рядка залежно від першої літери рядка

  show_result(file2); //фукнція для відображення результатів усіх функцій

  return 0;
}