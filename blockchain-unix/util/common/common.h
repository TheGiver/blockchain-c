#define SUCCESS 1 
#define FAILURE 0

typedef struct transaction {
    char sender[255]; 
    char receiver[255];
    double amount;
} transaction_t;