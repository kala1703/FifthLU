#include <iostream>
#include <algorithm>
using namespace std;


void zadacha1() {
    cout << "\n========================================\n";
    cout << "  ЗАДАЧА 1: Демонстрация на указатели\n";
    cout << "========================================\n\n";

    int    num    = 42;
    double pi     = 3.14159;
    char   letter = 'A';

    int    *pNum    = &num;
    double *pPi     = &pi;
    char   *pLetter = &letter;

    cout << "--- int ---\n";
    cout << "  Стойност на num          : " << num    << "\n";
    cout << "  Адрес на num (&num)      : " << &num   << "\n";
    cout << "  Стойност на pNum         : " << pNum   << "\n";
    cout << "  Стойност чрез *pNum      : " << *pNum  << "\n\n";

    cout << "--- double ---\n";
    cout << "  Стойност на pi           : " << pi     << "\n";
    cout << "  Адрес на pi (&pi)        : " << &pi    << "\n";
    cout << "  Стойност на pPi          : " << pPi    << "\n";
    cout << "  Стойност чрез *pPi       : " << *pPi   << "\n\n";

    cout << "--- char ---\n";
    cout << "  Стойност на letter       : " << letter            << "\n";
    cout << "  Адрес на letter (&letter): " << (void*)&letter    << "\n";
    cout << "  Стойност на pLetter      : " << (void*)pLetter    << "\n";
    cout << "  Стойност чрез *pLetter   : " << *pLetter          << "\n\n";

    cout << "--- Промяна на стойност чрез указател ---\n";
    cout << "  num преди промяна        : " << num    << "\n";
    *pNum = 100;
    cout << "  num след *pNum = 100     : " << num    << "\n";
}





void zadacha2() {
    cout << "\n========================================\n";
    cout << "  ЗАДАЧА 2: Аритметика с указатели\n";
    cout << "========================================\n\n";

    double a, b;
    cout << "Въведете първо число : ";  cin >> a;
    cout << "Въведете второ число : ";  cin >> b;

    double *pA = &a;
    double *pB = &b;

    cout << "\n--- Резултати ---\n";
    cout << "  Сума       (*pA + *pB) = " << *pA + *pB << "\n";
    cout << "  Разлика    (*pA - *pB) = " << *pA - *pB << "\n";
    cout << "  Умножение  (*pA * *pB) = " << *pA * *pB << "\n";
    if (*pB != 0)
        cout << "  Деление    (*pA / *pB) = " << *pA / *pB << "\n";
    else
        cout << "  Деление                  : невъзможно (деление на 0)!\n";
}




void zadacha3() {
    cout << "\n========================================\n";
    cout << "  ЗАДАЧА 3: Най-дълга площадка\n";
    cout << "========================================\n\n";

    int n;
    cout << "Въведете брой елементи N: ";  cin >> n;
    int a[1000];
    cout << "Въведете " << n << " сортирани числа: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int bestStart = 0, bestLen = 1;
    int curStart  = 0, curLen  = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            curLen++;
        } else {
            curStart = i;
            curLen   = 1;
        }
        if (curLen > bestLen) {
            bestLen   = curLen;
            bestStart = curStart;
        }
    }

    cout << "\n  Начален индекс на площадката : " << bestStart << "\n";
    cout << "  Дължина на площадката        : " << bestLen   << "\n";
    cout << "  Стойност на елементите       : " << a[bestStart] << "\n";
}





void zadacha4() {
    cout << "\n========================================\n";
    cout << "  ЗАДАЧА 4: Релации a0<a1>a2<a3...\n";
    cout << "========================================\n\n";

    int n;
    cout << "Въведете брой елементи N: ";  cin >> n;
    int a[1000];
    cout << "Въведете " << n << " числа: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    bool ok = true;
    for (int i = 0; i < n - 1 && ok; i++) {
        if (i % 2 == 0) {        // четен индекс -> a[i] < a[i+1]
            if (!(a[i] < a[i+1])) ok = false;
        } else {                  // нечетен индекс -> a[i] > a[i+1]
            if (!(a[i] > a[i+1])) ok = false;
        }
    }

    cout << "\n  Резултат: ";
    if (ok)
        cout << "Релациите са ИЗПЪЛНЕНИ (a0<a1>a2<a3...)\n";
    else
        cout << "Релациите НЕ са изпълнени.\n";
}


