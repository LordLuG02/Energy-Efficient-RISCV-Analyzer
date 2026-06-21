int _start() {

    int a = 10;
    int b = 5;

    int add, sub, and_op, or_op;

    for (int i = 0; i < 5; i++) {

        add = a + b;
        sub = a - b;
        and_op = a & b;
        or_op = a | b;

        a = add;   // create dependency
        b = sub;
    }

    while(1);

    return 0;
}
