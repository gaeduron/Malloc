echo "INFO:"
./print_page_size

echo "DEFAULT:"
/usr/bin/time -l ./test_no_malloc

echo "\n\n\nOFFICIAL MALLOC:"
/usr/bin/time -l ./test_official_malloc

