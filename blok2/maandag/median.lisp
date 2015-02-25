;  find median
;      1. sort data
;      2. is list even?
;          #t: get middle element
;          #f: get mean of middle 2 elements

(defun mean (x y &optional decimal)   ;  get mean of x and y
    (if decimal
        (/ (+ x y) 2.0)
        (/ (+ x y) 2)
    )
) ; (mean)

(defgeneric median (lst &optional decimal) ;  find median of lst
    (:method ((lst list) &optional decimal)
        (if (< (length lst) 2) 
            NIL
            (let ( (l (sort lst #'>)) (n (floor (/ (length lst) 2.0))) )
                (if (= n (/ (length lst) 2.0))
                    (nth n l)
                    (mean (nth n l) (nth (+ n 1) l) decimal)
                )
            )
        )
    )
) ; (median)
   
(defvar e_lst '(1 99 82 9 3 2))
(defvar o_lst '(9 22 82 1 98)) 
