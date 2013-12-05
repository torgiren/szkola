all: pics docs

pics:
	python main.py < test.dat

docs:
	latex sprawozdanie.tex
	latex sprawozdanie.tex

clean:
	rm -f *.ps
	rm -f *.dvi
	rm -f *.log
	rm -f *.aux
	rm -f *.pyc
