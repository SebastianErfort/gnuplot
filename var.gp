# vim: set ft=gnuplot

# Plot settings with variable mostly variable parameters, e.g.
# - text width, plot size factor wrt text width, aspect ratio
# - LaTeX header, font, font size

# Load basic settings, line styles, etc.
load 'gnuplot.gp'

# Set variables
if (!exist('textwidthmult')) { textwidthmult=1.0 }
if (!exist('textwidth')) {
    textwidth=6.21 # Latex textwidth in inches for A4 paper
    if (exist('doctype')) {
        if (doctype eq 'beamer' ) { textwidth=4.25 } # LaTeX beamer textwidth in inches
    }
}
if (!exist('aspectratio')) { aspectratio=(1.0+sqrt(5.0))/2.0 } # golden ratio

sizex=textwidth*textwidthmult; sizey=sizex/aspectratio

# Set header for LaTeX (packages to be loaded, font, etc.)
if ( !exist('latex_header') ) {
    if ( !exist('latex_font') ) {
        latex_header = "\\usepackage{amsmath}\n"
#                     "\\input{".HOME."/texmf/tex/latex/commands}\n";
    } else {
        latex_header = "\\usepackage{amsmath}\n".latex_font
#                    "\\input{".HOME."/texmf/tex/latex/commands}\n";
    }
}
if ( exist('latex_fontsize') ) { fontsize=latex_fontsize }
else { fontsize=11 }

# Set terminal
set terminal cairolatex pdf standalone color colortext dashed dashlength 1 linewidth 1 \
    font ", ".fontsize \
    size sizex, sizey header latex_header
set size ratio 1/aspectratio
# set size sizex, sizey

set sample 1000 # Increase sampling for smoother plots
