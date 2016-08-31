all: $(patsubst %.gpl,%.pdf,$(wildcard *.gpl))

clean:
	rm -f *~
	rm -r *.pdf

fast: $(patsubst %.gpl,%.pdf_fast,$(wildcard *.gpl))

new: clean all
	
%.pdf: %.gpl
	gnuplot -e "name='$*'" $*.gpl
	pdflatex $*.tex > /dev/null
	rm -f $*-inc.pdf $*.aux $*.log $*.tex
	pdfcrop $*.pdf $*.pdf > /dev/null
	pdf2ps $*.pdf > /dev/null
	ps2pdf $*.ps > /dev/null
	rm -f $*.ps

%.pdf_fast: %.gpl
	gnuplot -e "name='$*'" $*.gpl
	pdflatex $*.tex > /dev/null
	rm -f $*-inc.pdf $*.aux $*.log $*.tex
