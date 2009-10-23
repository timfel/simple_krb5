default: shared

krb5_simple_auth.o: krb5_simple_auth.c
	gcc -c krb5_simple_auth.c -I. -lkrb5 -fPIC -g

shared: krb5_simple_auth.o
	gcc -shared -Wl,-soname,krb5_simple_auth.so.1 -o krb5_simple_auth.so.1.0.0 krb5_simple_auth.o -lc	

binary: krb5_simple_auth

krb5_simple_auth: krb5_simple_auth.c
	gcc -o krb5_simple_auth -I. -lkrb5 krb5_simple_auth.c

clean:
	rm *.o *.so.*
