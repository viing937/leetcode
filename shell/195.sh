cat file.txt | awk '{if (NR==10) print $0}'
