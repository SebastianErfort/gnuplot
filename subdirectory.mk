all: $(patsubst %.gp,%.pdf,$(wildcard *.gp))

clean:
	rm -f *~
	rm -r *.pdf

fast: $(patsubst %.gp,%.pdf_fast,$(wildcard *.gp))

new: clean all
	
%.pdf: %.gp
	gnuplot -e "name='$*'" $*.gp
	pdflatex $*.tex > /dev/null
	rm -f $*-inc.pdf $*.aux $*.log $*.tex
	pdfcrop $*.pdf $*.pdf > /dev/null
	pdf2ps $*.pdf > /dev/null
	ps2pdf $*.ps > /dev/null
	rm -f $*.ps

%.pdf_fast: %.gp
	gnuplot -e "name='$*'" $*.gp
	pdflatex $*.tex > /dev/null
	rm -f $*-inc.pdf $*.aux $*.log $*.tex
