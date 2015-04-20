;;;; Top-level file Lisp 120309
;;;; mk120309
;;;;
;;;;

(defvar *tendency-list1* nil) ;; so we can bind global to local - gives random acces in other files
(setq *tendency-list1*  nil)




;;; 132 loop
(defun calc-tendency-1 (index total a1 a2 z1 z2 maxi)
  (format t "Now calculating Tendency #1~%")
    (let* (x)
      (loop for i from 0 to maxi
            do
            (setf x 
                  (cons 
                   (tend1 index total a1 a2 z1 z2) x)))
      x))

(defun calc-tendency-2 (index total a1 a2 z1 z2 maxi)
  (format t "Now calculating Tendency #2~%")    
    (let* (x)
        (loop for i from 0 to maxi
              do
              (setf x 
                    (cons 
                     (tend2 index total a1 a2 z1 z2) x)))
        x))


(defun alea (a z)
  "alea (a z) gives 1 random number between a and z back a = minimum, z = maximum"
  (round (+ (min a z) (* (random (+ 1 (abs (- z a))))))))

(defun tend1 (index total a1 a2 z1 z2)
  "tendency (index total a1 a2 z1 z2) gives 1 random number. index = ophoging"
  (alea (round (+ a1 (* (decf index) (/ (float (- z1 a1))(decf total)))))
        (round (+ a2 (* (decf index) (/ (float (- z2 a2))(decf total)))))))

(defun tend2 (index total a1 a2 z1 z2)
  "tendency2 (index total a1 a2 z1 z2) gives 1 random number. index = ophoging"
  (alea (round (+ a1 (* (decf index) (/ (float (- z1 a1)) total))))
        (round (+ a2 (* (decf index) (/ (float (- z2 a2)) total))))))


(format t "TENDENCY~%")

;;;; TOPLEVEL FUNCTION

;; (calc-tendency-1 index total a1 a2 z1 z2)
;; (calc-tendency-1 100 100 30 50 50 90 100)



;;;;;;;;;;



;; **********************
;; ***** Recursion  *****
;; **********************

;;;112

(defun sumall (n)
  (cond ((zerop n) 0)
        (t
         (+ n (sumall (- n 1))))))




;; 117

(defun find-prime (num1 num2)
  (cond ((primep num2) num2)
        ((equal num1 num2) nil)
        (t
         (find-prime num1 (- num2 1)))))  ;; or: (1- num2)


(defun list-primes (arg)
  (cond ((zerop arg) nil)
        ((primep arg) (cons arg (list-primes (- arg 1))))
        (t
         (list-primes (- arg 1)))))

;;; 103
(defun primep (n)
  (cond ((< n 4) t)
        (t
         (psearch n))))

(defun psearch (num)
  (let ((count 2)
        (stop (sqrt num)))
    (loop
     (cond ((> count stop)(return t))
           ((zerop (mod num count ))(return nil)))
     (setq count (1+ count))))) ;; or: (+ count 1) or (incf count)



(format t "Have been loaded: TENDENCY~%")
