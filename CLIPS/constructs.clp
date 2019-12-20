(deffacts init-data 
	(data 34)
	(data 13.2)
)

(defrule get-data 
	(data ?num)
=>
	(printout t "Tripling " ?num crlf) 
	(assert (new-value (triple ?num)))
)

(defrule get-new-value
	(new-value ?num)
=>
	(printout t crlf "Now equal to " ?num crlf)
)
