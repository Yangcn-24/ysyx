#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct Connection *Database_open(const char *filename, char mode, int max_data, int max_rows);
void Database_close(struct Connection *conn);
void Database_load(struct Connection *conn);
void Database_write(struct Connection *conn);
void Database_create(struct Connection *conn);
void Database_set(struct Connection *conn, int id, const char *name, const char *email);
void Database_get(struct Connection *conn, int id);
void Database_delete(struct Connection *conn, int id);
void Database_list(struct Connection *conn);
void Database_find(struct Connection *conn, const char *field, const char *value);

struct Address {
    int id;
    int set;
    char *name;
    char *email;
};

struct Database {
	int max_data;
	int max_rows;
    struct Address *rows;
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void Database_close(struct Connection *conn)
{
    if(conn) {
        if(conn->file) fclose(conn->file);
        if(conn->db) {
        	if(conn->db->rows){
        		int i=0;
        		for(i;i<conn->db->max_rows;i++){
        			free(conn->db->rows[i].name);
        			free(conn->db->rows[i].email);
        		}
        	free(conn->db->rows);
        	}
        free(conn->db);
        }
    }
    free(conn);
}

void die(const char *message,struct Connection *conn)
{
    if(conn){
    	Database_close(conn);
    }
    if(errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n",
            addr->id, addr->name, addr->email);
}

//void Database_load(struct Connection *conn)
//{
//    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
//    if(rc != 1) die("Failed to load database.",conn);
//}
void Database_load(struct Connection *conn)
{
    // 先读取max_data和max_rows
    int rc = fread(&conn->db->max_data, sizeof(int), 1, conn->file);
    rc += fread(&conn->db->max_rows, sizeof(int), 1, conn->file);
    if(rc != 2) die("Failed to load database header.", conn);
    
    // 分配rows数组
    conn->db->rows = malloc(sizeof(struct Address) * conn->db->max_rows);
    if(!conn->db->rows) die("Memory error for rows", conn);
    
    // 读取每个Address的数据
    for(int i = 0; i < conn->db->max_rows; i++) {
        rc = fread(&conn->db->rows[i].id, sizeof(int), 1, conn->file);
        rc += fread(&conn->db->rows[i].set, sizeof(int), 1, conn->file);
        if(rc != 2) die("Failed to load address header.", conn);
        
        // 分配并读取name
        conn->db->rows[i].name = malloc(conn->db->max_data);
        rc = fread(conn->db->rows[i].name, conn->db->max_data, 1, conn->file);
        
        // 分配并读取email
        conn->db->rows[i].email = malloc(conn->db->max_data);
        rc += fread(conn->db->rows[i].email, conn->db->max_data, 1, conn->file);
        
        if(rc != 2) die("Failed to load address data.", conn);
    }
}


/*struct Connection *Database_open(const char *filename, char mode,int max_data,int max_rows)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error",conn);

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error",conn);
	
	conn->db->max_data = max_data;
    conn->db->max_rows = max_rows;
    
    if(mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if(conn->file) {
            Database_load(conn);
        }
    }

    if(!conn->file) die("Failed to open the file",conn);
	// 分配rows数组
    conn->db->rows = malloc(sizeof(struct Address) * max_rows);
    if(!conn->db->rows) die("Memory error for rows",conn);
    
    // 如果是创建模式，初始化数据库
    if(mode == 'c') {
        Database_create(conn);
    }
    return conn;
}*/

struct Connection *Database_open(const char *filename, char mode, int max_data, int max_rows)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error", NULL);

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error", conn);
    
    if(mode == 'c') {
        conn->file = fopen(filename, "w");
        conn->db->max_data = max_data;
        conn->db->max_rows = max_rows;
        
        // 分配rows数组
        conn->db->rows = malloc(sizeof(struct Address) * max_rows);
        if(!conn->db->rows) die("Memory error for rows", conn);
        
        Database_create(conn);
    } else {
        conn->file = fopen(filename, "r+");
        if(!conn->file) die("Failed to open the file", conn);
        
        Database_load(conn);
    }

    return conn;
}

/*void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if(rc != 1) die("Failed to write database.",conn);

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.",conn);
}*/

