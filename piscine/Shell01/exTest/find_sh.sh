find . -type f -name '*.sh'|ls|cut -f 1 -d '.' #the basename funtion truncates the directory, and the cut function selects only the first field before the delimiter "."
