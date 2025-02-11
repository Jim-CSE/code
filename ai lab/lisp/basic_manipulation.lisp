(write (car '(a b c d e f))) ; Access the first element of the list
(terpri) ; Newline
(write (cdr '(a b c d e f))) ; Access the rest of the list except the first element
(terpri) ; Newline
(write (cons 'a '(b c))) ; Construct a new list with 'a' as the first element and '(b c)' as the rest
(terpri) ; Newline
(write (list 'a '(b c) '(e f))) ; Create a list of three elements: 'a', '(b c)', and '(e f)'
(terpri) ; Newline
(write (append '(b c) '(e f) '(p q) '() '(g))) ; Concatenate several lists into one
(terpri) ; Newline
(write (last '(a b c d (e f)))) ; Access the last element of the list, which can be a sublist
(terpri) ; Newline
(write (reverse '(a b c d (e f)))) ; Reverse the list







(write (append '(b c) '(e f) '(p q) '() '(g))) ; Concatenate several lists into one
(terpri) ; Newline

(write (last '(a b c d (e f)))) ; Access the last element of the list, which can be a sublist
(terpri) ; Newline

(write (reverse '(a b c d (e f)))) ; Reverse the list
(terpri) ; Newline

(write (member 'c '(a b c d e f))) ; Check if 'c' is a member of the list and return the sublist starting from 'c'
