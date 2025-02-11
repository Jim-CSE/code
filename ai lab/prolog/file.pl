writeinfile :-
    open('G:/New folder/7th/AI/ai lab/prolog/filen.txt', write, Stream),  % Open file for writing
    write(Stream, 'radif is a boy'), nl(Stream),  % Write 'radif' and add newline
    close(Stream).  % Close the file

readfromfile :-
    readfromfile('G:/New folder/7th/AI/ai lab/prolog/filen.txt',
                 'G:/New folder/7th/AI/ai lab/prolog/output.txt').

readfromfile(Infile, Outfile) :-
    open(Infile, read, InStream),  % Open input file for reading
    open(Outfile, write, OutStream),  % Open output file for writing
    read_line_to_string(InStream, Sentence),  % Read a line as a string
    write(OutStream, Sentence), nl(OutStream),  % Write to output file and add newline
    close(InStream),  % Close the input file
    close(OutStream).  % Close the output file
