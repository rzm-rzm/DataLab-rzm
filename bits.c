/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */
#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */
You will provide your solution to the Data Lab by
editing the collection of functions in this source file.
INTEGER CODING RULES:
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;
      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }
  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.
  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.
 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.
EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }
  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }
FLOATING POINT CODING RULES
For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.
You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.
NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.
/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */
#endif
#include "bits.h"

/* P1 */
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
    return 1 << 31;
}

/* P2 */
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
    return ~(~x & ~y) & ~(x & y);
}

/* P3 */
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x) {
    int mask, neg;
    mask = x >> 31;
    neg = ~x + 1;
    return mask & neg;
}

/* P4 */
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
    int s, d, byte_val;
    s = src << 3;
    d = dst << 3;
    byte_val = (x >> s) & 0xFF;
    return (x & ~(0xFF << d)) | (byte_val << d);
}

/* P5 */
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
    int mask;
    mask = ~(((1 << 31) >> n) << 1);
    return (x >> n) & mask;
}

/* P6 */
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
    int mask, low4, high4;
    mask = 0x0F;
    mask = mask | (mask << 8);
    mask = mask | (mask << 16);
    low4 = x & mask;
    high4 = x & (mask << 4);
    return (low4 << 4) | ((high4 >> 4) & mask);
}

/* P7 */
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *            secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
    int l0;
    l0 = ~x & (x + 1);
    x = x | l0;
    return ~x & (x + 1);
}

/* P8 */
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return (x & 1) ^ 1;
}

/* P9 */
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
    int n_mod, nm32, mask, right, left;
    n_mod = n & 31;
    nm32 = 33 + ~n_mod;
    mask = ~(((1 << 31) >> n_mod) << 1);
    right = (x >> n_mod) & mask;
    left = x << nm32;
    return right | left;
}

/* P10 */
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
    int nm1, half_m1, q, odd, offset;
    nm1 = n + ~0;
    half_m1 = ~(~0 << nm1);
    q = x >> n;
    odd = q & 1;
    offset = half_m1 + odd;
    return (x + offset) & (~0 << n);
}

/* P11 */
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *            midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
    int xy_xor, floor_mid, same_sign, diff_sign;
    int sub, sub_neg, x_pos, x_greater, odd;
    xy_xor = x ^ y;
    floor_mid = (x & y) + (xy_xor >> 1);
    same_sign = ~(xy_xor >> 31);
    diff_sign = xy_xor >> 31;
    sub = y + ~x + 1;
    sub_neg = sub >> 31;
    x_pos = ~(x >> 31);
    x_greater = (same_sign & sub_neg) | (diff_sign & x_pos);
    odd = xy_xor & 1;
    return floor_mid + (x_greater & odd);
}

/* P12 */
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
    int x_sign, xa_xor, xb_xor;
    int same1, same2, diff1, diff2;
    int d1, d2, sign_d1, sign_d2;
    int diff_sign, zero1, zero2;
    x_sign = x >> 31;
    xa_xor = x ^ a;
    xb_xor = x ^ b;
    same1 = ~(xa_xor >> 31);
    same2 = ~(xb_xor >> 31);
    diff1 = xa_xor >> 31;
    diff2 = xb_xor >> 31;
    d1 = x + ~a + 1;
    d2 = x + ~b + 1;
    sign_d1 = (same1 & (d1 >> 31)) | (diff1 & x_sign);
    sign_d2 = (same2 & (d2 >> 31)) | (diff2 & x_sign);
    diff_sign = sign_d1 ^ sign_d2;
    zero1 = !d1;
    zero2 = !d2;
    return (diff_sign | zero1 | zero2) & 1;
}

