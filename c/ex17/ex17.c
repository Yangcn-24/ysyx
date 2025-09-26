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
                for(i; i < conn->db->max_rows; i++){
                    if(conn->db->rows[i].name) free(conn->db->rows[i].name);
                    if(conn->db->rows[i].email) free(conn->db->rows[i].email);
                }
                free(conn->db->rows);
            }
            free(conn->db);
        }
        free(conn);
    }
}

void die(const char *message, struct Connection *conn)
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
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

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
        // 读取id和set
        rc = fread(&conn->db->rows[i].id, sizeof(int), 1, conn->file);
        rc += fread(&conn->db->rows[i].set, sizeof(int), 1, conn->file);
        if(rc != 2) die("Failed to load address header.", conn);
        
        // 分配name内存
        conn->db->rows[i].name = malloc(conn->db->max_data);
        if(!conn->db->rows[i].name) die("Memory error for name", conn);
        
        // 读取name（正确参数顺序）
        rc = fread(conn->db->rows[i].name, 1, conn->db->max_data, conn->file);
        if(rc != conn->db->max_data) die("Failed to load name", conn);
        
        // 分配email内存
        conn->db->rows[i].email = malloc(conn->db->max_data);
        if(!conn->db->rows[i].email) die("Memory error for email", conn);
        
        // 读取email（正确参数顺序）
        rc = fread(conn->db->rows[i].email, 1, conn->db->max_data, conn->file);
        if(rc != conn->db->max_data) die("Failed to load email", conn);
    }
}

struct Connection *Database_open(const char *filename, char mode, int max_data, int max_rows)
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn) die("Memory error", NULL);

    conn->db = malloc(sizeof(struct Database));
    if(!conn->db) die("Memory error", conn);
    
    // 初始化指针
    conn->db->rows = NULL;
    
    if(mode == 'c') {
        conn->file = fopen(filename, "w+"); // 使用w+以便读写
        if(!conn->file) die("Failed to open the file", conn);
        
        conn->db->max_data = max_data;
        conn->db->max_rows = max_rows;
        
        // 分配rows数组
        conn->db->rows = malloc(sizeof(struct Address) * max_rows);
        if(!conn->db->rows) die("Memory error for rows", conn);
        
        // 初始化所有指针为NULL
        for(int i = 0; i < max_rows; i++) {
            conn->db->rows[i].name = NULL;
            conn->db->rows[i].email = NULL;
        }
        
        Database_create(conn);
    } else {
        conn->file = fopen(filename, "r+");
        if(!conn->file) die("Failed to open the file", conn);
        
        Database_load(conn);
    }

    return conn;
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    // 写入max_data和max_rows
    int rc = fwrite(&conn->db->max_data, sizeof(int), 1, conn->file);
    rc += fwrite(&conn->db->max_rows, sizeof(int), 1, conn->file);
    if(rc != 2) die("Failed to write database header.", conn);
    
    // 写入每个Address的数据
    for(int i = 0; i < conn->db->max_rows; i++) {
        // 写入id和set
        rc = fwrite(&conn->db->rows[i].id, sizeof(int), 1, conn->file);
        rc += fwrite(&conn->db->rows[i].set, sizeof(int), 1, conn->file);
        if(rc != 2) die("Failed to write address header.", conn);
        
        // 写入name（正确参数顺序）
        rc = fwrite(conn->db->rows[i].name, 1, conn->db->max_data, conn->file);
        if(rc != conn->db->max_data) die("Failed to write name", conn);
        
        // 写入email（正确参数顺序）
        rc = fwrite(conn->db->rows[i].email, 1, conn->db->max_data, conn->file);
        if(rc != conn->db->max_data) die("Failed to write email", conn);
    }

    rc = fflush(conn->file);
    if(rc == -1) die("Cannot flush database.", conn);
}