void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    // 写入max_data和max_rows
    int rc = fwrite(&conn->db->max_data, sizeof(int), 1, conn->file);
    rc += fwrite(&conn->db->max_rows, sizeof(int), 1, conn->file);
    if(rc != 2) die("Failed to write database header.", conn);
    
    // 写入每个Address的数据
    for(int i = 0; i < conn->db->max_rows; i++) {
        rc = fwrite(&conn->db->rows[i].id, sizeof(int), 1, conn->file);
        rc += fwrite(&conn->db->rows[i].set, sizeof(int), 1, conn->file);
        if(rc != 2) die("Failed to write address header.", conn);
        
        rc = fwrite(conn->db->rows[i].name, conn->db->max_data, 1, conn->file);
        rc += fwrite(conn->db->rows[i].email, conn->db->max_data, 1, conn->file);
        if(rc != 2) die("Failed to write address data.", conn);
    }
    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.", conn);
}


void Database_create(struct Connection *conn)
{
    int i = 0;

    for(i = 0; i < conn->db->max_rows; i++) {
        
        conn->db->rows[i].id=i;
        conn->db->rows[i].set=0;
        conn->db->rows[i].name=malloc(conn->db->max_data);
        conn->db->rows[i].email=malloc(conn->db->max_data);
        if(!conn->db->rows[i].name||!conn->db->rows[i].email){
        	die("Memory error for address fields",conn);
        }
        conn->db->rows[i].name[0]='\0';
        conn->db->rows[i].email[0]='\0';
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{	

	// 检查连接和数据库是否有效
    if(!conn || !conn->db) {
        die("Invalid database connection", conn);
    }
    
	// 检查rows数组是否已分配
    if(!conn->db->rows) {
        die( "Database not initialized",conn);
    }
    
	if(id < 0 || id >= conn->db->max_rows) {
        die( "ID out of bounds",conn);
    }
    
    struct Address *addr = &(conn->db->rows[id]);
    if(addr->set) die("Already set, delete it first", conn);

    addr->set = 1;
    
    // 复制name，并确保字符串终止
    strncpy(addr->name, name, conn->db->max_data - 1);
    addr->name[conn->db->max_data - 1] = '\0'; // 强制终止
    
    // 复制email，并确保字符串终止
    strncpy(addr->email, email, conn->db->max_data - 1);
    addr->email[conn->db->max_data - 1] = '\0'; // 强制终止
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set",conn);
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for(i = 0; i < conn->db->max_rows; i++) {
        struct Address *cur = &db->rows[i];

        if(cur->set) {
            Address_print(cur);
        }
    }
}
void Database_find(struct Connection *conn,const char *field,const char *value)
{
	int i=0;
	for(i;i<conn->db->max_rows;i++){
		if((value==conn->db->rows[i].name)||(value==conn->db->rows[i].email)){
			Address_print(&conn->db->rows[i]);
			break;
		}
		else{
			printf("No records found with %s containing '%s'\n", field, value);
		}
	}
}
int main(int argc, char *argv[])
{
	if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]",NULL);
	char *filename = argv[1];
    char action = argv[2][0];

	int max_data=0;
	int max_rows=0;
	int id = 0;
	struct Connection *conn = NULL;
    /*if(action=='g'||action=='s'||action=='d') id = atoi(argv[3]);
    if(action=='c') {
    	max_data=atoi(argv[3]);
    	max_rows=atoi(argv[4]);
    	}
    struct Connection *conn = Database_open(filename, action,max_data,max_rows);
    
    if(id >= conn->db->max_rows) die("There's not that many records.",conn);*/
	if(action == 'c') {
        if(argc != 5) die("Need max_data and max_rows to create", NULL);
        max_data = atoi(argv[3]);
        max_rows = atoi(argv[4]);
        conn = Database_open(filename, action, max_data, max_rows);
    } else {
        // 对于其他操作，先打开文件获取max_data和max_rows
        conn = Database_open(filename, action, 0, 0);
        if(argc >= 4) id = atoi(argv[3]);
    }
    switch(action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            printf("Database created with max_data=%d, max_rows=%d\n",max_data,max_rows);
            break;

        case 'g':
            if(argc != 4) die("Need an id to get",conn);

            Database_get(conn, id);
            break;

        case 's':
            if(argc != 6) die("Need id, name, email to set",conn);

            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4) die("Need id to delete",conn);

            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
		case 'f':
			if(argc != 5) die("Need name/email to find",conn);
			Database_find(conn,argv[3],argv[4]);
			break;
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list",conn);
    }

    Database_close(conn);

    return 0;
}
