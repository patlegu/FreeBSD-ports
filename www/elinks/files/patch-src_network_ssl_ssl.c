--- src/network/ssl/ssl.c.orig	2019-01-09 23:04:06 UTC
+++ src/network/ssl/ssl.c
@@ -49,11 +49,17 @@ init_openssl(struct module *module)
 	 * cannot initialize the PRNG and so every attempt to use SSL fails.
 	 * It's actually an OpenSSL FAQ, and according to them, it's up to the
 	 * application coders to seed the RNG. -- William Yodlowsky */
-	if (RAND_egd(RAND_file_name(f_randfile, sizeof(f_randfile))) < 0) {
+	RAND_file_name(f_randfile, sizeof(f_randfile));
+#ifndef OPENSSL_NO_EGD
+	if (RAND_egd(f_randfile) < 0)
+	{
 		/* Not an EGD, so read and write to it */
+#endif
 		if (RAND_load_file(f_randfile, -1))
 			RAND_write_file(f_randfile);
+#ifndef OPENSSL_NO_EGD
 	}
+#endif
 
 	SSLeay_add_ssl_algorithms();
 	context = SSL_CTX_new(SSLv23_client_method());
