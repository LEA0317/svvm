test : test_avx.s test_avx2.s test_avx512.s

clean_test : 
	rm -fr *.s a.out

test_avx.s:
	clang++ -Ofast -mavx -std=c++11 test/test_avx.cpp -S -I${CURDIR}/include

test_avx2.s:
	clang++ -Ofast -mavx2 -std=c++11 test/test_avx2.cpp -S -I${CURDIR}/include

test_avx512.s:
	clang++ -Ofast -mavx512f -std=c++11 test/test_avx512.cpp -S -I${CURDIR}/include
