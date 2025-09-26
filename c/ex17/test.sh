#!/bin/bash
set -e  # 在任何命令失败时退出

DB_FILE="test.dat"

echo "Testing database operations..."

# 创建数据库
./ex17 $DB_FILE c 256 50

# 添加一些记录
./ex17 $DB_FILE s 1 yangcn cnyang24@mails.jlu.edu.cn
./ex17 $DB_FILE s 2 yangyt ytyang@mails.jlu.edu.cn
./ex17 $DB_FILE s 3 lulg lglu@mails.jlu.edu.cn

# 列出所有记录
echo "Listing all records:"
./ex17 $DB_FILE l

# 查找记录
echo "Searching for 'John':"
./ex17 $DB_FILE f name yangcn

echo "Searching for 'example.com':"
./ex17 $DB_FILE f email cnyang24@mails.jlu.edu.cn

# 获取特定记录
echo "Getting record 2:"
./ex17 $DB_FILE g 2

# 删除记录
./ex17 $DB_FILE d 1

echo "After deletion:"
./ex17 $DB_FILE l

echo "All tests passed!"
