#include "./dynamic-array/arraylist.h"

int main() {
    transaction_t firstTransaction;
    firstTransaction.sender = "faysal";
    firstTransaction.receiver = "raed";
    firstTransaction.amount = 10;

    int res = add(firstTransaction);
    
    return 0;
}