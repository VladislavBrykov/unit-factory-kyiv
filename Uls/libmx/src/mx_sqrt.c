int mx_sqrt(int x) {
    long sqrt = 0;
    long buff = 3;

    if (x < 1)
        return 0;
    sqrt = x / 2;
    while (sqrt * sqrt != x){
        if (buff - sqrt == 1)
            return 0;
        if (sqrt * sqrt > x) {
            buff = sqrt;
            sqrt /= 2;
        } 
        else
            sqrt = (buff + sqrt) / 2;
    }
    return sqrt;
} 