/* P13 */
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 *   INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
    int x2, ov1, x4, ov2, res;
    int same, diff, ov3, overflow, int_max, sat;
    x2 = x + x;
    ov1 = (x ^ x2) >> 31;
    x4 = x2 + x2;
    ov2 = (x2 ^ x4) >> 31;
    res = x4 + x;
    same = ~(x4 ^ x);
    diff = x4 ^ res;
    ov3 = (same & diff) >> 31;
    overflow = ov1 | ov2 | ov3;
    int_max = ~(1 << 31);
    sat = (x >> 31) ^ int_max;
    return (res & ~overflow) | (sat & overflow);
}

/* P14 */
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
    int x_sign, y_sign, s1, s1_sign;
    int both_pos1, both_neg1, ov1_pos, ov1_neg;
    int z_sign, s2, s2_sign;
    int both_pos2, both_neg2, ov2_pos, ov2_neg;
    int ov_pos, ov_neg;
    x_sign = x >> 31;
    y_sign = y >> 31;
    s1 = x + y;
    s1_sign = s1 >> 31;
    both_pos1 = ~x_sign & ~y_sign;
    both_neg1 = x_sign & y_sign;
    ov1_pos = both_pos1 & s1_sign;
    ov1_neg = both_neg1 & ~s1_sign;
    z_sign = z >> 31;
    s2 = s1 + z;
    s2_sign = s2 >> 31;
    both_pos2 = ~s1_sign & ~z_sign;
    both_neg2 = s1_sign & z_sign;
    ov2_pos = both_pos2 & s2_sign;
    ov2_neg = both_neg2 & ~s2_sign;
    ov_pos = ov1_pos | ov2_pos;
    ov_neg = ov1_neg | ov2_neg;
    return (ov_pos & 1) + ov_neg;
}

/* P15 */
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
    unsigned s, exp_e, frac, M, M3, mask, rem, frac_out;
    unsigned frac_mask, one_23, round_bit, sticky_bit, tmp;
    int E, E3, k, shift_right, exp_out;
    s = uf >> 31;
    exp_e = (uf >> 23) & 0xFF;
    frac_mask = ~(~0 << 23);
    one_23 = 1 << 23;
    frac = uf & frac_mask;

    /* Inf / NaN 直接返回 */
    if (exp_e == 0xFF) {
        return uf;
    }
    /* 0 直接返回对应符号的0 */
    if (exp_e == 0 && frac == 0) {
        return s << 31;
    }
    /* 统一转换为 M × 2^E 的数值形式 */
    if (exp_e == 0) {
        M = frac;
        E = -149;
    } else {
        M = frac | one_23;
        E = exp_e - 150;
    }
    /* 乘以 3/2：有效数字乘3，指数减1 */
    M3 = M + (M << 1);
    E3 = E - 1;
    /* 查找M3的最高位位置k */
    k = 0;
    tmp = M3;
    while (tmp >> 1) {
        k = k + 1;
        tmp = tmp >> 1;
    }
    /* 计算总右移位数和最终阶码 */
    if (E3 + k >= -126) {
        shift_right = k - 23;
        exp_out = E3 + shift_right + 150;
    } else {
        shift_right = -149 - E3;
        exp_out = 0;
    }
    /* 计算舍入位和粘滞位 */
    round_bit = 0;
    sticky_bit = 0;
    if (shift_right > 0) {
        mask = (1 << shift_right) - 1;
        rem = M3 & mask;
        round_bit = (rem >> (shift_right - 1)) & 1;
        if (shift_right > 1) {
            sticky_bit = (rem & ((1 << (shift_right - 1)) - 1)) != 0;
        }
        M3 = M3 >> shift_right;
    }
    frac_out = M3 & frac_mask;
    /* 银行家舍入 */
    if (round_bit && (sticky_bit || (frac_out & 1))) {
        frac_out = frac_out + 1;
        if (frac_out >= one_23) {
            frac_out = 0;
            exp_out = exp_out + 1;
        }
    }
    /* 阶码溢出：返回无穷大 */
    if (exp_out >= 0xFF) {
        return (s << 31) | (0xFF << 23);
    }
    return (s << 31) | (exp_out << 23) | frac_out;
}

