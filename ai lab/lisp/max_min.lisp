finding max between 2 numbers using cond
(defun max2(a b)
(cond ((> a b) a)
(t b)))
MAX2
[22]> (max2 20 10)
20

finding max between 3 numbers using cond
(defun max3 (a b c)
  (cond
    ((and (> a b) (> a c)) a) ; If a is greater than both b and c, return a
    ((> b c) b)               ; If b is greater than c, return b
    (t c)))                   ; Otherwise, return c
MAX3
[27]> (max3 10 30 15)
30


(defun find-max-min ()
  (terpri)
  (princ "Enter a list of numbers (e.g., (1 2 3 4 5)): ")
  (let ((numbers (read)))  ; Read the list of numbers from user input
    (let ((maximum (apply #'max numbers))  ; Find the maximum value
          (minimum (apply #'min numbers))) ; Find the minimum value
      (terpri)
      (format t "Maximum: ~d~%" maximum)  ; Print the maximum
      (format t "Minimum: ~d~%" minimum)))) ; Print the minimum

; Call the function
(find-max-min)
