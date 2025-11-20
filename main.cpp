#include "Time.h"
#include <Windows.h>

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Time t1(12, 30, 45);
    Time t2;
    t2.Read();

    cout << "Час 1: " << t1 << endl;
    cout << "Час 2: " << t2 << endl;

    cout << "Різниця оператором - : " << (t1 - t2) << " сек\n";

    Time t3 = t1 + 500;
    cout << "Час 1 після +500: " << t3 << endl;

    if (t1 > t2) cout << "t1 більше ніж t2\n";
    else cout << "t1 не більше ніж t2\n";

    return 0;
}
