fib(0,0).
fib(1,1).
fib(N,F):- N>1,
N1 is N-1,
N2 is N-2,
fib(N1,F1),
fib(N2,F2),
F is F1+F2.


% Base cases
fibonacci(0, 0).
fibonacci(1, 1).
% Recursive case
fibonacci(N, Result) :-
 N > 1, % Ensure N is greater than 1 for recursion
 N1 is N - 1, % Calculate N1 as N-1
 N2 is N - 2, % Calculate N2 as N-2
 fibonacci(N1, R1), % Recursive call to calculate the Fibonacci number for N1
 fibonacci(N2, R2), % Recursive call to calculate the Fibonacci number for N2
 Result is R1 + R2. % Sum the results of the two recursive calls
