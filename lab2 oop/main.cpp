// home film library

#include <fstream>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "interface.cpp"

using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);//Подключение русского языка
    play r;
    r.run();
}
