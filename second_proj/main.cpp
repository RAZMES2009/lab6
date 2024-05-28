#include "main.h"
#include "logic.h"

int main(int argc, char *argv[])
{
    system("chcp 1251"); // windows encode 1251
    checkEnterArgs(argc, argv);
    runApp(argv);
    return 0;
}