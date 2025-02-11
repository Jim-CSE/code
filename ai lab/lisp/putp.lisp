(defun putprop-example ()
  ;; Define a symbol 'person
  (setq person 'john)

  ;; Assign properties to the symbol using putprop
  (putprop person 'male 'gender)    ; Assign gender as male
  (putprop person 35 'age)          ; Assign age as 35
  (putprop person 'engineer 'profession) ; Assign profession as engineer

  ;; Retrieve and display the properties using get
  (format t "Gender: ~a~%" (get person 'gender))   ; Retrieve gender
  (format t "Age: ~a~%" (get person 'age))         ; Retrieve age
  (format t "Profession: ~a~%" (get person 'profession)) ; Retrieve profession

  ;; Display the full property list of the symbol
  (format t "Property list of 'john: ~a~%" (symbol-plist person)))
;; Example usage:
(putprop-example)