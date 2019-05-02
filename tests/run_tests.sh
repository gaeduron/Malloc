echo "\n\033[1;33mMALLOC UNIT TEST:\033[0m\n"
./test_libft_malloc

echo "\n\n\033[1;33m42 CORRECTION TEST:\033[0m"
echo "INFO:"
./print_page_size
echo "$> nm ../libft_malloc.so"
nm ../libft_malloc.so

echo "\n\nDEFAULT:"
default_pages=$(/usr/bin/time -l ./test_no_malloc 2>&1 | grep "page reclaims" | sed 's/[^0-9]//g')
echo "$default_pages"
echo "0"

echo "\nFor 1MBytes asked:"
echo "\nOFFICIAL MALLOC:"
malloc_pages=$(/usr/bin/time -l ./test_official_malloc 2>&1 | grep "page reclaims" | sed 's/[^0-9]//g')
echo "$malloc_pages"
bc <<< "$malloc_pages - $default_pages"

echo "\nLIBFT MALLOC:"
libft_pages=$(zsh ./run.sh /usr/bin/time -l ./test_official_malloc 2>&1 | grep "page reclaims" | sed 's/[^0-9]//g')
echo "$libft_pages"
bc <<< "$libft_pages - $default_pages"

echo "Minimal page number:"
bc <<< "(1024 * 1024) / 4096"