// задание 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

struct Bagage {
public:
	int countBagage;
	double weight;
    Bagage() : countBagage(0), weight(0.0) {

    }
    Bagage(int c, double w) : countBagage(c), weight(w) {

    }
};
int main()
{
    const int size = 6;
    setlocale(LC_ALL, "Russian");

    Bagage passengers[size];

    ifstream file("1.txt");
    if (file.is_open()) {
        for (int i = 0; i < size; ++i) {
            int countbagage;
            double weight;
            file >> countbagage >> weight;
            passengers[i] = Bagage(countbagage, weight);
        }
        file.close();

        cout << "Пассажиры с одной вещью и весом менее 5 кг:\n";
        for (int i = 0; i < size; i ++) {
            if (passengers[i].countBagage == 1 && passengers[i].weight < 5.0) {
                cout << "количество вещей: " << passengers[i].countBagage << ", вес: " << passengers[i].weight << " кг\n";
            }
        }
    }
    else {
        cout << "Ошибка открытия файла\n";
    }
    /*
    FILE* file = fopen("1.txt", "r");
    for (int i = 0; i < size; i++) {
        if (feof(file)) break;
        else {
            int b;
            float c;
            fscanf(file, "%d %s", &b, &c);
            passengers[i] = Bagage(b, c);
        }
    }
    fclose(file);
    for (int i = 0; i < size; i++) {
        if (passengers[i].countBagage == 1 && passengers[i].weight < 5.0) {
            cout << "Количество вещей: " << passengers[i].countBagage << ", Вес: " << passengers[i].weight << " кг\n";
        }
    }*/
}