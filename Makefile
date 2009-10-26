default: shared

krb5_simple_auth.o: krb5_simple_auth.c
	gcc -m32 -c krb5_simple_auth.c -I. -lkrb5 -fPIC -g -I/usr/include

shared: krb5_simple_auth.o
	gcc -m32 -shared -Wl,-export-dynamic,-soname,krb5_simple_auth.so -o krb5_simple_auth.so krb5_simple_auth.o -lc -lkrb5

binary: krb5_simple_auth

krb5_simple_auth: krb5_simple_auth.c
	gcc -m32 -o krb5_simple_auth -I. -lkrb5 krb5_simple_auth.c

clean:
	rm *.o *.so.*
