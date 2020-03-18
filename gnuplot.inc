# Basic information
gnuplot_version=system('gnuplot --version')

set macros # Enable macros (strings evaluated using @MACRO)
 
# parameters 
i = {0.0,1.0}
tm = 0.95; bm = 0.15; lm = 0.15; rm = 0.9 # Default plot margins

#~~~~~~~~~~~~~~~~~~~~ line styles ~~~~~~~~~~~~~~~~~~~~
if (!exist('lw_')) {lw_=3} # Set line width if not already defined
 
# Set line styles NOTE dashed line specification was changed with version 5, hence the discrimination

# solid
set style line 1 lt 1 lw lw_ pt 4 ps 0.5 lc rgb 'red' 
set style line 2 lt 1 lw lw_ pt 4 ps 0.5 lc rgb 'blue'
set style line 3 lt 1 lw lw_ pt 4 ps 0.5 lc rgb 'forest-green'
set style line 4 lt 1 lw lw_ pt 4 ps 0.5 lc rgb 'gold'
set style line 5 lt 1 lw lw_ pt 4 ps 0.5 lc rgb 'magenta'
set style line 6 lt 1 lw lw_ pt 4 ps 0.5 lc rgb 'cyan'
set style line 7 lt 1 lw lw_ pt 4 ps 0.5 lc rgb 'brown'
set style line 8 lt 1 lw lw_ pt 4 ps 0.5 lc rgb 'black'
 
if (int(gnuplot_version[9:9]) < 5) {
  # dashed with colors (for grey scale support) TODO Add more dashtypes
  set style line 11 lt 1 lw lw_ pt 4 ps 0.5 lc rgb 'red' 
  set style line 12 lt 2 lw lw_ pt 4 ps 0.5 lc rgb 'blue'
  set style line 13 lt 3 lw lw_ pt 4 ps 0.5 lc rgb 'forest-green'
  set style line 14 lt 4 lw lw_ pt 4 ps 0.5 lc rgb 'gold'
  set style line 15 lt 5 lw lw_ pt 4 ps 0.5 lc rgb 'magenta'
  set style line 16 lt 6 lw lw_ pt 4 ps 0.5 lc rgb 'cyan'
  set style line 17 lt 7 lw lw_ pt 4 ps 0.5 lc rgb 'brown'
  set style line 18 lt 8 lw lw_ pt 4 ps 0.5 lc rgb 'black'
   
  # dashed lt 2 only
  set style line 21 lt 2 lw lw_ pt 4 ps 0.5 lc rgb 'red' 
  set style line 22 lt 2 lw lw_ pt 4 ps 0.5 lc rgb 'blue'
  set style line 23 lt 2 lw lw_ pt 4 ps 0.5 lc rgb 'forest-green'
  set style line 24 lt 2 lw lw_ pt 4 ps 0.5 lc rgb 'gold'
  set style line 25 lt 2 lw lw_ pt 4 ps 0.5 lc rgb 'magenta'
  set style line 26 lt 2 lw lw_ pt 4 ps 0.5 lc rgb 'cyan'
  set style line 27 lt 2 lw lw_ pt 4 ps 0.5 lc rgb 'brown'
  set style line 28 lt 2 lw lw_ pt 4 ps 0.5 lc rgb 'black'

} else {
  # More dashtypes - TODO rework 
  set dashtype 6 "--."
  set dashtype 7 "...-"
  set dashtype 8 "---."
  set dashtype 9 "_.-"
  set dashtype 10 ". ."
   
  # dashed with colors (for grey scale support)
  set style line 11 lt 1 dt  1 lw lw_ pt 4 ps 0.5 lc rgb 'red' 
  set style line 12 lt 1 dt  2 lw lw_ pt 4 ps 0.5 lc rgb 'blue'
  set style line 13 lt 1 dt  3 lw lw_ pt 4 ps 0.5 lc rgb 'forest-green'
  set style line 14 lt 1 dt  4 lw lw_ pt 4 ps 0.5 lc rgb 'gold'
  set style line 15 lt 1 dt  5 lw lw_ pt 4 ps 0.5 lc rgb 'cyan'
  set style line 16 lt 1 dt  6 lw lw_ pt 4 ps 0.5 lc rgb 'magenta'
  set style line 17 lt 1 dt  7 lw lw_ pt 4 ps 0.5 lc rgb 'brown'
  set style line 18 lt 1 dt  8 lw lw_ pt 4 ps 0.5 lc rgb 'black'
  set style line 19 lt 1 dt 10 lw lw_ pt 4 ps 0.5 lc rgb 'red' 
   
  # dashed lt 2 only
  set style line 21 lt 1 dt 2 lw lw_ pt 4 ps 0.5 lc rgb 'red' 
  set style line 22 lt 1 dt 3 lw lw_ pt 4 ps 0.5 lc rgb 'blue'
  set style line 23 lt 1 dt 4 lw lw_ pt 4 ps 0.5 lc rgb 'forest-green'
  set style line 24 lt 1 dt 5 lw lw_ pt 4 ps 0.5 lc rgb 'magenta'
  set style line 25 lt 1 dt 6 lw lw_ pt 4 ps 0.5 lc rgb 'cyan'
  set style line 26 lt 2 dt 7 lw lw_ pt 4 ps 0.5 lc rgb 'gold'
  set style line 27 lt 2 dt 8 lw lw_ pt 4 ps 0.5 lc rgb 'brown'
  set style line 28 lt 2 dt 9 lw lw_ pt 4 ps 0.5 lc rgb 'black'

} 
 
#~~~~~~~~~~~~~~~~~~~~ functions ~~~~~~~~~~~~~~~~~~~~
max(x,y) = (x > y) ? x : y
min(x,y) = (y > x) ? x : y

#~~~~~~~~~~~~~~~~~~~~ settings ~~~~~~~~~~~~~~~~~~~~
set decimalsign '{.}'
set fit errorvariables

#~~~~~~~~~~~~~~~~~~~~ MACROS ~~~~~~~~~~~~~~~~~~~~
# Use these as strings that will be attached to other macros or
# executed by using eval() or use as standalone macros


# Tics, labels and key
 
setXLabel="set xlabel '$x$';"; unsetXLabel="unset xlabel;"
setXTics="set xtics autofreq; set xtics format '%g';"
unsetXTics="unset xtics; set xtics format '';"
 
setYLabel="set ylabel '$y$';"; unsetYLabel="unset ylabel;"
setYTics="set ytics autofreq; set ytics format '%g';"
unsetYTics="unset ytics; set ytics format '';"
 
setColorbox(opt)= (opt == "") ? "set colorbox;" : "set colorbox ".opt.";" # TODO enable usage with empty brackets only
unsetColorbox="unset colorbox;"
 
unsetKey="unset key;"


# Function for setting top, bottom, left and right subplot margins relative to screen
subPltMrgns(t,b,l,r) = sprintf("set tmargin at screen %1.4f; set bmargin at screen %1.4f; set lmargin at screen %1.4f; set rmargin at screen %1.4f;",t,b,l,r)

# Special plot settings
setHeatmap="set pm3d map interpolate 0,0;" # Plot 2d heat map using splot
unsetHeatmap="unset pm3d;"
