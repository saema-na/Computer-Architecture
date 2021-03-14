#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef union {
	float floating_value_in_32_bits;
	struct sign_exp_mantissa {
		unsigned mantissa : 23;
		unsigned exponent : 8;
		unsigned sign : 1;
	} f_bits;
	struct single_bits {
		unsigned b0 : 1;
		unsigned b1 : 1;
		unsigned b2 : 1;
		unsigned b3 : 1;
		unsigned b4 : 1;
		unsigned b5 : 1;
		unsigned b6 : 1;
		unsigned b7 : 1;
		unsigned b8 : 1;
		unsigned b9 : 1;
		unsigned b10 : 1;
		unsigned b11 : 1;
		unsigned b12 : 1;
		unsigned b13 : 1;
		unsigned b14 : 1;
		unsigned b15 : 1;
		unsigned b16 : 1;
		unsigned b17 : 1;
		unsigned b18 : 1;
		unsigned b19 : 1;
		unsigned b20 : 1;
		unsigned b21 : 1;
		unsigned b22 : 1;
		unsigned b23 : 1;
		unsigned b24 : 1;
		unsigned b25 : 1;
		unsigned b26: 1;
		unsigned b27 : 1;
		unsigned b28: 1;
		unsigned b29 : 1;			
		unsigned b30 : 1;
		unsigned b31 : 1;
	}bit;
}FLOAT_UN;


