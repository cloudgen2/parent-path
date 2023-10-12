# parent-path

This program try to find a relative path from a doc root path and test if it exists.  This is useful for operation in Mutable File System (MFS) in IPFS.

This program written in C program.

# Examples
```
parent-path "$HOME/Library/Caches/doc-root/folder/file.txt" "$HOME/Library/Caches/doc-root"
```
Expected result (if the file is exists and inside the doc root folder: $HOME/Library/Caches/doc-root)
```
'$HOME/Library/Caches/doc-root'
```
If the file does not exists:
```
''
```

# Build and test
Build command:
```
./build.sh
```
Test command:
```
./build.sh test
```


