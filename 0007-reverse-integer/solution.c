int reverse(int x) {
    int rev = 0;

    while (x != 0) {
        int digit = x % 10;   // last digit
        x = x / 10;           // remove last digit
        if (rev > 214748364 || (rev == 214748364 && digit > 7))
            return 0;
        if (rev < -214748364 || (rev == -214748364 && digit < -8))
            return 0;

        rev = rev * 10 + digit;
    }

    return rev;
}

