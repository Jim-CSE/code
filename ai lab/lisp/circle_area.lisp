(defun ca()
  (terpri) ;newline
  (princ "Enter the radius: ")
  (setq radius (read)) ; Read the radius as a variable
  (setq area (* 3.1416 radius radius)) ; Calculate the area
  (princ "The area of the circle is: ")
  (format t " ~,3f~%" area)) ; Properly format the output
; Call the function to calculate the area
(ca)