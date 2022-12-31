#ifndef _EASY_ECC_H_
#define _EASY_ECC_H_

#include <stdint.h>
typedef uint64_t uint256_t[4];
extern uint256_t exPrivateKey;
/* Curve selection options. */
#define secp128r1 16
#define secp192r1 24
#define secp256r1 32
#define secp384r1 48
#ifndef ECC_CURVE
    #define ECC_CURVE secp256r1
#endif

#if (ECC_CURVE != secp128r1 && ECC_CURVE != secp192r1 && ECC_CURVE != secp256r1 && ECC_CURVE != secp384r1)
    #error "Must define ECC_CURVE to one of the available curves"
#endif

#define ECC_BYTES ECC_CURVE

#ifdef __cplusplus
extern "C"
{
#endif

#define NUM_ECC_DIGITS (ECC_BYTES/8)
#define MAX_TRIES 16

typedef struct
{
    uint64_t x[NUM_ECC_DIGITS];
    uint64_t y[NUM_ECC_DIGITS];
} EccPoint;

/* ecc_make_key() function.
Create a public/private key pair.

Outputs:
    p_publicKey  - Will be filled in with the public key.
    p_privateKey - Will be filled in with the private key.

Returns 1 if the key pair was generated successfully, 0 if an error occurred.
*/
int ecc_make_key(uint8_t p_publicKey[ECC_BYTES+1], uint8_t p_privateKey[ECC_BYTES]);

/* ecdh_shared_secret() function.
Compute a shared secret given your secret key and someone else's public key.
Note: It is recommended that you hash the result of ecdh_shared_secret before using it for symmetric encryption or HMAC.

Inputs:
    p_publicKey  - The public key of the remote party.
    p_privateKey - Your private key.

Outputs:
    p_secret - Will be filled in with the shared secret value.

Returns 1 if the shared secret was generated successfully, 0 if an error occurred.
*/
int ecdh_shared_secret(const uint8_t p_publicKey[ECC_BYTES+1], const uint8_t p_privateKey[ECC_BYTES], uint8_t p_secret[ECC_BYTES]);

/* ecdsa_sign() function.
Generate an ECDSA signature for a given hash value.

Usage: Compute a hash of the data you wish to sign (SHA-2 is recommended) and pass it in to
this function along with your private key.

Inputs:
    p_privateKey - Your private key.
    p_hash       - The message hash to sign.

Outputs:
    p_signature  - Will be filled in with the signature value.

Returns 1 if the signature generated successfully, 0 if an error occurred.
*/
int ecdsa_sign(const uint8_t p_privateKey[ECC_BYTES], const uint8_t p_hash[ECC_BYTES], uint8_t p_signature[ECC_BYTES*2]);

/* ecdsa_verify() function.
Verify an ECDSA signature.

Usage: Compute the hash of the signed data using the same hash as the signer and
pass it to this function along with the signer's public key and the signature values (r and s).

Inputs:
    p_publicKey - The signer's public key
    p_hash      - The hash of the signed data.
    p_signature - The signature value.

Returns 1 if the signature is valid, 0 if it is invalid.
*/
int ecdsa_verify(const uint8_t p_publicKey[ECC_BYTES+1], const uint8_t p_hash[ECC_BYTES], const uint8_t p_signature[ECC_BYTES*2]);

/* ecc_make_KeyY() function.
Get publickey Y

Inputs:
    PublicKey_IN - PublicKeyX
    PublicKey_Y  - PublicKeyY.
*/
void ecc_make_KeyY(const uint8_t PublicKey_IN[33],uint8_t PublicKey_Y[32]);
void vli_mult(uint64_t *p_result, uint64_t *p_left, uint64_t *p_right);
int vli_cmp(uint64_t *p_left, uint64_t *p_right);
void vli_modAdd(uint64_t* p_result, uint64_t* p_left, uint64_t* p_right, uint64_t* p_mod);
/*求left*right%p_mod保存到p_result*/
void vli_modMult(uint64_t* p_result, uint64_t* p_left, uint64_t* p_right, uint64_t* p_mod);
uint64_t vli_sub(uint64_t* p_result, uint64_t* p_left, uint64_t* p_right);
void EccPoint_mult(EccPoint* p_result, EccPoint* p_point, uint64_t* p_scalar, uint64_t* p_initialZ);
void XYcZ_add(uint64_t* X1, uint64_t* Y1, uint64_t* X2, uint64_t* Y2);
void vli_modSquare_fast(uint64_t* p_result, uint64_t* p_left);
void vli_modSub(uint64_t* p_result, uint64_t* p_left, uint64_t* p_right, uint64_t* p_mod);
void vli_modMult_fast(uint64_t* p_result, uint64_t* p_left, uint64_t* p_right);
void mod_sqrt(uint64_t a[NUM_ECC_DIGITS]);
uint64_t vli_add(uint64_t* p_result, uint64_t* p_left, uint64_t* p_right);
void XYcZ_addC(uint64_t* X1, uint64_t* Y1, uint64_t* X2, uint64_t* Y2);
void XYcZ_initial_double(uint64_t* X1, uint64_t* Y1, uint64_t* X2, uint64_t* Y2, uint64_t* p_initialZ);
void vli_modInv(uint64_t* p_result, uint64_t* p_input, uint64_t* p_mod);



#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif /* _EASY_ECC_H_ */

