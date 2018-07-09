#include <iostream>
#include "Controller.h"
#include "sha256.h"
#include <string>
#include <windows.h>
using namespace std;

int main() {
    Controller new_user("shurtado98", 100);
    Sleep(400);
    Controller new_user2("fmejia98", 100);
    //doble enlace
    new_user.connect_node(new_user2);
    new_user2+new_user;
    //ver igualdad en tiempo
    new_user.display_menu();
    new_user2.display_menu();
    //hacer una apuesta y ver sincronia
    new_user.display_menu();
    new_user2.display_menu();
     //gastar dinero y mostrar balance
     new_user2.display_menu();
     new_user2.display_menu();
     //gastar mas de lo que puedes
     new_user2.display_menu();

    //realizar otra apuesta
    new_user.display_menu();
    //guardar archivo en cmake
    new_user.display_menu();
    //editar archivo de manera poco etica (CROACIA E INGLATERRA).
    new_user.display_menu();



    return 0;
}