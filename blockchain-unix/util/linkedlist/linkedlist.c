#include "linkedlist.h"

#define SUCCESS 1; 
#define FAILURE 0; 

long INITIAL_LENGTH = 10;
long INCREMENT_BY = 20;
long currentLength = 0; 
long currNumOfElements = 0;  

static transaction_t * transactions; 

static bool is_transaction_valid(transaction_t transaction);
static int realloc_arr();

int init() {
    transactions = (transaction_t *) calloc(INITIAL_LENGTH, sizeof(transaction_t));
    if(transactions == NULL) {
        return FAILURE;
    }
    currentLength = INITIAL_LENGTH;
    return SUCCESS;
}

int add(transaction_t transaction) {
    if(transactions == NULL) {
        return FAILURE;
    }

    if(!is_transaction_valid(transaction)) {
        return FAILURE;
    }

    if(currNumOfElements == currentLength/2) {
        
    }
}

transaction_t* get_all_transactions() {

}

long size() {
    return currNumOfElements;
}

static bool is_transaction_valid(transaction_t transaction) {
    if(transaction.amount <= 0) {
        return false;
    }

    if(transaction.receiver == NULL || transaction.sender == NULL) {
        return false;
    }

    return true;
}

static int realloc_arr() {
    transactions = (transaction_t *) realloc(transactions, currentLength+INCREMENT_BY);
    if(transactions == NULL) {
        return FAILURE;
    }
    return SUCCESS;
}

