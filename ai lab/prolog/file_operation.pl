writeinfile :-
    tell('G:/New folder/7th/AI/ai lab/prolog/filen.txt'),  % Open file for writing
    write('hello'), nl,  % Write 'radif' and add a new line
    told.  % Close the file

readfromfile :-
    readfromfile('G:/New folder/7th/AI/ai lab/prolog/filen.txt',
                 'G:/New folder/7th/AI/ai lab/prolog/output.txt').

readfromfile(Infile, Outfile) :-
    see(Infile),  % Open input file for reading
    tell(Outfile),  % Open output file for writing
    read(Sentence),  % Read a Prolog term from input file
    write(Sentence), nl,  % Write the term to output file
    seen,  % Close input file
    told.  % Close output file
