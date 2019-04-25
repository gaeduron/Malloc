#!/bin/sh

#export DYLD_LIBRARY_PATH=.
#export DYLD_INSERT_LIBRARIES="libft_malloc.so"
#export DYLD_FORCE_FLAT_NAMESPACE=1

echo "INFO:"
./print_page_size

echo "DEFAULT:"
/usr/bin/time -l ./test_no_malloc

echo "\n\n\nOFFICIAL MALLOC:"
/usr/bin/time -l ./test_official_malloc

