//
// Created by Sebastian on 7/07/2018.
//

#include "Blockchain.h"

Blockchain::Blockchain() {
    create_block(1, "0");

}

Block Blockchain::create_block(int proof, const string& previous_hash) {
    Block block={lenght+1, time(NULL), proof,  previous_hash, transactions};
    lenght++;
    chain.push_back(block);
    transactions={};
    return block;
}

Block Blockchain::get_previous_block() {

    return chain.back();
}

int Blockchain::proof_of_work(int previous_proof) {
    int new_proof= 1;
    bool check_proof= false;

    string hash_operation;

    while(!check_proof){
        hash_operation= sha256(to_string(new_proof^2 - previous_proof^2));
        if (hash_operation.substr(0,4)=="0000")
        {
            check_proof= true;
        }
        else{
            new_proof++;
        }
    }
    return new_proof;
}

string Blockchain::hash(Block block) {
    string str;
    str= str + "INDEX: " + to_string(block.index) + ", DATETIME: " + to_string(block.timer) +", PROOF: " + to_string(block.proof)+", PREVIOUS HASH: " + block.previous_hash;
    for (auto& transaction: block.transactions){
        str= str + "\n" + ", TRANSACTION: "+ "{sender: "+ transaction.sender + ", receiver: " + transaction.receiver + ", country: "+ transaction.country + ", amount: " + to_string(transaction.amount);
        str+= "\n";
    }
    string encoded_block= sha256(str);
    return encoded_block;
}

bool Blockchain::is_chain_valid() {
    Block previous_block = chain[0];
    Block block;
    int block_index = 1, previous_proof, proof;
    string hash_operation;
    while (block_index < lenght) {
        block = chain[block_index];
        if (block.previous_hash != hash(previous_block)) return false;
        previous_proof = previous_block.proof;
        proof = block.proof;
        hash_operation= sha256(to_string(proof^2 - previous_proof^2));
        if (hash_operation.substr(0,4) != "0000") return false;
        previous_block = block;
        block_index += 1;
    }
    return true;
}

int Blockchain::add_transaction(string sender, string receiver, string country, int amount) {

    Transaction transaction= {sender, receiver, country, amount};
    transactions.push_back(transaction);
    Block previous_block= get_previous_block();
    return previous_block.index + 1;
}



//Falta add node, replace chain y set de nodes




