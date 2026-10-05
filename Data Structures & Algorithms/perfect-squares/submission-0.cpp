class Solution {
public:
    // returns true if x is a perfect square
    bool isSquare(int x) {
        int r = (int)sqrt(x);       // integer square root
        return r * r == x;          // exact match means x is a square
    }

    int numSquares(int n) {
        if (isSquare(n)) return 1;          // answer 1: n itself is a square

        while (n % 4 == 0) n /= 4;          // factors of 4 don't change the answer

        if (n % 8 == 7) return 4;           // Legendre: n = 4^a(8b+7) needs 4 squares

        for (int a = 1; a * a <= n; a++) {  // try every square a*a that fits in n
            if (isSquare(n - a * a)) return 2;  // n = a^2 + b^2 -> 2 squares
        }
        return 3;                           // otherwise, 3 squares
    }
};