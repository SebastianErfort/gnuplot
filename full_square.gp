load 'gnuplot.gp'

textwidthmult=1.0
textwidth=6.21 #Latex textwidth in inches
sizex=textwidth*textwidthmult;sizey=sizex

set terminal cairolatex pdf standalone color colortext dashed dashlength 1 linewidth 1 font ", 11" size sizex,sizey header "\\usepackage{amsmath}\n\\input{".HOME."/texmf/tex/latex/commands}\n"
set sample 1000
