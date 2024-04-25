#include <iostream>
#include "Vector/Vector.hpp"

using namespace std;

int main(void)
{
    setlocale(LC_ALL, "Ru");

    int arr[4] = { 3, 4, 5 };
    Vector<int> v1({ 1, 2, 3 });
    
    cout << "Инициализация через список инициализации v1:\n";
    cout << v1 << '\n';
    
    cout << "Инициализация через массив v2" << '\n';
    Vector<int> v2(3, arr);
    cout << v2 << '\n';

    cout << "Пустой вектор v3:\n";
    Vector<int> v3(0);
    cout << v3 << '\n';

    cout << "Заполнение вектора v4:\n";
    Vector<int> v4(5, 5);
    cout << v4 << '\n';
    
    cout << "Единичный вектор v5:\n";
    auto v5 = Vector<int>::UnitVector(3);
    cout << v5 << '\n';

    cout << "v1 + v2:\n";
    cout << v1 + v2 << '\n';

    cout << "v1 - v2:\n";
    cout << v1 - v2 << '\n';

    cout << "v1 * v2:\n";
    cout << v1 * v2 << '\n';

    cout << "v1 / v2:\n";
    cout << v1 / v2 << '\n';

    cout << "v2[0]=0:\n";
    v2[0] = 0;
    cout << v2 << '\n';

    cout << "При делении координаты на ноль:\n";
    try
    {
        cout << "v1 / v2:\n";
        cout << v1 / v2 << '\n';
    }
    catch (BaseException ex)
    {
        cout << ex.what() << '\n';
    }

    cout << "Проверка итераторов: \n";

    cout << "Шаг с помощью инкрементов вперёд v4:\n";
    auto it = v4.begin();
    for (; it != v4.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << '\n';

    cout << "Шаг с помощью через одну вперёд v1:\n";
    it = v1.begin();
    for (; it < v1.end(); it += 2)
    {
        cout << *it << ' ';
    }
    cout << '\n';

    cout << "Шаг с помощью инкрементов вперёд v4:\n";
    it = --v4.end();
    for (; it >= v4.begin(); --it)
    {
        cout << *it << ' ';
    }
    cout << '\n';

    cout << "Шаг с помощью через одну назад v1:\n";
    it = --v1.end();
    for (; it >= v1.begin(); it -= 2)
    {
        cout << *it << ' ';
    }
    cout << '\n';

    return 0;
}