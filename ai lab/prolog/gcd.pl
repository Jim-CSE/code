% Base case: GCD of a number and 0 is the number itself
gcd(X, 0, X).
% Recursive case: Calculate the remainder and recursively find GCD
gcd(X, Y, D) :-
    R is X mod Y,
    gcd(Y, R, D).
% LCM is calculated using GCD
lcm(X, Y, M) :-
    gcd(X, Y, D),
    M is (X * Y) // D.
