all: sprawozdanie.pdf lab01
	

sprawozdanie.pdf: sprawozdanie.tex
	pdflatex $^

lab01:
	python lab_01.py

clean:
	rm *.log *.aux


.PHONY: clean
