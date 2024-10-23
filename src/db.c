#include <stdio.h>
#include <sqlite3.h>
#include "db.h"

int initialize_db(const char *db_name) {
    sqlite3 *db;
    int rc;

    printf("Attempting to open the database: %s\n", db_name);

    // Try to open the database (this will create the file if it doesn't exist)
    rc = sqlite3_open(db_name, &db);

    if (rc) {
        // Error occurred
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    } else {
        // Success: database is opened or created
        printf("Database initialized successfully: %s\n", db_name);
    }

    // Close the database connection
    sqlite3_close(db);
    printf("Database connection closed.\n");

    return 0; // Return success
}
