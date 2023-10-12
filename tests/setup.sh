#!/bin/sh

# @author Cloudgen Wong
# @date 2023-10-12
TEST_FOLDER="$HOME/Library/Caches"
RESULT_FILE="$TEST_FOLDER/test-result.txt"
DOC_ROOT="$TEST_FOLDER/doc-root"

echo "Creating Folder: ${DOC_ROOT}"
mkdir -p "${DOC_ROOT}"
mkdir -p "${DOC_ROOT}/folder/folder"
mkdir -p "${DOC_ROOT}/folder/folder\ 2"
echo "This is a test file." > "${DOC_ROOT}/file.txt"
echo "This is a test file." > "${DOC_ROOT}/folder/file.txt"
echo "This is a test file." > "${DOC_ROOT}/folder/folder/file.txt"
echo "This is a test file." > "${DOC_ROOT}/folder/folder\ 2/file.txt"