void zadacha5() {
    cout << "\n========================================\n";
    cout << "  ЗАДАЧА 5: Обръщане на масив\n";
    cout << "========================================\n\n";

    int n;
    cout << "Въведете брой елементи N: ";  cin >> n;
    int a[1000];
    cout << "Въведете " << n << " числа: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0, j = n-1; i < j; i++, j--)
        swap(a[i], a[j]);

    cout << "\n  Обърнат масив: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}





void zadacha6() {
    cout << "\n========================================\n";
    cout << "  ЗАДАЧА 6: Ротация с K позиции\n";
    cout << "========================================\n\n";

    int n;
    cout << "Въведете брой елементи N: ";  cin >> n;
    int a[1000];
    cout << "Въведете " << n << " числа: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cout << "Въведете K (брой позиции): ";  cin >> k;
    k = ((k % n) + n) % n;   // нормализиране

    // Ротация: reverse частично, после изцяло
    reverse(a, a + k);
    reverse(a + k, a + n);
    reverse(a, a + n);

    cout << "\n  Масив след ротация: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}





void zadacha7() {
    cout << "\n========================================\n";
    cout << "  ЗАДАЧА 7: K-ти по големина елемент\n";
    cout << "========================================\n\n";

    int n;
    cout << "Въведете брой елементи N: ";  cin >> n;
    int a[1000];
    cout << "Въведете " << n << " числа: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int k;
    cout << "Въведете K: ";  cin >> k;

    if (k < 1 || k > n) {
        cout << "\n  Невалидно K!\n";
        return;
    }

    int b[1000];
    for (int i = 0; i < n; i++) b[i] = a[i];
    sort(b, b + n);   

    cout << "\n  " << k << "-тият по големина елемент е: " << b[n - k] << "\n";
}






void zadacha9() {
    cout << "\n========================================\n";
    cout << "  ЗАДАЧА 9: Подредица с дадена сума\n";
    cout << "========================================\n\n";

    int n;
    cout << "Въведете брой елементи N: ";  cin >> n;
    int a[1000];
    cout << "Въведете " << n << " числа: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int target;
    cout << "Въведете целева сума: ";  cin >> target;

    bool found = false;
    for (int i = 0; i < n && !found; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == target) {
                cout << "\n  Намерена подредица: ";
                for (int k = i; k <= j; k++) cout << a[k] << " ";
                cout << "\n";
                found = true;
                break;
            }
        }
    }
    if (!found)
        cout << "\n  Няма подредица с такава сума.\n";
}








void zadacha11() {
    cout << "\n========================================\n";
    cout << "  ЗАДАЧА 11: Макс. редица еднакви ел.\n";
    cout << "========================================\n\n";

    int n;
    cout << "Въведете брой елементи N: ";  cin >> n;
    int a[1000];
    cout << "Въведете " << n << " числа: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    int bestStart = 0, bestLen = 1;
    int curStart  = 0, curLen  = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) {
            curLen++;
        } else {
            curStart = i;
            curLen   = 1;
        }
        if (curLen > bestLen) {
            bestLen   = curLen;
            bestStart = curStart;
        }
    }

    cout << "\n  Най-дълга редица от еднакви елементи: ";
    for (int i = bestStart; i < bestStart + bestLen; i++) cout << a[i] << " ";
    cout << "\n  (дължина: " << bestLen << ", стойност: " << a[bestStart] << ")\n";
}

// ============================================================
//  Главно меню
// ============================================================
int main() {
    int izbor;
    do {
        cout << "\n╔═══════════════════════════════════════════╗\n";
        cout <<   "║              ГЛАВНО МЕНЮ                  ║\n";
        cout <<   "╠═══════════════════════════════════════════╣\n";
        cout <<   "║  1.  Демонстрация на указатели            ║\n";
        cout <<   "║  2.  Аритметика с указатели               ║\n";
        cout <<   "║  3.  Най-дълга площадка в масив           ║\n";
        cout <<   "║  4.  Релации a0<a1>a2<a3...               ║\n";
        cout <<   "║  5.  Обръщане на масив                    ║\n";
        cout <<   "║  6.  Ротация с K позиции                  ║\n";
        cout <<   "║  7.  K-ти по големина елемент             ║\n";
        cout <<   "║  9.  Подредица с дадена сума              ║\n";
        cout <<   "║  10. Вмъкване на елементи в масив         ║\n";
        cout <<   "║  11. Макс. редица от еднакви елементи     ║\n";
        cout <<   "║  0.  Изход                                ║\n";
        cout <<   "╚═══════════════════════════════════════════╝\n";
        cout << "Избор: ";
        cin  >> izbor;

        switch (izbor) {
            case 1:  zadacha1();  break;
            case 2:  zadacha2();  break;
            case 3:  zadacha3();  break;
            case 4:  zadacha4();  break;
            case 5:  zadacha5();  break;
            case 6:  zadacha6();  break;
            case 7:  zadacha7();  break;
            case 9:  zadacha9();  break;
            case 11: zadacha11(); break;
            case 0:  cout << "\nДовиждане!\n\n"; break;
            default: cout << "\nНевалиден избор! Моля, опитайте отново.\n";
        }
    } while (izbor != 0);

    return 0;
}