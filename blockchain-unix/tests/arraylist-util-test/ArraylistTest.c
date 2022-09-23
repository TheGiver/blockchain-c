#include "../../util/dyanmic-array/arraylist.h"

int main() {
    if(init() != SUCCESS) {
        fprintf(stdout, "%s", "[error]: Blockchain initialisation failure...");
    }

    transaction_t firstTransaction = {"faysal", "raed", 10};
    int res = add(firstTransaction);
    fprintf(stdout, "Transaction-01 has been added to the list of transactions, the current size of the list is: %d\n", size());
    
    return 0;
}

/**
 * @brief 
 * TITLE: TEST CASE ONE 
 * BEHAVIOUR: ADDING ONE TRANSACTION TO THE ARRAYLIST INCREMENTS THE SIZE OF THE LIST BY 1 AND PERSISTS THAT TRANSACTION OF THE LIST OF TRANSACTIONS 
 */
