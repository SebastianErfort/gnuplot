load 'gnuplot.inc'

textwidthmult=0.5
textwidth=6.21 #Latex textwidth in inches
golden=(1.0+sqrt(5.0))/2.0
sizex=textwidth*textwidthmult
if (exist('setAspectRatio')) {eval(setAspectRatio)}
else {aspect_ratio=1.0/golden}
sizey=aspect_ratio*sizex 

set terminal cairolatex pdf standalone color colortext dashed dashlength 1 linewidth 1 font ", 11" size sizex,sizey header "\\usepackage{amsmath}\n\\input{".HOME."/texmf/tex/latex/commands}\n"
set sample 1000
