clang -emit-llvm -S optimizations.c -o noopt.ll

opt --type-promotion --break-crit-edges -S noopt.ll -o opt1.ll
opt --globalopt -S noopt.ll -o opt2.ll
opt --strip -S noopt.ll -o opt3.ll
