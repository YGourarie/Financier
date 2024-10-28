#include <stdio.h>
#include "db.h"

int main() {
    sqlite3 *db;
    int rc;

    // Initialize the database and create the Users table
    rc = initialize_db("financier.db");
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to initialize the database.\n");
        return rc;
    }

    // Open the database connection (since initialize_db closes it after setup)
    rc = sqlite3_open("financier.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    // Insert data
    const char *sql_insert = "INSERT INTO Users (Name, Age) VALUES ('Alice', 30);";
    insert_data(db, sql_insert);

    // Query data
    const char *sql_query = "SELECT * FROM Users;";
    query_data(db, sql_query);

    // Delete data
    const char *sql_delete = "DELETE FROM Users WHERE Name = 'Alice';";
    delete_data(db, sql_delete);

    // Close the database when done
    sqlite3_close(db);

    return 0;
}

