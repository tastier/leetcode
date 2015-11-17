int reverse(int x) {
    int sum = 0;

    while(x != 0) {
        // we do not need to check if sum == 214748364，这种情况下是一定不会溢出的
        //|| ((sum == 214748364) && (x > 7)) || ((sum == -214748364) && (x < -8))
        if( (sum > 214748364) || (sum < -214748364)) 
            return 0;         
        sum = sum * 10 + x % 10;
        x = x / 10;
    }
    return sum;
}
