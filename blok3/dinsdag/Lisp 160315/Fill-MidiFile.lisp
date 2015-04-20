;;;; Top-level file Lisp 050309
;;;;

(defvar *track-list1* nil) ;; so we can bind global to local - random acces in other file
(setq *track-list1*  nil)



(defun make-random-note1 (key-range key-duration) ;; lists: (min-key max-key)(min-duration max-duration)
  (let* ((dStartTime (random 100))
         (midikey (+ (random (- (second key-range)
                                (first key-range)))
                     (first key-range)))

        (velocity (+ (random 100) 27))
        (duration (+ (random (- (second key-duration) 
                                (first key-duration)))
                     (first key-duration))))
    (list 
     dStartTime midiKey velocity duration)))

(defun make-random-note2 (key-range key-duration bandwidth densx) ;; lists: (min-key max-key)(min-duration max-duration)
  (let* ((py (/ bandwidth 3.0))

         (y (+ (random (+ py 1.0))
               (random (+ py 1.0))
               (random (+ py 1.0))))

;;         (x (/ si densx))


         (dStartTime (round (* 7.0 y)))

         (midikey (round (+ (first key-range) y)))

        (velocity (round (+ 20.0 (* 3.0 y))))
        (duration (round (+ (first key-duration) y))))
    (list 
     dStartTime midiKey velocity duration)))

(defun make-tendency-note (list-of-data)
  (let ((dStartTime (first list-of-data))
        (midiKey (second list-of-data)) 
        (velocity (third list-of-data))
        (duration (fourth list-of-data)))
   (list 
     dStartTime midiKey velocity duration)))


;; ************************
;; ***** LIST JUMPING *****
;; ************************
(defun get-jump-list (i j L)
  "get-jump-list (startindex jumpsize List) jumpt door een lijst."
  (let* ((res nil)
         (L (nthcdr i L)))
    (setf i -1)
    (map 'list
         #'(lambda (x) 
             (if (eq (mod (incf i) j) 0)
               (push x res)))
         L)
    (reverse res)))



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;; TOPLEVEL FUNCTION USE IN LISTENER
;; (random-fill-midi-file "MyMIDIFile11.mid" 50)
;; (tendency-fill-midi-file "myTEND1.mid" 100)
;; (quantize '(20 43 103 139)
;;          :quantum 0.6 :speed 0.5) ;; 0.5

(defun random-fill-midi-file (midi-file-name number-of-notes min-interval max-interval minmax-pitch minmax-duration)
  (let ((TempList '())
        (prev-pitch '60)) ;; als je unieke pitches wil.
    (dotimes (i number-of-notes)
      (let* ((one-note 'nil))
        (setf one-note (make-random-note1 minmax-pitch minmax-duration))
        (princ one-note) 
        (if (and (not (eq (first one-note) 0))
                 (< (abs (- (second one-note) 
                            prev-pitch)) 
                    max-interval)
                 (> (abs (- (second one-note) 
                            prev-pitch)) 
                    min-interval))
            (progn
              (setf (first one-note) (car (quantize (list (first one-note))
                                                    :quantum 0.5
                                                    :speed 0.5)))
              (setf (fourth one-note) (car (quantize (list (fourth one-note))
                                                     :quantum 0.5
                                                     :speed 0.5)))
              (setf previous-pitch (second one-note))
              (setf TempList (cons one-note TempList))))))

    (setf Templist (reverse TempList)) ;; even reversen !!!!!
    ;;   (princ TempList) (terpri)
    (setf *track-list1* (append 
                         (TranslateCACEvntstoSTDMIDIfile TempList)))
    (write-to-stdmidi-file 4 4 120 1 midi-file-name)))   ;;; 4 4 maatsoort - tempo 120 - midichannel 1 - filename


(defun random2-fill-midi-file (midi-file-name number-of-notes min-interval max-interval minmax-pitch minmax-duration bandwidth densx)
  (let ((TempList '())
        (prev-pitch '60) ;; als je unieke pitches wil.
        (one-note 'nil))
    (dotimes (i number-of-notes)
      (setf one-note (make-random-note2 minmax-pitch minmax-duration bandwidth densx))

        (princ one-note) (terpri)

        (if (and (not (eq (first one-note) 0))
                 (< (abs (- (second one-note) 
                            prev-pitch)) 
                    max-interval)
                 (> (abs (- (second one-note) 
                            prev-pitch)) 
                    min-interval))
            (progn
              (setf (first one-note) (car (quantize (list (first one-note))
                                                    :quantum 0.5
                                                    :speed 0.5)))
              (setf (fourth one-note) (car (quantize (list (fourth one-note))
                                                     :quantum 0.5
                                                     :speed 0.5)))
              (setf previous-pitch (second one-note))
              (setf TempList (cons one-note TempList)))))

    (setf Templist (reverse TempList)) ;; even reversen !!!!!
    ;;   (princ TempList) (terpri)
    (setf *track-list1* (append 
                         (TranslateCACEvntstoSTDMIDIfile TempList)))
    (write-to-stdmidi-file 4 4 120 1 midi-file-name)))


(defun tendency-fill-midi-file (midi-file-name index total a1 a2 z1 z2 number-of-notes)
  (let ((note-list '())
        (TempList '())
        (x (calc-tendency-2 index total a1 a2 z1 z2 number-of-notes))) ;; 100 100 30 50 50 90 nos. first create a sequence of n numbers. (number-of-notes)
;;    (princ x)
    (loop for i from 0 to number-of-notes by 4 ;; we need four elements to make a note !!
          do
          (setf note-list 
                (cons (nth (+ i 0) x)
                      (cons (nth (+ i 1) x)
                            (cons (nth (+ i 2) x)
                                  (cons (nth (+ i 3) x) note-list)))))
          (princ note-list)
          (if (not (eq (cadddr note-list) nil))
              (progn
                (setf TempList 
                      (cons 
                       (make-tendency-note note-list) TempList))
                (setf note-list '())))) ;; make the list empty
         
  
  (setf *track-list1* (append 
                       (TranslateCACEvntstoSTDMIDIfile TempList))) ;; zijn we klaar dan append alles in the list
  (write-to-stdmidi-file 4 4 120 1 midi-file-name)))   ;;; 4 4 maatsoort - tempo 120 - midichannel 1 - filename


  ;;; (tendency-fill-midi-file "tendency1.mid" 102)





;;;;;;;;;;