int main(int argc, char* argv[])
{
	FLOAT_UN float_32_s1, float_32_s2, float_32_rslt, fun_arg;
	
	/******** local helper variables ***********/
	float the_hardware_result;
	int mant_s1, mant_s2, mant_res, exp_s1, exp_s2;
	int i, j, k, shift_count;
	int denom_s1 = true, denom_s2 = true;


	/******** request two floating point numbers ********/
	/*printf("please enter your first floating point number and new-line: ");
	scanf("%g", &float_32_s1.floating_value_in_32_bits);
	printf("please enter your second floating point number and new-line: ");
	scanf("%g", &float_32_s2.floating_value_in_32_bits);*/
	
	printf("Please enter two positive floating point values each with:\n\t- no more than 6 significant digits\n\t- a value between + 10**37 and 10**-37\n\n");
	printf("Enter float 1:\t");
	scanf("%g", &float_32_s1.floating_value_in_32_bits);
	printf("Enter float 2:\t");
	scanf("%g", &float_32_s2.floating_value_in_32_bits);


	//---------------------------------------------------------------------------------------------------------- assigning input arr bits
	char bs1[43];
	for (i = 0; i < 42; i++) {
		bs1[i] = ' ';
	}
	bs1[42] = '\0';
	bs1[0] = float_32_s1.bit.b31 ? '1' : '0';

	bs1[2] = float_32_s1.bit.b30 ? '1' : '0';
	bs1[3] = float_32_s1.bit.b29 ? '1' : '0';
	bs1[4] = float_32_s1.bit.b28 ? '1' : '0';
	bs1[5] = float_32_s1.bit.b27 ? '1' : '0';

	bs1[7] = float_32_s1.bit.b26 ? '1' : '0';
	bs1[8] = float_32_s1.bit.b25 ? '1' : '0';
	bs1[9] = float_32_s1.bit.b24 ? '1' : '0';
	bs1[10] = float_32_s1.bit.b23 ? '1' : '0';

	bs1[12] = float_32_s1.bit.b22 ? '1' : '0';
	bs1[13] = float_32_s1.bit.b21 ? '1' : '0';
	bs1[14] = float_32_s1.bit.b20 ? '1' : '0';

	bs1[16] = float_32_s1.bit.b19 ? '1' : '0';
	bs1[17] = float_32_s1.bit.b18 ? '1' : '0';
	bs1[18] = float_32_s1.bit.b17 ? '1' : '0';
	bs1[19] = float_32_s1.bit.b16 ? '1' : '0';

	bs1[21] = float_32_s1.bit.b15 ? '1' : '0';
	bs1[22] = float_32_s1.bit.b14 ? '1' : '0';
	bs1[23] = float_32_s1.bit.b13 ? '1' : '0';
	bs1[24] = float_32_s1.bit.b12 ? '1' : '0';

	bs1[26] = float_32_s1.bit.b11 ? '1' : '0';
	bs1[27] = float_32_s1.bit.b10 ? '1' : '0';
	bs1[28] = float_32_s1.bit.b9 ? '1' : '0';
	bs1[29] = float_32_s1.bit.b8 ? '1' : '0';

	bs1[31] = float_32_s1.bit.b7 ? '1' : '0';
	bs1[32] = float_32_s1.bit.b6 ? '1' : '0';
	bs1[33] = float_32_s1.bit.b5 ? '1' : '0';
	bs1[34] = float_32_s1.bit.b4 ? '1' : '0';

	bs1[36] = float_32_s1.bit.b3 ? '1' : '0';
	bs1[37] = float_32_s1.bit.b2 ? '1' : '0';
	bs1[38] = float_32_s1.bit.b1 ? '1' : '0';
	bs1[39] = float_32_s1.bit.b0 ? '1' : '0';


	char bs2[43];
	for (i = 0; i < 42; i++) {
		bs2[i] = ' ';
	}
	bs2[42] = '\0';
	bs2[0] = float_32_s1.bit.b31 ? '1' : '0';

	bs2[2] = float_32_s2.bit.b30 ? '1' : '0';
	bs2[3] = float_32_s2.bit.b29 ? '1' : '0';
	bs2[4] = float_32_s2.bit.b28 ? '1' : '0';
	bs2[5] = float_32_s2.bit.b27 ? '1' : '0';

	bs2[7] = float_32_s2.bit.b26 ? '1' : '0';
	bs2[8] = float_32_s2.bit.b25 ? '1' : '0';
	bs2[9] = float_32_s2.bit.b24 ? '1' : '0';
	bs2[10] = float_32_s2.bit.b23 ? '1' : '0';

	bs2[12] = float_32_s2.bit.b22 ? '1' : '0';
	bs2[13] = float_32_s2.bit.b21 ? '1' : '0';
	bs2[14] = float_32_s2.bit.b20 ? '1' : '0';

	bs2[16] = float_32_s2.bit.b19 ? '1' : '0';
	bs2[17] = float_32_s2.bit.b18 ? '1' : '0';
	bs2[18] = float_32_s2.bit.b17 ? '1' : '0';
	bs2[19] = float_32_s2.bit.b16 ? '1' : '0';

	bs2[21] = float_32_s2.bit.b15 ? '1' : '0';
	bs2[22] = float_32_s2.bit.b14 ? '1' : '0';
	bs2[23] = float_32_s2.bit.b13 ? '1' : '0';
	bs2[24] = float_32_s2.bit.b12 ? '1' : '0';

	bs2[26] = float_32_s2.bit.b11 ? '1' : '0';
	bs2[27] = float_32_s2.bit.b10 ? '1' : '0';
	bs2[28] = float_32_s2.bit.b9 ? '1' : '0';
	bs2[29] = float_32_s2.bit.b8 ? '1' : '0';

	bs2[31] = float_32_s2.bit.b7 ? '1' : '0';
	bs2[32] = float_32_s2.bit.b6 ? '1' : '0';
	bs2[33] = float_32_s2.bit.b5 ? '1' : '0';
	bs2[34] = float_32_s1.bit.b4 ? '1' : '0';

	bs2[36] = float_32_s2.bit.b3 ? '1' : '0';
	bs2[37] = float_32_s2.bit.b2 ? '1' : '0';
	bs2[38] = float_32_s2.bit.b1 ? '1' : '0';
	bs2[39] = float_32_s2.bit.b0 ? '1' : '0';
//------------------------------------------------------------------------------------------------------------------------------------------------


	printf("\nOriginal pattern of float 1\t\t:\t");
	for (i = 0; i < 40; ++i) {
		printf("%c", bs1[i]);
	}
	printf("\nOriginal pattern of float 2\t\t:\t");
	for (i = 0; i < 40; ++i) {
		printf("%c", bs2[i]);
	}

	/****** generate the floating point hardware result ********/
	the_hardware_result = float_32_s2.floating_value_in_32_bits + float_32_s1.floating_value_in_32_bits;

	/******* get the mantissa and exponent components ****/
/******* into the helper variables ****/
	mant_s1 = float_32_s1.f_bits.mantissa;
	mant_s2 = float_32_s2.f_bits.mantissa;
	exp_s1 = float_32_s1.f_bits.exponent;
	exp_s2 = float_32_s2.f_bits.exponent;
	
	
	/******* check for normalization and slam in the *****/
	/******* hidden bit if normalized *****/
	if (exp_s1) {
		mant_s1 |= (1 << 23);
		denom_s1 = 0;
	}
	if (exp_s2) {
		mant_s2 |= (1 << 23);
		denom_s2 = 0;
	}

	/******* check exponent diff and who's the smallest ****/
	if ((shift_count = exp_s1 - exp_s2) < 0) {
		shift_count = -(shift_count); /* keep diff + */
		if (shift_count > 24)shift_count = 24;
		if (shift_count >= 1 && denom_s1) {
			mant_s1 = (mant_s1 >> shift_count - 1);
		}
		else {
			mant_s1 = mant_s1 >> shift_count;
		}
		float_32_rslt.f_bits.exponent = exp_s2;
	}
	else {
		if (shift_count > 24)shift_count = 24;
		if (shift_count >= 1 && denom_s2) {
			mant_s2 = (mant_s2 >> shift_count - 1);
		}
		else {
			mant_s2 = mant_s2 >> shift_count;
		}
		float_32_rslt.f_bits.exponent = exp_s1;
	}
	/**** finally ready to add helper mantissa variables ****/
	mant_res = mant_s1 + mant_s2;

	/**** check if the addition overflowed 24 bits, since ****/
	/**** mantissa with hidden bit can only be 24 bits ****/
	/**** if we need to right shift, must increase the exp ****/
	/**** finally clear the slammed hidden bit in the ****/
	/**** mantissa helper to get to 23 bits and put these ****/
	/**** 23 bits into the mantissa bit field of the result ****/
	if (mant_res & (1 << 24)) {
		mant_res >>= 1;
		float_32_rslt.f_bits.exponent++;
		printf("\n2 HIDDEN BITS, MUST INCREMENT EXPONENT\n");
			float_32_rslt.f_bits.mantissa = (mant_res & ~(1 << 23));
	}
	else {
		float_32_rslt.f_bits.mantissa = (mant_res & ~(1 << 23));
	}
	//--------------------------------------------------------------------------------------------------  assigning result array bits
	char bs3[43];
	for (i = 0; i < 42; i++) {
		bs3[i] = ' ';
	}
	bs3[42] = '\0';
	//bs3[0] = float_32_rslt.bit.b31 ? '1' : '0';
	float_32_rslt.bit.b31 = '0';
	bs3[0] = '0';

	bs3[2] = float_32_rslt.bit.b30 ? '1' : '0';
	bs3[3] = float_32_rslt.bit.b29 ? '1' : '0';
	bs3[4] = float_32_rslt.bit.b28 ? '1' : '0';
	bs3[5] = float_32_rslt.bit.b27 ? '1' : '0';

	bs3[7] = float_32_rslt.bit.b26 ? '1' : '0';
	bs3[8] = float_32_rslt.bit.b25 ? '1' : '0';
	bs3[9] = float_32_rslt.bit.b24 ? '1' : '0';
	bs3[10] = float_32_rslt.bit.b23 ? '1' : '0';

	bs3[12] = float_32_rslt.bit.b22 ? '1' : '0';
	bs3[13] = float_32_rslt.bit.b21 ? '1' : '0';
	bs3[14] = float_32_rslt.bit.b20 ? '1' : '0';

	bs3[16] = float_32_rslt.bit.b19 ? '1' : '0';
	bs3[17] = float_32_rslt.bit.b18 ? '1' : '0';
	bs3[18] = float_32_rslt.bit.b17 ? '1' : '0';
	bs3[19] = float_32_rslt.bit.b16 ? '1' : '0';

	bs3[21] = float_32_rslt.bit.b15 ? '1' : '0';
	bs3[22] = float_32_rslt.bit.b14 ? '1' : '0';
	bs3[23] = float_32_rslt.bit.b13 ? '1' : '0';
	bs3[24] = float_32_rslt.bit.b12 ? '1' : '0';

	bs3[26] = float_32_rslt.bit.b11 ? '1' : '0';
	bs3[27] = float_32_rslt.bit.b10 ? '1' : '0';
	bs3[28] = float_32_rslt.bit.b9 ? '1' : '0';
	bs3[29] = float_32_rslt.bit.b8 ? '1' : '0';

	bs3[31] = float_32_rslt.bit.b7 ? '1' : '0';
	bs3[32] = float_32_rslt.bit.b6 ? '1' : '0';
	bs3[33] = float_32_rslt.bit.b5 ? '1' : '0';
	bs3[34] = float_32_rslt.bit.b4 ? '1' : '0';

	bs3[36] = float_32_rslt.bit.b3 ? '1' : '0';
	bs3[37] = float_32_rslt.bit.b2 ? '1' : '0';
	bs3[38] = float_32_rslt.bit.b1 ? '1' : '0';
	bs3[39] = float_32_rslt.bit.b0 ? '1' : '0';

	//-----------------------------------------------------------------------------------

	if ((float_32_s1.f_bits.exponent == 255) || (float_32_s2.f_bits.exponent == 255)) {
		printf("infinity*****\n");
		int j = 0;
		for (i = 2; i < 11; ++i) {	
			j++;									// assign exponent bits to: 1111 1111
			bs3[i] = '1';	
			if (j % 5 == 0) {
				bs3[i] = ' ';
			}
		}
		j = 0;
		bs3[11] = ' ';
		for (i = 12; i < 40; ++i) {
			j++;
			bs3[i] = '0';							// assign mantissa bits to: 0000 0000 0000 0000 0000 0000
			if (j % 5 == 0) {
				bs3[i] = ' ';
			}
		}
	}

	printf("\nBit pattern of result\t\t\t:\t");
	for (i = 0; i < 40; ++i) {
		printf("%c", bs3[i]);
	}
	printf("\n\n");

	printf("EMULATED FLOATING RESULT FROM PRINTF ==>>>  %g\n", float_32_rslt.floating_value_in_32_bits);
	printf("HARDWARE FLOATING RESULT FROM PRINTF ==>>>  %g", the_hardware_result);
	printf("\n\n\n");

	return 0;
}


