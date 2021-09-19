find ./ -type f -name "*.sh"|rev|cut -f 1 -d '/'|rev|cut -f 1 -d '.' 
#this command line prints all files with the path, reverses the string to cut the pathname, and reverses it again to cut the extension
