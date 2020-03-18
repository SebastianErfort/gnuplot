#######################################################################
# Der folgende Abschnitt "Variablen" muss editiert werden. Alles      #
# andere funktioniert dann automatisiert, sofern keine Sonderwünsche  #
# an die Fähigkeiten des make-Skriptes bestehen.		      #
#######################################################################

# Variablen:
# ==========

# Unterverzeichnisse, die abgearbeitet werden müssen
DIRS = dir1 \
       dir2

# BSP1: LaTeX

# Alle LaTeX-Dateien des gesamten Dokuments
TEXFILES = file.tex
# Haupt-LaTeX-Datei
TEXMAINFILE = file.tex
# Alle benötigten BibTeX-Dateien
BIBTEXFILES = lit.bib

#######################################################################
# Ende des Abschnitts, der editiert werden muss.                      #
#######################################################################


# Mögliche ZIELE und AKTIONEN:
# ============================

# Erzeuge das Dokument, Standardziel
all:	pdf dirs

pdf:	file.pdf

bbl:	lit.bib

# Lösche alle Dateien bis auf die Quellen, sauberer Ausgangszustand
# (gilt auch für die Unterverzeichnisse)
clean:  clean_dirs
	rm -f *.swn *.swo *.swp *.aux *.bbl *.blg *.log *.out *.pdf *.toc *.dvi *~ *.bak *.ps *.glo *.acn *.ist *.xdy *.glo *.tdo

# Stelle einen sauberen Ausgangszustand her und erzeuge das Dokument
new:    clean all


# Spezielle Eigenschaften einiger Ziele (siehe make-Dokumentation):
# =================================================================

.PHONY: clean dirs $(DIRS) clean_dirs new pdf

.PRECIOUS: %.aux %.bbl


# REGELN - Behandlung von Zielen in den oben angegebenen Verzeichnissen:
# =============================================================

dirs: $(DIRS)

clean_dirs:
	$(foreach directory, $(DIRS), $(MAKE) -C $(directory) clean;)

$(DIRS):
	$(MAKE) -C $@


# Ziele in diesem Verzeichnis (LaTeX und BibTeX):
# ===============================================

%.pdf:	$(DIRS) $(TEXFILES) %.aux %.bbl %.out
	pdflatex -interaction=nonstopmode $*; pdflatex -interaction=nonstopmode $*

%.bbl:	%.blg
	biber presentation

%.out:	$(DIRS) $(TEXFILES)
	pdflatex -interaction=nonstopmode $*
