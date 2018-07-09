//
// Created by Sebastian on 8/07/2018.
//

#ifndef PROYECTOPOOII_CONTROLLER_H
#define PROYECTOPOOII_CONTROLLER_H
#include "Blockchain.h"
#include <fstream>


struct CheckBlock{
    int index;
    long int timer;
    int proof;
    string previous_hash;
    vector<Transaction> transactions;
};



class Controller {
private:
    Blockchain blockchain;
    string user;
    int i=0;
    int balance;
    Controller* nodes[1];
    int get_balance();
    void display_chain();
    void display_bet();
    void mine_block();
    void save_file(string filename);
    void replace_chain();
    void add_node(Controller& node);
    string hash(CheckBlock block);
    void check_file(string filename);

public:
    Controller(string new_user, int new_balance);
    void connect_node(Controller& new_friend);
    void operator+(Controller& node);
    void display_menu();


};


#endif //PROYECTOPOOII_CONTROLLER_H
