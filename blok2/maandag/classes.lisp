(defclass test_class () 
    (
        (name :initarg :name :initform "test" :accessor name)
        (val :initarg :val :initform 10 :accessor val)
    )
)

(defmethod initialise-instance :after ((self test_class) &rest initargs)
    (format 't "new instance of ~A~%" self)
)

(defmethod get_val :after ((self test_class))
    (let ((a (slotvalue self 'val)))
        (format 't "value: ~A~%" a)
    )
)



