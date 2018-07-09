//
// Created by Sebastian on 7/07/2018.
//

#ifndef PROYECTOPOOII_BLOCKCHAIN_H
#define PROYECTOPOOII_BLOCKCHAIN_H
#include <ctime>
#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <set>
#include <sstream>
#include "sha256.h"


using namespace std;

struct Transaction{
    string sender;
    string receiver;
    string country;
    int amount;
};

struct Block{
    int index;
    time_t timer;
    int proof;
    string previous_hash;
    vector<Transaction> transactions;

};

//implementar blockchain
class Blockchain {
private:
    int lenght=0;
    vector <Block> chain;
    vector <Transaction> transactions;
    Blockchain();
    Block create_block(int proof, const string&  previous_hash);
    Block get_previous_block();
    int proof_of_work(int previous_proof);
    string hash(Block block);
    bool is_chain_valid();
    int add_transaction(string sender, string receiver, string country, int amount);
    friend class Controller; //desde acá accederemos a Blockchain.

};


//Falta add node, replace chain y set de nodes


#endif //PROYECTOPOOII_BLOCKCHAIN_H
