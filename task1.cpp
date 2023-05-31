#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string filename = "text.txt"; // имя файла

    ifstream file(filename); // создаем поток для чтения файла
    if (!file.is_open()) // проверяем, удалось ли открыть файл
    {
        cout << "Ошибка чтения файла!" << endl;
        return 1;
    }

    int count = 0; // счетчик точек
    char c = '\0'; // текущий символ

    while (file.get(c)) // читаем символы из файла, пока не достигнем конца файла
    {
        if (c == '.') // если текущий символ - точка, увеличиваем счетчик
        {
            count++;
        }
    }

    file.close(); // закрываем файл

    cout << "Количество точек в файле: " << count << endl; // выводим результат

    return 0;
}
