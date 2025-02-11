gpa(jim,3.6).
gpa(j,5).
result:- write('enter name: '),
    read(X),gpa(X,Y),nl,
    write('gpa is '),
    write(Y).
