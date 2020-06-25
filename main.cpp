#include <iostream>
#include "classes/Cliente.h"

using namespace std;

int main() {
    Cliente *cliente = new Cliente("Luis", "Casa", "3125642338", "25/01/2001");
    cliente->Store();
    return 0;
}