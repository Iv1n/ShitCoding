#include <iostream>
#include <cmath>


using namespace std;
int main() {
    setlocale(LC_ALL, "ru");

    int N = 0;//колличесвто символов в сообщении
    double l = 0; //среднее число бит 
    double H = 0; //энтропия источника
    double C = 0; //ээфективность проскная способность 
    double R = 0; //избыточность 
    double C1 = 0; //ээфективность проскная способность 
    double R1 = 0; //избыточность 
    double R2 = 0;
    double n = 0; //скорость передачи сиволов 
    int T = 0; //колличество 2-ой вероятности
    double H1 = 0;
    double l1 = 0;

    cout << "Введите колличество символов в сообщение :";
    cin >> N;
    cout << "Введите скорость передачи символа n (бит/c) :";
    cin >> n;
    cout << "Введите вероятности появления символа :" << endl;

    T = N * N;
    cout << T << endl;
    //заполнения массива вероятностями 
    double* a = new double[N];
    for (int i = 0; i < N; i++) {
        cout << "P" << i + 1 << "=";
        cin >> a[i];
    }

    //сортировка массива
    cout << "" << endl;
    cout << "Отсортированный массив по убыванию :" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - i; j++) {
            if (a[j] < a[j + 1]) {
                double temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    //массив с вероятностями 
    double* k = new double[N];
    for (int i = 0; i < N; i++) {
        k[i] = a[i];
    }

    double* e = new double[T];
    e[0] = k[0] * k[0];
    e[1] = k[0] * k[1];
    e[2] = k[0] * k[2];
    e[3] = k[1] * k[0];
    e[4] = k[1] * k[1];
    e[5] = k[1] * k[2];
    e[6] = k[2] * k[0];
    e[7] = k[2] * k[1];
    e[8] = k[2] * k[2];

    for (int i = 0; i < N; i++) {
        cout << "a[" << i + 1 << "]=" << a[i] << endl;
    }

    cout << "" << endl;

    //нахождение энтропии 
    for (int i = 0; i < N; i++) {
        a[i] = a[i] * (log(a[i]) / log(2));
    }
    for (int i = 0; i < N; i++) {
        H = H - a[i];
    }
    cout << "Энтропия источника (бит) =" << H << endl;
    cout << "" << endl;

    double* o = new double[N];
    for (int i = 0; i < N; i++) {
        cout << "Введите количество символов использованных для коддирования " << "[" << i + 1 << "]" << "-го символа :";
        cin >> o[i];
    }

    cout << "" << endl;

    for (int i = 0; i < N; i++) {
        o[i] = o[i] * k[i];
    }
    for (int i = 0; i < N; i++) {
        l = o[i] + l;
    }

    cout << "Среднее число бит затраченное на кодировку одного символа :" << l << endl;

    R = l - H;
    cout << "Избыточность(бит) :" << R << endl;

    C = n * l;
    cout << "Эффективность(симв/с) :" << C << endl;
    cout << "" << endl;

    cout << "Отсортированный массив по убыванию :" << endl;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T - i; j++) {
            if (e[j] < e[j + 1]) {
                double temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
    double* k1 = new double[T];
    for (int i = 0; i < T; i++) {
        k1[i] = e[i];
    }

    for (int i = 0; i < T; i++) {
        cout << "a[" << i + 1 << "]=" << e[i] << endl;
    }

    for (int i = 0; i < T; i++) {
        e[i] = e[i] * (log(e[i]) / log(2));
    }
    for (int i = 0; i < T; i++) {
        H1 = H1 - e[i];
    }
    cout << "Энтропия источника (бит) =" << H1 << endl;
    cout << "" << endl;

    double* q = new double[T];
    for (int i = 0; i < T; i++) {
        cout << "Введите количество символов использованных для коддирования " << "[" << i + 1 << "]" << "-го символа :";
        cin >> q[i];
    }

    cout << "" << endl;

    for (int i = 0; i < T; i++) {
        q[i] = q[i] * k1[i];
    }
    for (int i = 0; i < T; i++) {
        l1 = q[i] + l1;
    }
    cout << "Среднее число бит затраченное на кодировку одного символа :" << l1 << endl;

    R1 = l1 - H1;
    cout << "Избыточность(бит) :" << R1 << endl;

    C1 = n * l1;
    cout << "Эффективность(симв/с) :" << C1 << endl;
    cout << "" << endl;

    R2 = R1 - R;
    cout << "Разность избыточностей :" << R2 << endl;

}