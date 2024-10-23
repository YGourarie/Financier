#include <stdio.h>
#include "db.h"

int main() {
    const char *db_name = "financier.db";

    printf("Starting the database initialization process.\n");

    // Initialize the database
    int result = initialize_db(db_name);

    if (result == 0) {
        printf("Database exists and is ready to use.\n");
    } else {
        printf("Failed to initialize the database.\n");
    }

    return 0;
}
