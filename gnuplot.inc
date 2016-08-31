#load inputDir.'/jet.pal'  # Mathematica-like color bar for palette plots

set macros # Enable macros (strings evaluated using @MACRO)
 
# parameters 
i = {0.0,1.0}
tm = 0.95; bm = 0.15; lm = 0.15; rm = 0.9 # Default plot margins

#~~~~~~~~~~~~~~~~~~~~ line styles ~~~~~~~~~~~~~~~~~~~~
set style line 1 lt 1 lw 2 pt 4 ps 0.5 lc rgb 'red' 
set style line 2 lt 1 lw 2 pt 4 ps 0.5 lc rgb 'blue'
set style line 3 lt 1 lw 2 pt 4 ps 0.5 lc rgb 'dark-green'
set style line 4 lt 1 lw 2 pt 4 ps 0.5 lc rgb 'magenta'
set style line 5 lt 1 lw 2 pt 4 ps 0.5 lc rgb 'cyan'
set style line 6 lt 1 lw 2 pt 4 ps 0.5 lc rgb 'gold'
set style line 7 lt 1 lw 2 pt 4 ps 0.5 lc rgb 'brown'
set style line 8 lt 1 lw 2 pt 4 ps 0.5 lc rgb 'black'
# dashed
set style line 11 lt 2 lw 2 pt 4 ps 0.5 lc rgb 'red' 
set style line 12 lt 2 lw 2 pt 4 ps 0.5 lc rgb 'blue'
set style line 13 lt 2 lw 2 pt 4 ps 0.5 lc rgb 'dark-green'
set style line 14 lt 2 lw 2 pt 4 ps 0.5 lc rgb 'magenta'
set style line 15 lt 2 lw 2 pt 4 ps 0.5 lc rgb 'cyan'
set style line 16 lt 2 lw 2 pt 4 ps 0.5 lc rgb 'gold'
set style line 17 lt 2 lw 2 pt 4 ps 0.5 lc rgb 'brown'
set style line 18 lt 2 lw 2 pt 4 ps 0.5 lc rgb 'black'

# key
set key samplen 5 spacing 1.2
set key width 3.0

#~~~~~~~~~~~~~~~~~~~~ functions ~~~~~~~~~~~~~~~~~~~~
max(x,y) = (x > y) ? x : y
min(x,y) = (y > x) ? x : y

#~~~~~~~~~~~~~~~~~~~~ settings ~~~~~~~~~~~~~~~~~~~~
set decimalsign '{.}'
set fit errorvariables

#~~~~~~~~~~~~~~~~~~~~ MACROS ~~~~~~~~~~~~~~~~~~~~
# Use these as strings that will be attached to other macros or
# executed by using eval() or use as standalone macros

# Tics and labels
 
unsetXLabel="unset xlabel;"
setXTics="set xtics autofreq; set xtics format '%g';"
unsetXTics="unset xtics; set xtics format '';"
 
unsetYLabel="unset ylabel;"
setYTics="set ytics autofreq; set ytics format '%g';"
unsetYTics="unset ytics; set ytics format '';"
 
setColorbox(opt)= (opt == "") ? "set colorbox;" : "set colorbox ".opt.";" # TODO enable usage with empty brackets only
unsetColorbox="unset colorbox;"
 
subPltMrgns(t,b,l,r) = sprintf("set tmargin at screen %1.4f; set bmargin at screen %1.4f; set lmargin at screen %1.4f; set rmargin at screen %1.4f;",t,b,l,r) # Function for setting top, bottom, left and right subplot margins
   
# Special plot settings
setHeatmap="set pm3d map interpolate 0,0" # Plot 2d heat map using splot
