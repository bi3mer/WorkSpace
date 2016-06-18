#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

const int MAX_DATA = 512;
const int MAX_ROWS = 100;

struct Address 
{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database
{
	struct Address rows[MAX_ROWS];
};

struct Connection 
{
	FILE *file;
	struct Database *db;
};

void Database_close(struct Connection *conn)
{
	assert(conn != NULL);
	if(conn)
	{
		if(conn->file)
		{
			fclose(conn->file);
		}

		if(conn->db)
		{
			free(conn->db);
		}

		free(conn);
	}
}

void die(const char * message, struct Connection *conn)
{
	if(errno)
	{
		perror(message);
	}
	else
	{
		printf("ERROR: %s\n", message);
	}

	Database_close(conn);

	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	
	if(rc == 0)
	{
		die("Failed to load Database", conn);
	}
}

struct Connection *Database_open(const char *file_name, char mode)
{
	struct Connection *conn = malloc(sizeof(struct Connection));

	if(!conn)
	{
		die("Memory Error", conn);
	}

	conn->db = malloc(sizeof(struct Database));
	if(!conn->db)
	{
		die("Memory Error!", conn);
	}

	if(mode =='c')
	{
		conn->file = fopen(file_name, "w");
	}
	else
	{
		conn->file = fopen(file_name, "r+");

		if(conn->file)
		{
			Database_load(conn);
		}
	}

	if(!conn->file)
	{
		die("Failed to open the file", conn);
	}

	return conn;
}

void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);

	if(rc != 1)
	{
		die("Failed to write to database", conn);
	}

	rc = fflush(conn->file);

	if(rc == -1)
	{
		die("cannot flush database", conn);
	}
}

void Database_create(struct Connection *conn)
{
	int i;

	for(i = 0; i < MAX_ROWS; ++i)
	{
		// Create prootype without a pointer
		struct Address addr = {.id = i, .set = 0};

		// add to db
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set)
	{
		die("Already set, delete it first!", conn);
	}

	addr->set = 1;

	// WARNING THIS IS A BUG
	char *res = strncpy(addr->name, name, MAX_DATA);
	// to fix set last character to be '\0'

	if(!res)
	{
		die("Email copy failed", conn);
	}

	res = strncpy(addr->email, email, MAX_DATA);

	if(!res)
	{
		die("Email copy failed", conn);
	}
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];

	if(addr->set)
	{
		Address_print(addr);
	}
	else
	{
		die("ID is not set", conn);
	}
}

void Database_delete(struct Connection *conn, int id)
{
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
	int i;
	struct Database *db = conn->db;

	for(i = 0; i < MAX_ROWS; ++i)
	{
		struct Address *cur = &db->rows[i];

		if(cur ->set)
		{
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		die("Usage: ex17 <dbfile> <action> [action params]", NULL);
	}

	struct Connection *conn = Database_open(argv[1], argv[2][0]);
	int id = 0;

	if(argc > 3)
	{
		id = atoi(argv[3]);
	}

	if(id >= MAX_ROWS)
	{
		die("To many records indicated", conn);
	}

	switch(argv[2][0])
	{
		case 'c':
			Database_create(conn);
			break;

		case 'g':
			if(argc != 4)
			{
				die("Need an id to get", conn);
			}

			Database_get(conn, id);
			break;

		case 's':
			if(argc != 6)
			{
				die("Need an id, name, and email to set", conn);
			}

			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;

		case 'd':
			if(argc != 4)
			{
				die("need id to delte", conn);
			}

			Database_delete(conn, id);
			Database_write(conn);
			break;

		case 'l':
			Database_list(conn);
			break;

		default:
			die("Invalid action, only: c=create, g=get, s=set, d=delete, l=list", conn);
	}

	Database_close(conn);

	return 0;
}






