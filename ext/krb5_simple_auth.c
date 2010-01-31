#include <krb5_simple_auth.h>

struct krb5_object {
  krb5_context ctx;
  krb5_creds creds;
  krb5_principal princ;
};

/*
 * call-seq:
 *   new
 *
 * Create a new Krb5Auth::Krb5 object.  This must be called before any other 
 * methods are called.  Returns true on success, raises 
 * Krb5Auth::Krb5::Exception on failure.
 */
struct krb5_object * Krb5_new()
{
  struct krb5_object *kerb;
  krb5_error_code krbret;

  kerb = (struct krb5_object *)malloc(sizeof(struct krb5_object));
  if (kerb == NULL) /* fail */;

  memset(kerb, 0, sizeof(struct krb5_object));

  krbret = krb5_init_context(&kerb->ctx);
  if (krbret) /* fail */;

  return kerb;
}

/*
 * call-seq:
 *   get_init_creds_password(username, password)
 *
 * Call krb5_get_init_creds_password() to get credentials based on a username 
 * and password.  Returns true on success, raises Krb5Auth::Krb5::Exception 
 * on failure.
 */
int Krb5_get_init_creds_password(char* user, char* pass)
{

  struct krb5_object *kerb = Krb5_new();
  krb5_error_code krbret;

  krbret = krb5_parse_name(kerb->ctx, user, &kerb->princ);
  if (krbret) {
    //fail
  }

  krbret = krb5_get_init_creds_password(kerb->ctx, &kerb->creds, kerb->princ,
					pass, 0, NULL, 0,NULL, NULL);
  if (krbret) 
     return 0;
  else
     return 1;
}

int Krb5_get_init_creds_password_proxy(char* userString, int userSize, 
   char* pwString, int pwSize) {
   char* user = (char*)calloc(userSize+1, sizeof(char));
   char* password = (char*)calloc(pwSize+1, sizeof(char));

   strncpy(user, userString, userSize);
   user[userSize] = '\0';
   strncpy(password, pwString, pwSize);
   user[pwSize] = '\0';

   return Krb5_get_init_creds_password(user, password);
}

int main(int argc, char** argv) {
   if (argc < 3) return 1;

   printf("User %s with %s: %d\n", argv[1], argv[2], 
	 (int)Krb5_get_init_creds_password(argv[1], argv[2]));
   return 0;
}
