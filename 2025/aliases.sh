#!/bin/zsh

acm() {


    if [ $# -ne 2 ]; then
        echo "Please input the correct parameters: "
        echo "  acm np [folder_name] [create_file_quantity]"
        echo "  acm run [cpp_file_name]"
        return 1
    fi

    identifier=$1        # 标识符（如 np）

    if [ "$identifier" = "np" ]; then

        if [ $# -ne 3 ]; then
            echo "Please input the correct parameters: "
            echo "  acm np [folder_name] [create_file_quantity]"
            echo "  acm run [cpp_file_name]"
            return 1
        fi

      
        folder_name=$2       # 新建文件夹名
        cpp_count=$3         # 要创建的 cpp 文件数量（如 3）


        # 检查参数3是否是有效数字
        if ! [[ "$cpp_count" =~ ^[0-9]+$ ]] || [ "$cpp_count" -le 0 ]; then
            echo "请输入有效的数字参数！"
            return 1
        fi

        # 获取当前目录下按时间排序的文件夹，选择最新的一个
        # 查找符合条件的 3 位数字文件夹
        latest_folder=$(find . -maxdepth 1 -type d | grep -E './[0-9]{3}$' | xargs -I {} stat -f "%m %N" {} | sort -n | tail -n 1 | awk '{print $2}')
        latest_folder=$(basename "$latest_folder") # 提取文件夹名
        latest_folder="${latest_folder}/" # 确保添加尾部斜杠

        if [ -z "$latest_folder" ]; then
            echo "当前目录下没有文件夹！"
            return 1
        fi

        # 在最新文件夹下创建目标文件夹
        target_folder="${latest_folder}${folder_name}"

        # 如果目标文件夹不存在，则创建它
        if [ ! -d "$target_folder" ]; then
            mkdir "$target_folder"
            echo "创建文件夹 $target_folder"
        fi

        # 在目标文件夹中创建指定数量的 cpp 文件
        for i in $(seq 1 $cpp_count); do
            # 获取字母序列 A、B、C...
            letter=$(printf \\$(printf '%03o' $((65 + i - 1))))
            touch "${target_folder}/${letter}.cpp"
            echo "${letter}.cpp 创建完成"
        done

        echo "操作完成！"
    
    elif [ "$identifier" = "run" ]; then

        /Users/wsy/Back_end/ACM/2025/run_code.sh $2

    else 
        echo "Please input the correct parameters: "
        echo "  acm np [folder_name] [create_file_quantity]"
        echo "  acm run [cpp_file_name]"
        return 1
    fi

}
