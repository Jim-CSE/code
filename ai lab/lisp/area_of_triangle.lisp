(defun AreaOfTriangle()
(terpri)
(princ "Enter the base: ")
(setq base (read))
(princ "Enter the height: ")
(setq height (read))
(setq area (* 0.5 base height))
(princ "The area of the triangle : ")
(write area)
(terpri))

(AreaOfTriangle)





