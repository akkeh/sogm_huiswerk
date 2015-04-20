(defun square (x) (* x x))

(defun quantize (intervals &key (speed 0.0) (trust 1.)
                           (quantum (first intervals)))
  (loop for in in intervals
        as out = (quantize-ioi in quantum)
        as error = (quantization-error in out quantum)
        do (incf quantum
                 (* (delta-quantum error out quantum)
                    (confidence error trust)
                    speed))
        collect out))

(defun quantize-ioi (time quantum)
  (round (/ time quantum)))

(defun quantization-error (in out quantum)
  (- (/ in quantum) out))

(defun delta-quantum (error out quantum)
  (* quantum (/ error out)))

(defun confidence (error trust)
  (- 1 (* (- 1 trust)(square (* 2 error)))))


#|
(quantize '(1.177 0.592 0.288 0.337 0.436 0.337 0.387 0.600
                  0.634 0.296 0.280 0.296 0.346 1.193)
          :quantum 0.1 :speed 0.5)
|#

(quantize '(20 43 103 139)
          :quantum 0.6 :speed 0.5) ;; 0.5

