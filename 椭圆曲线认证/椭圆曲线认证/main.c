#include <openssl/ssl.h>
#include<stdio.h>

#define ECDH_SIZE 33

void handleErrors()
{
	printf("Error occurred.\n");
}
static void disp(const char *str, const void *pbuf, const int size)
{
	int i = 0;
	if (str != NULL){
		printf("%s:\n", str);
	}
	if (pbuf != NULL && size > 0){
		for (i = 0; i<size; i++)
			printf("%02x ", *((unsigned char *)pbuf + i));
		putchar('\n');
	}
	putchar('\n');
}
int main() {
	/* alice */
	EC_KEY *ecdh = EC_KEY_new();
	EC_POINT *point = NULL;
	EC_POINT *point2c;
	EC_GROUP *group;
	unsigned char pubkey[ECDH_SIZE];
	unsigned char shared[ECDH_SIZE];
	int len;

	//Generate Public
	ecdh = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);//NID_secp521r1
	EC_KEY_generate_key(ecdh);
	point = (struct ec_point_st *)EC_KEY_get0_public_key(ecdh);
	group = (struct ec_group_st *)EC_KEY_get0_group(ecdh);

	if (0 == (len = EC_POINT_point2oct(group, point, POINT_CONVERSION_COMPRESSED, pubkey, ECDH_SIZE, NULL))) handleErrors();
	printf("len=%d\n", len);

	/* bob */
	EC_KEY *ecdh2 = EC_KEY_new();
	EC_POINT *point2 = NULL;
	EC_POINT *pointc;
	EC_GROUP *group2;
	unsigned char pubkey2[ECDH_SIZE];
	unsigned char shared2[ECDH_SIZE];
	int len2;

	//Generate Public
	ecdh2 = EC_KEY_new_by_curve_name(NID_X9_62_prime256v1);//NID_secp521r1
	EC_KEY_generate_key(ecdh2);
	point2 = (struct ec_point_st *)EC_KEY_get0_public_key(ecdh2);
	group2 = (struct ec_group_st *)EC_KEY_get0_group(ecdh2);

	if (0 == (len2 = EC_POINT_point2oct(group2, point2, POINT_CONVERSION_COMPRESSED, pubkey2, ECDH_SIZE, NULL))) handleErrors();
	printf("len2=%d\n", len);

	/* alice */
	//ComputeKey
	point2c = EC_POINT_new(group);
	EC_POINT_oct2point(group, point2c, pubkey2, ECDH_SIZE, NULL);

	if (0 != EC_POINT_cmp(group, point2, point2c, NULL)) handleErrors();
	if (0 == (len = ECDH_compute_key(shared, ECDH_SIZE, point2c, ecdh, NULL))) handleErrors();
	printf("len=%d\n", len);
	disp("shared", shared, len);

	/* bob */
	//ComputeKey
	pointc = EC_POINT_new(group2);
	EC_POINT_oct2point(group2, pointc, pubkey, ECDH_SIZE, NULL);

	if (0 != EC_POINT_cmp(group2, point, pointc, NULL)) handleErrors();
	if (0 == (len2 = ECDH_compute_key(shared2, ECDH_SIZE, pointc, ecdh2, NULL))) handleErrors();
	printf("len2=%d\n", len2);
	disp("shared2", shared2, len2);

	/* alice */
	EC_POINT_free(pointc);
	EC_KEY_free(ecdh);
	/* bob */
	EC_POINT_free(point2c);
	EC_KEY_free(ecdh2);

	printf("To the end\n");

	return 0;
}
