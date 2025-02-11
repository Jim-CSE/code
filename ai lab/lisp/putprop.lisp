syntex
(setf (get 'object_name 'attribute_name or property) '(values)

for example i have 3 pets name a b c then the code is
(setf (get 'jim 'pets) '(a b c))

to retrieve the property value,use get funtion
(get 'jim 'pets)

adding one more pet with previous pets
(setf (get 'jim 'pets) (cons 'd (get 'jim 'pets)))

remove a pet
(setf (get 'jim 'pets) (remove 'b (get 'jim 'pets)))





final code

(defun demo-property-list ()
  ;; Set property 'pets for symbol 'jim to (a b c)
  (setf (get 'jim 'pets) '(a b c))
  (format t "Jim's pets name: ~a~%" (get 'jim 'pets))
  
  ;; Set another property 'age for symbol 'jim to 24
  (setf (get 'jim 'age) 24)
  (format t "Jim's age: ~a~%" (get 'jim 'age))
  
  ;; Change the 'pets property to add 'd at the front of the existing list
  (setf (get 'jim 'pets) (cons 'd (get 'jim 'pets)))
  (format t "Updated Jim's pets: ~a~%" (get 'jim 'pets))
  
  ;; Add property 'e to specify that Jim is a student in CSE
  (setf (get 'jim 'e) "student")
  (format t "Jim is a: ~a~%" (get 'jim 'e))

  ;; You can add more operations or checks if necessary
)

;; Call the function
(demo-property-list)

