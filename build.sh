#!/bin/sh

# @author Cloudgen Wong
# @date 2023-10-12
build_main() {

    # create the target directory if it doesn't exist
    mkdir -p ${TARGET_DIR}
    rm -rf ${TARGET}

    # compile the program and output to the target directory
    gcc -Wall -Werror \
        src/main.c \
        src/parent-path.c \
        src/trim-quotes.c \
        -o ${TARGET} 2> $ERROR_LOG

    if [ $? -ne 0 ]; then
        echo "Build failed. Please check the error in $ERROR_LOG."
        exit 1
    fi

    # Make the binary executable
    chmod +x ${TARGET}

    if [ "$1" = "install" ]; then
        cp ${TARGET} /usr/bin/
        if [ $? -ne 0 ]; then
            echo "Cannot install to /usr/bin/${FNAME}"
        else
            echo "Build successful! Please run '${FNAME}'!"
        fi
    elif [ "$1" = clean ]; then
        rm -rf ${TARGET_DIR}/*
        echo "Folder ${TARGET_DIR} has been cleared!"
    elif [ "$1" = "test" ]; then
        # Set the necessary variables
        tests/test.sh ${TARGET} tests/cases/test-cases.txt
    else
        echo "Build successful! Please run '${TARGET}' or run './build test' for running test cases"
    fi
}
source ./project/project.ini
build_main "$1"