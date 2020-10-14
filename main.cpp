/*Ежов 204
 *Бюджет
 * Сложение, вычитание, умножение, деление
 * нахождение сопряжённого, сравнение комплексных чисел
 * */
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

class Budget
{
private:
    //Коэфициенты комплексного числа
    double a, b;
public:
    //Стандартный конструктор
    Budget(){
        a = 0;
        b = 0;
    }
    //Конструктор
    Budget(double arg1, double arg2){
        a = (round(arg1*100))/100;
        b = (round(arg2*100))/100;
    }
    //Геттеры и сеттеры для private переменных
    double get_a() const{
        return a;
    }
    double get_b() const{
        return b;
    }
    void set_a(double input){
        a = input;
    }
    void set_b(double input){
        b = input;
    }
    //Печать бюджета на экран
    void Print() const{
        cout << "Собственная часть средств: " << this->a << " Заёмная часть средств: " << this->b << endl;
    }
    //Прототипы операторов
    friend Budget operator +(Budget &first, Budget &second);
    friend Budget operator -(Budget &first, Budget &second);
    friend Budget operator *(Budget &first, Budget &second);
    friend Budget operator /(Budget &first, Budget &second);
    friend bool operator ==(Budget &first, Budget &second);
    friend bool operator <=(Budget &first, Budget &second);
    friend bool operator >=(Budget &first, Budget &second);
    friend bool operator >(Budget &first, Budget &second);
    friend bool operator <(Budget &first, Budget &second);

    ~Budget() //деструктор
    = default;
};

Budget operator"" _bg(const char *str){
    double budget[2];
    sscanf(str, "%lf %lf", budget[0], budget[1]);
    return Budget(budget[0], budget[1]);
}


Budget operator +(Budget &first, Budget &second){
    Budget res = Budget(first.a + second.a, first.b + second.b);
    return res;
}

Budget operator -(Budget &first, Budget &second){
    double d = first.a - second.a;
    double z = first.b - second.b;
    if (d < 0){
        z -= d;
        d = 0;
    }
    Budget res = Budget(d, z);
    return res;
}

Budget operator *(Budget &first, Budget &second){
    Budget res = Budget(first.a * second.a,first.b*second.b);
    return res;
}

Budget operator /(Budget &first, Budget &second){
    Budget res = Budget(first.a/second.a, first.b/second.b);
    return res;
}

bool operator < (Budget &first, Budget &second){
    if (first.a - first.b < second.a - second.b)
        return true;
    else
        return false;
}

bool operator > (Budget &first, Budget &second){
    if (first.a - first.b > second.a - second.b)
        return true;
    else
        return false;
}

bool operator >= (Budget &first, Budget &second){
    if (first.a - first.b >= second.a - second.b)
        return true;
    else
        return false;
}

bool operator <= (Budget &first, Budget &second){
    if (first.a - first.b <= second.a - second.b)
        return true;
    else
        return false;
}

bool operator ==(Budget &first, Budget &second){
    if(first.a == second.a && first.b == second.b)
        return true;
    else
        return false;

}

int main(int argc, char *argv[])
{
    double a1, b1, a2, b2;
    //Если передали аргументом имя файла, то читаем бюджет из него
    if (argc == 1)
    {
        cout << "Введите собственную и заёмную часть средств первого бюджета: ";
        cin >> a1 >> b1;
        cout << "Введите собственную и заёмную часть средств второго бюджет: ";
        cin >> a2 >> b2;
        if(cin.fail()){
            //Если не число, то выдаём ошибку
            cout << "ERROR!" << endl;
            return 1;
        }
    }
        //В ином случае читаем с консоли
    else
    {
        ifstream file (argv[1]);
        file >> a1 >> b1 >> a2 >> b2;
        if(file.fail()){
            //Если не число, то выдаём ошибку
            cout << "ERROR!" << endl;
            return 1;
        }
        file.close();
    }
    //Первый бюджет
    Budget a = Budget (a1, b1);
    //Второй бюджет
    Budget b = Budget(a2, b2);
    //Экземпляр класса бюджет для хранения арифмитических операций
    Budget res = Budget();

    res = a+b;
    cout << "a + b = ";
    res.Print();
    res = a-b;
    cout << "a - b = ";
    res.Print();
    res = a*b;
    cout << "a * b = ";
    res.Print();
    res = a/b;
    cout << "a / b = ";
    res.Print();
    res.Print();
    cout << "a < b?: " << (int)(a<b) << endl << "a > b ?: " << (int)(a>b) << endl << "a == b ?: " <<  (int)(a==b)
         << endl;
    return 0;
}