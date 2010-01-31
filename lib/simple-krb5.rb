require 'ffi'

module SimpleKrb5
  extend FFI::Library

  ffi_lib File.join(File.expand_path(__FILE__).split("/").tap do |path|
    path.pop
    path << "krb5_simple_auth.so"
  end)
  attach_function "Krb5_get_init_creds_password", [:string, :string], :int

  def self.authenticate(user, password)
    Krb5_get_init_creds_password(user, password) == 1
  end
end
