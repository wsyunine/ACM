#!/bin/bash

# 检查是否提供了参数
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <source_file>"
    exit 1
fi

# 获取传入的文件路径
SOURCE_FILE="$1"

# 检查文件是否存在
if [ ! -f "$SOURCE_FILE" ]; then
    echo "Error: File '$SOURCE_FILE' does not exist."
    exit 1
fi

# 提取文件目录和文件名（不带扩展名）
DIR=$(dirname "$SOURCE_FILE")
BASE_NAME=$(basename "$SOURCE_FILE" .cpp)

# 设置输出的可执行文件路径（无后缀）
OUTPUT_FILE="$DIR/$BASE_NAME"

# 编译源文件
echo "Compiling '$SOURCE_FILE'..."
g++ -std=c++2b -o "$OUTPUT_FILE" "$SOURCE_FILE"

# 检查编译是否成功
if [ "$?" -ne 0 ]; then
    echo "Error: Compilation failed."
    exit 1
fi

# 执行生成的可执行文件
echo "Executing '$OUTPUT_FILE'..."

touch "${OUTPUT_FILE}.out"
"$OUTPUT_FILE" >"${OUTPUT_FILE}.out"
echo "Output:"
cat "${OUTPUT_FILE}.out"
