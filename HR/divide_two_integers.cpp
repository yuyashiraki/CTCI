int divide(int dividened, int divisor)
{
    int sign = ((dividened < 0) ^ (divisor < 0)) ? -1 : 1;
    dividened = abs(dividened);
    divisor = abs(divisor);
    int quotinent = 0;
    while (dividened >= divisor) {
        dividened -= divisor;
        quotinent++;
    }
    return sign * quotinent;
}
