#!/bin/bash
echo -e "Choose number: \n1)Soft Link\n2)Hard Link\n3)FIFO"
read file_type
date_time=$(date +"%Y-%m-%d_%H:%M:%S")
if [[ "$file_type" -eq 1 ]]; then
    # echo "Soft Link"
    rm -f soft_link_*.txt
    rm -f soft_*.txt
    file_name="soft_${date_time}.txt"
    touch "$file_name"
    if [[ $? -ne 0 ]]; then
        echo "Failed to create $file_name"
        exit 1
    fi
    echo "This is an example soft text file at time $date_time" > "$file_name"
    SCRIPT_DIR=$(dirname "$(realpath "$0")")
    link_file_name="soft_link_${date_time}.txt"
    ln -s "$SCRIPT_DIR"/"$file_name" "$SCRIPT_DIR"/"$link_file_name"
    if [[ $? -ne 0 ]]; then
        echo "Failed to create Soft Link file"
        exit 1
    fi
    echo "Soft Link File created Successfully"
    echo "Contents of ${file_name}: $(cat "$file_name")"
    echo "Contents of ${link_file_name}: $(cat "$link_file_name")"
    echo "inode Number of ${file_name}: $(stat -c '%i' "$file_name")"
    echo "inode Number of ${link_file_name}: $(stat -c '%i' "$link_file_name")"
elif [[ "$file_type" -eq 2 ]]; then
    # echo "Hard Link"
    rm -f hard_link_*.txt
    rm -f hard_*.txt
    file_name="hard_${date_time}.txt"
    touch "$file_name"
    if [[ $? -ne 0 ]]; then
        echo "Failed to create $file_name"
        exit 1
    fi
    echo "This is an example hard text file at time $date_time" > "$file_name"
    SCRIPT_DIR=$(dirname "$(realpath "$0")")
    link_file_name="hard_link_${date_time}.txt"
    ln "$SCRIPT_DIR"/"$file_name" "$SCRIPT_DIR"/"$link_file_name"
    if [[ $? -ne 0 ]]; then
        echo "Failed to create Hard Link file"
        exit 1
    fi
    echo "Hard Link File created Successfully"
    echo "Contents of ${file_name}: $(cat "$file_name")"
    echo "Contents of ${link_file_name}: $(cat "$link_file_name")"
    echo "inode Number of ${file_name}: $(stat -c '%i' "$file_name")"
    echo "inode Number of ${link_file_name}: $(stat -c '%i' "$link_file_name")"
elif [[ "$file_type" -eq 3 ]]; then
    # echo "FIFO"
    rm -f pipe
    mkfifo pipe
    if [[ $? -ne 0 ]]; then
        echo "Failed to create Pipe"
        exit 1
    else
        echo "FIFO pipe created named 'pipe'"
    fi
else
    echo "Entered Wrong Input"
    exit 1
fi
