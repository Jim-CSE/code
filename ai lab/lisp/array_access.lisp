(defun array-example ()
  ;; Declare an array of size 5
  (let ((my-array (make-array 5)))  ;; Declare the array using LET

    ;; Prompt the user to input values for each element
    (dotimes (i 5)
      (format t "Enter value for element ~d: " i)
      (setf (aref my-array i) (read))) ;; Set the array elements with user input

    ;; Access and print array elements
    (format t "~%Array Elements:~%")
    (dotimes (i 5)  ;; Loop through the array and print elements
      (format t "Element ~d: ~d~%" i (aref my-array i)))
    )
  )

;; Call the function to run the program
(array-example)
