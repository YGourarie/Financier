#ifndef DB_H
#define DB_H

#include <sqlite3.h>

// Function to initialize the database
int initialize_db(const char *db_name);

// Function to create a table
int create_table(sqlite3 *db, const char *sql_create_table);

// Function to insert data into a table
int insert_data(sqlite3 *db, const char *sql_insert);

// Function to query data from a table
int query_data(sqlite3 *db, const char *sql_query);

// Function to delete data from a table
int delete_data(sqlite3 *db, const char *sql_delete);

#endif
