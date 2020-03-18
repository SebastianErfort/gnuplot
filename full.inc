load 'gnuplot.inc'

textwidthmult=1.0
textwidth=6.21 #Latex textwidth in inches
golden=(1.0+sqrt(5.0))/2.0
sizex=textwidth*textwidthmult;sizey=sizex/golden

set terminal cairolatex pdf standalone color colortext dashed dashlength 1 linewidth 1 font ", 11" size sizex,sizey header "\\usepackage{amsmath}\n\\input{".HOME."/texmf/tex/latex/commands}\n"
set sample 1000