/* P16 */
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
    unsigned s, frac, m, mask, rem, int_m;
    int exp, E, frac_bits;
    unsigned round_bit, sticky_bit, new_frac;
    s = uf >> 31;
    exp = (uf >> 23) & 0xFF;
    frac = uf & 0x7FFFFF;

    /* Inf / NaN直接返回 */
    if (exp == 0xFF) return uf;
    E = exp - 127;
    /* 阶码>=23，无小数部分 */
    if (E >= 23) return uf;
    /* 绝对值小于0.5，舍入到0 */
    if (E < -1) {
        return s << 31;
    }
    /* E==-1，[0.5, 1.0)区间 */
    if (E == -1) {
        if (frac == 0) {
            return s << 31;
        } else {
            return (s << 31) | (0x7F << 23);
        }
    }
    frac_bits = 23 - E;
    m = frac | (1 << 23);
    mask = (1 << frac_bits) - 1;
    rem = m & mask;
    int_m = m & ~mask;
    round_bit = (rem >> (frac_bits - 1)) & 1;
    sticky_bit = 0;
    if (frac_bits > 1) {
        sticky_bit = (rem & ((1 << (frac_bits - 1)) - 1)) != 0;
    }
    /* 银行家舍入 */
    if (round_bit && (sticky_bit || (int_m & (1 << frac_bits)))) {
        int_m = int_m + (1 << frac_bits);
    }
    /* 处理进位 */
    if (int_m >= (1 << 24)) {
        new_frac = (int_m >> 1) & 0x7FFFFF;
        exp = exp + 1;
    } else {
        new_frac = int_m & 0x7FFFFF;
    }
    return (s << 31) | (exp << 23) | new_frac;
}

/* P17 */
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
    unsigned s, ux, frac, round_bit, sticky_bit;
    int k, exp;
    unsigned shift, one;
    if (x == 0) return 0;
    s = 0;
    ux = x;
    if (x < 0) {
        s = 1;
        ux = -x;
    }
    one = 1;
    k = 31;
    while (!(ux & (one << k))) {
        k = k - 1;
    }
    exp = k + 127;
    shift = 31 - k;
    ux = ux << shift;
    frac = (ux >> 8) & 0x7FFFFF;
    round_bit = (ux >> 7) & 1;
    sticky_bit = ux & 0x7F;
    /* 银行家舍入 */
    if (round_bit && (sticky_bit || (frac & 1))) {
        frac = frac + 1;
        if (frac >= (one << 23)) {
            frac = 0;
            exp = exp + 1;
        }
    }
    return (s << 31) | (exp << 23) | frac;
}

/* P18 */
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
    int m1, m2, m4;
    m1 = 0x55;
    m2 = 0x33;
    m4 = 0x0F;
    m1 = m1 | (m1 << 8);
    m1 = m1 | (m1 << 16);
    m2 = m2 | (m2 << 8);
    m2 = m2 | (m2 << 16);
    m4 = m4 | (m4 << 8);
    m4 = m4 | (m4 << 16);
    x = x + (~((x >> 1) & m1) + 1);
    x = (x & m2) + ((x >> 2) & m2);
    x = (x + (x >> 4)) & m4;
    x = x + (x >> 8);
    x = x + (x >> 16);
    return x & 0x3F;
}

/* P19 */
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *            bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x) {
    int m8, m4, m2, m1, mask16;
    m8 = 0xFF | (0xFF << 16);
    m4 = m8 ^ (m8 << 4);
    m2 = m4 ^ (m4 << 2);
    m1 = m2 ^ (m2 << 1);
    mask16 = 0xFF | (0xFF << 8);

    x = ((x >> 1) & m1) | ((x & m1) << 1);
    x = ((x >> 2) & m2) | ((x & m2) << 2);
    x = ((x >> 4) & m4) | ((x & m4) << 4);
    x = ((x >> 8) & m8) | ((x & m8) << 8);
    x = ((x >> 16) & mask16) | (x << 16);
    return x;
}
