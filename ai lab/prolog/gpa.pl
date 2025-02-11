gpa(jim,3.66).
gpa(atel,3.80).
gpa(moni,3.25).
gpa(sadi,3.35).
gpa(abid,3.55).
result:- write('Enter student name:'),
read(X),gpa(X,Y),nl,
write('GPA is '),
write(Y).
