--- lib/softoken/pkcs11c.c.orig	2021-09-30 12:41:14 UTC
+++ lib/softoken/pkcs11c.c
@@ -6293,9 +6293,6 @@ sftk_unwrapPrivateKey(SFTKObject *key, S
             break;
         case NSSLOWKEYDSAKey:
             keyType = CKK_DSA;
-            crv = (sftk_hasAttribute(key, CKA_NSS_DB)) ? CKR_OK : CKR_KEY_TYPE_INCONSISTENT;
-            if (crv != CKR_OK)
-                break;
             crv = sftk_AddAttributeType(key, CKA_KEY_TYPE, &keyType,
                                         sizeof(keyType));
             if (crv != CKR_OK)
@@ -6335,9 +6332,6 @@ sftk_unwrapPrivateKey(SFTKObject *key, S
         /* what about fortezza??? */
         case NSSLOWKEYECKey:
             keyType = CKK_EC;
-            crv = (sftk_hasAttribute(key, CKA_NSS_DB)) ? CKR_OK : CKR_KEY_TYPE_INCONSISTENT;
-            if (crv != CKR_OK)
-                break;
             crv = sftk_AddAttributeType(key, CKA_KEY_TYPE, &keyType,
                                         sizeof(keyType));
             if (crv != CKR_OK)
