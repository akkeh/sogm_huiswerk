(defvar test '(1 2 3 4 5 6 7 8 9 10))

(defun get-jump-list (i j L)
    "get-jump-list (start jumpsize list) return each nth value"
    (let* ((res nil)
        (L (nthcdr i L)))
        (setf i -1)
        (map 'list
            #'(lambda (x)
                (if (eq (mod (incf i) j) 0)
                    (push x res)))
            L)
        (reverse res)))


(get-jump-list 1 2 test)
