#include "Print.h"

int main()
{
    setlocale(LC_ALL, "");

    do
    {
        printMain();
    } while (printRestart());

    return 0;
}
