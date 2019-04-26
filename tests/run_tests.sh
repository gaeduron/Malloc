echo "INFO:"
./print_page_size
echo "$> nm ../libft_malloc.so"
nm ../libft_malloc.so

echo "DEFAULT:"
/usr/bin/time -l ./test_no_malloc

echo "\n\n\nOFFICIAL MALLOC:"
/usr/bin/time -l ./test_official_malloc

echo "\n\n\nLIBFT MALLOC:"
/usr/bin/time -l zsh ./run.sh ./test_official_malloc