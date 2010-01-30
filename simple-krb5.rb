require 'ffi'
module SimpleKrb5
  extend FFI::Library
   
  ffi_lib "krb5_simple_auth.so"
  attach_function(:Krb5_get_init_creds_password, [:string, :string], :int)

  def self.authenticate(user, password)
    Krb5_get_init_creds_password(user, password) == 1
  end
end