void Database_create(struct Connection *conn)
{
    for(int i = 0; i < conn->db->max_rows; i++) {
        conn->db->rows[i].id = i;
        conn->db->rows[i].set = 0;
        
        // 确保内存已分配
        if(!conn->db->rows[i].name) {
            conn->db->rows[i].name = malloc(conn->db->max_data);
            if(!conn->db->rows[i].name) die("Memory error for name", conn);
        }
        conn->db->rows[i].name[0] = '\0';
        
        if(!conn->db->rows[i].email) {
            conn->db->rows[i].email = malloc(conn->db->max_data);
            if(!conn->db->rows[i].email) die("Memory error for email", conn);
        }
        conn->db->rows[i].email[0] = '\0';
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
        die("Database not initialized", conn);
    }
    
    if(id < 0 || id >= conn->db->max_rows) {
        die("ID out of bounds", conn);
    }
    
    struct Address *addr = &(conn->db->rows[id]);
    if(addr->set) die("Already set, delete it first", conn);

    addr->set = 1;
    
    // 复制name，并确保字符串终止
    strncpy(addr->name, name, conn->db->max_data - 1);
    addr->name[conn->db->max_data - 1] = '\0';
    
    // 复制email，并确保字符串终止
    strncpy(addr->email, email, conn->db->max_data - 1);
    addr->email[conn->db->max_data - 1] = '\0';
}

void Database_get(struct Connection *conn, int id)
{
    if(id < 0 || id >= conn->db->max_rows) {
        die("ID out of bounds", conn);
    }
    
    struct Address *addr = &conn->db->rows[id];

    if(addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set", conn);
    }
}

void Database_delete(struct Connection *conn, int id)
{
    if(id < 0 || id >= conn->db->max_rows) {
        die("ID out of bounds", conn);
    }
    
    struct Address *addr = &conn->db->rows[id];
    addr->set = 0;
    if(addr->name) addr->name[0] = '\0';
    if(addr->email) addr->email[0] = '\0';
}

void Database_list(struct Connection *conn)
{
    int found = 0;
    for(int i = 0; i < conn->db->max_rows; i++) {
        struct Address *cur = &conn->db->rows[i];
        if(cur->set) {
            Address_print(cur);
            found = 1;
        }
    }
    if(!found) {
        printf("No records found.\n");
    }
}

void Database_find(struct Connection *conn, const char *field, const char *value)
{
    int found = 0;
    for(int i = 0; i < conn->db->max_rows; i++) {
        if(conn->db->rows[i].set) {
            if((strcmp(field, "name") == 0 && strcmp(conn->db->rows[i].name, value) == 0) ||
               (strcmp(field, "email") == 0 && strcmp(conn->db->rows[i].email, value) == 0)) {
                Address_print(&conn->db->rows[i]);
                found = 1;
            }
        }
    }
    if(!found) {
        printf("No records found with %s containing '%s'\n", field, value);
    }
}

int main(int argc, char *argv[])
{
    if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]", NULL);
    
    char *filename = argv[1];
    char action = argv[2][0];
    int max_data = 0;
    int max_rows = 0;
    int id = 0;
    struct Connection *conn = NULL;
    
    if(action == 'c') {
        if(argc != 5) die("Need max_data and max_rows to create", NULL);
        max_data = atoi(argv[3]);
        max_rows = atoi(argv[4]);
        conn = Database_open(filename, action, max_data, max_rows);
    } else {
        // 对于其他操作，先打开文件获取max_data和max_rows
        conn = Database_open(filename, action, 0, 0);
        if(argc >= 4) id = atoi(argv[3]);
        
        // 检查id是否有效
        if((action == 'g' || action == 's' || action == 'd') && id >= conn->db->max_rows) {
            die("There's not that many records.", conn);
        }
    }
    
    switch(action) {
        case 'c':
            // Database_create已经在Database_open中调用
            Database_write(conn);
            printf("Database created with max_data=%d, max_rows=%d\n", max_data, max_rows);
            break;

        case 'g':
            if(argc != 4) die("Need an id to get", conn);
            Database_get(conn, id);
            break;

        case 's':
            if(argc != 6) die("Need id, name, email to set", conn);
            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;

        case 'd':
            if(argc != 4) die("Need id to delete", conn);
            Database_delete(conn, id);
            Database_write(conn);
            break;

        case 'l':
            Database_list(conn);
            break;
            
        case 'f':
            if(argc != 5) die("Need field and value to find", conn);
            Database_find(conn, argv[3], argv[4]);
            break;
            
        default:
            die("Invalid action, only: c=create, g=get, s=set, d=del, l=list, f=find", conn);
    }

    Database_close(conn);
    return 0;
}
