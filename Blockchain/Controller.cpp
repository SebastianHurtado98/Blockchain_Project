//
// Created by Sebastian on 8/07/2018.
//

#include "Controller.h"

Controller::Controller(string new_user, int new_balance) {
    user= new_user;
    balance= new_balance;
}

int Controller::get_balance() {
    for (auto& block : blockchain.chain){
        int prize= 0;
        for (auto& transaction: block.transactions){
            if (transaction.sender==user) prize= -transaction.amount;
            balance=+ prize;
            if (transaction.receiver==user) prize= transaction.amount;
            balance=+prize;
        }
    }
    return balance;
}

void Controller::mine_block() {
    Block previous_block = blockchain.get_previous_block();
    int previous_proof = previous_block.proof;
    int proof = blockchain.proof_of_work(previous_proof);
    string previous_hash = blockchain.hash(previous_block);
    blockchain.add_transaction("localhost: "+ user, user, "NULL", 1);
    blockchain.create_block(proof, previous_hash);
}

void Controller::display_menu() {

    int index;
    cout << endl;
    cout << "MENU - APUESTAS";
    cout << endl;
    cout << "VER HISTORIAL - 1";
    cout << endl;
    cout << "REALIZAR APUESTA - 2";
    cout << endl;
    cout << "VER BALANCE - 3";
    cout << endl;
    cout << "GUARDAR ARCHIVO - 4";
    cout << endl;
    cout << "VERIFICAR CADENA - 5";
    cout << endl;

    cin>>index;
    cout << endl;
    if(index==1){
        display_chain();
    }
    if(index==2){
        display_bet();
    }
    if(index==3){
        cout << endl << get_balance() <<" utecoins.";
    }
    if(index==4){
        string file;
        cout << endl << "nombre del archivo: ";
        cin>> file;
        save_file(file);
        cout << endl << "guardado.";
    }
    /*
    if(index==5){
        string file;
        cout << endl<< "nombre del archivo: ";
        cin>> file;
        check_file(file);
        cout << endl << "FIN.";
    }
     */

}

void Controller::display_chain() {
   replace_chain();

    for (auto &block : blockchain.chain) {
        cout << to_string(block.index) << endl;
        cout << to_string(block.timer) << endl;
        cout << to_string(block.proof) << endl;
        cout << block.previous_hash << endl;
        //TRANSACTIONS:
        for (auto &transaction: block.transactions) {
            cout << transaction.sender << endl;
            cout << transaction.receiver << endl;
            cout << transaction.country << endl;
            cout << to_string(transaction.amount) << endl;
        }
    }

}


void Controller::display_bet() {
    replace_chain();
    string country;
    int amount;
    cout << "REALIZA TU APUESTA" << endl;
    cout << "COUNTRY: ";
    cin >> country;
    cout << endl;
    cout << "AMOUNT: ";
    cin >> amount;
    cout << endl;
    if (amount <= get_balance()) {
        blockchain.add_transaction(user, "house", country, amount);
        mine_block();
    }
    else {
        cout << "NO HAY SUFICIENTES UTECOINS";
    }


}


void Controller::connect_node(Controller& new_friend) {
    add_node(new_friend);
    cout << "SE AGREGA A " << new_friend.user << " A TU NETWORK" << endl;
}


void Controller::add_node(Controller& node) {
    nodes[i]=&node;
    i++;
}

void Controller::replace_chain() {
    for (auto& x: nodes){
        if((blockchain.lenght < (x->blockchain.lenght))&& (x->blockchain.is_chain_valid())){
            blockchain.chain= x->blockchain.chain;
        }
    }

}

void Controller::save_file(string filename) {
    ofstream myfile;
    myfile.open (filename);
    replace_chain();
    for (auto &block : blockchain.chain) {
        myfile << to_string(block.index) << endl;
        myfile << to_string(block.timer) << endl;
        myfile << to_string(block.proof) << endl;
        myfile << block.previous_hash << endl;
        //TRANSACTIONS:
        for (auto &transaction: block.transactions) {
            myfile << transaction.sender << endl;
            myfile << transaction.receiver << endl;
            myfile << transaction.country << endl;
            myfile << to_string(transaction.amount) << endl;
        }
    }
    myfile.close();
}

void Controller::operator+(Controller &node) {
    add_node(node);
}


//INTENTO DE VERIFICAR POR ARCHIVOS
void Controller::check_file(string filename) {

    ifstream file(filename);
    string str;
    CheckBlock block;
    vector <CheckBlock> chain;
    Transaction transaction;
    //AÑADIR
        getline(file, str);
        block.index= stoi(str);getline(file, str);
        block.timer= stol(str);getline(file, str);
        block.proof= stoi(str);getline(file, str);
        block.previous_hash= str;getline(file, str);
        chain.push_back(block);getline(file, str);
        block.index= stoi(str);getline(file, str);
        block.timer= stol(str);getline(file, str);
        block.proof= stoi(str);getline(file, str);
        block.previous_hash= str;getline(file, str);
        transaction.sender= str;getline(file, str);
        transaction.receiver= str;getline(file, str);
        transaction.country= str;getline(file, str);
        transaction.amount= stoi(str);getline(file, str);
        block.transactions.push_back(transaction);getline(file, str);
        transaction.sender= str;getline(file, str);
        transaction.receiver= str;getline(file, str);
        transaction.country= str;getline(file, str);
        transaction.amount= stoi(str);getline(file, str);
        block.transactions.push_back(transaction);
        chain.push_back(block);
        cout << chain[0].proof;

        //FIN DE AÑADIR
    int lenght= chain.size();
    CheckBlock previous_block = chain[0];

    int block_index = 1, previous_proof, proof;
    string hash_operation;
    while (block_index < lenght) {
        block = chain[block_index];
        if (block.previous_hash != hash(previous_block)) cout << "FALSE FILE";
        previous_proof = previous_block.proof;
        proof = block.proof;
        hash_operation= sha256(to_string(proof^2 - previous_proof^2));
        if (hash_operation.substr(0,4) != "0000") cout << "FALSE FILE";
        previous_block = block;
        block_index += 1;
    }
    cout <<"REAL FILE";
}

string Controller::hash(CheckBlock block) {
    string str;
    str= str + "INDEX: " + to_string(block.index) + ", DATETIME: " + to_string(block.timer) +", PROOF: " + to_string(block.proof)+", PREVIOUS HASH: " + block.previous_hash;
    for (auto& transaction: block.transactions){
        str= str + "\n" + ", TRANSACTION: "+ "{sender: "+ transaction.sender + ", receiver: " + transaction.receiver + ", country: "+ transaction.country + ", amount: " + to_string(transaction.amount);
        str+= "\n";
    }
    string encoded_block= sha256(str);
    return encoded_block;


}