#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// using c preprocessor here(cpp)
// a way to create constants that will work reliably
#define MAX_DATA 512
#define MAX_ROWS 100

// fixed sized structs are less efficient but it's easier to store and read them
struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
    // an object type used for streams
    FILE *file;
    struct Database *db;
};

// prints error and terminates the process
void die(const char *message) {
    // errno - number of last error
    if (errno) {
        // prints a system error message
        perror(message);
    } else { 
        // for custom errors
        printf("ERROR: %s\n", message);
    }

    // causes normal process termination
    exit(1);
}

// prints given address
void Address_print(struct Address *addr) {
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

// loads a database from the file
void Database_load(struct Connection *conn) {
    // reads 1 items of data, sizeof(struct Database) long, 
    // from the stream pointed to by conn->file, storing them at the conn->db
    // on success return the number of items read
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) {
        die("Failed to load database.");
    }
}

// returns connection to database in given file
struct Connection *Database_open(const char *filename, char mode) {
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn) {
        die("Memory error.");
    }

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db) {
        die("Memory error.");
    }

    // mode c is using for creating new file or rewriting existing one?
    if (mode == 'c') {
        // fopen opens the file whose name is the string pointed to by filename
        // and associates a stream with it. 
        // On successful completion return a FILE pointer. 
        // Otherwise, NULL is returned and erno is set to indicate the error
        // w - truncate file to zero length or create text file for writing. 
        // The stream is positioned at the beginning of the file
        conn->file = fopen(filename, "w");
    } else {
        // r+ - open for reading and writing. 
        // The stream is positioned at the beginning of the file
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file) {
        die("Failed to open the file.");
    }

    return conn;
}

// closes connection to the database
void Databae_close(struct Connection *conn) {
    if (conn) {
        if (conn->file) {
            // Close stream
            fclose(conn->file);
        }
        if (conn->db) {
            free(conn->db);
            free(conn);
        }
    }
}

// writes data from database to a file???
void Database_write(struct Connection *conn) {
    // rewind function sets the file position indicator for the stream 
    // pointed to by conn->file to the beginning of the file
    rewind(conn->file);


    // fwrite writes 1 item of data, 
    // each sizeof(struct Database) long, 
    // to the stream pointed to by conn->file, 
    // obtaining them from the location given by conn->db
    // Returns the number of written items 
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) {
        die("Failed to write database.");
    }

    // for output streams, 
    // fflush() forces a write of all user-space buffered data for the given output 
    // or update conn->file via the stream's underlying write function
    // upon successful completion 0 is returned. 
    // Otherwise, EOF is returned and errno is set to indicate the error
    rc = fflush(conn->file);
    if (rc == -1) {
        die("Cannot flush database.");
    }
}

// creates a database
void Database_create(struct Connection *conn) {
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it
        struct Address addr = {.id = i, .set = 0};
        // then just assign it
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) {
    // gets the address of rows[id]
    struct Address *addr = &conn->db->rows[id];
    if (addr->set) {
        die("Already set, delete it first");
    }

    addr->set = 1;
    // WARNING: bug
    // strncpy copies at most MAX_DATA bytes of string pointed to by name, 
    // including the terminating null byte ('\0')
    // returns a pointer to the destination string.
    // The strings may not overlap, 
    // and the destination string must be large enough to receive the copy. 
    // BEWARE OF BUFFER OVERRUNS!
    // Warning: if there is no null byte among the first MAX_DATA bytes of name, 
    // the string placed in dest will not be null-terminated
    char *res = strncpy(addr->name, name, MAX_DATA);
    // demonstrate this strncpy bug
    if (!res) {
        die("Name copy failed.");
    } 
    
    res = strncpy(addr->email, email, MAX_DATA);
    if (!res) {
        die("Email copy failed.");
    }
}

// prints address by id 
void Database_get(struct Connection *conn, int id) {
    struct Address *addr = &conn->db->rows[id];

    if (addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set.");
    }
}

// marks address as not set 
void Database_delete(struct Connection *conn, int id) {
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

// print all addresses stored in db
void Database_list(struct Connection *conn) {
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];

        if (cur->set) {
            Address_print(cur);
        }
    }
}

// whe whole point of this program is to allocate a large amount of memory when creating the database
int main(int argc, char **argv) {
    if (argc < 3) {
        die("USAGE: ex17 <dbfile> <action> [action params]");
    }

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);
    int id = 0;

    if (argc > 3) {
        id = atoi(argv[3]);
    }
    if (id >= MAX_ROWS) {
        die("There's not that many records.");
    }

    switch (action)
    {
    case 'c':
        Database_create(conn);
        Database_write(conn);
        break;
    
    case 'g':
        if (argc != 4) {
            die("Need an id to get.");
        }
        Database_get(conn, id);
        break;

    case 's':
        if (argc != 6) {
            die("Need id, name, email to set.");
        }

        Database_set(conn, id, argv[4], argv[5]);
        Database_write(conn);
        break;

    case 'd':
        if (argc != 4) {
            die("Need id to delete.");
        }

        Database_delete(conn, id);
        Database_write(conn);
        break;

    case 'l':
        Database_list(conn);
        break;

    case 'h':
        die("Available actions: c=create, g=get, s=set, d=del, l=list.");
        break;

    default:
        die("Invalid action: c=create, g=get, s=set, d=del, l=list.");
        break;
    }

    Databae_close(conn);

    return 0;
}