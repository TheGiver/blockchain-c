#include "arraylist.h"

long INITIAL_LENGTH = 10;
long RESIZE_BY = 20;
long currentLength = 0; 
long currNumOfElements = 0;  

static transaction_t * transactions; 

static bool is_transaction_valid(transaction_t transaction);
static int resize_and_reallocate_data();

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
        fprintf(stderr, "***************** Error: Failed to add a transaction to the system | Reason: Transactions list not initialized...\n");
        return FAILURE;
    }

    if(!is_transaction_valid(transaction)) {
        return FAILURE;
    }

    if(currNumOfElements >= currentLength/2) {
        int status = resize_and_reallocate_data();
        if(status == FAILURE) {
            return FAILURE;
        }
    }

    transactions[currNumOfElements++]=transaction;
    return SUCCESS;
}

transaction_t* get_all_transactions() {
    if(transactions == NULL) {  
        fprintf(stderr, "***************** Error: Failed to add a transaction to the system | Reason: Transactions list not initialized...\n");
        return NULL;
    }
    return transactions;
}

long size() {
    return currNumOfElements;
}

static bool is_transaction_valid(transaction_t transaction) {
    if(transaction.amount <= 0) {
        fprintf(stderr, "***************** Error: Invalid transaction | Reason: Transaction amount is less than or equal to zero\n");
        return false;
    }

    if(transaction.receiver == NULL || transaction.sender == NULL) {
        fprintf(stderr, "***************** Error: Invalid transaction | Reason: Sender or Beneficiary details are invalid\n");
        return false;
    }

    return true;
}

static int resize_and_reallocate_data() {
    currentLength += RESIZE_BY;
    transaction_t * newRegion = (transaction_t *) realloc(transactions, currentLength);
    if(newRegion == NULL) {
        fprintf(stderr, "***************** Error: Failed to resize the list | Reason: Memory reallocation failed\n");
        return FAILURE;
    }
    memcpy(newRegion, transactions, currNumOfElements*sizeof(transaction_t));
    transactions = newRegion;
    return SUCCESS;
}