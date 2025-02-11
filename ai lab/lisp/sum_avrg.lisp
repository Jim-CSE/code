(defun sa(defun at(n1 n2 n3)
(/(+ n1 n2 n3)3))
AT
[17]> (at 10 20 30)
20


(defun sum-and-average ()
  (terpri)
  (princ "Enter the numbers (as a list, e.g., (1 2 3 4)): ")
  (let ((numbers (read))) ; Read the list of numbers from user input
    (let ((sum (reduce #'+ numbers))) ; Calculate the sum of the numbers
      (let ((average (/ sum (length numbers)))) ; Calculate the average
        (terpri)
        (format t "Sum: ~d~%" sum) ; Print the sum
        (format t "Average: ~f~%" average))))) ; Print the average

; Call the function
(sum-and-average)
