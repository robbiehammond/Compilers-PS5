FILENAME='a.out'


echo "----------"
clang  optimizations.c -o noopt.o
echo "No optimizations"
time ./noopt.o

echo "----------"


clang -O1 optimizations.c -o O1.o 
echo "O1"
time ./O1.o
echo "----------"


clang -O2 optimizations.c -o O2.o
echo "O2"
time ./O2.o
echo "----------"

clang -Os optimizations.c -o Os.o
echo "Os"
time ./Os.o
echo "----------"

clang -Oz optimizations.c -o Oz.o
echo "Oz"
time ./Oz.o
echo "----------"

clang -O3 optimizations.c -o O3.o
echo "O3"
time ./O3.o
echo "----------"

clang -Ofast optimizations.c -o Ofast.o
echo "Ofast"
time ./Ofast.o
echo "----------"