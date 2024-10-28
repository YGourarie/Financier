#include <stdio.h>
#include <sqlite3.h>
#include "db.h"

// SQL statement to create the Users table
const char *sql_create_users_table = "CREATE TABLE IF NOT EXISTS Users("
                                     "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                                     "Name TEXT NOT NULL, "
                                     "Age INTEGER NOT NULL);";

// Initialize the database and create the Users table
int initialize_db(const char *db_name) {
    sqlite3 *db;
    int rc;

    printf("Attempting to open the database: %s\n", db_name);
    rc = sqlite3_open(db_name, &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return rc;
    } else {
        printf("Database initialized successfully: %s\n", db_name);
    }

    // Create the Users table
    rc = create_table(db, sql_create_users_table);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to create table.\n");
        sqlite3_close(db);
        return rc;
    }

    // Close the database connection
    sqlite3_close(db);
    printf("Database connection closed.\n");

    return 0;
}

// Create a table
int create_table(sqlite3 *db, const char *sql_create_table) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql_create_table, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error when creating table: %s\n", err_msg);
        sqlite3_free(err_msg);
        return rc;
    } else {
        printf("Table created successfully.\n");
    }

    return SQLITE_OK;
}

// Insert data
int insert_data(sqlite3 *db, const char *sql_insert) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql_insert, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Data inserted successfully.\n");
    }

    return rc;
}

// Query data
int query_data(sqlite3 *db, const char *sql_query) {
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_query, -1, &stmt, 0);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Failed to execute query: %s\n", sqlite3_errmsg(db));
        return rc;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("%s: %s\n", sqlite3_column_name(stmt, 0), sqlite3_column_text(stmt, 0));
    }

    if (rc != SQLITE_DONE) {
        printf("Failed to fetch data: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
    return SQLITE_OK;
}

// Delete data
int delete_data(sqlite3 *db, const char *sql_delete) {
    char *err_msg = 0;
    int rc = sqlite3_exec(db, sql_delete, 0, 0, &err_msg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Data deleted successfully.\n");
    }

    return rc;
}
